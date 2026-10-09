// Leetcode problem No. 46
#include <iostream>
#include <vector>
using namespace std;

void getAllPermutations(vector<int> &nums, vector<vector<int>> &ans, int idx, int n)
{
    if (idx == n)
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < n; i++)
    {

        swap(nums[idx], nums[i]);

        getAllPermutations(nums, ans, idx + 1, n);

        swap(nums[idx], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int n = nums.size();

    getAllPermutations(nums, ans, 0, n);

    //we can print ans here using a loop or return in Leetcode

    return 0;
}