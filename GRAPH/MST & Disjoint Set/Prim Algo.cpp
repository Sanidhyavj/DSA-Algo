 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
        vector<int> vis(V,0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt  = it.first;
            int node = it.second;
            
            if(vis[node]==1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto i:adj[node])
            {
                int edw = i[1];
                int adjj = i[0];
                if(!vis[adjj])
                pq.push({edw,adjj});
            }
        }
        return sum;
    }
