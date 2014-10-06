#include <vector>
#include <string>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

class Solution {
    bool isOperator(string input) {
        switch (input[0]) {
            case '/': 
            case '*':
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }
    
    int operation(int num1, int num2, char oprt) {
        switch (oprt) {
            case '+':
                return num1+ num2;
            case '-':
                return num1- num2;
            case '*':
                return num1*num2;
            case '/':
                return num1/num2;
        }
    }
    
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> num;
        int length = tokens.size(), num1, num2;
        for (int i = 0; i < length; i++) {
            if (isOperator(tokens[i]) ) {
                num1 = num.top(); num.pop();
                num2 = num.top(); num.pop();
                num.push(operation(num2, num1, tokens[i][0]) );
            } else num.push(atoi(tokens[i].c_str() ) );
        }
        return num.top();
    }
};

int main() {
    vector<string> vec = {"-1","1","*","-1","+"};
    Solution sol;
    sol.evalRPN(vec);
    return 0;
}
