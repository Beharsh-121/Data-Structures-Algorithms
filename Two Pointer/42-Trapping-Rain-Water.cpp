//Brute-Force T.C - O(N^2)
int trap(vector<int>& height) {
        int count = 0, n = height.size();
        for(int i = 1; i < n-1; i++){
           int currBuilding = height[i], maxLeftBuilding = 0, maxRightBuilding = 0;
           for(int j = i-1; j >= 0; j--) maxLeftBuilding  = max(maxLeftBuilding, height[j]);
           for(int k = i+1; k < n; k++) maxRightBuilding  = max(maxRightBuilding, height[k]);
           int minHeight = min(maxRightBuilding, maxLeftBuilding);
           if(minHeight > currBuilding) count += min(maxRightBuilding, maxLeftBuilding) - currBuilding;          
        }
        return count;
    }
//Better T.C - O(2N), S.C - O(2N)
int trap(vector<int>& height) {
        int count = 0, n = height.size(), curr = height[0];
        vector<int> prefix(n, 0), suffix(n, 0);
        for(int i = 0; i < n; i++){
            curr = max(curr, height[i]);
            prefix[i] = curr;
        }
        curr = height[n-1];
        for(int i = n-1; i >= 0; i--){
            curr = max(curr, height[i]);
            suffix[i] = curr;
        }
        for(int i = 0; i < n; i++){
            int currBuilding = height[i];
            count += min(prefix[i], suffix[i]) - currBuilding;
        }
        return count;
    }
//Optimal T.C - O(N), S.C - O(1)
int trap(vector<int>& height) {
        int water = 0, n = height.size(), left = 0, right = n-1, leftMax = height[0], rightMax = height[n-1];

        while(left <= right){
         if(height[left] <= height[right]){
             if(height[left] > leftMax) leftMax = height[left];
             else water += leftMax - height[left];
             left++;
         }else{
             if(height[right] > rightMax) rightMax = height[right];
             else water += rightMax - height[right];
             right--;
         }
          
        }
        return water;
    }