/*
    lintcode 17, 子集
    利用二进制。包括空集的子集有2^n个，一一对应二进制中1、0排列
    http://houjixin.blog.163.com/blog/static/3562841020099310654175/
*/
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        int n = nums.size();
        for (int i=0; i<(1<<n); i++)
        {
            vector<int> a;
            for (int j=0; j<n; j++)
            {
                if ((i>>j)&1) a.push_back(nums[j]);
            }
            result.push_back(a);
        }
        return result;
    }
};
