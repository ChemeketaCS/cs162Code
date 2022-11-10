#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H

#include <memory>
#include <string>

///Abstract class representing a mathematical expression
class ExpressionNode
{
public:
    ///Get value of expression starting at this node
    virtual int evaluate() const = 0;

    ///Get printable representation
    virtual std::string toString() const = 0;

    ///We won't actually use it, but a class that is going
    /// to be inherited from should make a virtual destructor so
    /// we get the correct child destructor when the time comes
    virtual ~ExpressionNode();
};


///Represents a literal value like 2.5
class ValueNode : public ExpressionNode
{
public:
    ValueNode(int val);

    virtual int evaluate() const;
    virtual std::string toString() const;

private:
    int value;
};

///Represents a binary operator like + that applies to two other nodes
class BinaryOperatorNode : public ExpressionNode
{
public:
    ///Valid operations for a BinaryOperatorNode
    enum operationType {ADD, SUBTRACT, MULTIPLY, DIVIDE, MOD};

    BinaryOperatorNode(operationType op);

    std::string getName() const;
    std::string getSymbol() const;

    ///Store another ExpressionNode as the left/right child of this node.
    void setLeft(ExpressionNode* child);
    void setRight(ExpressionNode* child);

    ExpressionNode* getLeft();
    ExpressionNode* getRight();

    virtual int evaluate() const;
    virtual std::string toString() const;

private:
    operationType operation;
    ExpressionNode* left;           ///left operand
    ExpressionNode* right;          ///right operand
};


#endif // EXPRESSIONNODE_H
