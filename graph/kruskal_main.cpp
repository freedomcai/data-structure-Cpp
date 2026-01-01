#include <iostream>
#include <climits>
#include <vector>
#include "kruskal.h"

int main()
{
    int n, m;
    std::cin >> n >> m;
    int s, t, val;
    std::vector<Edge> edges;
    while(m--){
        std::cin >> s >> t >> val;
        edges.push_back({s, t, val});
    }
    
    int res = 0;

    kruskal(n+1, res, edges);

    std::cout << res << std::endl;
}



