nclude <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

#define MOD 1000000007
typedef pair<int,int> pii;

int n, t;
vector<int> a, b, c;
int ans = 0;

void solve(int time, int nn, int tt){
    int tn, ta;
    vector<int> cur;
    cur.push_back(a[time]);
    cur.push_back(b[time]);
    cur.push_back(c[time]);
    sort(cur.begin(),cur.end());
    do {
        tn = nn;
        ta = tt;
        if (tn >= cur[0]){
            tn -= cur[0];
            ++ta;
        }
        if (tn >= cur[1]){
            tn -= cur[1];
            ++ta;
        }
        if (tn >= cur[2]){
            tn -= cur[2];
            ++ta;
        }
        if (time == t-1){
            ans = max(ans,ta);
        }
        else {
            solve(time+1,tn,ta);
        }
    } while (next_permutation(cur.begin(),cur.end()));
}

int main() {
    cin >> n >> t;
    a.resize(t);
    b.resize(t);
    c.resize(t);
    for (int i = 0; i < t; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    solve(0,n,0);
    cout << ans << endl;
}