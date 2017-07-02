#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        int start = 0;
        int space = -1;
        cout<<s<<endl;
        for(int i=0; i<n; i++){
            if(s[i] == ' ') {
                if(space == -1 || s[i-1] == ' ') {
                    s.erase(s.begin()+i);
                    i--;
                }
                else {
                    cout<<s<<endl;
                    cout<<start<<' '<<i<<endl;
                    reverse(s.begin()+start, s.begin()+i); 
                    start = i+1;
                }
            }
            else space = 0;
        }
        reverse(s.begin()+start, s.end());
        if(s[s.length()-1] == ' ') s.erase(s.end()-1);
    }
};
int
main ()
{
    string test = "  inmywholword   test";
    Solution *s = new Solution();
    s->reverseWords(test);
    cout<<test;
    cout<<'1'<<endl;
}
