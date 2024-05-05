    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), result = 0;
        int l = 0, r = n-1;

        vector<int> power(n);
        power[0] = 1;

        for(int i = 1; i < n; i++) power[i] = (power[i-1]*2) % M;


        while(l <= r){
            if(nums[l] + nums[r] <= target){
               int diff = r - l;
               result = (result % M + power[diff]) % M;
               l++;
            }else r--;
        }
        return result;
    }