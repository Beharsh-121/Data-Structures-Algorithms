//Top down
//key.length = M and ring.length = N
//time complexity - o(M^N) without memo
//time complexity - o(M*N*N), space complexity - o(M*N) with memo
int t[101][101];
    int countSteps(int ringIndex, int i, int n){
        int dist = abs(i - ringIndex);
        int wrapAround = n - dist;
        return min(dist, wrapAround);
    }
    int solve(int ringIndex, int keyIndex, string &ring, string &key){
        if(keyIndex == key.length()) return 0;
        if(t[ringIndex][keyIndex] != -1) return t[ringIndex][keyIndex];

        int result = INT_MAX;
        for(int i = 0; i < ring.length(); i++){//extra n for this
            if(ring[i] == key[keyIndex]){
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + solve(i, keyIndex + 1, ring, key);
                result = min(result, totalSteps);
            }
        }
        return t[ringIndex][keyIndex] = result;
    }
    int findRotateSteps(string ring, string key) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, ring, key);
    }
//Bottom UP Approach
//time complexity - O(M*N*N), space complexity - O(M*N); can be furthre optimized for space by taking only one column
int countSteps(int ringIndex, int i, int n){
        int dist = abs(i - ringIndex);
        int wrapAround = n - dist;
        return min(dist, wrapAround);
    }
    int findRotateSteps(string ring, string key) {
       int n = ring.length(), m = key.length();
       
       vector<vector<int>> t(n+1, vector<int>(m+1, INT_MAX));
       for(int ringIndex = 0; ringIndex < n; ringIndex++) t[ringIndex][m] = 0;

       for(int keyIndex = m-1; keyIndex >= 0; keyIndex--){
         for(int ringIndex = 0; ringIndex < n; ringIndex++){

            int result = INT_MAX;
            for(int i = 0; i < n; i++){
                if(ring[i] == key[keyIndex]){
                    int totalSteps = countSteps(ringIndex, i, n) + 1 + t[i][keyIndex+1];
                    result = min(result, totalSteps);
                }
            }
            t[ringIndex][keyIndex] = result;
         }
       }
       return t[0][0];
    }