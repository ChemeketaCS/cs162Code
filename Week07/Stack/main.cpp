#include <iostream>

#include "GenericStack.h"

using namespace std;

int main() {
  //    Stack<int> myStack;

  //    myStack.push(5);
  //    myStack.push(10);
  //    myStack.push(20);
  //    myStack.push(15);
  //    cout << myStack.toString() << endl;

  //    myStack.clear();
  //    for(int i = 1; i <= 100; i++) {
  //        cout << "Pushing " << i << endl;
  //        myStack.push(i);
  //    }
  //    cout << myStack.toString() << endl;

  //    int topItem = myStack.pop();
  //    cout << "Popped " << topItem << endl;
  //    cout << myStack.toString() << endl;

  //    int x = 30;
  //    myStack.push(x);
  //    cout << "Pushed " << x << endl;
  //    cout << myStack.toString() << endl;

  //    int top = myStack.peek();
  //    cout << "Peeked at " << top << endl;
  //    cout << myStack.toString() << endl;

  //    cout << "--------------------------------" << endl;
  //    //Copy our myStack
  //    Stack<int> copy(myStack);
  //    cout << "Adding 99 to copy of stack..." << endl;
  //    copy.push(99);
  //    cout << "Original " << myStack.toString() << endl;
  //    cout << "Copy     " << copy.toString() << endl;

  //    cout << "--------------------------------" << endl;
  Stack<double> secondStack;
  secondStack.push(1.5);
  secondStack.push(2.3);
  secondStack.push(4.1);
  secondStack.push(3.1);
  secondStack.push(5.6);
  cout << secondStack.toString() << endl;

  cout << "Splitting in half..." << endl;

  Stack<double> topPart = secondStack.split();

  cout << secondStack.toString() << endl;
  cout << topPart.toString() << endl;

  return 0;
}
