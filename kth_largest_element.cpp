/*
    lintcode 5，数组中第k大的值
    快排
*/
#include <iostream>
#include <vector>
using namespace std;

int quicksort(int n, vector<int> &nums, int begin, int end)
{
    int i = begin;
    int j = end-1;

    while (i <= j)
    {
        if (nums[i] <= nums[end]) {
            swap(nums[i], nums[j--]);
        } else {
            i++;
        }
    }
    swap(nums[i], nums[end]);

    int a = i-begin;
    if (a >= n) {
        return quicksort(n, nums, begin, i-1);
    } else if (a == n-1) {
        return nums[i];
    } else {
        return quicksort(n, nums, i, end);
    }
}

int kthLargestElement(int n, vector<int> &nums)
{
    return quicksort(n, nums, 0, nums.size()-1);
}

int main()
{
    int a[] = {9, 3, 2, 4, 8};
    vector<int> data(a, a+5);
    cout << kthLargestElement(3, data) << endl;
}