#include <string>  
#include <iostream>  
#include <fstream>  
#include <vector>  
#include "winsock2.h"  
#include <time.h>  
#include <queue>  
#include <hash_set>  
  
  
#pragma comment(lib, "ws2_32.lib")   
using namespace std;  
  
#define DEFAULT_PAGE_BUF_SIZE 1048576  
  
queue<string> hrefUrl;  
hash_set<string> visitedUrl;  
hash_set<string> visitedImg;  
int depth=0;  
int g_ImgCnt=1;  
  
//����URL������������������Դ��  
bool ParseURL( const string & url, string & host, string & resource){  
    const char * pos = strstr( url.c_str(), "http://" );  
    if( pos==NULL ) pos = url.c_str();  
    else pos += strlen("http://");  
    if( strstr( pos, "/")==0 )  
        return false;  
    char pHost[100];  
    char pResource[200];  
    sscanf( pos, "%[^/]%s", pHost, pResource );  
    host = pHost;  
    resource = pResource;  
    return true;  
}  
  
//ʹ��Get���󣬵õ���Ӧ  
bool GetHttpResponse( const string & url, char * &response, int &bytesRead ){  
    string host, resource;  
    if(!ParseURL( url, host, resource )){  
        cout << "Can not parse the url"<<endl;  
        return false;  
    }  
      
    //����socket  
    struct hostent * hp= gethostbyname( host.c_str() );  
    if( hp==NULL ){  
        cout<< "Can not find host address"<<endl;  
        return false;  
    }  
  
    SOCKET sock = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if( sock == -1 || sock == -2 ){  
        cout << "Can not create sock."<<endl;  
        return false;  
    }  
  
    //������������ַ  
    SOCKADDR_IN sa;  
    sa.sin_family = AF_INET;  
    sa.sin_port = htons( 80 );  
    //char addr[5];  
    //memcpy( addr, hp->h_addr, 4 );  
    //sa.sin_addr.s_addr = inet_addr(hp->h_addr);  
    memcpy( &sa.sin_addr, hp->h_addr, 4 );  
  
    //��������  
    if( 0!= connect( sock, (SOCKADDR*)&sa, sizeof(sa) ) ){  
        cout << "Can not connect: "<< url <<endl;  
        closesocket(sock);  
        return false;  
    };  
  
    //׼����������  
    string request = "GET " + resource + " HTTP/1.1\r\nHost:" + host + "\r\nConnection:Close\r\n\r\n";  
  
    //��������  
    if( SOCKET_ERROR ==send( sock, request.c_str(), request.size(), 0 ) ){  
        cout << "send error" <<endl;  
        closesocket( sock );  
        return false;  
    }  
  
    //��������  
    int m_nContentLength = DEFAULT_PAGE_BUF_SIZE;  
    char *pageBuf = (char *)malloc(m_nContentLength);  
    memset(pageBuf, 0, m_nContentLength);  
  
    bytesRead = 0;  
    int ret = 1;  
    cout <<"Read: ";  
    while(ret > 0){  
        ret = recv(sock, pageBuf + bytesRead, m_nContentLength - bytesRead, 0);  
          
        if(ret > 0)  
        {  
            bytesRead += ret;  
        }  
  
        if( m_nContentLength - bytesRead<100){  
            cout << "\nRealloc memorry"<<endl;  
            m_nContentLength *=2;  
            pageBuf = (char*)realloc( pageBuf, m_nContentLength);       //���·����ڴ�  
        }  
        cout << ret <<" ";  
    }  
    cout <<endl;  
  
    pageBuf[bytesRead] = '\0';  
    response = pageBuf;  
    closesocket( sock );  
    return true;  
    //cout<< response <<endl;  
}  
//��ȡ���е�URL�Լ�ͼƬURL  
void HTMLParse ( string & htmlResponse, vector<string> & imgurls, const string & host ){  
    //���������ӣ�����queue��  
    const char *p= htmlResponse.c_str();  
    char *tag="href=\"";  
    const char *pos = strstr( p, tag );  
    ofstream ofile("url.txt", ios::app);  
    while( pos ){  
        pos +=strlen(tag);  
        const char * nextQ = strstr( pos, "\"" );  
        if( nextQ ){  
            char * url = new char[ nextQ-pos+1 ];  
            //char url[100]; //�̶���С�Ļᷢ�������������Σ��  
            sscanf( pos, "%[^\"]", url);  
            string surl = url;  
            if( visitedUrl.find( surl ) == visitedUrl.end() ){  
                visitedUrl.insert( surl );  
                ofile << surl<<endl;  
                hrefUrl.push( surl );  
            }  
            pos = strstr(pos, tag );  
            delete [] url;  
        }  
    }  
    ofile << endl << endl;  
    ofile.close();  
  
    tag ="<img ";  
    const char* att1= "src=\"";  
    const char* att2="lazy-src=\"";  
    const char *pos0 = strstr( p, tag );  
    while( pos0 ){  
        pos0 += strlen( tag );  
        const char* pos2 = strstr( pos0, att2 );  
        if( !pos2 || pos2 > strstr( pos0, ">") )  
            pos = strstr( pos0, att1)+strlen(att1);  
        else  
            pos = pos2 + strlen(att2);  
        const char * nextQ = strstr( pos, "\"");  
        if( nextQ ){  
            char * url = new char[nextQ-pos+1];  
            sscanf( pos, "%[^\"]", url);  
            cout << url<<endl;  
            string imgUrl = url;  
            if( visitedImg.find( imgUrl ) == visitedImg.end() ){  
                visitedImg.insert( imgUrl );  
                imgurls.push_back( imgUrl );  
            }  
            pos0 = strstr(pos0, tag );  
            delete [] url;  
        }  
    }  
    cout << "end of Parse this html"<<endl;  
}  
  
