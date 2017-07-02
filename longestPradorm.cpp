#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cmath>
#define ll unsigned long long
#define INF (~(1<<31))
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1) return s;
        //int left = 0, right = 0;
        string ans = ""+s[0];
        for(int i=0; i<s.length()-1; i++){
            string a = palindrome(s, i, i);
            if(a.length()>ans.length()) ans = a;
            string b = palindrome(s, i, i+1);
            if(b.length() > ans.length()) ans = b;
        }
        return ans;
    }
    string palindrome(string s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left-- ;
            right++;
        }
        //cout<<left<<right<<endl;
        //return s.substr(left+1, right-1-left);
        return "";
    }
};

int main(){
    Solution* s = new Solution();
    string ss = "a";
    cout<<s->longestPalindrome(ss);
    return 0;
}















