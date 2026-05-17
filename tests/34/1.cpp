#include <bits/stdc++.h>

int n, m, p, q;

signed main(){
    std::cin >> n >> m >> p >> q;
    std::vector<int> source(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int pos = i*m + j;
            std::cin >> source[pos];
        }
    }
    
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; ++j){
            int pos = i*q + j;
            std::cout << source[pos] << ' ';
        }
        std::cout << '\n';
    }
    
}