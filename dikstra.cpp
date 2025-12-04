#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, vector<pair<int,int>>> g;
    g[0]={{1,1},{2,4}};
    g[1]={{2,2},{3,5}};
    g[2]={{3,1}};
    g[3]={};

    vector<int> d(4,1e9);
    d[0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto p=pq.top(); pq.pop();
        int dist=p.first, u=p.second;
        if(dist!=d[u]) continue;
        for(auto x:g[u]){
            int v=x.first, w=x.second;
            if(d[u]+w < d[v]){
                d[v]=d[u]+w;
                pq.push({d[v],v});
            }
        }
    }

    for(int i=0;i<4;i++) cout<<i<<" "<<d[i]<<"\n";
}
