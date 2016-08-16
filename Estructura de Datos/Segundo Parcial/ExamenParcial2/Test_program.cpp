#include <iostream>
#include <string>
#include "Postfix.h"

int main()
{
	std::string expression = "(8+9)*7^2";
	Postfix postfix(expression);

	// Show the contents of the current expression
	std::cout << "Infix: " << postfix.getInfix().c_str() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix().c_str() << std::endl;
	std::cout << "Evaluation: " << postfix.evaluate() << std::endl;
    std::cout << "Converting to tree ..." << std::endl;
    postfix.postfixTree();
    std::cout << "Inorder tree: " << std::endl;
    postfix.printTree();
	std::cout << "Tree evaluation: " << postfix.treeEvaluate() << std::endl;


	std::cout << std::endl;

	// Try a new expression
	postfix.setData("3 + 4 ^ 3 * 2 / (1 - 5) ^ 2");
	std::cout << "Infix: " << postfix.getInfix().c_str() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix().c_str() << std::endl;
	std::cout << "Evaluation: " << postfix.evaluate() << std::endl;
    std::cout << "Converting to tree ..." << std::endl;
    postfix.postfixTree();
    std::cout << "Inorder tree: " << std::endl;
    postfix.printTree();
	std::cout << "Tree evaluation: " << postfix.treeEvaluate() << std::endl;

	return 0;
}
