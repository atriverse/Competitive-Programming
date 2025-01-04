#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll maxVal, minVal;
    Node(ll max_val = LLONG_MIN, ll min_val = LLONG_MAX) : 
        maxVal(max_val), minVal(min_val) {}
};

class SegTree {
    vector<Node> tree;
    int n;
public:
    SegTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n-1, arr);
    }
    
    void build(int node, int start, int end, vector<ll>& arr) {
        if(start == end) {
            tree[node] = Node(arr[start], arr[start]);
            return;
        }
        int mid = (start + end) >> 1;
        build(2*node, start, mid, arr);
        build(2*node+1, mid+1, end, arr);
        tree[node].maxVal = max(tree[2*node].maxVal, tree[2*node+1].maxVal);
        tree[node].minVal = min(tree[2*node].minVal, tree[2*node+1].minVal);
    }
    
    void update(int idx, ll val) {
        updateUtil(1, 0, n-1, idx, val);
    }
    
    Node query(int l, int r) {
        return queryUtil(1, 0, n-1, l, r);
    }
    
private:
    void updateUtil(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node] = Node(val, val);
            return;
        }
        int mid = (start + end) >> 1;
        if(idx <= mid) updateUtil(2*node, start, mid, idx, val);
        else updateUtil(2*node+1, mid+1, end, idx, val);
        tree[node].maxVal = max(tree[2*node].maxVal, tree[2*node+1].maxVal);
        tree[node].minVal = min(tree[2*node].minVal, tree[2*node+1].minVal);
    }
    
    Node queryUtil(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return Node();
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) >> 1;
        Node left = queryUtil(2*node, start, mid, l, r);
        Node right = queryUtil(2*node+1, mid+1, end, l, r);
        return Node(
            max(left.maxVal, right.maxVal),
            min(left.minVal, right.minVal)
        );
    }
};

ll findMaxConvenience(vector<ll>& arr) {
    int n = arr.size();
    SegTree st(arr);
    ll result = LLONG_MIN;
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            Node range = st.query(i, j);
            result = max(result, range.maxVal - range.minVal - (j - i));
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cout << findMaxConvenience(arr) << '\n';
        while(q--) {
            int p, x;
            cin >> p >> x;
            arr[p-1] = x;
            cout << findMaxConvenience(arr) << '\n';
        }
    }
    return 0;
}
