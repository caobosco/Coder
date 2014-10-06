#include <vector>

using namespace std;

int main(){
    vector<int> ret(10, 1);
    foreach(auto a in ret)
        printf(++a);
    auto begin = ret.begin();
}
