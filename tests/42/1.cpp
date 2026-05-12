#include <bits/stdc++.h>

int n, m;

bool c_method(std::vector<int>& a, std::vector<int>& b, std::vector<int>& s){
    
};

bool truth(std::vector<int>& a, std::vector<int>& b){
    if (a.size() != b.size()) return false;

    int bm1{}, bm2{};
    for (int i = 0; i < a.size(); i++)
    {
        bm1 = 
    }
    
    
};

signed main(){
    std::cin >> n >> m;
    std::vector<int> s(n);
    std::vector<std::vector<int>>  setsS(m);
    std::vector<std::vector<int>>  setsT(m);

    for(int i = 0; i < n; ++i){
        std::cin >> s[i];
    }

    int size{};
    for(int i = 0; i < m; ++i){
        std::cin >> size;
        while(size--){
            int x;
            std::cin >> x;
            setsS[i].push_back(x);
        }
    }


    for(int i = 0; i < m; ++i){
        std::cin >> size;
        while(size--){
            int x;
            std::cin >> x;
            setsT[i].push_back(x);
        }
    }

    for(int i = 0;i < m; ++i){
        if(c_method(setsS[i], setsT[i], s) == truth(setsS[i], setsT[i]))
        std::cout << "correct" << std::endl;
        else std::cout << "wrong" << std::endl;
    }

    return 0;
}