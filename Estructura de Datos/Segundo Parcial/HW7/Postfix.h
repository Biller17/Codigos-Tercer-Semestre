#pragma once
#include <iostream>
#include "Stack.h"

class Postfix {
private:
	std::string infix_expression;
	std::string postfix_expression;

	int precedence(char current_operator, char other_operator);
	void convertExpression();
	int compute(float op1, float op2, char sign);
public:
	Postfix() {};
	Postfix(std::string expression);
	void setData(std::string expression);
	std::string getInfix();
	std::string getPostfix();
	int evaluate();
};
