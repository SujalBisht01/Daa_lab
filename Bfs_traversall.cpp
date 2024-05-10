#include<bits/stdc++.h>

using namespace std;

void prepareadjlist(unordered_map<int,set<int>>&AdjList ,vector<pair<int,int>> edges){

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        AdjList[u].insert(v);
        AdjList[v].insert(u);
    }
    
} 
void bfs(unordered_map<int, set<int>> &AdjList, unordered_map<int, bool> &visited, vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);

        for(auto i : AdjList[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> BFS(int vertices , vector<pair<int,int>> edges){

    unordered_map<int, set<int>> AdjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareadjlist(AdjList, edges);

    for (int i = 0; i < vertices; i++){
        if(!visited[i]){
            bfs(AdjList, visited, ans, i);
        }
    }
    return ans;
}
int main (){

    int vertices = 5;

    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 6}};

   vector<int> result = BFS(vertices, edges);

   for(auto node : result){
       cout << node << ", ";
   }
} 