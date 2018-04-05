/*
    lintcode 40, 两栈实现一堆
*/

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        if (s2.empty()) transfer();
        int result = s2.top();
        s2.pop();
        return result;
    }

    void transfer() {
        while (!s1.empty())
        {
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if (s2.empty()) transfer();
        return s2.top();
    }
};
