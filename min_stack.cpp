/*
    lintcode 12, 带最小值操作的栈
*/
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> numstack;
    stack<int> minstack;
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        numstack.push(number);
        if (minstack.size() == 0) {
            minstack.push(number);
        } else {
            if (minstack.top() > number) {
                minstack.push(number);
            } else {
                minstack.push(minstack.top());
            }
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        minstack.pop();
        int val = numstack.top();
        numstack.pop();
        return val;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return minstack.top();
    }
};