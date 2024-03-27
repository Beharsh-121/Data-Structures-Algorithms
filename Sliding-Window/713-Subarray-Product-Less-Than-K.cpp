/********************************************************************** C++ *****************************************************************/
//Approach  : Standard Sliding window Problem
//T.C : O(N)
//S.C : O(1)
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size(), count = 0, i = 0, j = 0, prod = 1;

        while(j < n){
          prod *= nums[j];
            while (prod >= k)  prod /= nums[i++];
            count += (j - i + 1); // Count all subarrays ending at j
            j++;
        }
        return count;
    }