#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void permutation(int pos, string in){
    int len = in.size();
    if(pos == len){
        cout << in << endl;
        return;
    }
    char tmp = in[pos];
    int i = pos;
//    while(i < len && in[pos] == in[i++]);
    permutation(pos+ 1, in);
    while(i < len) {
        if(in[pos] != in[i]){
            tmp = in[pos];
            in[pos] = in[i];
            in[i] = tmp;
            permutation(pos+ 1, in);
            tmp = in[pos];
            in[pos] = in[i];
            in[i] = tmp;
            i++;
            while( i< len && in[i- 1] == in[i])
                i++;
        }
        else i++;
    }
}
        
int main(){
    string in;
    while(cin >> in){
        sort(in.begin(), in.end());
        permutation(0, in);
    }
    return 0;
}
