//T.c- O(n), S.C- O(n)
long long countSubarrays(vector<int>& nums, int k) {
       int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
       long long result = 0;
       vector<int> maxIndices;

       for(int i = 0; i < n; i++){
        if(nums[i] == maxElement) maxIndices.push_back(i);
        int size = maxIndices.size();
        if(size >= k){
            int last_i = maxIndices[size-k];
            result += (last_i + 1);
        }
       }
      return result;
    }

//Approach - 2 Sliding Window
//T.C - O(n), S.C - O(1)
 long long countSubarrays(vector<int>& nums, int k) {
       int maxElement = *max_element(nums.begin(), nums.end()), n = nums.size();
       long long result = 0;
       int i = 0, j = 0,  countMax = 0; 

       while(j < n){
        if(nums[j] == maxElement) countMax++;
        while(countMax >= k){
            result += n-j;
            if(nums[i] == maxElement) countMax--; 
            i++;
        }
        j++;
       } 
       return result;

    }
