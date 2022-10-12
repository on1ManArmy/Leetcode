typedef long long ll;
class Solution {
public:
    const ll kInf = 1e18;
    vector<long long> dijkstra(vector<vector<pair<int, long long>>>& g, int src){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int n = g.size();
        vector<ll> cost(n, kInf);
        
        cost[src] = 0;
        pq.push(make_pair(0, src));
        
        while(!pq.empty()){
            
            auto [fromCost, fromNode] = pq.top();
            pq.pop();
            
            if (fromCost != cost[fromNode]) continue;
            
            // vector<pair<long long, int>>:: iterator it;
            for(auto [toNode, toCost]: g[fromNode]){
                if(cost[toNode] > fromCost + toCost){
                    cost[toNode] = fromCost + toCost;
                    pq.push(make_pair(cost[toNode], toNode));
                }
            }
            
        }
        
        return cost;
        
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, ll>>> adj(n);
		vector<vector<pair<int, ll>>> rev(n);  // the graph with reversed edges

		for (auto& e : edges) {
			int u = e[0];
            int v = e[1];
            int w = e[2];
            
			adj[u].push_back(make_pair(v, w));
			rev[v].push_back(make_pair(u, w));
		}
		// Dijkstra
		vector<ll> subGraph1 = dijkstra(adj, src1);
		vector<ll> subGraph2 = dijkstra(adj, src2);
		vector<ll> subGraph3   = dijkstra(rev, dest);
		// find the smallest w[i]
		ll ans = kInf;
		for (int i = 0; i < n; i++) {
			ans = min(ans, subGraph1[i] + subGraph2[i] + subGraph3[i]);
		}
		return ans == kInf ? -1 : ans;
    }
};