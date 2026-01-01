#include <iostream>
#include <climits>
#include <vector>

#include "bellman_ford.h"
 
int main()
{
    int n, m;
    int s, t, val;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid;
    while(m--){
        std::cin >> s >> t >> val;
        grid.push_back({s, t, val});
    }
 
    int start = 1, end = n;
    std::vector<int> minDist(n+1, INT_MAX);
    minDist[start] = 0;
    bool flag = false;

    bellman_ford(n, flag, grid, minDist);
 
    if(flag) std::cout << "circle" << std::endl;
    else if(minDist[end] == INT_MAX) std::cout << "unconnected" << std::endl;
    else std::cout << minDist[end] << std::endl;
}

