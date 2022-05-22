#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <vector>
#include "ExpressionNode.h"

class ExpressionTree
{
public:
    ExpressionTree();

    //Deletes all nodes in this tree
    ~ExpressionTree();

    //Provide for deep copy
    ExpressionTree(const ExpressionTree& other);

    //Declared but not implemented to prevent use of default
    //assignment operator.
    ExpressionTree& operator=(const ExpressionTree& other);

    /**
     * @brief Makes an operator node with the given operation
     * @return pointer to the new node
     *
     * The ExpressionTree assumes responsibility for the memory associated
     * with the new node. The caller can use the pointer, but should not try
     * to delete it.
     */
    BinaryOperatorNode* makeOp(BinaryOperatorNode::operationType);

    /**
     * @brief Makes a ValueNode with the given value
     * @param value
     * @return pointer to the new node
     *
     * The ExpressionTree assumes responsibility for the memory associated
     * with the new node. The caller can use the pointer, but should not try
     * to delete it.
     */
    ValueNode* makeValue(int value);

    /**
     * @brief Returns pointer to first item in the list of nodes
     * @return Pointer to item assumed to be the root.
     */
    ExpressionNode* getRoot() const;

    /**
     * @brief Marks the most recently added node as the root of the tree.
     */
    void setMostRecentAsRoot();

private:

    ///List of nodes that have been created as part of this tree
    /// and need to be cleaned up
    std::vector<ExpressionNode*> nodes;

    ///Store index of item assumed to be the root of the expression tree
    int rootIndex = -1;
};

#endif // EXPRESSIONTREE_H