//��URLת��Ϊ�ļ���  
string ToFileName( const string &url ){  
    string fileName;  
    fileName.resize( url.size());  
    int k=0;  
    for( int i=0; i<(int)url.size(); i++){  
        char ch = url[i];  
        if( ch!='\\'&&ch!='/'&&ch!=':'&&ch!='*'&&ch!='?'&&ch!='"'&&ch!='<'&&ch!='>'&&ch!='|')  
            fileName[k++]=ch;  
    }  
    return fileName.substr(0,k) + ".txt";  
}  
  
//����ͼƬ��img�ļ���  
void DownLoadImg( vector<string> & imgurls, const string &url ){  
  
    //���ɱ����url��ͼƬ���ļ���  
    string foldname = ToFileName( url );  
    foldname = "./img/"+foldname;  
    if(!CreateDirectory( foldname.c_str(),NULL ))  
        cout << "Can not create directory:"<< foldname<<endl;  
    char *image;  
    int byteRead;  
    for( int i=0; i<imgurls.size(); i++){  
        //�ж��Ƿ�ΪͼƬ��bmp��jgp��jpeg��gif   
        string str = imgurls[i];  
        int pos = str.find_last_of(".");  
        if( pos == string::npos )  
            continue;  
        else{  
            string ext = str.substr( pos+1, str.size()-pos-1 );  
            if( ext!="bmp"&& ext!="jpg" && ext!="jpeg"&& ext!="gif"&&ext!="png")  
                continue;  
        }  
        //�������е�����  
        if( GetHttpResponse(imgurls[i], image, byteRead)){  
            const char *p=image;  
            const char * pos = strstr(p,"\r\n\r\n")+strlen("\r\n\r\n");  
            int index = imgurls[i].find_last_of("/");  
            if( index!=string::npos ){  
                string imgname = imgurls[i].substr( index , imgurls[i].size() );  
                ofstream ofile( foldname+imgname, ios::binary );  
                if( !ofile.is_open() )  
                    continue;  
                cout <<g_ImgCnt++<< foldname+imgname<<endl;  
                ofile.write( pos, byteRead- (pos-p) );  
                ofile.close();  
            }  
            free(image);  
        }  
    }  
}  
  
  
  
//��ȱ���  
void BFS( const string & url ){  
    char * response;  
    int bytes;  
    if( !GetHttpResponse( url, response, bytes ) ){  
        cout << "The url is wrong! ignore." << endl;  
        return;  
    }  
    string httpResponse=response;  
    free( response );  
    string filename = ToFileName( url );  
    ofstream ofile( "./html/"+filename );  
    if( ofile.is_open() ){  
        ofile << httpResponse << endl;  
        ofile.close();  
    }  
    vector<string> imgurls;  
    HTMLParse( httpResponse,  imgurls, url );  
      
    //����ͼƬ��Դ  
    DownLoadImg( imgurls, url );  
}  
void main()  
{  
    WSADATA wsaData;  
    if( WSAStartup(MAKEWORD(2,2), &wsaData) != 0 ){  
        return;  
    }  
    CreateDirectory( "./img",0);  
    CreateDirectory("./html",0);  
    //string urlStart = "http://hao.360.cn/meinvdaohang.html";  
    string urlStart = "http://hao.360.cn/meinvdaohang.html";  
    BFS( urlStart );  
    visitedUrl.insert( urlStart );  
    while( hrefUrl.size()!=0 ){  
        string url = hrefUrl.front();  
        cout << url << endl;  
        BFS( url );  
        hrefUrl.pop();  
    }  
    WSACleanup();  
    return;  
}  