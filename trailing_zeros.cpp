/*
    lintcode 2，统计n阶乘尾部的零的个数
    http://blog.csdn.net/hugo2052/article/details/78575984
*/
#include <iostream>
using namespace std;

long long trailingZeros(long long n)
{
    long long res = 0;
    while (n >= 5)
    {
        long long tmp = n/5;
        res += tmp;
        n = tmp;
    }
    return res;
}

int main()
{
    cout << trailingZeros(25) << endl;
}