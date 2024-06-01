class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> answer(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]<heights[i]){
                // We can see st.top() from i
                answer[i]++;
                st.pop();
            }
            if(!st.empty()) answer[i]++;
            st.push(i);
        }
        return answer;
    }
};