class Solution {
  public:
    vector<int> toposort(int& V,vector<pair<int,int>> adj_list[],vector<int>& indegree){
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(auto it:adj_list[node]){
                int neighbour=it.first;
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        return order;
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj_list[V];
        vector<int> indegree(V,0);
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            adj_list[u].push_back({v,weight});
            indegree[v]++;
        }
        vector<int> order=toposort(V,adj_list,indegree);
        vector<int> dist(V,1e9);
        dist[0]=0;
        for(int i=0;i<order.size();i++){
            int node=order[i];
            for(auto it:adj_list[node]){
                int neighbour=it.first;
                int weight=it.second;
                if(dist[node]+weight<dist[neighbour]){
                    dist[neighbour]=dist[node]+weight;
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};
