#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
 bool comp(Interval i1, Interval i2){
     if (i1.start < i2.start) return true;
     else if (i1.start == i2.start) return i1.end < i2.end;
     else return false;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), comp);
        cout<<intervals[0].start<<' '<<intervals[1].start<<endl;
        return ans;
    }
};
int main(){
	int n;
	cin>>n;
	vector<Interval> intervals;
	while(n--){
		int i, j;
		cin>>i>>j;
		Interval in(i, j);
		intervals.push_back(in);
	}
	Solution* s=new Solution();
	s->merge(intervals);
}