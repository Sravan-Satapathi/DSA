class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj_list[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj_list[u].push_back({v,w});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,src});
        dist[src]=0;
        int mini=INT_MAX;
        while(!q.empty()){
            int node=q.front().second;
            int stops=q.front().first;
            q.pop();
            if(node==dst) mini=min(mini,dist[node]);
            if(stops==k+1) continue;
            for(auto it:adj_list[node]){
                int neighbour=it.first;
                int weight=it.second;
                if(dist[node]+weight<dist[neighbour] && stops<=k){
                    dist[neighbour]=dist[node]+weight;
                    q.push({stops+1,neighbour});
                }
            }
            
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};
