/*
Kth Largest Element

19% Accepted
Find K-th largest element in an array.

Have you met this question in a real interview? Yes
Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Note
You can swap elements in the array

Challenge
O(n) time, O(1) extra memory.
*/
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
      if (nums.empty() || k > nums.size())
        return -1;
      return getKth(nums, k, 0, nums.size() - 1);
    }

    int getKth(vector<int> nums, int k, int start, int end){
      int left = start + 1;
      int right = end;
      while (left <= right){
        while (left <= right && nums[left] >= nums[start])
          left++;
        while (left <= right && nums[right] <= nums[start])
          right--;
        if (left < right)
          swap(nums[left], nums[right]);
      }
      swap(nums[start], nums[right]);

      if (k == right + 1)
        return A[right];
      else if (k < right + 1)
        return getKth(nums, k, start, right - 1);
      else
        return getKth(nums, k, right + 1, end);
    }
};
class Solution1 {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
      if (nums.empty() || k > nums.size())
        return -1;
      vector<int> minheap(k);
      for (int i = 0; i < k; i++)
        minheap[i] = nums[i];

      buildMinHeap(minheap, k);

      for (int i = k; i < nums.size(); i++){
        if (nums[i] > minheap[0]){
          minheap[0] = nums[k];
          minHeapify(minheap, k, 0);
        }
      }
      return minheap[0];
    }
    void buildMinHeap(vector<int> &A, int N){
      for (int i = N / 2; i >= 0; i--){
        minHeapify(A, N, i);
      }
    }
    void minHeapify(vector<int> &A, int N, int i){
      int l = 2 * i;
      int r = 2 * i + 1;
      int smallest = i;
      if (l < N && A[l] < A[smallest])
        smallest = l;
      if (r < N && A[r] < A[smallest])
        smallest = r;

      if (smallest != i){
        swap(A[i], A[smallest]);
        minHeapify(A, N, smallest);
      }
    }
  };
