/*
    lintcode 15, 全排列
    http://blog.csdn.net/u013309870/article/details/68941284
*/
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        if (nums.size() == 0) {
            result.push_back(nums);
            return result;
        }
        permuteHelper(nums, result, 0, nums.size()-1);
        return result;
    }

    void permuteHelper(vector<int> &nums, vector<vector<int>> &result, int start, int end)
    {
        if (start <= end) {
            for (int i=start; i<=end; i++) {
                swap(nums[i], nums[start]);
                permuteHelper(nums, result, start+1, end);
                swap(nums[i], nums[start]);
            }
        } else {
            result.push_back(nums);
        }
    }
};

int main()
{
    int d[] = {1};
    vector<int> data(d);
    Solution* a = new Solution();
    a->permute(data);
}
