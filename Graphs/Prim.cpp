class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj_list[]) {
        // code here
        vector<bool> visited(V,false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //weight,node,parent
        pq.push({0,{0,-1}});
        int sum=0;
        vector<pair<int,int>> mst;
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second.first;
            int parent=pq.top().second.second;
            pq.pop();
            if(visited[node]) continue;
            visited[node]=true;
            sum+=weight;
            if(parent!=-1){
                mst.push_back({node,parent});
            }
            for(auto element:adj_list[node]){
                int neighbour=element[0];
                int wt=element[1];
                if(!visited[neighbour]){
                    pq.push({wt,{neighbour,node}});
                }
            }
        }
        return sum;
    }
};
