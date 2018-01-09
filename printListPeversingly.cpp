/*
    剑指offer 6，从尾到头打印链表
    1. 递归实现
    2. 栈实现
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int num;
    ListNode* next;
};

void printListPerversingly1(ListNode* node)
{
    if (node != NULL) {
        printListPerversingly1(node->next);
        printf("%d ", node->num);
    }
}

void printListPerversingly2(ListNode* head)
{
    std::stack<ListNode*> list;

    ListNode* node = head;
    while (node != nullptr)
    {
        list.push(node);
        node = node->next;
    }

    while (!list.empty())
    {
        node = list.top();
        printf("%d ", node->num);
        list.pop();
    }
}

void show(ListNode* node)
{
    while (node != NULL)
    {
        printf("%d ", node->num);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->num = 0;
    head->next = NULL;

    ListNode* cur = head;
    ListNode* tmp = NULL;

    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i=0; i<10; i++)
    {
        tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->num = nums[i];
        tmp->next = NULL;

        cur->next = tmp;
        cur = tmp;
    }

    show(head);
    printListPerversingly1(head);
    printListPerversingly2(head);
}