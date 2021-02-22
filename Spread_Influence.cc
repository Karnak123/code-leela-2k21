// -*- coding: utf-8 -*-
// Author : Sagnik Mazumder

#include<bits/stdc++.h>
#include<time.h>
using namespace std;

#define ll long long
#define ld long double
#define Fill(s, v) memset(s, v, sizeof(s))

const int MX = 100000;

int n, vis[MX];
vector<pair<int, char>> G[MX];
vector<int> part[3];

bool dfs(int v, int p, char c) {
    if (vis[v] != 0) {
        // returns false if edge needs to be assigned to two different sets
        return vis[v] == p;
    }

    vis[v] = p;
    part[p].push_back(v);

    for (auto x : G[v]) {
        // if edge colour different from assigning colour, change sets
        if (dfs(x.first, x.second == c ? p : p ^ 3, c) == false)
            return false;
    }

    return true;
}

ll solve(char c) {
    Fill(vis, 0);

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (vis[i] == 0) {
            part[1].clear();
            part[2].clear();

            if (dfs(i, 1, c) == false) {
                return (n+1);
            }

            int f = 1;
            if (part[2].size() < part[1].size()) f = 2;

            ans.insert(ans.end(), part[f].begin(), part[f].end());
        }

    return (ll)ans.size();
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin>>u>>v>>c;
        
        --u, --v;
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    ll f = solve('A');
    ll g = solve('B');

    if (g < f) f = g;

    if (f > n) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<f<<endl;
    
    return(0);
}
