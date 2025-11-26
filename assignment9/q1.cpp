#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> &adj, int &n, int start){
    queue<int> q;
    q.push(start);
    vector<bool> visited(n,false);
    visited[start]=true;
    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        cout<<frontnode<<" ";
        for(auto i:adj[frontnode]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main(){
    int n,m,u,v;
    cout<<"enter the number of nodes: ";
    cin>>n;
    cout<<"enter the number of edges: ";
    cin>>m;
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        cout<<"edge "<<i+1<<endl;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        u=edges[i].first;
        v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto x:adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    bfs(adj,n,0);

}
