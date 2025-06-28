class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; 
        vector<int> adj_list[n];
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            indegree[u]++,indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }
        while(!q.empty()){
            int len=q.size();
            if(n<=2) break;
            for(int i=0;i<len;i++){
                int node=q.front();
                q.pop();
                n--;
                for(int neighbour:adj_list[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==1) q.push(neighbour);
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
