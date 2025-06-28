class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj_list[numCourses];
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        } 
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(auto element:adj_list[node]){
                indegree[element]--;
                if(indegree[element]==0){
                    q.push(element);
                }
            }
        }
        if(result.size()==numCourses){
            return result;
        }
        return {};
    }
};
