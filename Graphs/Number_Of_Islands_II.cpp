class DisjointSet{
private:
    vector<int> parent,size;
public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<int> result;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int count=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<operators.size();i++){
            int row=operators[i][0],col=operators[i][1];
            if(visited[row][col]){
                result.push_back(count);
                continue;
            }
            visited[row][col]=true;
            count++;
            int curr=row*m+col;
            for(int i=0;i<4;i++){
                int r=row+dr[i],c=col+dc[i];
                if(r>=0 && r<n && c>=0 && c<m && visited[r][c]){
                    int node=r*m+c;
                    if(ds.findUPar(node)!=ds.findUPar(curr)){
                        ds.unionBySize(curr,node);
                        count--;
                    }
                }
            }
            result.push_back(count);
        }
        return result;
    }
};
