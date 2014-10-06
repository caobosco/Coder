#include <vector>
#include <cstring>

using namespace std;
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int s_len = strlen(haystack), p_len = strlen(needle);
        if (p_len == 0) return haystack;
        if (s_len == 0) return NULL;
        vector<int> next(p_len);
        getNext(needle, next);
        int s_pos = 0, p_pos = 0;
        while (s_pos < s_len && p_pos < p_len) {
            if (p_pos == -1 || haystack[s_pos] == needle[p_pos])
                s_pos++, p_pos++;
            else p_pos = next[p_pos];
        }
        
        if (p_pos == p_len) return haystack + s_pos - p_pos;
        return NULL;
    }
private:
    void getNext(char *p, vector<int> &next) {
        next[0] = -1;
        int length = strlen(p), k = -1;
        for (int i = 1; i < length;) {
            if (k == -1 || p[i] == p[k])
                next[i++] = ++k;
            else k = next[k];
        }
    }
};

int main() {
    char s[] = "mississippi";
    char p[] = "issip";
    Solution sol;
    sol.strStr(s, p);
    return 0;
}
