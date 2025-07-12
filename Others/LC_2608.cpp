class Solution {
private:
    void bfs(int node,vector<int> adj_list[],vector<bool>& visited,vector<int>& dist,int& mini){
        queue<pair<int,int>> q;
        q.push({node,-1});
        visited[node]=true;
        dist[node]=0;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int neighbour:adj_list[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push({neighbour,node});
                    dist[neighbour]=dist[node]+1;
                }
                else if(neighbour!=parent){
                    mini=min(mini,dist[neighbour]+dist[node]+1);
                }
            }
        }
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj_list[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int mini=1e8;
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            vector<int> dist(n,0);
            bfs(i,adj_list,visited,dist,mini);
        }
        if(mini==1e8) return -1;
        return mini;
    }
};
