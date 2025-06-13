class Solution {
public:
    int length(int node,vector<int> adj_list[],vector<int>& parent,string& s,int& ans){
        if(adj_list[node].size()==0){
            return s[parent[node]]!=s[node];
        }
        int max1=0,max2=0;
        for(int i=0;i<adj_list[node].size();i++){
            int len=length(adj_list[node][i],adj_list,parent,s,ans);
            if(len>=max1){
                max2=max1;
                max1=len;
            }
            else if(len>max2) max2=len;
        }
        ans=max(ans,max1);
        ans=max(ans,1+max1+max2);
        if(parent[node]!=-1 && s[parent[node]]==s[node]) return 0;
        return 1+max1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        if(n==1) return 1;
        vector<int> adj_list[n];
        for(int i=1;i<n;i++){
            int node=parent[i];
            adj_list[node].push_back(i);
        }
        int ans=0;
        length(0,adj_list,parent,s,ans);
        return ans;
    }
};
