#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
class Solution {
    vector<string> ret;
    string str;
    int len;
    bool isLegal(string s){
        if(s == "0")
            return 1;
        if(s[0] = '0')
            return 0;
        int num = atoi(s.c_str());
        if(num >= 0 && num < 256)
            return 1;
        return 0;
    }
    
    void dfs(string irt, int pos, int level){
        if(level == 4 && pos == len){
            ret.push_back(irt);
            return;
        }
        if(level)
            irt += ".";
        if(level == 4 || pos >= len)
            return;
        for(int i = 1; i < 4; i++){
            string tmp = str.substr(pos, i);
            if(isLegal(tmp))
                dfs(irt+ tmp, pos+ i, level+ 1);
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        string irt; 
        len = s.size();
        str = s;
        dfs(irt, 0, 0);
        return ret;
    }
};
int main(){
	string in = "1111";
	Solution sol;
	sol.restoreIpAddresses(in);
	return 0;
}
