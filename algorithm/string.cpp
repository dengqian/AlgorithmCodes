#include <iostream>

using namespace std;
class String
{
private:
    char* data_;
public:
    String(){};
    String(const char* s){
        strcpy(data_ = new char[strlen(s)+1], s);
    }
    String(const String& s){
       strcpy(data_ = new char[strlen(s.data_)+1], s.data_); 
    }
    String& operator=(const String& s){
       delete []data_ ;
       strcpy(data_=new char(strlen(s.data_)+1), s.data_);
       return *this;
    }
    String operator+(const String& s1, const String& s2){
            
    }

};

int main()
{
    return 0;
}
