//Using DFS
class Solution {
  public:
    bool dfs(int node,int parent,vector<bool>& visited,vector<int> adj_list[]){
        visited[node]=true;
        for(auto neighbour:adj_list[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,node,visited,adj_list)) return true;
            }
            else{
                if(neighbour!=parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,adj_list)) return true;
            }
        }
        return false;
    }
};



//Using BFS
class Solution {
  public:
    bool bfs(int node,vector<bool>& visited,vector<int> adj_list[]){
        queue<pair<int,int>> q;
        q.push({node,-1});
        visited[node]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto neighbour:adj_list[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push({neighbour,node});
                }
                else if(neighbour!=parent) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,visited,adj_list)) return true;
            }
        }
        return false;
    }
};
