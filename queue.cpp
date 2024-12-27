#include <iostream>
#include <bits/stdc++.h>
#include "queue.h"

void Queue_Copy::ExpendMemory() //阔内存
{
    MemoryNum++;//也是一次阔100
    int *tempContainer = new int[MemorySpace * MemoryNum];
    for (int i = 0; i < MemorySpace * (MemoryNum - 1); i++) //拷贝
    {
        tempContainer[i] = queueContainer[i];
    }
    delete[] queueContainer;//删除原数值
    queueContainer = tempContainer;//重新赋值
}

void Queue_Copy::init() //新开辟内存
{
    memset(queueContainer, 0, MemorySpace * sizeof(int));
}

int Queue_Copy::front() //显示堆顶的那个元素
{
    if (frontNum == 0) //处理为空的情况
    {
        std::cout << "the queue is empty!!!\n";
        return -1;
    }
    return queueContainer[1];
}

void Queue_Copy::push(int pushNum) //入堆
{
    if (frontNum == MemoryNum * MemorySpace - 1) //处理数组内存不够的情况
    {
        ExpendMemory();
    }
    int i = frontNum + 1;
    while (i > 1 && pushNum > queueContainer[i / 2]) //找到堆中插入元素应该在的位置（最大堆） (i<1限制插入为根节点的情况   后面的为父节点大于子节点)
    {
        queueContainer[i] = queueContainer[i / 2];//直接将父节点移到子节点，找到i的值插入到相应位置
        i /= 2;
    }
    queueContainer[i] = pushNum;
    frontNum++;//元素个数+1
}

void Queue_Copy::clear() //清除
{
    frontNum = 0;
    MemoryNum = 1;
    delete[] queueContainer;//删除原有数据
    queueContainer = new int[MemorySpace];//指针重新赋值
    memset(queueContainer, 0, MemorySpace * sizeof(int));
}

void Queue_Copy::pop() //堆顶元素删除/弹出
{
    if (frontNum == 0) //处理可能为空的情况
    {
        std::cout << "the queue is empty!!!\n";
        return;
    }
    int max = queueContainer[1];//第一个最大（由于如果开始标号为一，之后父节点乘二就是左子节点）
    int lastElement = queueContainer[frontNum];//最后一个元素
    frontNum--;
    int i = 1;
    int childNum;//左子数
    while (2 * i <= frontNum) {
        childNum = 2 * i;
        if (childNum + 1 <= frontNum && queueContainer[childNum + 1] > queueContainer[childNum]) //处理只剩下一个孩子的情况   右孩子大于左孩子
        {
            childNum++;//将操作的数值调整为右孩子
        }
        if (lastElement < queueContainer[childNum]) //最后一个数比找到的孩子小
        {
            queueContainer[i] = queueContainer[childNum];//替换，将大的元素往下送
            i = childNum;//直到最后一个数是
        }
        else //最后一个数就是最大的数
        {
            break;
        }
    }
    queueContainer[i] = lastElement;//替换位置
    std::cout << "the maximum element " << max << " has been deleted successfully!!!\n";
}

int Queue_Copy::size() //返回元素个数
{
    return frontNum;
}

void Queue_Copy::printQueue()//输出堆的数组
{
    for(int i=1;i<=frontNum;i++)
    {
        std::cout<<queueContainer[i]<<" ";
    }
    std::cout<<"\n";
}
