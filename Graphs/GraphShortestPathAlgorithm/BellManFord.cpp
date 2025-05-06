vector<int> bellmanFord(int v, vector<vector<int>>&edges, int s){
    vector<int> distance(v,1e8);
    distance[s] = 0;
    // relaxinf all the edges
    for(int i = 0; i<v-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];

            if(distance[u] != 1e8 && distance[u] + edgeWeight <distance[v]){
                distance[v] = distance[u] + edgeWeight 
            }

            //nth relaxation to check for negative edge cycle
            for(auto it : edges){
              int u = it[0];
              int v = it[1];
              int edgeWeight = it[2];
              
              if(distance[u] != 1e8 && distance[u] + edgeWeight <distance[v]){
                return{-1};
              }
            }

            return distance;
        }
    }
}