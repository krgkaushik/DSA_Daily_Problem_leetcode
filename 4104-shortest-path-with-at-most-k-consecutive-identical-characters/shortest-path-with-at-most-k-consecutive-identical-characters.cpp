class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // dist[node][consecutive_count] initialized to infinity
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        // Min-heap priority queue storing {cost, node, consecutive_count}
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        // Start at node 0 with consecutive count 1 and weight 0
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Skip outdated states
            if (d > dist[u][cnt]) continue;
            
            // Reached target node
            if (u == n - 1) return d;

            for (const auto& [v, w] : adj[u]) {
                // Determine consecutive label streak for neighbor node v
                int new_cnt = (labels[v] == labels[u]) ? cnt + 1 : 1;

                // Transition if streak satisfies <= k constraint
                if (new_cnt <= k && d + w < dist[v][new_cnt]) {
                    dist[v][new_cnt] = d + w;
                    pq.push({d + w, v, new_cnt});
                }
            }
        }

        return -1;
        
    }
};