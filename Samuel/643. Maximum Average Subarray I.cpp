#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto size = nums.size();
        if(size == 1){
            return nums[0];
        }
        double sum = 0;
        for(int i = 0; i < k; i++){//initialize the first sum
            sum += nums[i];
        }
        double maxSum = sum;
        for(int i = 0; i < size - k; i++){
            //right shift  k values one step
            sum = sum - nums[i] + nums[i+k];
            //check the new sum
            if(maxSum < sum){
                maxSum = sum;
            }
        }
        return maxSum/k;
    }
};