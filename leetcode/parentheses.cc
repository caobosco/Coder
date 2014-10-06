#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n < 1) return ret;
        dfs(0, n, string(), ret);
        return ret;
    }
private:
    void dfs(int left, int num, string parentheses, vector<string>& ret) {
        if (left == 0 && num == 0) {
            ret.push_back(parentheses);
            return;
        }
        
        string tmp = parentheses;
        for (int i = 0; i < left; i++)
            tmp += ')';
        dfs(0, num, tmp, ret);
        
        tmp = parentheses;
        for (int i = 0; i < num; i++) {
            tmp += '(';
            dfs(left + i + 1, num - i - 1, tmp, ret);
        }
    }
};

int main() {
    Solution sol;
    int n;
    while (cin >> n ) {
    vector<string> ret = sol.generateParenthesis(n);
    for (auto str:ret)
        cout << str << ' ';
    cout << endl;
    }
    return 0;
}
