// time complexity - O(n), space complexity - O(n) Approach 1
int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flips = 0, flipCountFromPastFori = 0;
        vector<bool> isFlipped(n, false);

        for(int i = 0; i < n; i++){
            if(i >= k && isFlipped[i-k] == true) flipCountFromPastFori--;
            if(flipCountFromPastFori % 2 == nums[i]){
                if(i + k > n) return -1;
                flipCountFromPastFori++;
                flips++;
                isFlipped[i] = true;
            }
        }
        return flips;
    }

// Approach 2 modify input t.c- O(N), s.c- O(1)
 int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flips = 0, flipCountFromPastFori = 0;

        for(int i = 0; i < n; i++){
            if(i >= k && nums[i-k] == 5) flipCountFromPastFori--;
            if(flipCountFromPastFori % 2 == nums[i]){
                if(i + k > n) return -1;
                flipCountFromPastFori++;
                flips++;
                nums[i] = 5;
            }
        }
        return flips;
    }

//Approach 3 space complexity reduced to - O(k)
int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flips = 0, flipCountFromPastFori = 0;
        deque<int> flipQ;

        for(int i = 0; i < n; i++){
            if(i >= k) {
                flipCountFromPastFori -= flipQ.front();
                flipQ.pop_front();
            }
            if(flipCountFromPastFori % 2 == nums[i]){
                if(i + k > n) return -1;
                flipCountFromPastFori++;
                flips++;
                flipQ.push_back(1);
            }else flipQ.push_back(0);
        }
        return flips;
    }


