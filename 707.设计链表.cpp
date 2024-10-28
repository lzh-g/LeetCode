/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <iostream>

using namespace std;
// @lc code=start
class MyLinkedList
{
public:
    MyLinkedList()
    {
        this->next = NULL;
    }

    int get(int index)
    {
        int count = -1;
        MyLinkedList *cur = this;
        while (cur->next != NULL)
        {
            cur = cur->next;
            count++;
            if (count == index)
            {
                return cur->val;
            }
        }

        return -1;
    }

    void addAtHead(int val)
    {
        MyLinkedList *newHead;
        newHead->val = val;
        newHead->next = this->next;
        this->next = newHead;
    }

    void addAtTail(int val)
    {
        MyLinkedList *cur = this;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        MyLinkedList *newTail;
        newTail->val = val;
        newTail->next = NULL;
        cur->next = newTail;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
        {
            return;
        }

        MyLinkedList *newIndex;
        newIndex->val = val;

        int count = 0;
        MyLinkedList *cur = this->next;
        MyLinkedList *pre_cur = this;

        while (cur->next != NULL)
        {
            if (count == index)
            {
                pre_cur->next = newIndex;
                newIndex->next = cur;
                return;
            }
            pre_cur = cur;
            cur = cur->next;
            count++;
        }

        if (count == index)
        {
            addAtTail(val);
            return;
        }

        return;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0)
        {
            return;
        }

        int count = 0;
        MyLinkedList *cur = this->next;
        MyLinkedList *pre_cur = this;

        while (cur->next != NULL)
        {
            if (count == index)
            {
                pre_cur->next = cur->next;
                delete cur;
                return;
            }
            pre_cur = cur;
            cur = cur->next;
            count++;
        }

        if (count == index)
        {
            pre_cur->next = NULL;
            delete cur;
            return;
        }

        return;
    }

private:
    int val;
    MyLinkedList *next;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
