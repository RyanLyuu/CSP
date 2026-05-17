#include <bits/stdc++.h>
using namespace std;

// 总共63种字符
const int LOG = 63;
const int N = 256;

int up[LOG][N];

string source;
int n;
int m;
long long k;

void build(){
    for(int i = 1; i < LOG; ++i){
        for(int x = 0; x < N; ++x){
            up[i][x] = up[i - 1][up[i-1][x]];
        }
    }
}

int jump(int x, long long k){
    for(int i = 0; i < LOG; ++i){
        if(k & (1LL << i)){
            x = up[i][x];
        }
    }
    return x;
}

signed main(){
    getline(cin, source);
    cin >> n;
    cin.ignore();
    // 初始化默认映射
    for(int i = 0; i < N; ++i){
        up[0][i] = i; 
    }
    // 读映射，填表
    for(int i = 0; i < n; ++i){
        string str;
        getline(cin, str);
        up[0][(int)str[1]] = (int)str[2];
    }

    build(); // 建表
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        string s = source;
        for(char& letter : s){
            if(letter == '#') continue;
            letter = (char)jump(letter, k);
        }

        cout << s << std::endl;
    }
    
    
}