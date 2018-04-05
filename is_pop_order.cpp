/*
    剑指offer, 栈的压入弹出序列
    未测试!!!lintcode、leetcode均未发现
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isPopOrder(vector<int> vpush, vector<int> vpop) {
        stack<int> a;
        int k = 0;
        for (int i=0; i<vpop.size(); i++)
        {
            while ((a.empty() || a.top()!=vpop[i]) && k<vpush.size()) a.push(vpush[k++]);
            if (a.top()==vpop[i]) a.pop();
            else return false;
        }
        return true;
    }
};
