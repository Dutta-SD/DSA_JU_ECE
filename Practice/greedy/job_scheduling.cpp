# include <bits/stdc++.h>
# define print(v) {for(auto i : v)cout << i.first << " " << i.second<<" : "; cout << "\n";}
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

int main() {

    // Job Scheduling algorithms
    vector <pair<int, int>> v {{1, 4}, {4, 6}, {2, 5}, {7, 8}};
    vector <pair<int, int>> tasks;

    print(v);

    sort(v.begin(), v.end(), compare);

    print(v);

    tasks.emplace_back(v[0]);

    for(auto i : v){
        if(i.first >= tasks.back().second){
            tasks.emplace_back(i);
        }
    }

    print(tasks);

    return 0;
}