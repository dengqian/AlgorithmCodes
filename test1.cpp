#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

bool isnumber(char x) {
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

int priority(char x) {
    if (x == '+' || x == '-')
        return 0;
    else if (x == '*' || x == '/')
        return 1;
    else if (x == '(' || x == ')')
        return -1;
    else return -2;
}

int calculate(string s) {
    stack<int> number;
    stack<char> operate;
    char top;
    int a, b;
    for (unsigned int i = 0; i < s.size(); ++i) {
        if (isnumber(s[i])) {
            int Temp = 0;
            string temp;

            temp += s[i];
            while (isnumber(s[++i]))
                temp += s[i];
            for (unsigned int j = 0; j < temp.size(); ++j) {
                Temp = Temp * 10 + temp[j] - 48;
            }
            number.push(Temp);
            temp.clear();
        }
        if (!isnumber(s[i])) {
            if (operate.empty()) {
                operate.push(s[i]);
            }
            else {
                top = operate.top();

                if (priority(s[i])>priority(top) || s[i] == '(') {
                    operate.push(s[i]);
                }
                else {
                    while (priority(s[i]) <= priority(top)) {
                        if (top == '#'&&s[i] == '#') {
                            int answer;

                            operate.pop();
                            answer = number.top();
                            cout << answer << endl;
                            number.pop();
                            return 0;
                        }
                        else if (top == '('&&s[i] == ')') {
                            ++i;
                        }
                        else {
                            a = number.top();
                            number.pop();
                            b = number.top();
                            number.pop();
                        }
                        if (top == '+') {
                            b += a;
                            number.push(b);
                        }
                        else if (top == '-') {
                            b -= a;
                            number.push(b);
                        }
                        else if (top == '*') {
                            b *= a;
                            number.push(b);
                        }
                        else if (top == '/') {
                            b /= a;
                            number.push(b);
                        }
                        operate.pop();
                        top = operate.top();
                    }
                    operate.push(s[i]);
                }
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        s = "#" + s + "#";
        calculate(s);
    }
    return 0;
}