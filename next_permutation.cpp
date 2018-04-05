/*
    lintcode 52, 下一个排列
    http://www.cnblogs.com/houkai/p/3675270.html
    全排列顺序的下一个
    1.
*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        // 1. 从右往左寻找第一个不在递增序列中的数字a
        int i = nums.size()-2;
        while (i>=0 && nums[i]>=nums[i+1]) i--;
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }

        // 2. 从右往左寻找第一个大于a的数字b
        int j = nums.size()-1;
        while (nums[j]<=nums[i]) j--;
        swap(nums[i], nums[j]);

        // 3. 原a位置+1到末尾的序列逆序
        reverse(nums.begin()+i+1, nums.end());
        return nums;
    }
};