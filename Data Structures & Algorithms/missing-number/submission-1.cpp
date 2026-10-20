class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        set<int> seen(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (!seen.count(i)) {
                return i;
            }
        }
        return -1;
    }
};
