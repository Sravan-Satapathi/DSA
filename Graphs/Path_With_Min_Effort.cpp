class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            int effort=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row==n-1 && col==m-1){
                return dist[row][col];
            }
            pq.pop();
            for(int i=0;i<4;i++){
                int r=row+dr[i];
                int c=col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m){
                    int cost=max(abs(heights[row][col]-heights[r][c]),effort);
                    if(cost<dist[r][c]){
                        dist[r][c]=cost;
                        pq.push({cost,{r,c}});
                    }
                }
            }
        }
        return -1;
    }
};
