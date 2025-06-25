class Solution {
private:
    void dfs(int row,int col,vector<vector<char>>& arr,vector<vector<int>>& visited,int n,int m){
        visited[row][col]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int r=row+dr[i],c=col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && arr[r][c]=='O' && !visited[r][c]){
                dfs(r,c,arr,visited,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!visited[0][i] && arr[0][i]=='O'){
                dfs(0,i,arr,visited,n,m);
            }
            if(!visited[n-1][i] && arr[n-1][i]=='O'){
                dfs(n-1,i,arr,visited,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i][0] && arr[i][0]=='O'){
                dfs(i,0,arr,visited,n,m);
            }
            if(!visited[i][m-1] && arr[i][m-1]=='O'){
                dfs(i,m-1,arr,visited,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    arr[i][j]='X';
                }
            }
        }
    }
};
