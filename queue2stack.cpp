/*
    剑指offer 9(2)，两个队列组成一个栈
    巧记：永远有一个栈为空
    add时，往有元素的队列push，皆无则随选
    pop时，从有元素的队列转移元素到全空的队列，直到只剩最后一个，pop它为结果
*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T> class CStack
{
    public:
        void add(const T&);
        T pop();
    private:
        queue<T> queue1;
        queue<T> queue2;
        T pop2(queue<T>&, queue<T>&);
};

template <typename T> void CStack<T>::add(const T& node)
{
    if (queue1.size() > 0) {
        queue1.push(node);
    } else {
        queue2.push(node);
    }
}

template <typename T> T CStack<T>::pop2(queue<T>& q1, queue<T>& q2)
{
    while (q1.size() > 1) {
        T a = q1.front();
        q1.pop();
        q2.push(a);
    }
    T b = q1.front();
    q1.pop();
    return b;
}

template <typename T> T CStack<T>::pop()
{
    if (queue1.size() > 0) {
        return pop2(queue1, queue2);
    }
    if (queue2.size() > 0) {
        return pop2(queue2, queue1);
    }
    throw "stack is empty";
}

int main()
{
    CStack<int> s;
    
    for (int i=0; i<10; i++) s.add(i);
    for (int i=0; i<11; i++)
    {
        try {
            int a = s.pop();
            printf("%d\n", a);
        } catch (const char* e) {
            printf("%s\n", e);
        }
    }
}