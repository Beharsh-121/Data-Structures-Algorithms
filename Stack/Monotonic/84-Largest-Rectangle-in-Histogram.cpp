//Time Complexity- O(N), Space Complexity- O(N)
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), result = 0;
        stack<int> st;
        vector<int> nsr(n, 0), nsl(n, 0);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nsr[i] = n;
            else nsr[i] = st.top();
            st.push(i);
        }
        
        //EMPTY THE STACK
        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int height = heights[i], width = nsr[i] - nsl[i] - 1, area = height*width;
            result = max(area, result);
        }


        return result;
    }