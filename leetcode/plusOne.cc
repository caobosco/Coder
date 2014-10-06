#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 0, last = -1, len = digits.size();
        for (int i = 0; i < len; i++)
            if (last == -1 && digits[i] == 9) last == i;
            else if (digits[i] < 9) last = -1;
        
        if (last == -1) digits[len - 1] += 1;
        else {
            for (int i = len - 1; i >= last; i--)
                digits[i] = 0;
            if (last == 0) digits.insert(digits.begin(), 1);
            else digits[last - 1] += 1;
        }
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> num(1, 9);
    sol.plusOne(num);
    return 0;
}
