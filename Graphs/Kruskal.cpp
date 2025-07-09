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
    static bool comp(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),comp);
        vector<pair<int,int>> mst;
        int sum=0;
        DisjointSet ds(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            if(ds.findUPar(u)!=ds.findUPar(v)){
                sum+=w;
                mst.push_back({u,v});
                ds.unionBySize(u,v);
            }
        }
        return sum;
    }
};
