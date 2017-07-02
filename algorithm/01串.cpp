#include<iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        char ch[101];
        while(cin>>ch)
        {
                string str;
                str=ch;
                set<string> st;
                vector<string> vec;
                for(string::size_type i=0;i<str.size();i++)
                        for(string::size_type j=i;j<str.size();j++)
                        {
                        		string tempstr = str.substr(i,j-i+1);  
                                vec.insert(vec.end(),tempstr);
                                if(st.find(str.substr(i,j-i+1))==st.end()){
                                        st.insert(tempstr);
                                       // cout<<tempstr;
								} 
                               
                        }
                for(set<string>::iterator k=st.begin();k!=st.end();k++)
                        if(count(vec.begin(),vec.end(),*k)>=2){
                                cout<<*k<<' '<<count(vec.begin(),vec.end(),*k)<<endl;
                               // printf("%s %d\n",(*k).c_str(),count(vec.begin(),vec.end(),*k));
                        }
        }
        return 0;
}
