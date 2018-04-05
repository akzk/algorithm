/*
    lintcode 29, 交叉字符串
    动态规划，但比较难想到关系
    http://blog.csdn.net/smallfish_love/article/details/52277838
*/
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        // write your code here
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if (size1+size2!=size3) return false;
        bool dp[size1+1][size2+1];
        dp[0][0] = true;

        for (int i=0; i<size1; i++) dp[i+1][0] = (s1[i] == s3[i]) && dp[i][0];
        for (int i=0; i<size2; i++) dp[0][i+1] = (s2[i] == s3[i]) && dp[0][i];
        
        for (int i=1; i<=size1; i++)
            for (int j=1; j<=size2; j++)
                dp[i][j] = (s3[i+j-1] == s1[i-1] && dp[i-1][j]) || (s3[i+j-1] == s2[j-1] && dp[i][j-1]);
        return dp[size1][size2];
    }
};