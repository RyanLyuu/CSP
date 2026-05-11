#include <bits/stdc++.h>

struct Block{
    bool e;
    bool x; 
    Block(): e{false}, x{false} {}
};

struct Interface{
    int id;
    int length;
    std::list<Block> queue;
    Interface(int id, int length): id{id}, length{length} {}
};

struct Process{
    int id;
    std::vector<Interface> ifs;
    Process(int id): id{id}, ifs{} {}
};

class MyOs{
private:
    std::vector<Block> cache;

};