
#ifndef TASK4_MAP_H
#define TASK4_MAP_H

#include <iostream>


// 定义红黑树的节点结构体
struct Node {
    int key;//通过函数映射，映射到唯一的Key
    int value;
    Node *left;
    Node *right;
    Node *parent;
    bool color; // 0: 黑色, 1: 红色
};

//函数映射
int Function_Mapping(char input[10]);

//创建
Node *init(char input[10], int insertNum);

//寻找，主函数
void search(Node *root, char input[10]);

// 中序遍历红黑树
void inorderTraversal(Node *root);

// 插入键值对到红黑树中
void insert(Node *&root, char input[10], int value);

//删除节点
void remove_(Node *&root, char input[10]);

// 创建新节点
Node *createNode(int key, int value);


// 左旋操作
void leftRotate(Node *&root, Node *x);

// 右旋操作
void rightRotate(Node *&root, Node *x);

// 修复插入后的红黑树性质
void fixInsert(Node *&root, Node *z);

//寻找，返回指针
Node *operator_(Node *root, int key);

//删除后的修改
void fixDelete(Node *&root, Node *x);

//寻找最小节点
Node *minimum(Node *node);

//转换
void transplant(Node *&root, Node *u, Node *v);

//bool clear(Node *&root,const Node& key) ;

#endif //TASK4_MAP_H
