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


    for (int i = 0; i < t; i++)
    {
        int o, p1, p2;
        std::cin >> o >> p1 >> p2;
        if(o == 1){
            nx = p1;
            ny = p2;
        }
        if(o == 2){
            std::vector<int> trans(n*m);
            for(int i = 0; i < nx; ++i){
                for(int j = 0; j < ny; ++j){
                    int pos = i*ny + j;
                    trans[j*nx + i] = source[pos];
                }
            }
            std::copy(trans.begin(), trans.end(), source.begin());
            int temp = nx;
            nx = ny;
            ny = temp;
        }
        if(o == 3){
            std::cout << source[p1 * ny + p2] << std::endl;
        }
    }
    
    
}