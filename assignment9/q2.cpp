#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(vector<vector<int>> &adj, int node, vector<bool> &visited){
    visited[node]=true;
    cout<<node<<" ";
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj,i,visited);
        }
    }
}
int main(){
    int n,m,i,u,v;
    cout<<"enter the number of nodes: ";
    cin>>n;
    cout<<"enter the number of edges: ";
    cin>>m;
    vector<pair<int,int>> edges;
    for(i=0;i<m;i++){
        cout<<"edge "<<i+1<<endl;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<vector<int>> adj(n);
    for(i=0;i<m;i++){
        u=edges[i].first;
        v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"\nadjacency list\n";
    for(i=0;i<n;i++){
        cout<<i<<"->";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    vector<bool> visited(n,false);
    for(i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,i,visited);
        }
    }
}
