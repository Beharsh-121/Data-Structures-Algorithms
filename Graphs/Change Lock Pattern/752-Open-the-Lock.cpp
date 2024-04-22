//Time Complexity - O(n^w), Space Compelxity - O(n^w) where n =  10 and w = wheels
void getNeighbors(queue<string>& q, string& curr, unordered_set<string>& st){
        for(int i = 0; i < 4; i++){
            char ch = curr[i];

            char dec = ch == '0' ? '9' : ch-1;
            char inc = ch == '9' ? '0' : ch+1;
            
            curr[i] = dec;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = inc;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                q.push(curr);
            }

            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());

        string start = "0000";
        if(st.find(start) != st.end()) return -1;

        queue<string> q;
        q.push(start);

        int level = 0;
        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target) return level;
                
                getNeighbors(q, curr, st);
            }
            level++;
        }
        return -1;
    }