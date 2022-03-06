#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <list>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        a--;
        b--;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int parent[N];

    int key[N];

    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    set<pair<int, int>> st;
    key[0] = 0;
    parent[0] = -1;
    st.insert({0, 0});
    while (!st.empty())
    {
        auto it = *st.begin();
        int u = it.second;
        st.erase(st.begin());
        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                st.insert({key[v], v});
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}