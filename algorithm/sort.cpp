#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums{1,2,3,5,2,3,5,3,4};
    sort(nums.begin(), nums.end());
    for_each(nums.begin(), nums.end(), [](int n){cout << n << endl;});
    return 0;
}
