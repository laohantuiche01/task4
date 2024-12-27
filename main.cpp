#include <iostream>
#include "list.h"
#include "queue.h"
#include "map.h"
#include "stack.h"

using namespace std;
int main() {
//    Stack_Copy Stack1;
//    Stack1.init();
//    Stack1.push(1);
//    Stack1.push(2);
//    Stack1.push(3);
//    Stack1.push(4);
//    Stack1.push(5);
//    cout<<Stack1.size()<<endl;
//    cout<<Stack1.top()<<endl;
//    Stack1.pop();
//
//    Queue_Copy Queue1;
//    Queue1.push(1);
//    Queue1.push(2);
//    Queue1.push(3);
//    Queue1.push(4);
//    Queue1.push(5);
//    Queue1.size();
//    Queue1.printQueue();
//    Queue1.front();
//    Queue1.clear();

//    Node* Map1;
//    insert(Map1,"AB",5);
//    insert(Map1,"CD",4);
//    insert(Map1,"EF",3);
//    insert(Map1,"GH",2);
//    insert(Map1,"IJ",1);
//    inorderTraversal(Map1);
//    search(Map1,"CD");
//    remove_(Map1,"EF");
//    inorderTraversal(Map1);


    List_Copy list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(5);
    list1.printList();
    list1.remove(1);
    list1.clear();



    return 0;
}
