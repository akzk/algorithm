/*
    lintcode 13，字符串匹配
    创建坏字符表，长256，所有值初始化为len_target+1，target中含有的字符则为len_target-i
    i代表target头部在source的位置，开始用strncmp匹配，失配则i+=bads[text[i+len_target]]
*/
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        // write your code here

        if (source == NULL || target == NULL) return -1;

        int len_source = strlen(source);
        int len_target = strlen(target);
        char bads[256];

        if (len_source < len_target) return -1;

        for (int i=0; i<256; i++) bads[i] = len_target+1;
        for (int i=0; i<len_target; i++) bads[target[i]] = len_target-i;

        int i = 0;
        while (i <= len_source-len_target)
        {
            if (strncmp(source+i, target, len_target) == 0) return i;
            else i += bads[source[i+len_target]];
        }

        return -1;
    }
};

int main()
{
    Solution* a = new Solution();
    cout << a->strStr("abcdabcdefg", "bcd") << endl;
}