#include <iostream>

#include "ExpressionNode.h"
#include "ExpressionTree.h"

using namespace std;

//Builds up the expression ((7 + 3) * (5 - 2))
ExpressionNode* buildTree1();

//Builds up the expression (((10 - 3) * 4) % 10)
ExpressionTree buildTree2();

//Cleans up memory for the tree that starts at node
void destroyTree(ExpressionNode* node);

int main()
{
    //Build a tree on the stack
    ValueNode n1(7);
    ValueNode n2(3);
    BinaryOperatorNode addNode1(BinaryOperatorNode::ADD);
    addNode1.setLeft(&n1);
    addNode1.setRight(&n2);

    cout << addNode1.toString() << endl;
    cout << "Evaluates to: " << addNode1.evaluate() << endl;
    //No cleanup needed - all data is on the stack

    cout << "-----------------------------------------------------" << endl;

    ///---------------set up the tree--------------
    ExpressionNode* root = buildTree1();
    //main now "owns" all the memory that is connected to root

    cout << root->toString() << endl;
    cout << "Evaluates to: " << root->evaluate() << endl;

    //have to clean up the memory
    destroyTree(root);

    cout << "-----------------------------------------------------" << endl;
    ExpressionTree example3 = buildTree2();
    //main now "owns" all the memory that is connected to root

    cout << example3.getRoot()->toString() << endl;
    cout << "Evaluates to: " << example3.getRoot()->evaluate() << endl;

    //Expression tree will clean up all memory
}

//Builds up the expression ((7 + 3) * (5 - 2))
//Caller assumes responsibility for the memory
ExpressionNode* buildTree1() {
    //Build bottom up
    ValueNode* n1 = new ValueNode(7);
    ValueNode* n2 = new ValueNode(3);
    BinaryOperatorNode* n3 = new BinaryOperatorNode(BinaryOperatorNode::ADD);
    n3->setLeft(n1);
    n3->setRight(n2);

    ValueNode* n4 = new ValueNode(5);
    ValueNode* n5 = new ValueNode(2);
    BinaryOperatorNode* n6 = new BinaryOperatorNode(BinaryOperatorNode::SUBTRACT);
    n6->setLeft(n4);
    n6->setRight(n5);

    BinaryOperatorNode* root = new BinaryOperatorNode(BinaryOperatorNode::MULTIPLY);
    root->setLeft(n3);
    root->setRight(n6);

    return root;
}

//Recursively destroy nodes rooted at the given node
void destroyTree(ExpressionNode* node) {
    if(node == nullptr)
        return;         //nothing to do here

    //If this is an operator, recursively destroy children
    BinaryOperatorNode* nodeAsOperator = dynamic_cast<BinaryOperatorNode*>(node);
    if(nodeAsOperator) {
        destroyTree(nodeAsOperator->getLeft());
        destroyTree(nodeAsOperator->getRight());
    }

    //Now it is safe to delete this node
    delete node;
}


//Builds up the expression (((10 - 3) * 4) % 10)
//Returns it wrapped up in a
ExpressionTree buildTree2() {
    ExpressionTree expr2;
    ValueNode* n1 = expr2.makeValue(10);
    ValueNode* n2 = expr2.makeValue(3);
    BinaryOperatorNode* n3 = expr2.makeOp(BinaryOperatorNode::SUBTRACT);
    n3->setLeft(n1);
    n3->setRight(n2);
    ValueNode* n4 = expr2.makeValue(4);
    BinaryOperatorNode* n5 = expr2.makeOp(BinaryOperatorNode::MULTIPLY);
    n5->setLeft(n3);
    n5->setRight(n4);
    BinaryOperatorNode* n6 = expr2.makeOp(BinaryOperatorNode::MOD);
    expr2.setMostRecentAsRoot();
    n6->setLeft(n5);
    n6->setRight(n1);       //reuse the 10 node
    return expr2;
}
