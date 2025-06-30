class Solution {
private:
	vector<int> topoSort(int V, vector<int> adj_list[],vector<int>& order){
    vector<int> indegree(V,0);
		for(int node=0;node<V;node++){
			for(int neighbour:adj_list[node]){
				indegree[neighbour]++;
			}
		}
		queue<int> q;
		for (int i=0;i<V;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		while(!q.empty()){
			int node=q.front();
			q.pop();
			order.push_back(node);
			for(int neighbour:adj[node]){
				indegree[neighbour]--;
				if(indegree[neighbour]==0) q.push(neighbour);
			}
		}
	}
public:
	string findOrder(string dict[], int N, int K){
		vector<int>adj_list[K];
		for(int i=0;i<N-1;i++){
			string s1=dict[i];
			string s2=dict[i+1];
			int len=min(s1.size(),s2.size());
			for(int ind=0;ind<len;ind++){
				if (s1[ind]!=s2[ind]){
					adj[s1[ind]-'a'].push_back(s2[ind]-'a');
					break;
				}
			}
		}
    vector<int> order;
		topoSort(K,adj,order);
		string ans="";
		for (auto it:order) {
			result=result+char(it+'a');
		}
		return result;
	}
};
