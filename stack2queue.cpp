/*
    剑指offer 9(1)，两个栈实现一个队列
    add时，一号栈负责被push
    pop时，如果二号栈为空，一号栈元素转移到二号栈，然后再pop二号栈；不为空则直接pop二号栈
*/
#include <iostream>
#include <stack>
using namespace std;

template <typename T> class CQueue
{
    public:
        void append(const T&);
        T pop();
    private:
        stack<T> stack1;
        stack<T> stack2;
};

template <typename T> void CQueue<T>::append(const T& node)
{
    stack1.push(node);
}

template <typename T> T CQueue<T>::pop()
{
    if (stack2.size() == 0) {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0) throw "queue is empty";

    T head = stack2.top();
    stack2.pop();

    return head;
}

int main() {
    
    CQueue<int> q;
    
    for (int i=0; i<10; i++) q.append(i);
    for (int i=0; i<11; i++)
    {
        try {
            int a = q.pop();
            printf("%d\n", a);
        } catch (const char* e) {
            printf("%s\n", e);
        }
    }
}
