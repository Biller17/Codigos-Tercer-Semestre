#pragma once
#include <iostream>
#include <cmath>
#include "BinaryTree.h"
#include "Stack.h"

class Postfix {
private:
	std::string infix_expression;
	std::string postfix_expression;
    BinaryTree<char> tree_expression;

	int precedence(char current_operator, char other_operator);
	void convertExpression();
	int compute(int op1, int op2, char sign);
    int recursiveTreeEvaluate(TreeNode<char> * _root);
public:
	Postfix() {};
	Postfix(std::string expression);
	void setData(std::string expression);
	std::string getInfix();
	std::string getPostfix();
	int evaluate();
    void postfixTree();
    int treeEvaluate();
    void printTree();
};
