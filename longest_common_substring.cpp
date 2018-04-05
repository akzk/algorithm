/*
    lintcode 79, 最长公共子串
    动态规划，建立dp[sizeA+1]。从头到尾遍历b串每个字，每次遍历中再从尾到头遍历a串每个字，
    若当前a字与b字相等，则dp[i+1]=dp[i]+1，否则dp[i+1]=0，最后取max(dp[i+1],maxlen)为maxlen
*/
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int sza = A.size();
        int szb = B.size();
        int dp[sza+1];
        memset(dp, 0, (sza+1)*sizeof(int));
        int maxlen = 0;

        for (int j=0; j<szb; j++)
        {
            for (int i=sza-1; i>=0; i--)
            {
                if (A[i] == B[j]) dp[i+1] = dp[i]+1;
                else dp[i+1] = 0;
                maxlen = max(dp[i+1], maxlen);
            }
        }

        return maxlen;
    }
};