 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++)
        dist[i] = 1e9;
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int edw = it[1];
                int n = it[0];
                if(dis+edw<dist[n])
                {
                    dist[n] = dis + edw;
                    pq.push({dist[n],n});
                }
            }
        }
        return dist;
    }
