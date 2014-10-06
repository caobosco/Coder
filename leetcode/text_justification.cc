#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int pos = 0, len = words.size(), curLen, left, right;
        string str;
        vector<string> ret;
        while (pos < len) {
            left = pos, right = pos;
            curLen = 0;
            while ( pos < len) {
                if (curLen + words[pos].size() <= L ) {
                    curLen += (words[pos].size()+ 1);
                    pos++;
                    right++;
                } else {
                    curLen--;
                    str = words[left];
                    int words_number = right - left;
                    int space_number;
                    if (words_number == 1) 
                        space_number = L - curLen;
                    else  space_number = (L - curLen)/(words_number- 1);
                    string space_string(space_number, ' ');
                    
                    if (words_number == 1) {
                        str += space_string;
                        ret.push_back(str);
                        break;
                    }
                    
                    int space_surplus = (L - curLen)%(words_number- 1);
                    for (int i = left+ 1; i <= left+ space_surplus; i++) {
                        str += (space_string+ ' ' + words[i]);
                    }
                    
                    for (int i = left+ space_surplus+ 1; i < right; i++) 
                        str += space_string + words[i];
                    
                    ret.push_back(str);
                    break;
                }
            }
        }
        
        str = words[left];
        for (int i = left+ 1; i < len; i++) 
            str += (' ' + words[i]);
        string space(L- str.size(), ' ');
        str += space;
        ret.push_back(str);
        
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> vec(1, "");
    sol.fullJustify(vec, 0);
    return 0;
}    
