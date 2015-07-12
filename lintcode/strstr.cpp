/*
strStr

19% Accepted
strstr (a.k.a find sub string), is a useful function in string operation. Your task is to implement this function.

For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Have you met this question in a real interview? Yes
Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
*/
#include <string>
/**
 * Returns a index to the first occurrence of target in source,
 * or -1  if target is not part of source.
 * @param source string to be scanned.
 * @param target string containing the sequence of characters to match.
 */
int strStr(const char *source, const char *target) {
  if (NULL == source || NULL == target)
return -1;
int sourceLength = strlen(source);
int targetLength = strlen(target);
if (targetLength > sourceLength)
return -1;

if (0 == sourceLength && 0 == targetLength)
return 0;
int i, j;
for (i = 0; i < sourceLength; i++){
for (j = 0; j < targetLength;){
  if (source[i] != target[j])
      break;
  i++;
  j++;
}
if (j == targetLength)
return i - j;
}
return -1;
}
