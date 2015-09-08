/*
Medium 2 Sum

27% Accepted
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

Have you met this question in a real interview? Yes
Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]

Note
You may assume that each input would have exactly one solution

Challenge
Either of the following solutions are acceptable:

O(n) Space, O(nlogn) Time
O(n) Space, O(n) Time
*/
class Solution1 {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
      //use hash table to find the xj = target - xi
      //if not, put xi into hashtable
      //O(n) Space, O(n) Time
        int length = nums.size();
        unordered_map<int, int> hash(length);
        for (int i = 0; i < length; i++){
          if (hash.find(target - nums[i]) != hash.end()){
            return {hash[target - nums[i]], i + 1};
          }
          else
            hash[nums[i]] = i + 1;
        }
        return {};
    }
};
class Solution2 {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
      //O(n) Space, O(nlogn) Time
      if (nums.empty())
        return res;
      int length = nums.size();
      unordered_map<int, int> copy;
      for (int i = 0; i < length; i++)
        copy[nums[i]] = i + 1;
        //use hashtable to reserve the index of the original array

        //after sorted, use two pointers to find the two numbers has the target sum
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        while (start < end){
          if (nums[start] + nums[end] > target)
            end--;
          else if (nums[start] + nums[end] < target)
            start++;
          else{
            if (copy[nums[start]] < copy[nums[end]])
              return {copy[nums[start]], copy[nums[end]]};
            else
              return {copy[nums[end]], copy[nums[start]]};
          }
        }
        return {};
    }
};
