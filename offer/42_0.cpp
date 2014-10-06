#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
void reverse(int start, int end, string &str){
    if(start >= end)
        return;
    char tmp;
    while(start<end){
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++, end--;
    }
}
        

int main(){
    string str;    
    while(getline(cin, str)){
      int numOfSpace = 0, len = str.size(), pos = 0, cnt = 0;
        while(len > 0 && str[len- 1] == ' ')
            len--;
        while(pos < len &&str[pos] == ' ')
            pos++, numOfSpace++;
        while(pos < len){
            cnt = 0;
            while(pos < len && str[pos] != ' '){
                str[pos-numOfSpace] = str[pos];
                pos++, cnt++;
            }
            reverse(pos-numOfSpace- cnt, pos - numOfSpace - 1, str);
            if(pos != len)
                str[pos-numOfSpace] = str[pos++];
            while(pos < len &&str[pos] == ' ')
                pos++, numOfSpace++; 
        }
        reverse(0, len - numOfSpace- 1, str);
        cout << str.substr(0, len - numOfSpace) << endl;
    }
    return 0;
}
