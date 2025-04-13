vector<int> ShortestPath(vector<vector<int>> &edges,
int n, int m , int source){
    // edges here represent the pair of edges 
    vector<int> adj[n];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int distance[n];
    for(int i = 0; i<n; i++){
        distance[i] = 1e9;
    }

    distance[source] = 0;

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for( auto it : adj[node]){
            if(distance[node] + 1< distance[it]){
                distance[it] = 1 + distance[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(n,-1);

    for(int i = 0; i<n; i++){
        if(distance[i] != 1e9){
            ans[i] = distance[i];
        }
    }
    return ans;
}