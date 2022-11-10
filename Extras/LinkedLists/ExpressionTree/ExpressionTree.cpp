#include "ExpressionTree.h"

ExpressionTree::ExpressionTree() { }

ExpressionTree::ExpressionTree(const ExpressionTree& other) {
    //Go make duplicates of all the nodes in the other tree
    for(ExpressionNode* node : other.nodes) {
        //See if it is a binary operator, if not it must be a value
        BinaryOperatorNode* asBinaryOp = dynamic_cast<BinaryOperatorNode*>(node);
        if(asBinaryOp) {
            //Dereference existing pointer, use that object to make a new node for this tree
            nodes.push_back(new BinaryOperatorNode(*asBinaryOp));
        } else {
            ValueNode* asValue = dynamic_cast<ValueNode*>(node);
            nodes.push_back(asValue);
        }
    }
}

ExpressionTree::~ExpressionTree()
{
    //vector will manage its own memory, but we need to delete
    //the things it points at
    for(ExpressionNode* node : nodes) {
        delete node;
    }
}

BinaryOperatorNode* ExpressionTree::makeOp(BinaryOperatorNode::operationType op) {
    BinaryOperatorNode* opNode = new BinaryOperatorNode(op);
    nodes.push_back(opNode);
    return opNode;
}

ValueNode* ExpressionTree::makeValue(int value) {
    ValueNode* valNode = new ValueNode(value);
    nodes.push_back(valNode);
    return valNode;
}


ExpressionNode* ExpressionTree::getRoot() const {
    return nodes.at(rootIndex);
}

void ExpressionTree::setMostRecentAsRoot() {
    rootIndex = static_cast<int>(nodes.size()) - 1;
}
