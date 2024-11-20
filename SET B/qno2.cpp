#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PDAEqualOneZero {
	stack<char> pdaStack;

public:
	bool test(string input) {
		for (char c : input) {
			if (c == '1') {
				if (!pdaStack.empty() && pdaStack.top() == '0') {
					pdaStack.pop(); // Match found, pop the stack
				} else {
					pdaStack.push('1'); // No match, push '1'
				}
			} else if (c == '0') {
				if (!pdaStack.empty() && pdaStack.top() == '1') {
					pdaStack.pop(); // Match found, pop the stack
				} else {
					pdaStack.push('0'); // No match, push '0'
				}
			} else {
				cout << "Invalid input: " << c << endl;
				return false;
			}
			displayStack();
		}
		return pdaStack.empty();
	}

	void displayStack() {
		stack<char> temp = pdaStack;
		cout << "Stack (top to bottom): ";
		while (!temp.empty()) {
			cout << temp.top() << " ";
			temp.pop();
		}
		cout << endl;
	}
};

int main() {
	string input;
	PDAEqualOneZero pda;
	cout << "Enter a binary string: ";
	cin >> input;

	bool accepted = pda.test(input);
	if (accepted) {
		cout << input << " is accepted (equal number of 1s and 0s)." << endl;
	} else {
		cout << input << " is not accepted (unequal number of 1s and 0s)." << endl;
	}
	return 0;
}
