#include <bits/stdc++.h>

 long long n, m;

bool c_method(std::vector< long long>& a, std::vector< long long>& b, std::vector< long long>& s){
     long long res1{}, res2{};
    for(const auto& num: a){
        res1 ^= s[num];
    }

    for(const auto& num: b){
        res2 ^= s[num];
    }

    return res1 == res2;
};

bool truth(std::vector< long long>& a, std::vector< long long>& b){
    return a == b;
};

signed main(){
    std::cin >> n >> m;
    std::vector< long long> s(n + 1);
    std::vector<std::vector< long long>>  setsS(m);
    std::vector<std::vector< long long>>  setsT(m);

    for( long long i = 1; i <= n; ++i){
        std::cin >> s[i];
    }

     long long size{};
    for( long long i = 0; i < m; ++i){
        std::cin >> size;
        while(size--){
             long long x;
            std::cin >> x;
            setsS[i].push_back(x);
        }
    }


    for( long long i = 0; i < m; ++i){
        std::cin >> size;
        while(size--){
             long long x;
            std::cin >> x;
            setsT[i].push_back(x);
        }
    }

    for( long long i = 0;i < m; ++i){
        if(c_method(setsS[i], setsT[i], s) == truth(setsS[i], setsT[i]))
        std::cout << "correct" << std::endl;
        else std::cout << "wrong" << std::endl;
    }

    return 0;
}