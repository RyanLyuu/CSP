#include <bits/stdc++.h>


signed main(){
    long long n{}, m{}, c{};
    std::cin >> n >> m >> c;
    long long border[n][m];
    long long sum[n][m];
    for (long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < m; j++){
            std::cin >> border[i][j];
        }
    }
    
    for (long long i = 0; i < n; i++)
        for(long long j = 0; j < m; j++)
            sum[i][j] = border[i][j]
                    + (i > 0 ? sum[i-1][j] : 0)
                    + (j > 0 ? sum[i][j-1] : 0)
                    - (i > 0 && j > 0 ? sum[i-1][j-1] : 0);
    
    long long maxV = 0, curV = 0;
    long long x{}, y{};
    for (long long i = 0; i < n - c + 1; i++)
    {
        for (long long j = 0; j < m - c + 1; j++)
        {
            curV = sum[i+c-1][j+c-1];
            if(i > 0) curV -= sum[i-1][j+c-1];
            if(j > 0) curV -= sum[i+c-1][j-1];
            if(i > 0 && j > 0) curV += sum[i-1][j-1];
            if(curV > maxV) {
                maxV = curV;
                x = i;
                y = j;
            }
        }
    }

    std::cout << x + 1 << ' ' << y + 1 << std::endl;

    return 0;
}
