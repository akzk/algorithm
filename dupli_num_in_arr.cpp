/*
    数组中的重复数字
    剑指offer 3，在特定条件下，特定数组中，寻找任意一个重复数字
    1）数组长度n，取值范围0~n-1             -> 令i值放在arr[i]的位子上
    2）数组长度n，取值范围1~n-1，不可改变数组 -> 对取值范围进行二分查找
*/

#include <iostream>
using namespace std;

int find_dupli_num_in_arr1(int* arr, int n);
int find_dupli_num_in_arr2(int* arr, int n);
int find_dupli_num_in_arr2_help(int*arr, int n, int start, int end);

// 每次循环中，判断i值是否在arr[i]上，不在的话若arr[arr[i]]==arr[i]，则找到重复数字
int find_dupli_num_in_arr1(int* arr, int n)
{
    // check 1
    if (arr==nullptr || n<0) return -1;
    
    // check 2
    for (int i=0; i<n; i++)
    {
        if (0>arr[i] || arr[i]>n-1) return -1;
    }

    // find dupli
    for (int i=0; i<n; i++)
    {
        if (arr[i] != i)
        {
            if (arr[arr[i]] == arr[i]) return arr[i];

            // swap
            int tmp = arr[arr[i]];
            arr[arr[i]] = arr[i];
            arr[i] = tmp;
            i--;
        }
    }
};

// 取值范围1~n-1，不断进行：取值范围对半分后统计落入前半段的arr元素个数，多于一半则重复数字在前半段，否则后半段
int find_dupli_num_in_arr2(int* arr, int n)
{
    // check 1
    if (arr==nullptr || n<0) return -1;

    // check 2
    for (int i=0; i<n; i++)
    {
        if (arr[i]<1 || arr[i]>n-1) return -1;
    }

    int start = 1, end = n-1;

    // find
    while (start != end)
    {
        int middle = (start+end)>>1;

        int count = 0;
        for (int i=0; i<n; i++)
        {
            if (start<=arr[i]<=middle) count++;
        }

        if (count > middle-start+1) end = middle;
        else start = middle+1;
    }

    return arr[end];
};

int main()
{
    int arr1[10] = {4, 6, 1, 2, 7, 0, 9, 7, 5, 3};
    int arr2[10] = {4, 6, 1, 2, 7, 6, 9, 8, 5, 3};

    cout << find_dupli_num_in_arr1(arr1, 10) << endl;
    cout << find_dupli_num_in_arr2(arr2, 10) << endl;
}
