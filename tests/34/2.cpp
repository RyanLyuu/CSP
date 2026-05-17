#include <bits/stdc++.h>

int n, m, t;

signed main(){
    std::cin >> n >> m >> t;
    std::vector<int> source(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int pos = i*m + j;
            std::cin >> source[pos];
        }
    }

    int nx = n, ny = m;

    bool tranfered = false;

    for (int i = 0; i < t; i++)
    {
        int o, p1, p2;
        std::cin >> o >> p1 >> p2;
        if(o == 1){
            nx = p1;
            ny = p2;
        }
        if(o == 2){
            tranfered = !tranfered;
        }
        if(o == 3){
            if(!tranfered)
            std::cout << source[p1 * ny + p2] << std::endl;
            else 
            std::cout << source[p2 * ny + p1] << std::endl;
        }
    }
    
    
}