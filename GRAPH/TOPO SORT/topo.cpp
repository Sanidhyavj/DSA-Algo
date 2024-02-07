
	void dfs(int node,stack<int> &st,vector<int> adj[],int vis[])
	{
	    vis[node] = 1;
	    
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,st,adj,vis);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    stack<int> st;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,st,adj,vis);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
