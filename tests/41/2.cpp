#include <bits/stdc++.h>

struct task{
    int o;
    double t;
    int a;
    int b;
    double ratio;
};


bool operator > (task a, task b){
    return a.ratio > b.ratio;
}

int main(){
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<task> tasks(n);
    for(int i = 0; i < n; ++i){
        std::cin >> tasks[i].o >> tasks[i].t >> tasks[i].a >> tasks[i].b;
        tasks[i].ratio = (double)tasks[i].b/tasks[i].a;
    }

    std::sort(tasks.begin(), tasks.end(), std::greater<task>());

    for (size_t i = 0; i < n && m > 0; ++i)
    {
        task& t = tasks[i];
        if(t.o == 1){
            //看咖啡够不够分
            if(t.a <= m){
                m -= t.a;
                t.t -= t.b;
            }
            continue;
        }

        while(t.a > 0 && m > 0){
            t.t -= t.ratio;
            m--;
            t.a--;
        }
    }

    double sum{};
    for (int i = 0; i < n; i++)
    {
        sum += tasks[i].t;
    }
    
    std::cout << std::fixed << std::setprecision(6) << sum << std::endl;

    return 0;
}