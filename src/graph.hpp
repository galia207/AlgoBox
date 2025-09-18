#pragma once
#include <bits/stdc++.h>
struct Graph {
    int n;
    bool directed;
    std::vector<std::vector<std::pair<int,int>>> adj; // (to, weight)
    Graph(int n, bool directed=false): n(n), directed(directed), adj(n) {}
    void add_edge(int u, int v, int w=1){
        adj[u].push_back({v,w});
        if(!directed) adj[v].push_back({u,w});
    }
};
