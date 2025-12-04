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
    stack<char> st;
    unordered_set<char> vis;
    vector<char> order;

    st.push(start);

    while(!st.empty()){
        char u=st.top();
        st.pop();
        if(vis.count(u)) continue;
        vis.insert(u);
        order.push_back(u);
        for(char v:g[u]) st.push(v);
    }

    for(char c:order) cout<<c<<" ";
    cout<<endl;

    return 0;
}
