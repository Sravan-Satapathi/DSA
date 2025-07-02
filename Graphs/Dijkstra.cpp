// Dijkstra's Algorithm
//Time Complexity - O(ElogV)

//Using Priority Queue
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj_list[u].push_back({v,w});
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj_list[node]){
                int neighbour=it.first;
                int weight=it.second;
                if(dist[node]+weight<dist[neighbour]){
                    dist[neighbour]=dist[node]+weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist;
    }
};


//Using Set
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj_list[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj_list[u].push_back({v,w});
        }
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert({0,src});
        while(!s.empty()){
            pair<int,int> p=*(s.begin());
            int node=p.second;
            s.erase(p);
            for(auto it:adj_list[node]){
                int neighbour=it.first;
                int weight=it.second;
                if(dist[node]+weight<dist[neighbour]){
                    s.erase({dist[neighbour],neighbour});
                    dist[neighbour]=dist[node]+weight;
                    s.insert({dist[neighbour],neighbour});
                }
            }
        }
        return dist;
    }
};
