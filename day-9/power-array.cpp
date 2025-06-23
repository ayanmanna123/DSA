#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
         return;
    }
    solve(nums, output, ans, index + 1);
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, ans, index + 1);
}
bool compare(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5 ,6  };
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, ans, index);
   sort(ans.begin(), ans.end());
    sort(ans.begin(), ans.end(), compare);  
   int count=0;
    for (auto &subset : ans) {
        for (int x : subset)
            cout << x << " ";
        cout << endl;
        count++;
    }
    cout<< count-1<< endl;
}