/*
3 Sum

19% Accepted
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Have you met this question in a real interview? Yes
Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)
Note
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.
*/
class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int length = nums.size();
        for (int i = 0; i < length; i++){
          //skip the duplicate in the sorted array
          if (i > 0 && nums[i] == nums[i - 1])
            continue;
          int start = i + 1;
          int end = length - 1;
          while (start < end){
            if (nums[start] + nums[end] == 0 - nums[i]){
              res.push_back({nums[i], nums[start], nums[end]});
              while (start < end && nums[start] == nums[++start]);
            }
            else if (nums[start] + nums[end] > 0 - nums[i]){
              while (start < end && nums[end] == nums[--end]);
            }
            else{
              while (start < end && nums[start] == nums[++start]);
            }
          }
        }
        return res;
    }
};
