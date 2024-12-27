#include "map.h"
#include <iostream>

Node *init(char input[10], int insertNum) {
    int key = Function_Mapping(input);//函数映射
    return createNode(key, insertNum);
}

Node *createNode(int key, int insertNum) //创建节点
{
    Node *newNode = new Node;//new创建
    newNode->key = key;//键
    newNode->value = insertNum;//值
    newNode->left = nullptr;//左孩子
    newNode->right = nullptr;//右孩子
    newNode->parent = nullptr;//父节点
    newNode->color = 1; // 新节点默认为红色
    return newNode;
}


void leftRotate(Node *&root, Node *x) // 左旋操作
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr) //没有左节点
    {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) //没有父节点
    {
        root = y;
    } else if (x == x->parent->left) //如果是父节点的左孩子
    {
        x->parent->left = y;
    } else//是父节点的右孩子
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}


void rightRotate(Node *&root, Node *x) // 右旋操作
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) //右孩子情况
    {
        y->right->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == nullptr) //没有父节点
    {
        root = y;
    } else if (x == x->parent->right) //是父节点的右孩子
    {
        x->parent->right = y;
    } else //是父节点的左孩子
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}


void fixInsert(Node *&root, Node *tempNode) // 插入后恢复性质
{
    while (tempNode->parent != nullptr && tempNode->parent->color == 1) // 只要插入节点的父节点存在且为红色
    {
        if (tempNode->parent == tempNode->parent->parent->left) // 如果插入节点的父节点是其祖父节点的左孩子
        {
            Node *Uncle = tempNode->parent->parent->right;// 获取插入节点的叔父节点
            if (Uncle != nullptr && Uncle->color == 1) // 如果叔父节点存在且为红色
            {
                tempNode->parent->color = 0;// 将父节点的颜色改为黑色
                Uncle->color = 0;// 将叔父节点的颜色改为黑色
                tempNode->parent->parent->color = 1;// 将祖父节点的颜色改为红色
                tempNode = tempNode->parent->parent; // 将当前节点更新为祖父节点，继续循环
            } else // 如果叔父节点不存在或为黑色
            {
                if (tempNode == tempNode->parent->right)// 如果插入节点是其父节点的右孩子
                {
                    tempNode = tempNode->parent;// 将当前节点更新为父节点
                    leftRotate(root, tempNode);// 对以当前节点为根的子树进行左旋操作
                }
                tempNode->parent->color = 0;// 将父节点的颜色改为黑色
                tempNode->parent->parent->color = 1;// 将祖父节点的颜色改为红色
                rightRotate(root, tempNode->parent->parent); // 对以祖父节点为根的子树进行右旋操作
            }
        } else // 如果插入节点的父节点是其祖父节点的右孩子
        {
            Node *y = tempNode->parent->parent->left;// 获取插入节点的叔父节点
            if (y != nullptr && y->color == 1) // 如果叔父节点存在且为红色
            {
                tempNode->parent->color = 0;// 将父节点的颜色改为黑色
                y->color = 0;// 将叔父节点的颜色改为黑色
                tempNode->parent->parent->color = 1;// 将祖父节点的颜色改为红色
                tempNode = tempNode->parent->parent;// 将当前节点更新为祖父节点，继续循环
            } else  // 如果叔父节点不存在或为黑色
            {
                if (tempNode == tempNode->parent->left)// 如果插入节点是其父节点的左孩子
                {
                    tempNode = tempNode->parent;// 将当前节点更新为父节点
                    rightRotate(root, tempNode);// 对以当前节点为根的子树进行右旋操作
                }
                tempNode->parent->color = 0;// 将父节点的颜色改为黑色
                tempNode->parent->parent->color = 1;// 将祖父节点的颜色改为红色
                leftRotate(root, tempNode->parent->parent);// 对以祖父节点为根的子树进行左旋操作
            }
        }
    }
    root->color = 0;//根节点变黑（感觉没用必要o.O）
}

int Function_Mapping(char input[10])
{
    int key=input[0]+input[1];
    return key;
}


void insert(Node *&root, char input[10], int value) // 插入键值对到红黑树中
{
    int key= Function_Mapping(input);//转换关系
    Node *insertNode = createNode(key, value);//创建节点
    Node *tempStore = nullptr;
    Node *pthis = root;//临时指针从根节点遍历

    while (pthis != nullptr) //没到叶
    {
        tempStore = pthis;
        if (insertNode->key < pthis->key) //顺着指针往左孩子走
        {
            pthis = pthis->left;
        } else if (insertNode->key > pthis->key) //顺着指针往右孩子走
        {
            pthis = pthis->right;
        } else //相等！！！
        {
            pthis->value = insertNode->value;// 更新当前节点的值
            delete insertNode;// 释放创建的新节点
            return;
        }
    }

    insertNode->parent = tempStore;// 设置新节点的父节点
    if (tempStore == nullptr)// 如果父节点为空，说明新节点将成为根节点
    {
        root = insertNode;
    } else if (insertNode->key < tempStore->key) // 根据键的大小确定新节点在父节点的左子树还是右子树
    {
        tempStore->left = insertNode;
    } else {
        tempStore->right = insertNode;
    }

    fixInsert(root, insertNode);//修复红黑树
}


void inorderTraversal(Node *root) // 遍历红黑树
{
    if (root != nullptr) //没有到叶，就再调用函数
    {
        inorderTraversal(root->left);
        std::cout << root->key << ": " << root->value << std::endl;
        inorderTraversal(root->right);
    }
}

