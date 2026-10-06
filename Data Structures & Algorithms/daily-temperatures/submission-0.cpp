class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>result(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i])st.pop();
            if(st.empty())result[i] = i;
            else result[i] = st.top();
            st.push(i);
        }
        for(int i = 0;i<n;i++){
            result[i] = result[i]-i;
        }
        return result;

    }
};
