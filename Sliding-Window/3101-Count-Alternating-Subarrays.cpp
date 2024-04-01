//T.c- O(N), s.c-O(1) OMO
long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = 0, n = nums.size();

        while(j < n){
            if(j != 0 and nums[j] == nums[j-1]) i = j;
            ans += j-i+1;
            j++;
        }

        return ans;
    }

//T.c- O(N), s.c-O(1)
long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size(), j = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
           j = i;
           while(j+1 < n and nums[j] != nums[j+1]) j++;
           int len = j-i+1;
           ans += (long long)len*(len+1)/2;
           i = j;
        }
        return ans;
    }