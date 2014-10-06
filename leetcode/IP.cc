#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4) return vector<string>();
        vector<string> irt, ret;
        dfs(irt, 0, s, ret);
        return ret;
    }
private:
    void dfs(vector<string> &irt, int pos, const string &s, vector<string> &ret) {
        if (pos == s.size() && irt.size() == 4) {
            string tmp = accumulate(irt.begin(), irt.end(), "");
            tmp.pop_back();
            ret.push_back(tmp);
            return;
        } else if (irt.size() == 4 || pos == s.size() || s[pos] == '0') return;
        for (int num = s[pos] - '0', i = 1; num <= 255; i++) {
            irt.push_back(s.substr(pos, i) + '.');
            dfs(irt, pos + i, s, ret);
            irt.pop_back();
            if (pos + i >= s.size()) break;
            num *= 10;
            num += s[pos + i] - '0';
        }
    }
};

int main () {
    Solution sol;
    sol.restoreIpAddresses("1111");
    return 0;
}