// 搜索红黑树元素的函数(返回指针)
Node *operator_(Node *root, int key)
{
    if (root == nullptr || root->key == key) //找到了KEY
    {
        return root;
    }
    if (key < root->key) //往下找
    {
        return operator_(root->left, key);
    } else {
        return operator_(root->right, key);
    }
}

//搜索，主函数
void search(Node *root, char input[10])
{
    int key = Function_Mapping(input);
    if (operator_(root, key) == NULL) //没有找到，返回了NULL
    {
        std::cout << "We cannot find the number!!!\n";
        return;
    }
    std::cout << operator_(root, key)->value<<std::endl;
}


void transplant(Node *&root, Node *transNode, Node *helpNode)//转换
{
    if (transNode->parent == nullptr) // 如果是根节点，将根节点设置为helpNode
    {
        root = helpNode;
    } else if (transNode == transNode->parent->left) // 如果 是左子节点
    {
        transNode->parent->left = helpNode;
    } else// 如果是右子节点
    {
        transNode->parent->right = helpNode;
    }
    if (helpNode != nullptr) // 如果helpNode不为空，设置helpNode的父节点为transNode的父节点
    {
        helpNode->parent = transNode->parent;
    }
}


// 寻找最小节点
Node *minimum(Node *node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// 删除红黑树中的节点
void remove_(Node *&root, char input[10]) {
    int key= Function_Mapping(input);
    Node *tempRoot = root;
    while (tempRoot != nullptr && tempRoot->key != key) // 根据键值大小决定向左或向右子树查找
    {
        if (key < tempRoot->key) {
            tempRoot = tempRoot->left;
        } else {
            tempRoot = tempRoot->right;
        }
    }

    if (tempRoot == nullptr)  // 若未找到要删除的节点，输出提示信息并返回
    {
        std::cout << "Key not found" << std::endl;
        return;
    }

    Node *recordNum = tempRoot;// 记录要删除节点的信息
    bool yOriginalColor = recordNum ->color;
    Node *excessiveNode;//操作用的过度节点

    if (tempRoot->left == nullptr) // 处理要删除节点只有一个子节点的情况
    {
        excessiveNode = tempRoot->right;
        transplant(root, tempRoot, tempRoot->right);
    } else if (tempRoot->right == nullptr) {
        excessiveNode = tempRoot->left;
        transplant(root, tempRoot, tempRoot->left);
    } else // 处理要删除节点有两个子节点的情况
    {
        recordNum  = minimum(tempRoot->right);
        yOriginalColor = recordNum ->color;
        excessiveNode = recordNum ->right;// 若为右子节点
        if (recordNum ->parent == tempRoot) {
            excessiveNode->parent = recordNum ;
        } else // 进行节点替换操作
        {
            transplant(root, recordNum , recordNum ->right);
            recordNum ->right = tempRoot->right;
            recordNum ->right->parent = recordNum ;
        }
        transplant(root, tempRoot, recordNum );
        recordNum ->left = tempRoot->left;
        recordNum ->left->parent = recordNum ;
        recordNum ->color = tempRoot->color;
    }

    if (yOriginalColor == 0) // 根据删除节点的原始颜色进行后续处理
    {
        fixDelete(root, excessiveNode);
    }
}

// 修复删除操作后的红黑树性质
void fixDelete(Node *&root, Node *excessiveNode) {
    while (excessiveNode != root && excessiveNode->color == 0) // 不是根节点  且   颜色为黑色时，进行循环处理
    {
        if (excessiveNode == excessiveNode->parent->left) // 若是左子节点
        {
            Node *wthis = excessiveNode->parent->right;
            if (wthis->color == 1) // 若为红色
            {
                wthis->color = 0;
                excessiveNode->parent->color = 1;
                leftRotate(root, excessiveNode->parent);
                wthis = excessiveNode->parent->right;
            }
            if (wthis->left->color == 0 && wthis->right->color == 0) // 若两个子节点均为黑色
            {
                wthis->color = 1;
                excessiveNode = excessiveNode->parent;
            } else // 若右子节点为黑色
            {
                if (wthis->right->color == 0) {
                    wthis->left->color = 0;
                    wthis->color = 1;
                    rightRotate(root, wthis);
                    wthis = excessiveNode->parent->right;
                }
                wthis->color = excessiveNode->parent->color;
                excessiveNode->parent->color = 0;
                wthis->right->color = 0;
                leftRotate(root, excessiveNode->parent);
                excessiveNode = root;
            }
        } else // 若为右子节点
        {
            Node *wthis = excessiveNode->parent->left;
            if (wthis->color == 1)  // 若为红色
            {
                wthis->color = 0;
                excessiveNode->parent->color = 1;
                rightRotate(root, excessiveNode->parent);
                wthis = excessiveNode->parent->left;
            }
            if (wthis->right->color == 0 && wthis->left->color == 0)  // 若两个子节点均为黑色
            {
                wthis->color = 1;
                excessiveNode = excessiveNode->parent;
            } else // 若左子节点为黑色
            {
                if (wthis->left->color == 0) {
                    wthis->right->color = 0;
                    wthis->color = 1;
                    leftRotate(root, wthis);
                    wthis = excessiveNode->parent->left;
                }
                wthis->color = excessiveNode->parent->color;
                excessiveNode->parent->color = 0;
                wthis->left->color = 0;
                rightRotate(root, excessiveNode->parent);
                excessiveNode = root;
            }
        }
    }
    excessiveNode->color = 0; // 将颜色设置为黑色
}


