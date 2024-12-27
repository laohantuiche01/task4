#ifndef TASK4_LIST_H
#define TASK4_LIST_H

#include <bits/stdc++.h>

class List_Copy {
private:
    struct Node_//创建节点
    {
        int data;//储存数据
        Node_ *prev;//前一个元素指针
        Node_ *next;//后一个元素指针

        Node_(int insertNum) : data(insertNum), prev(nullptr), next(nullptr) {}//指针初始化/创建
    };
    Node_ *head;//头指针
    Node_ *tail;//尾指针

public:
    List_Copy() : head(nullptr), tail(nullptr) {}

    ~List_Copy() //析构函数
    {
        Node_ *tempNode = head;//从头结点循环删除
        while (tempNode) //直到删的只剩空姐点
        {
            Node_ *temp = tempNode;//将临时节点储存到临时变量
            tempNode = tempNode->next;//节点往后推
            delete temp;//删掉内容
        }
    }

    void insert(int insertNum);//加入内容


    void printList();// 打印链表


    void remove(int deleteNum);// 删除指定元素

    void clear();//清除链表
    void init(int inputNum);//创建链表

};





#endif //TASK4_LIST_H
