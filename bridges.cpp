const int mxN = 2e5 + 5;
vector<int> dfs_num(mxN, -1), dfs_low(mxN)
vector<int> dfs_parent(mxN, -1), articulation_vertex(mxN);
int dfsNumberCounter, dfsRoot, rootChildren;
// O(V + E)
void find_bridges(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];
    for (int v : adj[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;
            find_bridges(v);
            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            if (dfs_low[v] > dfs_num[u])
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
/*
example 
for (int u = 0; u < V; ++u){
    if (dfs_num[u] == -1) {
        dfsRoot = u; rootChildren = 0;
        articulationPointAndBridge(u);
        articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
    }
}
articulation_vertex[i] checks if i is an articulation point
*/


