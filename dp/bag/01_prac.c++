#include <bits/stdc++.h>

long long n, m;

signed main(){
    std::cin >> n >> m;
    std::vector<long long> o(n);
    std::vector<double> t(n);
    std::vector<long long> a(n);
    std::vector<double> b(n);
    double sum{};
    for (long long i = 0; i < n; i++)
    {
        std::cin >> o[i] >> t[i] >> a[i] >> b[i];
        sum += t[i];
    }
    
    // 01背包，总容量为m, 重量为a或1, 质量为b或b/a
    for (long long i = 0; i < n; i++)
    {
        if(o[i] == 0){
            double res = b[i]/a[i];
            for(long long j = 0; j < a[i]; ++j) {
                b.push_back(res);
                a.push_back(1);
            }
            
            b[i] = 0;
        }
    }
    
    std::vector<double> f(m + 1);

    for(long long i = 0; i < a.size(); ++i){
        for(long long j = m; j >= a[i]; --j){
            f[j] = std::max(f[j], f[j - a[i]] + b[i]);
        }
    }

    std::cout << std::fixed << std::setprecision(6) << sum - f[m] << std::endl;

    return 0;
}