#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=4;
    vector<vector<pair<int,int>>> g(n);
    g[0]={{1,1},{2,4}};
    g[1]={{0,1},{3,2}};
    g[2]={{0,4},{3,3}};
    g[3]={{1,2},{2,3}};

    vector<int> vis(n,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto p=pq.top(); pq.pop();
        int w=p.first, u=p.second;
        if(vis[u]) continue;
        vis[u]=1;
        cout<<u<<" "<<w<<"\n";
        for(auto x:g[u]) pq.push({x.second,x.first});
    }
}
