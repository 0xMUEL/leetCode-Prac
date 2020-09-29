class Solution {
    // public static double findMaxAverage(int[] nums, int k) {
    //     double[] maxs = new double[nums.length - k + 1];
    //     int startWindow = 0;
    //     for(int i = 0; i < k; i++){
    //         maxs[0] += nums[i];
    //     }
    //     double max = maxs[0];
    //     for (int i = 1; i < maxs.length; i++){
    //         maxs[i] = maxs[i-1] - nums[startWindow] + nums[i + k - 1];
    //         startWindow++;
    //         if(maxs[i] > max){
    //             max = maxs[i];
    //         }
    //     }
    //     return max/k;
    // }




    //cumulative sum 
    public static double findMaxAverage(int[] nums, int k) {
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for(int i = 1; i < nums.length; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        double res = sum[k-1] * 1.0 / k;
        for(int i = k; i < sum.length; i++){
            res = Math.max(res, (sum[i] - sum[i-k]) * 1.0 / k);
        }
        return res;
    }
}