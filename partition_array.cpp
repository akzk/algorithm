/*
    lintcode 31, 数组划分
    快排
*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        nums.push_back(k);
        int i=0, j=(int)nums.size()-1;
        while (i<j)
        {
            while (nums[i]<k && i<j) i++;
            while (nums[j]>=k && i<j) j--;
            if (i<j) swap(nums[i], nums[j]);
            else break;
        }
        return i;
    }
};