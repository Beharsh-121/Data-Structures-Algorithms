//Time Complexity -> O(nLogn), Space Complexity -> O(1) excluding result space
 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size(), i = 0, j = 0;
        bool skip = false;
        vector<int> result(n, 0);

        while(i < n){
            if(result[j] == 0 ){
                if(skip == false){
                 result[j] = deck[i];
                 i++;
              }
              skip = !skip;
            }
          j = (j+1)%n;
        }
        return result;
    }
//Time Complexity -> O(n Log n), Space Complexity -> O(n) for queue
vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int>q;
        vector<int> result(n, 0); 
        for(int i = 0; i < n; i++) q.push(i);
        sort(deck.begin(), deck.end());

        for(int i = 0; i < n; i++){
            int idx = q.front();
            q.pop();
            result[idx] = deck[i];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }