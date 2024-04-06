//T.C- O(N), S.C- O(N)
string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        unordered_set<int> remove_idx;

        for(int i = 0; i < n; i++){
           if(s[i] == '(') st.push(i);
           else if(s[i] == ')'){
            if(st.empty()) remove_idx.insert(i);
            else st.pop();
           } 
        }
        while(!st.empty()){
            remove_idx.insert(st.top());
            st.pop();
        }

        string result = "";
        for(int i = 0; i < n; i++){
            if(remove_idx.find(i) == remove_idx.end()) result.push_back(s[i]);
        }

        return result;
    }
//
string minRemoveToMakeValid(string s) {
        int n = s.length(), open = 0;
        string result = "";

        for(int i = 0; i < n; i++){
            if(s[i] >= 'a'  && s[i] <= 'z') result.push_back(s[i]);
            else if(s[i] == '('){
                open++;
                result.push_back(s[i]);
            }else if(open > 0){
                open--;
                result.push_back(s[i]);
            }
        }
        string final_result = "";
        int close = 0;
        for(int i = result.length()-1; i >= 0; i--){
            if(result[i] >= 'a' && result[i] <= 'z') final_result.push_back(result[i]);
            else if(result[i] == ')'){
                close++;
                final_result.push_back(result[i]);
            }else if(close > 0){
                close--;
                final_result.push_back(result[i]);
            }
        }
        reverse(final_result.begin(), final_result.end());
        return final_result;
    }