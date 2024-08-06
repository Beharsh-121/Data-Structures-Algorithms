    typedef pair<int, int> P;
    int M = 1e9 + 7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int result = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for(int i = 0; i < n; i++) pq.push({nums[i], i});

        for(int count = 1; count <= right; count++){
            auto [sum, index]  = pq.top();
            pq.pop();

            if(count >= left) result = (result + sum) % M;
            
            int new_idx = index + 1;
            P new_pair;
            if(new_idx < n){
                new_pair.first = sum + nums[new_idx];
                new_pair.second = new_idx;
                pq.push(new_pair);
            }

        }

      return result;
    }