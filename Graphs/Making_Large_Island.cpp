class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    int curr=row*n+col;
                    for(int i=0;i<4;i++){
                        int r=row+dr[i],c=col+dc[i];
                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]){
                            int node=r*n+c;
                            if(ds.findUPar(curr)!=ds.findUPar(node)){
                                ds.unionBySize(curr,node);
                            }
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    set<int> s;
                    for(int i=0;i<4;i++){
                        int r=row+dr[i],c=col+dc[i];
                        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]){
                            int node=r*n+c;
                            s.insert(ds.findUPar(node));
                        }
                    }
                    int count=1;
                    for(int neighbour:s){
                        count+=ds.size[neighbour];
                    }
                    maxi=max(maxi,count);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUPar(i)]);
        }
        return maxi;
    }
};
