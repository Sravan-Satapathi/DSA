class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int tot_fresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    tot_fresh++;
                }
            }
        }
        vector<vector<int>> result=grid;
        int time=0;
        int count_fresh=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=row-1;i<=row+1;i++){
                if(i>=0 && i<n && grid[i][col]==1 && result[i][col]!=2){
                    q.push({{i,col},t+1});
                    count_fresh++;
                    result[i][col]=2;
                }
            }
            for(int i=col-1;i<=col+1;i++){
                if(i>=0 && i<m && grid[row][i]==1 && result[row][i]!=2){
                    q.push({{row,i},t+1});
                    count_fresh++;
                    result[row][i]=2;
                }
            }
        }
        if(tot_fresh!=count_fresh){
            return -1;
        }
        return time;
    }
};
