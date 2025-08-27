#ifndef MY_BOILERPLATE_H
#define MY_BOILERPLATE_H

// Standard C headers
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++ standard library headers
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
typedef unsigned long long ull;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define maxe(v) (*max_element(all(v)))
#define mine(v) (*min_element(all(v)))
#define sumv(v) (accumulate(all(v), 0LL))
#define sortasc(v) sort(all(v))
#define sortdesc(v) sort(rall(v))
#define lb(v, x) (lower_bound(all(v), x) - (v).begin())
#define ub(v, x) (upper_bound(all(v), x) - (v).begin())
#define ispresent(v, x) (binary_search(all(v), x))
#define freqmap(mp, v) for (auto &el : v) mp[el]++
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repr(i, a, b) for (int i = (a); i >= (b); --i)
#define ff first
#define ss second

ll ceil_division(ll a, ll b) {
    return (a + b - 1) / b;
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// ---------- DSU (Disjoint Set Union) ----------
vector<int> parent, rnk;

void makeset(int n) {
    parent.resize(n);
    rnk.resize(n, 0);
    rep(i, 0, n) parent[i] = i;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]); // Path compression
}

void unions(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rnk[px] > rnk[py]) parent[py] = px;
    else if (rnk[px] < rnk[py]) parent[px] = py;
    else { parent[px] = py; rnk[py]++; }
}
// ---------------------------------------------

void input(vi &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cin >> v[i];
    }
}

void input(vll &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cin >> v[i];
    }
}

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void line() { cout << "\n"; }
void dfs(int node,int &no,int &edges,vvi&adj,vi&vis){
    vis[node]=1;
    no++;
    edges+=adj[node].size();
    for(int v:adj[node]){
        if(vis[v]!=1) dfs(v,no,edges,adj,vis);
    }

}
void aditi() {
    // Your problem-solving logic goes here
    int n,m;
    cin>>n>>m;
    vvi adj(n+1);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    vi vis(n+1,0);
    rep(i,1,n+1){
        if(vis[i]!=1){
            int num=0;
            int ed=0;
            dfs(i,num,ed,adj,vis);
            ed/=2;
            if(ed!=1LL*num*(num-1)/2){
                no();
                return;
            }
        }
    }
    yes();
}

int main() {
    fastio();
    int t=1;
    //cin >> t;
    while (t--) {
        aditi();
    }
    return 0;
}

#endif // MY_BOILERPLATE_H
