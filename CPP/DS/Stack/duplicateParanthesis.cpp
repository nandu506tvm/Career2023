#include <iostream>
#include <stack>

using namespace std;

void popStack(stack<char> &stck) {
    // POP till we encounter opening paranthesis
    while (!stck.empty() and stck.top() != '(') {
        stck.pop();
    }
    // POP the opening paranthesis also
    if (stck.top() == '(') {
        stck.pop();
    }
}

bool duplicateParentheses(string str) {
    stack<char> stck;
    int length = str.length();

    for (char ch : str) {
        switch (ch) {
            case '(':
                stck.push(ch);
                break;
            case ')':
                if (stck.top() == '(') return true;
                popStack(stck);
                break;
            case '+':
                stck.push(ch);
                break;
            default:
                break;
        }
    }
    // no duplicates found
    return false;
}

int main(int argc, char const *argv[]) {
    string str = "((a+(b))+(c+d))";
    cout << duplicateParentheses(str) << endl;

    return 0;
}
