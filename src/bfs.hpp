#pragma once
#include "graph.hpp"
std::vector<int> bfs_dist(const Graph& g, int s){
    std::vector<int> dist(g.n, -1);
    std::queue<int> q; dist[s]=0; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto [v,w]: g.adj[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}
