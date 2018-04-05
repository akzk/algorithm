/*
    lintcode 32, 最小子串覆盖
    核心在于一个哈希表map，初始化为：遍历target各字位置+1，其余为0
    counter=target.size()，从j位置开始遍历source各字c，map[c]>0则counter-1，每次遍历最后都要map[c]-1
    counter为0时匹配成功一个子串，记录i、j位置，从i位置开始遍历source各字c，map[c]=0则counter+1，因为匹配上的字符才=0，未匹配的为-1，最后都要+1
*/
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        int to_find[CHAR_MAX];
        memset(to_find, 0, CHAR_MAX*sizeof(int));
        for (auto c: target) to_find[c]++;

        int counter = target.size(), d = INT_MAX, i = 0, j = 0, head = 0;// counter, 未匹配的字符数
        while (j < source.size())
        {
            if (to_find[source[j++]]-- > 0) counter--;
            while (counter == 0) // counter=0时匹配成功
            {
                int tmp = j-i;
                if (d > tmp) {
                    d = tmp;
                    head = i;
                }
                if (to_find[source[i++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : source.substr(head, d);
    }
};