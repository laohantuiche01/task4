//
// Created by 1 on 2024/12/25.
//

#ifndef TASK4_QUEUE_H
#define TASK4_QUEUE_H

#include <iostream>
#include <bits/stdc++.h>
class Queue_Copy {
public:


    void init();

    int front() ;

    void push(int pushNum) ;

    void clear() ;

    void pop() ;

    void printQueue();

    int size();

private:
    int frontNum = 0;
    int MemoryNum = 1;
    int MemorySpace = 100;
    int *queueContainer = new int[MemorySpace];
    void ExpendMemory() ;
};


#endif //TASK4_QUEUE_H
