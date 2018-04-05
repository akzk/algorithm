/*
    lintcode 4，丑数
    所有丑数都是通过乘2、3或5得来的，跟踪三个指针，分别记录上一个最后乘2、3或5的数字的索引值
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ugly_number(int n)
{
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    int* data = new int[n];
    data[0] = 1;

    for (int i=1; i<n; i++)
    {
        int res2 = data[i2]*2;
        int res3 = data[i3]*3;
        int res5 = data[i5]*5;

        data[i] = min(res2, min(res3, res5));
        if (data[i] == res2) i2++;
        if (data[i] == res3) i3++; // 不能用else if，碰到2、3、5相乘的数时会发生重复
        if (data[i] == res5) i5++;
    }

    return data[n-1];
}

int main()
{
    cout << ugly_number(9) << endl;
}