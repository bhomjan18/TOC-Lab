#include<iostream>
#include<string>
using namespace std;

typedef struct Node{
    string name;
    bool final = false;
    Node *oneInput = nullptr;
    Node *zeroInput = nullptr;
} Node_dfa;

class odd_one {
    Node_dfa q0, q1;
    Node *present = &q0; 

public:
    odd_one() {
        q0.name = "q0";
        q0.oneInput = &q1; 
        q0.zeroInput = &q0;
        

        q1.name = "q1";
        q1.oneInput = &q0;
        q1.zeroInput = &q1;
        q1.final = true; 
    }

    bool test(string input) {
        for (int i = 0; i < input.length(); i++) {
            char c = input[i];
            if (c == '1') {
                present = present->oneInput;
            } else if (c == '0') {
                present = present->zeroInput;
            } else {
                cout << "Invalid input: " << c << endl;
                return false;
            }
            cout << "Current state: " << present->name << endl;
        }
        return present->final;
    }
};

int main() {
    string input;
    odd_one obj;
    cout << "Enter a binary string: ";
    cin >> input;

    bool accepted = obj.test(input);
    if (accepted) {
        cout << input << " is accepted (odd number of 1s)." << endl;
    } else {
        cout << input << " is not accepted (even number of 1s)." << endl;
    }
    return 0;
}
