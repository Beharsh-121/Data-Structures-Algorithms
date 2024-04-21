//BFS Traversal
bool check(unordered_map<int, vector<int>>& mp, vector<bool>& visited, int source, int destination){
            queue<int> q;
            q.push(source);
            visited[source] = true;

            while(!q.empty()){
               int src = q.front();
               q.pop();
               if(src == destination) return true;
               for(auto &v: mp[src]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
               }
            }
            return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);

        for(vector<int> &edge: edges){
            int src = edge[0], dest = edge[1];
            mp[src].push_back(dest);
            mp[dest].push_back(src);
        }

        return check( mp,  visited, source, destination);
    }
//DFS Traversal
 bool check(unordered_map<int, vector<int>>& mp, vector<bool>& visited, int source, int destination){
            if(source == destination) return true;
            if(visited[source] == true) return false;
            visited[source] = true;

            for(auto &node: mp[source]){
                if(check(mp, visited, node, destination) == true) return true;
            }
            return false;
            
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);

        for(vector<int> &edge: edges){
            int src = edge[0], dest = edge[1];
            mp[src].push_back(dest);
            mp[dest].push_back(src);
        }

        return check( mp,  visited, source, destination);
    }