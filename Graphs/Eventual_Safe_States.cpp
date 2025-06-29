//Using BFS (TopoSort)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj_list[n];
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj_list[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node=q.front();
            result.push_back(node);
            q.pop();
            for(int neighbour:adj_list[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};


//Using DFS
class Solution {
public:
    bool dfs(int node,vector<bool>& visited,vector<bool>& pathVisited,vector<int> adj_list[]){
        visited[node]=true;
        pathVisited[node]=true;
        for(int neighbour:adj_list[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour,visited,pathVisited,adj_list)) return true;
            }
            else if(pathVisited[neighbour]) return true;
        }
        pathVisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj_list[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj_list[i].push_back(graph[i][j]);
            }
        }
        vector<bool> visited(n,false),pathVisited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,pathVisited,adj_list);
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
            if(pathVisited[i]==false) result.push_back(i);
        }
        return result;
    }
};
