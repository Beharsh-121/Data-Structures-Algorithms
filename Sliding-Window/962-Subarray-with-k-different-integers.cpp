//T.C- O(n), S.C- O(n)
int slidingWindow(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int i = 0, j = 0, n = nums.size(), count = 0;

        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            count+= (j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
//T.c- O(3n) ,S.C - O(n)
int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0, i_bada = 0, result = 0;
        unordered_map<int,int> mp;

        while(j < n){
          mp[nums[j]]++;
          while(mp.size() > k){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
            i_bada = i;
          }
          while(mp[nums[i]] > 1){
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
          }
          if(mp.size() == k) result += (1 + i - i_bada);
          j++;
        }
        return result;
    }