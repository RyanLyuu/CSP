#include <bits/stdc++.h>

int n;
double a;

bool inside(std::pair<double, double> crd, double a){
    return a * a >= pow(crd.first, 2) + pow(crd.second, 2);
}

signed main(){
    std::cin >> n >> a;
    std::vector<std::pair<double, double>> crd(n);
    for(int i = 0; i < n; ++i){
        std::cin >> crd[i].first >> crd[i].second;
    }

    int cnt{};
    for(int i = 0; i < n; ++i){
        if(inside(crd[i], a)) cnt++;
    }

    std::cout << std::fixed << std::setprecision(6) << 4*(double)cnt/n;

    return 0;
}