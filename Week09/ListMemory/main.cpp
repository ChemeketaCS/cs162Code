#include <iostream>

#include "Node.h"

using namespace std;

//Cretes 3 nodes on heap
// Makes extra pointer to an existing node
// Deletes the three heap based nodes
void demo() {
    Node<int>* node1 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(15);
    Node<int>* node3 = new Node<int>(20);

    node1->next = node2;
    node2->next = node3;

    Node<int>* node4 = node1;
    cout << node4->element << endl;

    delete node1;
    delete node2;
    delete node3;
    //Node 4 does not "own" memory - do not delete with it
}


int main()
{

    demo();

    return 0;
}
