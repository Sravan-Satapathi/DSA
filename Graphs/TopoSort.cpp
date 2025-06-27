//Using DFS
class Solution {
  public:
    void dfs(int node,vector<bool>& visited,vector<int> adj_list[],stack<int>& st){
        visited[node]=true;
        for(auto neighbour:adj_list[node]){
            if(!visited[neighbour]){
                dfs(neighbour,visited,adj_list,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj_list[u].push_back(v);
        }
        stack<int> st;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj_list,st);
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};


//Using BFS (Kahn's Algo)
class Solution {
  public:
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            adj_list[u].push_back(v);
        }
        
        vector<int> indegree(V,0);
        for(int node=0;node<V;node++){
            for(int neighbour:adj_list[node]){
                indegree[neighbour]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(int neighbour:adj_list[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return result;
    }
};
