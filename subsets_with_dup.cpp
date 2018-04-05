/*
    lintcode 18, 带重复元素的子集
    比lintcode 17二进制解法多加一个重复判断
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        int n = nums.size();
        for (int i=0; i<(1<<n); i++)
        {
            vector<int> a;
            for (int j=0; j<n; j++)
            {
                if ((i>>j)&1) a.push_back(nums[j]);
            }
            sort(a.begin(), a.end());
            if (!hasSame(result, a)) result.push_back(a);
        }
        return result;
    }

    bool hasSame(vector<vector<int> > &a, vector<int> &b)
    {
        for (int i=0; i<a.size(); i++)
        {
            if (a[i] == b) return true;
        }
        return false;
    }
};

int main()
{
    vector<int> data = {4,4,4,1,4};
    Solution* a = new Solution();
    vector<vector<int>> result = a->subsetsWithDup(data);
    for (int i=0; i<result.size(); i++)
    {
        cout << "[";
        for (int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j];
            if (j<result[i].size()) cout << ",";
        }
        cout << "]";
    }
    cout << endl << result.size() << endl;
}