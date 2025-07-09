//Union Find By Rank
class DisjointSet{
private:
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};


//Union Find By Size
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
