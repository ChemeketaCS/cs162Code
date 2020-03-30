#include <iostream>

#include "Node.h"

using namespace std;

/**
 * @brief printList Prints out values in a list separated by spaces
 * @param current Starting location of print process
 */
template <typename T>
void printList(Node<T>* current) {
    while(current != nullptr) {
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
}

/**
 * @brief getLength Finds the length of a list
 * @param current Starting location to count from
 * @return length of list
 */
template <typename T>
int getLength(Node<T>* current) {
    int length = 0;
    while(current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}


/**
 * @brief destroyList Destroys all nodes starting from provided node
 * @param current Starting location
 */
template <typename T>
void destroyList(Node<T>* current) {
    while(current != nullptr) {
        Node<T>* temp = current->next;  //save address of next node
        delete current;
        current = temp;                 //advance to next ndoe
    }
}

/**
 * @brief addAtHead Inserts a new value at start of existing list
 * @param value Value to insert
 * @param oldHead The current head of the list to be modified
 * @return memory address of the new node - it is now the start of the list
 */
template <typename T>
Node<T>* addAtHead(T value, Node<T>* oldHead) {
    Node<T>* temp = new Node<T>(value);
    temp->next = oldHead;
    return temp;
}


int main()
{
    Node<char>* head = new Node<char>('C');
    head->next = new Node<char>('D');

    printList(head);

    cout << "Length is " << getLength(head) << endl;

    head = addAtHead('B', head);
    printList(head);

    head = addAtHead('A', head);
    printList(head);
    cout << "Length is " << getLength(head) << endl;

    destroyList(head);  //clean up all memory
    head = nullptr;
}
