class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        queue<vector<int>> q;
        q.push({0,0,0,0});
        visited[0][0][0]=true;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(!q.empty()){
            vector<int> node=q.front();
            int steps=node[0],obstacles=node[1];
            int row=node[2],col=node[3];
            q.pop();
            if(obstacles>k) continue;
            if(row==m-1 && col==n-1) return steps;
            for(int i=0;i<4;i++){
                int r=row+dr[i],c=col+dc[i];
                if(r>=0 && r<m && c>=0 && c<n){
                    if(grid[r][c]==0 && !visited[r][c][obstacles]){
                        visited[r][c][obstacles]=true;
                        q.push({steps+1,obstacles,r,c});
                    }
                    else if(grid[r][c]==1 && obstacles<k && !visited[r][c][obstacles+1]){
                        visited[r][c][obstacles+1]=true;
                        q.push({steps+1,obstacles+1,r,c});
                    }
                }
            }
        }
        return -1;
    }
};
