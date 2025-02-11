#include<iostream>

struct Node {
	std::string val;
	Node* left;
	Node* right;

	Node(std::string val) : val(val) {}
};

class ExpressionTree {
private:
	string exp;
public:
	ExpressionTree(string exp) : exp(exp) {}

	int evaluate() {
		
	}
};

int main() {

}