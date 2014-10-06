#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

string common_prefix( string &ret, string &tmp) {
    int len = max(ret.size(), tmp.size());
    int i;
    for(i = 0; i < len&& ret[i] == tmp[i]; i++);
    return ret.substr(0, i);
}

int main(){
    string in, ret, tmp;
    stringstream ss;
    while(getline(cin, in)){
        int pos = 0, cnt = 0, len = in.size();
        while(pos < len &&in[pos] == ' ')
            pos++;
        while(pos < len &&in[pos] != ' ')
            pos++, cnt++;
        ret = in.substr(pos-cnt, cnt);
        while(pos < len){
            cnt = 0;
            while(pos < len &&in[pos] == ' ')
                pos++;
            while(pos < len &&in[pos] != ' ')
                pos++, cnt++;
            tmp = in.substr(pos-cnt, cnt);
            ret = common_prefix(ret, tmp);
        }
        cout << ret;
    }
    return 0;
}
        
        
