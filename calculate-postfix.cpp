#include <iostream>
using namespace std;
class stack {
public:
	stack();
	void push(char);
	char pop();
	bool isfull();
	bool isempty();
	void CalcPostFix();
private:
	int top = -1, i = 0, j = 0;
	int size = 30;
	int arr[30];
	char arr2[30];
};
stack::stack() {

}
void stack::CalcPostFix() {
	char postfix[30];
	char infix[30];
	int x = 0, y = 0;
	cout << "inter your postfix like: 1412+-/51-*1* \n";
	cin >> infix;		//adad ha tak ragami bedoon fasele mesl 1412+-/51-*1* ya 231*+9-
	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] >= 48 && infix[i] <= 57) {
			push(int(infix[i]-48));
		}
		else if (infix[i] == '*')
			push(pop() * pop());
		else if (infix[i] == '+')
			push(pop() + pop());
		else if (infix[i] == '-') {
			x = pop();
			y = pop();
			push(y - x);
		}	
		else if (infix[i] == '/') {
			x = pop();
			y = pop();
			push(y / x);
		}
	}
	cout << "your postfix equal: "<<arr[0];
}
char stack::pop() {
	if (!isempty())
		return arr[top--];
}
void stack::push(char data) {
	if (!isfull()) {
		top++;
		arr[top] = data;
	}
	else
		cout << "Stack is full.\n";
}
bool stack::isfull() {
	if (top == size)
		return true;
	else
		return false;
}
bool stack::isempty() {
	if (top == -1)
		return true;
	else
		return false;
}
void main() {
	stack s;
	s.CalcPostFix();
}