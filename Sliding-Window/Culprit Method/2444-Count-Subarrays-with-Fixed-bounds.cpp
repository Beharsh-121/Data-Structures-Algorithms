//T.C- O(n), S.C- O(1)
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), minkPosition = -1, maxkPosition = -1, culpritIdx = -1;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK) culpritIdx = i;
            if(nums[i] == minK) minkPosition = i;
            if(nums[i] == maxK) maxkPosition = i;
            long long smaller = min(minkPosition, maxkPosition);
            long long temp = smaller - culpritIdx;
            ans += (temp <= 0) ? 0 : temp;
        }
        return ans;
    }