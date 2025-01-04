#include <bits/stdc++.h>
using namespace std;

bool checkPath(int src, int dest, int k, int mid, vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> count(n + 1, INT_MAX);
    count[src] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int vertex = pq.top().second;
        int curr_count = pq.top().first;
        pq.pop();
        
        if (vertex == dest) return true;
        if (curr_count > count[vertex]) continue;
        
        for (auto edge : graph[vertex]) {
            int next = edge.first;
            int weight = edge.second;
            int new_count = curr_count + (weight > mid);
            if (new_count < k && new_count < count[next]) {
                count[next] = new_count;
                pq.push({new_count, next});
            }
        }
    }
    return false;
}


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<pair<int, int>>> graph(n + 1);
    int maxWeight = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        maxWeight = max(maxWeight, w);
    }
    
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;
        
        int left = 0, right = maxWeight;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (checkPath(a, b, k, mid, graph, n)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
