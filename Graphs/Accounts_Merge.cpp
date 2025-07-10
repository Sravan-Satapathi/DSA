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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> mpp;
        DisjointSet ds(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string s=accounts[i][j];
                if(mpp.find(s)==mpp.end()){
                    mpp[s]=i;
                }
                else{
                    ds.unionBySize(i,mpp[s]);
                }
            }
        }
        vector<vector<string>> levels(n);
        for(auto it:mpp){
            int ulp=ds.findUPar(it.second);
            levels[ulp].push_back(it.first);
        }
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(levels[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(levels[i].begin(),levels[i].end());
            for(auto it:levels[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};
