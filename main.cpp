#include <iostream>
#include <stack>
#include <string>
#include <map>

enum class op {
	plus,
	minus,
	push,
	pop,
	print,
	quit
};

std::stack<int> stack;
std::map<std::string, op> string_op;

bool handle_plus() {
	if(stack.size() < 2) {
		std::cout << "error: stack size is " << stack.size() << std::endl;
	} else {
		int a = stack.top();
		stack.pop();
		int b = stack.top();
		stack.pop();
		stack.push(a + b);
	}
	return true;
}

bool handle_minus() {
	if(stack.size() < 2) {
		std::cout << "error: stack size is " << stack.size() << std::endl;
	} else {
		int a = stack.top();
		stack.pop();
		int b = stack.top();
		stack.pop();
		stack.push(a - b);
	}
	return true;
}

bool handle_push() {
	int n;
	std::cin >> n;
	stack.push(n);
	return true;
}

bool handle_pop() {
	stack.pop();
	return true;
}

bool handle_print() {
	if(stack.size() < 1) {
		std::cout << "error: stack size is " << stack.size() << std::endl;
	} else {
		std::cout << stack.top() << std::endl;
		stack.pop();
	}
	return true;
}

bool handle_quit() {
	return false;
}

bool exec_op() {
	std::string str;
	std::cin >> str;
	auto it = string_op.find(str);
	if(it == string_op.end()) {
		std::cout << "error: expected op, found " << str << std::endl;
		return false;
	} 
	switch(it->second) {
		case op::plus: return handle_plus();
		case op::minus: return handle_minus();
		case op::push: return handle_push();
		case op::pop: return handle_pop();
		case op::print: return handle_print();
		case op::quit: return handle_quit();
	}
	return false;
}

int main() {
	string_op["plus"] = op::plus;
	string_op["minus"] = op::minus;
	string_op["push"] = op::push;
	string_op["pop"] = op::pop;
	string_op["print"] = op::print;
	string_op["quit"] = op::quit;
	
	while(exec_op());
}
