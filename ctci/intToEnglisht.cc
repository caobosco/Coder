#include <string>
#include <iostream>

using namespace std;

string units[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"
                  , "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string decades[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string intBelowThousandToEnglish(int num) {
    string result;
    if (num >= 100)
        result = units[num/100- 1] + " Hundred";
    if (num == 0) return result;
    if (num >= 100) {
        result += " ";
        num %= 100;
    }
    if (num >= 20) {
        result += " " + decades[num/10 - 2];
        num = num%10;
        if (num != 0)
            result += " " + units[num - 1];
    } else if (num > 0) {
        result += " " + units[num - 1];
    }
    return result;
}

string intToEnglish(int num) {
    string ret;
    if (num == 0) return "Zero";
    if (num >= 1000) {
        ret += intBelowThousandToEnglish(num/1000);
        ret += " Thousand";
    }
    if (num%1000 == 0) return ret;
    if (num > 1000)
        ret += ", ";
    ret += intBelowThousandToEnglish(num%1000);
    return ret;
}

int main(){
    int num = 999999;
    while (cin >> num) {
    cout << intToEnglish(num) << endl;
    }
    return 0;
}
