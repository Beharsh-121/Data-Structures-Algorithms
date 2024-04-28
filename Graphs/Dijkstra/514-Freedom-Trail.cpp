//time complexity - O(m*n*log(m*n)), space complexity - O(m*n); where m = key.length(), n = ring.length()
 int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();
        unordered_map<char, vector<int>> adj;

        for(int i = 0; i < n; i++){
            char ch = ring[i];
            adj[ch].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        set<pair<int, int>> visited;
        int totalSteps = 0;
        while(!pq.empty()){
            vector<int> vec = pq.top();
            pq.pop();
            totalSteps = vec[0];
            int ri = vec[1];
            int ki = vec[2];
            char currChar = key[ki];
            if(ki == m) break;
            if(visited.count({ri, ki})) continue;
            visited.insert({ri, ki});
            for(int &nextIndex : adj[currChar]){
                int steps = countSteps(ri, nextIndex, n) + totalSteps;
                pq.push({steps, nextIndex, ki+1});
            }
        }
        return totalSteps + m;
    }