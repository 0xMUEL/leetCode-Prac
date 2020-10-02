#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k];
    }
};