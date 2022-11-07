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

    ///Nothing to do, but make virtual so subclass destructors can be fired
    /// Should not actually be needed since we are using smart pointers
	virtual ~ExpressionNode() {}
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
    void setLeft(std::shared_ptr<ExpressionNode> child);
    void setRight(std::shared_ptr<ExpressionNode> child);

    virtual int evaluate() const;
    virtual std::string toString() const;

private:
    operationType operation;
    std::shared_ptr<ExpressionNode> left;           ///left operand
    std::shared_ptr<ExpressionNode> right;          ///right operand
};


#endif // EXPRESSIONNODE_H
