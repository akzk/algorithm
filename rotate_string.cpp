/*
    lintcode 8, 旋转字符串
    新建string，分两端push_back即可
*/
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */

    void rotateString(string &str, int offset) {
        // write your code here
        if (offset == 0 || str.size() == 0) return;
        int size = str.size();
        offset %= size;
        string s;
        for (int i=size-offset; i<size; i++) {
            s.push_back(str[i]);
        }
        for (int i=0; i<size-offset; i++) {
            s.push_back(str[i]);
        }
        for (int i=0; i<size; i++) {
            str[i] = s[i];
        }
    }
};

int main()
{
    string s = "timelimiterror";

    Solution* a = new Solution();
    a->rotateString(s, 1000000000);

    cout << s << endl;
}