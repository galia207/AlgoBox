#include <bits/stdc++.h>
#include "graph.hpp"
#include "bfs.hpp"
#include "dijkstra.hpp"
using namespace std;

template<class T>
void print_dist(const vector<T>& d){
    for(size_t i=0;i<d.size();++i){
        cout << "dist["<<i<<"] = ";
        if constexpr (std::is_integral<T>::value)
            cout << d[i] << "\n";
        else
            cout << d[i] << "\n";
    }
}

int main(){
    Graph g(6, false);
    g.add_edge(0,1,4);
    g.add_edge(0,2,2);
    g.add_edge(1,2,1);
    g.add_edge(1,3,5);
    g.add_edge(2,3,8);
    g.add_edge(2,4,10);
    g.add_edge(3,5,2);
    g.add_edge(4,5,3);

    cout << "AlgoBox - Graph Algorithms\n";
    cout << "1) BFS (unweighted)\n2) Dijkstra (positive weights)\n";
    cout << "Choose [1/2]: ";
    int choice; if(!(cin>>choice)) return 0;
    cout << "Source node [0..5]: ";
    int s; if(!(cin>>s)) return 0;

    if(choice==1){
        auto d = bfs_dist(g, s);
        cout << "\nBFS hop distances from "<<s<<":\n";
        print_dist(d);
    } else {
        auto d = dijkstra(g, s);
        cout << "\nDijkstra distances from "<<s<<":\n";
        for(size_t i=0;i<d.size();++i){
            cout << "dist["<<i<<"] = " << (d[i] >= (1LL<<59) ? -1 : d[i]) << "\n";
        }
    }
    return 0;
}
