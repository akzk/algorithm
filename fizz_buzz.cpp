/*
    lintcode 9, fizzBuzz
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        // write your code here
        vector<string> res(n);
        for (int i=1; i<=n; i++)
        {
            string s = "";
            if (i%3 == 0) s = "fizz";
            if (s.size() > 0) s += " ";
            if (i%5 == 0) s+= "buzz";
            if (s.size() == 0) s = to_string(i);
            res[i-1] = s;
            cout << s << endl;
        }
        return res;
    }
};

int main()
{
    Solution* a = new Solution();
    a->fizzBuzz(15);
}