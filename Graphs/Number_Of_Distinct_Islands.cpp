class Solution {
  private:
    void dfs(int row,int col,vector<vector<bool>>& visited,vector<vector<int>>& grid,
    vector<pair<int,int>>& path,pair<int,int>& root){
      
        int n=grid.size(),m=grid[0].size();
        path.push_back({row-root.first,col-root.second});
        visited[row][col]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int r=row+dr[i],c=col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && grid[r][c]){
                dfs(r,c,visited,grid,path,root);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !visited[i][j]){
                    vector<pair<int,int>> path;
                    pair<int,int> root={i,j};
                    dfs(i,j,visited,grid,path,root);
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
};
