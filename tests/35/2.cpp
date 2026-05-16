#include <bits/stdc++.h>

std::string source;
int n;                                // 映射个数
int m;                                // 查询个数
std::vector<std::string> cache(1001); // 缓存
std::vector<int> last(1001);   // i位置上一个有效缓存位置
std::map<char, char> f;


void unwrap(const std::string& src){
    f.insert({src[1], src[2]});
}

signed main(){
    std::getline(std::cin, source);
    source = source.substr(1, source.size());
    cache[0] = source;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::getline(std::cin, str);
        unwrap(str);
    }
    std::cin >> m;
    std::vector<int> qs(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> qs[i];
    }


    for (int i = 0; i < m; i++)
    {
        // 执行j次transform
        for (int j = qs[i] - last[i]; j > 0; j--)
        {
            std::string initial = cache[last[qs[i]]];
            // transform
            for(char& letter: initial){
                if(f.find(letter) != f.end()) letter = f[letter];
            }
            //更新cache
            cache[qs[i]] = initial;
            //更新last数组
            int pos = qs[i];
            for(pos; (pos < m && !cache[pos+1].empty()); pos++){
                last[pos] = pos;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        std::cout << '#' << cache[qs[i]] << '#' << std::endl;
    }
    

}