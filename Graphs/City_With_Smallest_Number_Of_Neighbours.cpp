class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            mat[edges[i][0]][edges[i][1]]=edges[i][2];
            mat[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX){
                        continue;
                    }
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int node=-1,min_val=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold && i!=j){
                    count++;
                }
            }
            if(count<=min_val){
                min_val=count;
                node=i;
            }
        }
        return node;
    }
};
