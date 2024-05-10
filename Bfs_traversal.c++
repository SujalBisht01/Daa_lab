#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        // Adding edges to the adjacency list for an undirected graph
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true; // Corrected assignment
    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();

        // Store frontnode into ans
        ans.push_back(frontnode);

        // Traverse all neighbors of frontnode
        for (auto i : adjList[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {                                                                                                                                                  
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans; // Added return statement
}
 
int main() {
    // Example usage:
    int vertices = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3},{1,6},
     {2, 4}};
    vector<int> result = BFS(vertices, edges);

    // Output the result
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

// Function to prepare the adjacency list from the given edges
void prepareAdjList(unordered_map<int, unordered_set<int>>& adjList, const vector<pair<int, int>>& edges) {
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adjList[u].insert(v);
        adjList[v].insert(u); // For undirected graph
    }
}

// Depth-First Search traversal
void dfs(unordered_map<int, unordered_set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& result, int node) {
    stack<int> st;
    st.push(node);
    visited[node] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();
        result.push_back(current);

        // Traverse all neighbors of the current node
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// DFS traversal for disconnected graphs
vector<int> DFS(int vertices, const vector<pair<int, int>>& edges) {
    unordered_map<int, unordered_set<int>> adjList;
    unordered_map<int, bool> visited;
    vector<int> result;

    prepareAdjList(adjList, edges);

    // Traverse all components of the graph
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            dfs(adjList, visited, result, i);
        }
    }

    return result;
}

int main() {
    int vertices = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 5}, {5, 6}};

    vector<int> result = DFS(vertices, edges);

    // Output the DFS traversal result
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
