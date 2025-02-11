#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyStack {
private:
	vector<T> s;
public:
	MyStack() {}

	void push(const T& val) {
		s.push_back(val);
	}

	void pop() {
		if(empty())
			throw std::out_of_range("Stack is already empty! How much more empty do you want it to be?");
		s.pop_back();
	}

	const T& top() const {
		if(empty())
			throw std::out_of_range("Stack is empty!!! Cannot access top");

		return s.back();
	}

	size_t size() const {
		return s.size();
	}

	bool empty() const {
		return s.size() == 0 ? true : false;
	}

};

int main() {

}