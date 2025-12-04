//bfs
#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char, vector<char>> g;
    g['A']={'B','C'};
    g['B']={'A','D','E'};
    g['C']={'A','F'};
    g['D']={'B'};
    g['E']={'B','F'};
    g['F']={'C','E'};
    char start='A';
    queue<char> q;
    unordered_set<char> vis;
    vector<char> order;
    q.push(start);
    vis.insert(start);
    while(!q.empty()){
        char u=q.front(); q.pop();
        order.push_back(u);
        for(char v:g[u]){
            if(!vis.count(v)){
                vis.insert(v);
                q.push(v);
            }
        }
    }
    for(char c:order) cout<<c<<' ';
    cout<<'\n';
    return 0;
}
