//Time Complexity - O(m*n*n) Space Complexity - O(N)
vector<int> getNSR(vector<int> &height){
        int n = height.size();
        stack<int> st;
        vector<int> nsr(n, 0);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && height[st.top()] >= height[i]) st.pop();
            if(st.empty()) nsr[i] = n;
            else nsr[i] = st.top();
            st.push(i);
        }

        return nsr;
    }
vector<int> getNSL(vector<int> &height){
        int n = height.size();
        stack<int> st;
        vector<int> nsl(n, 0);

        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] >= height[i]) st.pop();
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top();
            st.push(i);
        }
        return nsl;
    }
int findMaxArea(vector<int> & height){
        int n = height.size(), maxArea = 0;    
        vector<int> nsr = getNSR(height);
        vector<int> nsl = getNSL(height);
        
        for(int i = 0; i < n; i++){
            int wd = nsr[i] - nsl[i] - 1;
            int ht = height[i];

            maxArea = max(maxArea, wd*ht);
        }
        
      return maxArea;
    }
int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n);//O(N)

        for(int i = 0; i < n; i++) height[i] = (matrix[0][i] == '1') ? 1 : 0;
        int maxArea = findMaxArea(height);

        for(int row = 1; row < m; row++){
            for(int col = 0; col < n; col++){
               if(matrix[row][col] == '1') height[col] += 1;
               else height[col] = 0;
            }
            maxArea = max(maxArea, findMaxArea(height));
        }

        return maxArea;
    }