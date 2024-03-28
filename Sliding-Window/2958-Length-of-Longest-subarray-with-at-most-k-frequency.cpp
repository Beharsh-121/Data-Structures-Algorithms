//T.C- O(n), S.C- O(n)
//C++ OMO(on my own)
int maxSubarrayLength(vector<int>& nums, int k) {
        int result = 0, n = nums.size(), i = 0, j = 0;
        unordered_map<int,int> mp;

        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] > k){
                while(mp[nums[j]] > k) mp[nums[i++]]--;
            }
            result = max(result, j-i+1);
            j++;
        }
        return result;
    }
//Culprit Approach without nested Loop
//T.C- O(n), S.C- O(n)
 int maxSubarrayLength(vector<int>& nums, int k) {
        int result = 0, n = nums.size(), i = 0, j = 0, culprit = 0;
        unordered_map<int,int> mp;

        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] == k+1) culprit++;
            if(culprit > 0){
                mp[nums[i]]--;
                if(mp[nums[i]] == k) culprit--;
                i++;
            }
            if(culprit == 0) result = max(result, j-i+1);
            j++;
        }
        return result;
    }