#include <bits/stdc++.h>
using namespace std;

int f[100];

int findp(int x){
    if(f[x] == x) return x;
    return f[x] = findp(f[x]);
}

int main(){
    int n = 4;

    vector<tuple<int,int,int>> edges;
    edges.push_back({1,0,1});
    edges.push_back({3,1,2});
    edges.push_back({2,1,3});
    edges.push_back({4,2,3});

    for(int i=0;i<n;i++) f[i] = i;

    sort(edges.begin(), edges.end());

    for(int i=0;i<edges.size();i++){
        int w = get<0>(edges[i]);
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);

        int a = findp(u);
        int b = findp(v);

        if(a != b){
            f[a] = b;
            cout << u << " " << v << " " << w << "\n";
        }
    }
}
