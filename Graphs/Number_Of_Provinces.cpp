class Solution {
public:
    void dfs(int node,int n,vector<bool>& visited,vector<vector<int>>& isConnected){
        visited[node]=true;
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[node][i]){
                dfs(i,n,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        int n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                dfs(i,n,visited,isConnected);
            }
        }
        return provinces;
    }
};
