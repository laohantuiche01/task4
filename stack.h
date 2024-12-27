
#ifndef TASK4_STACK_H
#define TASK4_STACK_H

#include <bits/stdc++.h>

class Stack_Copy {
public:


    void init();//创建，初始化


    int top();

    void clear();

    void push(int n);

    void pop();

    int size();

private:
    int topNum = 0;
    int MemoryNum = 1;
    int MemorySpace = 100;
    int *stackContainer = new int[100];//创建容器
    void expendMemory();//数组的扩容
};


#endif //TASK4_STACK_H
