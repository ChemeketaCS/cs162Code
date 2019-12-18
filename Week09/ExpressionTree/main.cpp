#include <iostream>

#include "ExpressionNode.h"

using namespace std;

///All build tree functions return a shared_ptr to root of expression tree
///Builds up the expression ((7 + 3) * (5 - 2))
shared_ptr<ExpressionNode> buildTree1();
///Builds up the expression (((10 - 3) * 4) % 10)
shared_ptr<ExpressionNode> buildTree2();

int main()
{
    ///---------------set up the tree--------------
    shared_ptr<ExpressionNode> root = buildTree1();

    cout << root->toString() << endl;
    cout << "Evaluates to: " << root->evaluate() << endl;

    cout << "-----------------------------------------------------\n";

    root = buildTree2();

    cout << root->toString() << endl;
    cout << "Evaluates to: " << root->evaluate() << endl;
}


//Builds up the expression ((7 + 3) * (5 - 2))
shared_ptr<ExpressionNode> buildTree1() {
    //Build bottom up
    shared_ptr<ValueNode> n1(new ValueNode(7));
    shared_ptr<ValueNode> n2(new ValueNode(3));
    shared_ptr<BinaryOperatorNode> n3(new BinaryOperatorNode(BinaryOperatorNode::ADD));
    n3->setLeft(n1);
    n3->setRight(n2);

    shared_ptr<ValueNode> n4(new ValueNode(5));
    shared_ptr<ValueNode> n5(new ValueNode(2));
    shared_ptr<BinaryOperatorNode> n6(new BinaryOperatorNode(BinaryOperatorNode::SUBTRACT));
    n6->setLeft(n4);
    n6->setRight(n5);

    shared_ptr<BinaryOperatorNode> root(new BinaryOperatorNode(BinaryOperatorNode::MULTIPLY));
    root->setLeft(n3);
    root->setRight(n6);

    return root;
}


////Builds up the expression (((10 - 3) * 4) % 10)
shared_ptr<ExpressionNode> buildTree2() {
    //Build bottom up
    shared_ptr<BinaryOperatorNode> subNode( new BinaryOperatorNode(BinaryOperatorNode::SUBTRACT) );

    //Don't need to store our own pointers for 10 & 3 if we use make_shared<T>(ptr) to package them up
    // make_shared produces anonymous shared pointer which will get copied to setLeft
    // Note that make_shared does its own allocation - don't have to say "new"
    subNode->setLeft( make_shared<ValueNode>(ValueNode(10)) );
    subNode->setRight( make_shared<ValueNode>(ValueNode(3)) );

    shared_ptr<BinaryOperatorNode> multNode( new BinaryOperatorNode(BinaryOperatorNode::MULTIPLY) );
    multNode->setLeft(subNode);
    multNode->setRight( make_shared<ValueNode>(ValueNode(4)) );

    shared_ptr<BinaryOperatorNode> modNode( new BinaryOperatorNode(BinaryOperatorNode::MOD) );
    modNode->setLeft(multNode);
    modNode->setRight( make_shared<ValueNode>(ValueNode(10)) );

    return modNode;
}
