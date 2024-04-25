//LIS Code time complexity - O(N^2), space complexity - O(N)
int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> t(n, 1);

        int result = 1;

        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(abs(s[i] - s[j]) <= k) t[i] = max(t[i], t[j] + 1);
                result = max(result, t[i]);
            }
        }

        return result;
    }
//Optimal Code time complexity - O(N), space complexity - O(26);
int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> t(26, 0);

        int result = 0;
        
        for(int i = 0; i < n; i++){
            int curr = s[i] - 'a', left = max(0, curr - k), right = min(25, curr + k), longest  = 0;

            for(int j = left; j <= right; j++) longest = max(longest, t[j]);

            t[curr] = max(t[curr] , longest + 1);
            result = max(result, t[curr]);
        }

        return result;
    }