
#include "list.h"
#include <bits/stdc++.h>

void List_Copy::insert(int insertNum)
{
    Node_ *newNode = new Node_(insertNum);//新开辟内存
    if (!head) //头节点为空，将头节点复制到这个新的节点上
    {
        head = newNode;
        tail = newNode;
    } else //有头节点了，把新的节点跟头节点连上
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void List_Copy::printList() // 打印链表
{
    Node_ *tempNode = head;//创建头节点
    while (tempNode) //循环输出，直到尾指针
    {
        std::cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;//最后输出换行
}


void List_Copy::remove(int deleteNum) // 删除指定元素
{
    Node_ *tempNode = head;//先赋值头节点
    while (tempNode)//没到尾节点
    {
        if (tempNode->data == deleteNum) //判断是不是要删除的书
        {
            if (tempNode == head) //如果要删的是头节点
            {
                head = tempNode->next;//头节点换到下一个元素
                if (head)//但是只有头节点一个元素了o.O
                {
                    head->prev = nullptr;
                }
            } else if (tempNode == tail) //删的是尾节点
            {
                tail = tempNode->prev;//尾节点换到前一个元素
                if (tail) //但是只有尾节点一个元素了O.o
                {
                    tail->next = nullptr;
                }
            } else//没删到头节点或者尾节点
            {
                tempNode->prev->next = tempNode->next;
                tempNode->next->prev = tempNode->prev;
            }
            delete tempNode;//删掉元素
            return;
        }
        tempNode = tempNode->next;
    }
    std::cout<<"We cannot find the number !!!\n";
    return;
}

void List_Copy::init(int inputNum)
{
    insert(inputNum);
}

void List_Copy::clear()
{
    Node_ *tempNode = head;//创建头节点
    while (tempNode) //循环输出，直到尾指针
    {
        Node_* tempDelete=tempNode;
        tempNode = tempNode->next;
        remove(tempDelete->data);

    }
    head= nullptr;
    tail= nullptr;
}


