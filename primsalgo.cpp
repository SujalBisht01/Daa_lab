
#include<bits/stdc++.h>

using namespace std;

pair<vector<pair<pair<int,int>,int>>, int> calculatePrimeMST(int n , int m ,vector <pair<pair<int,int>,int>> &g ){

    unordered_map < int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    int totalWeight = 0; // To store the total sum of minimum weights

    for (int i = 0; i <=n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n; i++){

        int mini = INT_MAX;
        int u;

        for (int  v = 0; v <= n ; v++)
        {
          if(mst[v]==false&&key[v]<mini){
              u = v;
              mini = key[v];
          }    
        }

        mst[u] = true;

        for(auto it : adj[u]){

            int v = it.first;
            int w = it.second;

            if(mst[v]==false && w< key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 1; i <= n; i++){
        if (parent[i] != -1) {
            result.push_back(make_pair(make_pair(parent[i], i), key[i]));
            totalWeight += key[i]; // Add minimum weights to the total sum
        }
    }

    return {result, totalWeight};
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<pair<int,int>,int>> edges;
    cout << "Enter the edges in format (source, destination, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }

    pair<vector<pair<pair<int,int>,int>>, int> result = calculatePrimeMST(n, m, edges);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for(auto edge : result.first) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }
    cout << "Total weight of Minimum Spanning Tree: " << result.second << endl;

    return 0;
}
