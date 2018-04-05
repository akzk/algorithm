/*
    lintcode 14, 二分查找
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        int result = binarySearchHelper(nums, target, 0, nums.size()-1);
        if (result > -1) {
            while (result >= 0 && nums[result] == target) result--;
            result += 1;
        }
        return result;
    }

    int binarySearchHelper(vector<int> &nums, int target, int i, int j)
    {
        if (j-i<=3) {
            for (;i<j; i++) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        int middle = (i+j)/2;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] < target) {
            return binarySearchHelper(nums, target, middle+1, j);
        } else {
            return binarySearchHelper(nums, target, i, middle);
        }
    }
};

int main()
{
    int d[] = {4,5,9,9,12,13,14,15,15,18};
    vector<int> data(d,d+10);
    Solution* a = new Solution();
    cout << a->binarySearch(data, 10) << endl;
}