/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.18%)
 * Likes:    3939
 * Dislikes: 446
 * Total Accepted:    571.7K
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        const int target = 0;
        auto last = nums.end();
        for (auto i = nums.begin(); i < last - 2; ++i)
        {
            auto j = i + 1;
            if (i > nums.begin() && *i == *(i - 1))
                continue;
            auto k = last - 1;
            while(j < k)
            {
                if (*i + *j + *k < target)
                {
                    ++j;
                    while(*j == *(j - 1) && j < k)
                        ++j;
                }
                else if (*i + *j + *k > target)
                {
                    --k;
                    while(*k == *(k + 1) && j < k)
                        --k;
                }
                else
                {
                    result.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k)
                        ++j;
                }
            }
        }
        return result;
    }
};

