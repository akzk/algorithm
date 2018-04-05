/*
    lintcode 3，计算数字k在0到n中的出现的次数，k可能是0~9的一个值
    从尾到头遍历每个位，总和每一位出现的个数。例：27142，到第三位时，取27、1、142，得27x100+42+1
*/
#include <iostream>
using namespace std;

int digitCounts(int n, int k)
{
    if (k == 0 && n == 0) return 1;

    int res = 0;
    int base = 1;
    int nn = n;

    while (nn>0)
    {
        int a = nn%10;
        nn /= 10;
        res += nn*base;
        if (a == k) {
            res += n%base + 1;
        } else if (a > k) {
            res += base;
        }
        base *= 10;
    }

    if (k == 0) res -= base/10;

    return res;
}

int main()
{
    cout << digitCounts(111, 1) << endl;
}