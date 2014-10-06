#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size() )
            return multiply(num2, num1);
        string ret;
        for (int i = 0; i < num2.size(); i++) {
            ret.push_back('0');
            ret = add(ret, multiply(num1, num2[i] - '0') );
        }
        return ret;        
    }
private:
    string multiply(string num, int digit) {
        if (digit == 0) return string();
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            int result = (num[i] - '0' )* digit + carry;
            int remainder = result%10;
            carry = result/10;
            num[i] = remainder + '0';
        }
        if (carry != 0) num.insert(num.begin(), carry + '0');
        return num;         
    }
    string add(string num1, string num2) {
        if (num1.size() < num2.size() ) return add(num2, num1);
        reverse(num1.begin(), num1.end() );
        reverse(num2.begin(), num2.end() );
        string result(num1);
        int carry = 0;
        for (int i = 0; i < num2.size(); i++) {
            int sum = num1[i] + num2[i] - '0' - '0' + carry;
            int remainder = sum%10;
            carry = sum/10;
            result[i] = remainder + '0';
        }
        for (int i = 0; carry != 0 && i < num1.size(); i++) {
            int sum = num1[i] - '0' + carry;
            int remainder = sum%10;
            carry = sum/10;
            result[i] = remainder + '0';
        }
        if (carry != 0) result += static_cast<char>(carry + '0');
        reverse(result.begin(), result.end() );
        return result;
    }
};

int main(){
    Solution sol;
    string s1 = "123", s2 = "456";
    sol.multiply(s1, s2);
    return 0;
}
