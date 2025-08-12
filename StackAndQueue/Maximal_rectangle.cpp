class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int curr=st.top();
                st.pop();
                int nse=i;
                int pse=(st.empty()?-1:st.top());
                maxArea=max(maxArea,heights[curr]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            int nse=n;
            int pse=(st.empty()?-1:st.top());
            maxArea=max(maxArea,heights[curr]*(nse-pse-1));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='0') sum=0;
                else sum+=1;
                prefix[i][j]=sum;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int area=largestRectangleArea(prefix[i]);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
