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
    
    
// 	vector<ll> dijkstra(vector<vector<pair<int, ll>>>& adj, int src) {
// 		int n = adj.size();
// 		vector<ll> dist(n, kInf);
// 		dist[src] = 0;
// 		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
// 		// pq contains pairs of <the current distance estimate from src to id, id>
// 		pq.push(make_pair(0, src));
// 		while (!pq.empty()) {
// 			auto [d, cur] = pq.top(); pq.pop();
// 			if (d != dist[cur]) continue;
// 			for (auto [nei, w] : adj[cur]) {
// 				if (dist[nei] > d + w) {
// 					dist[nei] = d + w;
// 					pq.push(make_pair(dist[nei], nei));
// 				}
// 			}
// 		}
// 		return dist;
// 	}
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
       vector<vector<pair<int, ll>>> adj(n);
		vector<vector<pair<int, ll>>> rev(n);  // the graph with reversed edges
		int u, v, w;
		for (auto& e : edges) {
			u = e[0], v = e[1], w = e[2];
			adj[u].push_back(make_pair(v, w));
			rev[v].push_back(make_pair(u, w));
		}
		// Dijkstra
		vector<ll> dist_from_src1 = dijkstra(adj, src1);
		vector<ll> dist_from_src2 = dijkstra(adj, src2);
		vector<ll> dist_to_dest   = dijkstra(rev, dest);
		// find the smallest w[i]
		ll ans = kInf;
		for (int i = 0; i < n; i++) {
			ans = min(ans, dist_from_src1[i] + dist_from_src2[i] + dist_to_dest[i]);
		}
		return ans == kInf ? -1 : ans;
    }
};