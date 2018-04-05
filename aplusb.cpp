/*
    lintcode 1，使用位运算进行a+b
    a^b和(a&b)<<1，两个操作得无进位相加结果与进位，两者再进行位操作相加，知道进位为零
*/

#include <iostream>
using namespace std;

int aplusb(int a, int b)
{
    int add, carry;
    do {
        add = a ^ b;
        carry = (a & b) << 1;
        a = add;
        b = carry;
    } while (carry != 0);
    return add;
}

int main()
{
    int a = 1;
    int b = 3;
    cout << a << "+" << b << "=" << aplusb(a, b) << endl;
}