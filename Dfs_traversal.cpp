#include<bits/stdc++.h>

using namespace std;

void prepareAdjList( unordered_map<int, set<int>> &AdjList,vector<pair<int,int>> edges){

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        AdjList[u].insert(v);
        AdjList[v].insert(u);
    }
    
}

void bfs( unordered_map<int, set<int>> &AdjList, unordered_map<int, bool> &visited, vector<int> &ans,int node){

    stack<int> s;
    s.push(node);
    visited[node] = true;

    while(!s.empty()){

        int frontnode = s.top();
        s.pop();

        ans.push_back(frontnode);

        for(auto i : AdjList[frontnode]){
            if(!visited[i]){
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> DFS(int vertex  ,vector<pair<int,int>> edges){

    unordered_map<int, set<int>> AdjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(AdjList, edges);

    for (int  i = 0; i < vertex; i++)
    {
        if(!visited[i]){
            bfs(AdjList, visited, ans, i);
        }
    }
    return ans;
}
int main (){

    int vertex = 5;

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};
    vector<int> result = DFS(vertex, edges);

    for(auto node : result){
        cout << node << ", ";
    }
}