#include <bits/stdc++.h>

struct Window{
    long long ll;
    long long sc;
    Window(long long ll_val): ll{ll_val}, sc{0} {}
};

class QQLog{
private:
    std::list<Window> win_list;
    std::unordered_map<long long, std::list<Window>::iterator> win_map;
    std::set<long long> active_ll;
    long long top_ll = -1;

    std::list<Window>::iterator getTopLayer(){
        if(top_ll == -1) return win_list.begin();
        else return win_map[top_ll];
    }

    void printLog(int opId, const std::string& msg){
        std::cout << "OpId #" << opId << ": " << msg << "." << std::endl;
    }

public:
    void add(int opId, long long ll){
        //查找重复
        if(active_ll.find(ll) != active_ll.end()){
            printLog(opId, "same likeness");
            return;
        }
    
        win_list.emplace_back(ll);
        active_ll.insert(ll);
        win_map[ll] = std::prev(win_list.end());
        printLog(opId, "success");
    }

    void close(int opId, long long ll){
        if(active_ll.find(ll) == active_ll.end()){
            printLog(opId, "invalid likeness");
            return;
        }

        // 若关闭的是置顶窗口，需要清除置顶状态
        if(ll == top_ll) top_ll = -1;
        auto it = win_map[ll];
        const std::string& msg = "close " + std::to_string(ll) = " with" + std::to_string(it->sc);
        win_list.erase(it);
        win_map.erase(ll);
        active_ll.erase(ll);
        printLog(opId, msg);
    }

    void chat(int opId, long long w){
        if(win_list.empty()){
            printLog(opId, "empty");
            return;
        }

        getTopLayer()->sc += w;
        printLog(opId, "success");
    }

    void rotate(int opId, int x){
        if(x > (int)win_list.size() || x < 1){
            printLog(opId, "out of bound");
            return;
        }

        auto it = win_list.begin();
        std::advance(it, x-1); //std::advance移动迭代器
        win_list.splice(win_list.begin(), win_list, it);
        printLog(opId, "success");
    }

    void prior(int opId){
        if(win_list.empty()){
            printLog(opId, "empty");
            return;
        }

        auto max_it = win_list.begin();
        for(auto it = win_list.begin(); it != win_list.end(); ++it){
            if(it->ll > max_it->ll) max_it->ll = it->ll;
        }
        win_list.splice(win_list.begin(), win_list, max_it);
        printLog(opId, "success");
    }

    void choose(int opId, long long u){
        if(active_ll.find(u) == active_ll.end()){
            printLog(opId, "invalid likeness");
            return;
        }

        auto it = win_map[u];
        win_list.splice(win_list.begin(), win_list, it);
        printLog(opId, "success");
    }

        void top(int opId, long long u) {
        if (active_ll.find(u) == active_ll.end()) {
            printLog(opId, "invalid likeness");
            return;
        }
        top_ll = u;
        printLog(opId, "success");
    }

        void untop(int opId) {
            if (top_ll == -1) {
                printLog(opId, "no such person");
                return;
            }
            top_ll = -1;
            printLog(opId, "success");
        }
};