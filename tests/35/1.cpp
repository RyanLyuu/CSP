#include <bits/stdc++.h>

int n;

int strenth(const std::string& p){
    std::map<char, int> s{};
    std::set<int> kind{};
    for(char letter : p){
        s[letter] += 1;
        if('A' <= letter && letter <= 'Z' || 'a' <= letter && letter <= 'z') kind.insert(1);
        else if('0' <= letter && letter <= '9') kind.insert(2);
        else kind.insert(3);
    }
    if(kind.size() == 3 && std::find_if(s.begin(), s.end(), [](std::pair<char, int> a){return a.second > 2;}) == s.end()) return 2;
    else if(kind.size() == 3) return 1;
    else return 0;
}

signed main(){
    std::cin >> n;
    std::vector<std::string> strs(n);
    std::getchar();
    for (int i = 0; i < n; i++)
    {   
        std::getline(std::cin, strs[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << strenth(strs[i]) << std::endl;
    }
    
}