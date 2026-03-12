class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

class Solution {
public:
    bool canAchieve(int n, vector<vector<int>>& edges, int k, int x) {
        DSU dsu(n);

        // 1) Mandatory edges must be included
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) {
                if (s < x) return false;          // cannot upgrade mandatory edge
                if (!dsu.unite(u, v)) return false; // mandatory edges form cycle
            }
        }

        // 2) Use all optional edges that already satisfy threshold (cost 0)
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s >= x) {
                dsu.unite(u, v);
            }
        }

        // 3) Use optional edges that need one upgrade (cost 1)
        int upgrades = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s < x && 2 * s >= x) {
                if (dsu.unite(u, v)) {
                    upgrades++;
                    if (upgrades > k) return false;
                }
            }
        }

        // 4) Check if fully connected
        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 1, hi = 0;

        for (auto &e : edges) {
            int s = e[2], must = e[3];
            if (must == 1) hi = max(hi, s);
            else hi = max(hi, 2 * s);
        }

        if (!canAchieve(n, edges, k, 1)) return -1;

        int ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canAchieve(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};