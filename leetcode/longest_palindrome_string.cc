#include <vector>
#include <string>

using namespace std;

class Solution {
    bool isPalindrome(int i, int j, vector<vector<char> > &flg, string &str) {
    if (flg[i][j] != 'a')
        return flg[i][j];

    if (i == j) return 'c';
    if (i > j) return isPalindrome(j, i, flg, str);
    if ((i+ 1) == j) {
        if (str[i] == str[j])
            flg[i][j] = 'c';
        else flg[i][j] = 'b';
    }
    else if (str[i] == str[j]) {
        flg[i][j] = isPalindrome(i+1, j- 1, flg, str);
    } else flg[i][j] = 'b';
    return flg[i][j];
}

public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<char> tmp(len, 'a');
        vector<vector<char> > flg(len, tmp);
        for (int i = len; i > 0; i--)
            for (int j = 0; j + i <= len; j++)
                if (isPalindrome(j, j+i- 1, flg, s) == 'c')
                    return s.substr(j, i);
    }
};

int main() {
    Solution sol;
    string str = "bb";
    sol.longestPalindrome(str);
    return 0;
}
