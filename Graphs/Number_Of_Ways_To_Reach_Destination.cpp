class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pair<long long,long long>> adj_list[n];
        for(int i=0; i<roads.size(); i++){
            long long u = roads[i][0];
            long long v = roads[i][1];
            long long w = roads[i][2];
            adj_list[u].push_back({v,w});
            adj_list[v].push_back({u,w});
        }

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,0});

        vector<long long> dist(n,1e18);
        vector<long long> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long node = pq.top().second;
            long long weight = pq.top().first;
            pq.pop();

            for(auto it : adj_list[node]){
                long long neighbour = it.first;
                long long distance = it.second;
                if(weight+distance<dist[neighbour]){
                    dist[neighbour] = weight+distance;
                    ways[neighbour] = ways[node]%mod;
                    pq.push({dist[neighbour],neighbour});
                }
                else if(weight+distance==dist[neighbour]){
                    ways[neighbour] = (ways[neighbour]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
