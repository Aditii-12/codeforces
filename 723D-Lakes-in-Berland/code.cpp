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
int n, m, k;
vector<string> grid;
vvi vis;
struct Lake {
    int size; //number of watwr cells in this lake
    vector<pair<int,int>> cells; //all coordinates of that water cell
    //bd me bhrenge isko with land cells
};
bool isBorder(int x, int y) {
    return (x ==0||y==0||x==n-1||y==m-1);
}

int dr[]={0,1,-1,0};
int dc[]={1,0,0,-1};

Lake dfs(int x, int y) {
    stack<pair<int,int>> st;
    st.push({x,y});
    vis[x][y] = 1;

    Lake lake;
    lake.size = 0;

    bool touchesBorder = false;

    while(!st.empty()) {
        auto [cx, cy] = st.top(); st.pop();
        lake.cells.push_back({cx,cy});
        lake.size++;

        if (isBorder(cx,cy)) touchesBorder = true;

        rep(i,0,4) {
            int nx = cx +dr[i], ny = cy + dc[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '.') {
                vis[nx][ny] = 1;
                st.push({nx,ny});
            }
        }
    }

    if (touchesBorder) {
        lake.size = -1; // mark as ocean
    }
    return lake;
}
void aditi() {
    // Your problem-solving logic goes here
    cin>>n>>m>>k;
    grid.resize(n);
    rep(i,0,n) cin>>grid[i];

    vis.assign(n, vi(m, 0));
    vector<Lake> lakes;
        // Step 1: Find all lakes
    rep(i,0,n){
        rep(j,0,m){
            if (vis[i][j]!=1 && grid[i][j] =='.') {
                Lake temp = dfs(i,j); //this temp will store a valid lake
                if (temp.size != -1) {
                    lakes.push_back(temp);
                }
            }
        }
    }
    sort(lakes.begin(), lakes.end(), [](const Lake &a, const Lake &b) {
        return a.size < b.size;
    });
    int filled = 0;
    int tofill =(int)lakes.size()-k;
    rep(i,0,tofill){
        filled+=lakes[i].cells.size();
        for (auto [x,y] : lakes[i].cells) {
            grid[x][y] = '*';
        }
    }
    cout << filled << "\n";
    rep(i,0,n) cout << grid[i] << "\n";


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
