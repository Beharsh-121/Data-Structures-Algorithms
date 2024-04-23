//Brute Force DFS
int dfs(int u, unordered_map<int, vector<int>> &adj, int par){
   int h=0;
   for(int &v:adj[u]){
    if(v!= par ) {
      h=max(h,1+dfs(v,adj,u));
    } 
   }

   return h;
}
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> adj;
        vector<int> inDeg(n,0);
        // 1-> prepare the adjacency list
        for (auto& v : edges) {
            int a = v[0], b = v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            inDeg[a]++;
            inDeg[b]++;
        }
        vector<int> ans;
     if(n==1) return {0};

        int mini = INT_MAX;
        //apply dfs and calculate the height
        for (int i = 0; i < n; i++) {
          
         int h =dfs(i, adj,-1);
           if(h<mini){
            ans.clear();
            ans.push_back(i);
            mini=h;
           }
           else if(h==mini) ans.push_back(i);
        }



        return ans;
    }
};
//Brute Force - BFS
 int solve(int node, vector<bool>&visited,vector<vector<int>>&adj){
        visited[node] = true;
        queue<int> q;
        q.push(node);
        int count = 0;

        while(!q.empty()){
            int size = q.size();
            int vartual = 0;
            while(size--){
                int top = q.front();
                q.pop();
                
                for(auto temp:adj[top]){
                    int a = temp;
                    if(visited[a] == false){
                        visited[a] = true;
                        q.push(a);
                        vartual++;
                    }
                }
            }
            if(vartual>0){
                count++;
            }  
        }
        return count;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(n);
        for(int i = 0; i<n; i++){
            vector<bool> visited(n,false);
            result[i] = solve(i,visited,adj);
        }

        int mini = INT_MAX;

        for(int i = 0; i<n; i++){
            mini = min(mini,result[i]);
        }
        vector<int> ans;
        for(int i = 0; i<result.size(); i++){
            if(result[i] == mini){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//Optimal topological sorting T.c- O(v+e) s.c same as t.c
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n);
        if(n == 1) return {0};
         
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> result;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1) q.push(i);
        }

        while(n > 2){
            int size = q.size();
            n -= size;

            while(size--){
                int u = q.front();
                q.pop();

                for(int &v: adj[u]){
                    indegree[v]--;
                    if(indegree[v] == 1) q.push(v);
                }
            }
        }

        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }