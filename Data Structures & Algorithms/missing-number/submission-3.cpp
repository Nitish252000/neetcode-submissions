class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        // set<int> seen(nums.begin(), nums.end());
        // int n = nums.size();
        // for (int i = 0; i <= n; i++) {
        //     if (!seen.count(i)) {
        //         return i;
        //     }
        // }
        // return -1;
        int n = nums.size();
        int total = n * (n + 1) / 2;
        for (auto& num : nums) {
            total -= num;
        }
        return total;
    }
};
