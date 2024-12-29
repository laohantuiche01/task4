#include "stack.h"
#include <bits/stdc++.h>

void Stack_Copy::expendMemory()//数组的扩容
{
    MemoryNum++;//计数，开了多少内存（内存不够每次多开100位）
    int *tempContainer = new int[MemorySpace * MemorySpace];//新开辟内存
    for (int i = 1; i < MemorySpace * MemoryNum; i++) //对原数组进行拷贝
    {
        tempContainer[i] = stackContainer[i];
    }
    delete[] stackContainer;//删除原来的指针所指内容
    stackContainer = tempContainer; //将新的内存赋值给指针
}

void Stack_Copy::init()//创建，初始化
{
    memset(stackContainer, 0, 100 * sizeof(int));//将容器初始化（后改成内存开辟与扩容）
}

int Stack_Copy::top() //
{
    if (topNum == 0)//处理栈为空的情况
    {
        std::cout << "the stack is empty!!!\n";
        return -1;
    }
    return stackContainer[topNum];//返回数组值
}

void Stack_Copy::clear() //清除并且初始化
{
    topNum = 0;
    MemoryNum = 1;//将次数重置为0
    delete[] stackContainer;
    memset(stackContainer, 0, 100 * sizeof(int));//将容器初始化（后改成内存开辟与扩容）
}

void Stack_Copy::push(int n) //栈中加入元素
{
    if (topNum == MemoryNum * MemorySpace - 1)//数组空间已经满了
    {
        expendMemory();//扩容
    }
    topNum++;
    stackContainer[topNum] = n;
}

void Stack_Copy::pop()  //弹出元素
{
    if (topNum == 0) //处理元素为空
    {
        std::cout << "the stack is empty!!!\n";
        return;
    }
    stackContainer[topNum] = 0;
    topNum--;
    std::cout << "the member has been deleted successfully !!!\n";
}

int Stack_Copy::size() //数组中元素个数
{
    return topNum;
}


