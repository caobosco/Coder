#include <vector>
#include <string>
#include <iostream>

using namespace std;
bool isPalindrome(int i, int j, vector<vector<int> > &flg, string &str) {
    if (flg[i][j] != -1)
        return flg[i][j];
    
    if (i == j) return 1;
    if (i > j) return isPalindrome(j, i, flg, str);
    if ((i+ 1) == j) 
       flg[i][j] = (str[i] == str[j]); 
    else if (str[i] == str[j]) {
        flg[i][j] = isPalindrome(i+1, j- 1, flg, str);
    } else flg[i][j] = false;
    return flg[i][j];
}

int main(){
    int T;
    string input;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> input;
        string pre(input);
        bool flg = 1;
        int len;
        while (flg) {
            string next;
            flg = 0;
            len = pre.size();
            int pos = 0;
            while (pos < len) {
                if(pos == (len -1) ) {
                    next += pre[pos];
                    break;
                }
                if( pre[pos+ 1] == pre[pos]) {
                    flg = 1;
                    char tmp = pre[pos];
                    while(pos < len && pre[pos] == tmp) pos++;
                    continue;
                }
                next += pre[pos];
                pos++;
            }
            pre = next;
        }
        
        len = pre.size();
        vector<int> vect1(len, -1);
        flg = 1;
        vector<vector<int> > isPalin(len, vect1);
        for (int i = len; i > 0 && flg; i--)
            for (int j = 0; j + i <= len && flg; j++)
                if (isPalindrome(j, j+i- 1, isPalin, pre) ) { 
                    len -= i;
                    flg = 0;
                }

        
        cout << (input.size() - len + 1)<< endl;
    }
    return 0;
}
             
