#pragma once
#include "graph.hpp"
std::vector<long long> dijkstra(const Graph& g, int s){
    const long long INF = (1LL<<60);
    std::vector<long long> dist(g.n, INF);
    using P = std::pair<long long,int>; // (dist,node)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    dist[s]=0; pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]: g.adj[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
