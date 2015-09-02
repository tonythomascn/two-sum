/*
Trailing Zeros

29% Accepted
Write an algorithm which computes the number of trailing zeros in n factorial.

Have you met this question in a real interview? Yes
Example
11! = 39916800, so the out should be 2

Challenge
O(log N) time

*/
class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long count = 0;
        //Zero comes from 5 * 2. And 2 is apperantly more than 5, because 4, 6, 8 all includes 2.
        //So how many 5 means how many 0 will trailing at the end.
        for (long long i = 5; n / i >= 1; i *= 5)
          count += n / i;
        return count;
    }
};
