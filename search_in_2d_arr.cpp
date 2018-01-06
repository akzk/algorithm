/*
    二维数组中的查找
    剑指offer 4，所给二维数组的每一行从左到右递增，每一列从上到下递增，判断里面是否含有给出的整数
    匹配右上角，给出数等于该数则返回1，大于则排除该行，小于则排除该列，继续匹配新的右上角
*/

#include <iostream>
using namespace std;

void showArr(int* arr, int row, int col);
int find(int* arr, int row, int col, int target);

void showArr(int* arr, int row, int col)
{
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            cout << arr[i*col+j] << (j<col-1 ? " ":"\n");
}

int find(int* arr, int row, int col, int target)
{
    int i = 0, j = col-1;

    while (i<row && j>=0)
    {
        int tmp = arr[i*col+j];

        if (tmp == target)
            return 1;
        else if (tmp > target)
            j--;
        else
            i++;
    }
    return 0;
}

int main()
{
    int arr[4][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    showArr((int*)arr, 4, 4);
    cout << 10 << " " << (find((int*)arr, 4, 4, 10) ? "found" : "notFound") << endl;
    cout << 17 << " "  << (find((int*)arr, 4, 4, 17) ? "found" : "notFound") << endl;
}
