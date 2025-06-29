class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj_list[n+1];
        vector<int> indegree(n+1,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0];
            int v=relations[i][1];
            adj_list[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<int> months(n+1,0);
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                months[i]=time[i-1];
            }
        }
        int result=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result=max(result,months[node]);
            for(int neighbour:adj_list[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
                months[neighbour]=max(months[neighbour],months[node]+time[neighbour-1]);
            }
        }
        return result;
    }
};
