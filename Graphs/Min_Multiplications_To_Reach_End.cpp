class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(1e5,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,start});
        int mod=1e5;
        while(!q.empty()){
            int node=q.front().second;
            int steps=q.front().first;
            q.pop();
            if(node==end) return steps;
            for(int i=0;i<arr.size();i++){
                long long el=arr[i];
                int neighbour=(node*el)%mod;
                if(steps+1<dist[neighbour]){
                    dist[neighbour]=steps+1;
                    q.push({dist[neighbour],neighbour});
                }
            }
        }
        return -1;
    }
};
