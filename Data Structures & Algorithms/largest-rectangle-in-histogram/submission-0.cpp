class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0) , right(n,0);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
        int maxarea = 0;
        for(int i = 0;i<n;i++){
            int height = heights[i];
            int leftmax = left[i];
            int rightmax = right[i];
            int width = rightmax-leftmax -1;
            maxarea = max(maxarea,width*height);
            
        }
        return maxarea;
    }
};
