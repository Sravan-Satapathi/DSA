class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return -1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        visited[0][0]=true;
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int len=q.front().first;
            q.pop();
            if(row==n-1 && col==n-1) return len;
            for(int i=-1;i<=1;i++){
                int r=row+i;
                for(int j=-1;j<=1;j++){
                    int c=col+j;
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && !visited[r][c]){
                        q.push({len+1,{r,c}});
                        visited[r][c]=true;
                    }
                }
            }
        }
        return -1;
    }
};
