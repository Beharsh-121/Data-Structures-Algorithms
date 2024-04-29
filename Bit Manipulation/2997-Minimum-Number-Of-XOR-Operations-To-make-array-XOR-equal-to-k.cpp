int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;

        for(int &num : nums) totalXor ^= num;//O(n);
        int diff = (totalXor ^ k);
        return __builtin_popcount(diff);//log(n)
    }