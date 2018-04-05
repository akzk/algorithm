/*
    lintcode 154, 剑指ofer 19, 正则表达式匹配
    支持'.'与'*'
*/
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        // write your code here
        return isMatchHelper(s, p, 0, 0, s.size(), p.size());
    }
    
    bool isMatchHelper(string &s, string &p, int i, int j, int szs, int szp)
    {
        if (i==szs) return j==szp;

        if (j==szp-1 || p[j+1]!='*') {
            if (s[i]==p[j] || p[j]=='.') return isMatchHelper(s, p, i+1, j+1, szs, szp);
            else return false;
        } else {
            while (i < szs && (s[i]==p[j] || p[j]=='.')) {
                if (isMatchHelper(s, p, i, j+2, szs, szp)) return true; // 往后匹配，若true则此处匹配零个字符
                i++;
            }
            return isMatchHelper(s, p, i, j+2, szs, szp);
        }
    }
};