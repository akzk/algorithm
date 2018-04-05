/*
    lintcode 20, 骰子求和
    动态规划, f(n,sum)=f(n-1,sum-1)+f(n-1,sum-2)+...+f(n-1,sum-6)
    部分不解
*/
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<pair<int, double>> result;
        vector<vector<long>> dp;

        vector<long> tmp;
        dp.push_back(tmp);
        for (int i=1; i<=6; i++) tmp.push_back(1);
        dp.push_back(tmp);

        for (int i=2; i<=n; i++)
        {
            vector<long> a;
            for (int j=i; j<=6*i; j++)
            {
                long value = 0;
                for (int k=i; k<6+i; k++) // 此处不解
                    if (j>=k && j-k<dp[i-1].size()) value += dp[i-1][j-k];
                a.push_back(value);
            }
            dp.push_back(a);
        }

        double all = pow(6, n);
        vector<long> last = dp[dp.size()-1];
        for (int i=0; i<last.size(); i++)
        {
            result.push_back(make_pair(i+n, last[i]/all));
        }

        return result;
    }
};

int main()
{
    Solution* a = new Solution();
    a->dicesSum(10);
}
