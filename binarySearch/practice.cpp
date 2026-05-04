#include <bits/stdc++.h>

//二分法优化绳子长度

bool check(const std::vector<int>& a, double mid, int k);

signed main(){
    int n{}, k{};
    std::cin >> n >> k;
    std::vector<int> v(n);
    int max_length{};
    for(auto& x : v){
        std::cin >> x;
        if(max_length < x) max_length = x;
    }
    
    double l = 0, r = max_length;
    double mid{};
    for (size_t i = 0; i < 50; i++)
    {
        mid = l + (r - l) / 2;
        if(check(v, mid, k))  l = mid;
        else r = mid;
    }
    
    std::cout << mid << std::endl;

    return 0;
}

bool check(const std::vector<int>& a, double mid, int k){
    int sum{};
    for(auto& x : a){
        sum += (double)x / mid;
    }

    return sum >= k;
    // true k base太小 ， false base太大
}

