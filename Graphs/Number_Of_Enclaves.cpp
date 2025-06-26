class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>> visited(n,vector<int>(m,0));
       queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
           if(!visited[0][i] && grid[0][i]==1){
               visited[0][i]=1;
               q.push({0,i});
           }
           if(!visited[n-1][i] && grid[n-1][i]==1){
               visited[n-1][i]=1;
               q.push({n-1,i});
           }
       } 
       for(int i=0;i<n;i++){
           if(!visited[i][0] && grid[i][0]==1){
               visited[i][0]=1;
               q.push({i,0});
           }
           if(!visited[i][m-1] && grid[i][m-1]==1){
               visited[i][m-1]=1;
               q.push({i,m-1});
           }
       }
       while(!q.empty()){
           int row=q.front().first;
           int col=q.front().second;
           q.pop();
           int dr[]={-1,0,1,0};
           int dc[]={0,-1,0,1};
           for(int i=0;i<4;i++){
                int r=row+dr[i],c=col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && grid[r][c]==1){
                   visited[r][c]=true;
                   q.push({r,c});
                }
            }
        }
       int length=0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!visited[i][j] && grid[i][j]==1){
                   length++;
               }
           }
       }
       return length;
    }
};
