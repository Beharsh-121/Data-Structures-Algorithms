//Top Down ->> Time Complexity = O(N*N) , Space Complexity = O(N*N)
int t[101][101];
    bool solve(int idx, int open, string &s, int n){
        if(idx == n) return open == 0;
        if(t[idx][open] != -1) return t[idx][open];
        bool isValid = false;
        if(s[idx] == '*'){
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);
            if(open > 0) isValid |= solve(idx+1, open-1, s, n);
        }else if(s[idx] == '('){
            isValid |= solve(idx+1, open+1, s, n);
        }else if(open > 0){
            isValid |= solve(idx+1, open-1, s, n);
        }
        return t[idx][open] = isValid;
    }
    bool checkValidString(string s) {
       int n = s.length();
       memset(t, -1, sizeof(t));
       return solve(0, 0, s, n); 
    }
//Bottom UP Approach ->> Time Complexity = O(N*N) , Space Complexity = O(N*N)
bool checkValidString(string s) {
       int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        //State Definition :
        //t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= t[i + 1][open + 1]; //Treating * as ( --> solve(i+1, open+1)
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //Treating * as ) --> solve(i+1, open-1)
                    }
                    isValid |= t[i + 1][open]; //Treating * as empty --> solve(i+1, open)
                } else {
                    if (s[i] == '(') {
                        isValid |= t[i + 1][open + 1]; //solve(i+1, open+1)
                    } else if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //solve(i+1, open=-1)
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
//Time Complexity -> O(N) and Space complexity -> O(N)
bool checkValidString(string s) {
       stack<int> openSt, asteriskSt;
       int n = s.length();

       for(int i = 0; i < n; i++){
        if(s[i] == '(') openSt.push(i);
        else if(s[i] == '*') asteriskSt.push(i);
        else{
            if(!openSt.empty()) openSt.pop();
            else if(!asteriskSt.empty()){
                asteriskSt.pop();
            }else return false;
        }
       }

       while(!openSt.empty() && !asteriskSt.empty()){
        if(openSt.top() > asteriskSt.top()) return false;
        openSt.pop();
        asteriskSt.pop();
       }

       return openSt.empty();
    }
//Time Complexity -> O(N), Space Complexity -> O(1)
bool checkValidString(string s) {
       int n = s.length(), open = 0, close = 0;

       for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '*') open++;
        else open--;
        if(open < 0) return false;
       }

       for(int i = n-1; i >= 0; i--){
        if(s[i] == ')' || s[i] == '*') close++;
        else close--;
        if(close < 0) return false;
       }

       return true;

    }