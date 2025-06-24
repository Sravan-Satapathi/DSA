//1.BFS
//Time Complexity: O(V+2E)
//Space Complexity: O(3V)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>n>>m;
    vector<int> adj_list[n+1];
    cout<<"Enter the edges"<<endl;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    //BFS
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<int> bfs;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        bfs.push_back(vertex);
        for(auto element:adj_list[vertex]){
            if(!visited[element]){
                q.push(element);
                visited[element]=true;
            }
        }
    }
    cout<<"BFS: ";
    for(auto element:bfs){
        cout<<element<<" ";
    }
    return 0;
}



//DFS using stack and recursion give different results

//2.DFS(Recursive)
//Time Complexity: O(V+2E)
//Space Complexity: O(V)+O(V)+O(V)

#include<bits/stdc++.h>
using namespace std;
void dfs(int vertex,vector<int> adj_list[],vector<bool>& visited,vector<int>& result){
    visited[vertex]=true;
    result.push_back(vertex);
    for(auto element:adj_list[vertex]){
        if(!visited[element]){
            dfs(element,adj_list,visited,result);
        }
    }
    return;
}
int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>n>>m;
    vector<int> adj_list[n+1];
    cout<<"Enter the edges"<<endl;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    vector<int> result;
    int start=1;
    dfs(start,adj_list,visited,result);
    cout<<"DFS: ";
    for(auto element:result){
        cout<<element<<" ";
    }
    return 0;
}

//DFS(Iterative)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>n>>m;
    vector<int> adj_list[n+1];
    cout<<"Enter the edges"<<endl;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    stack<int> s;
    vector<bool> visited(n+1,false);
    visited[1]=true;
    s.push(1);
    vector<int> dfs;
    //DFS
    while(!s.empty()){
        int vertex=s.top();
        s.pop();
        dfs.push_back(vertex);
        for(auto element:adj_list[vertex]){
            if(!visited[element]){
                visited[element]=true;
                s.push(element);
            }
        }
    }
    cout<<"DFS: ";
    for(auto element:dfs){
        cout<<element<<" ";
    }
    return 0;
}

