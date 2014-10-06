#include <vector>

using namespace std;
int majority(vector<int> nums) {
    if (nums.size() == 0) return -1;
    int ret = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == ret) count++;
        else if (count > 0) count--;
        else ret = nums[i], count++;
    }
    return ret;
}

int main() {
    }
