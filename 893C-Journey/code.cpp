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
#include <iomanip>
 
 
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
double ans=0;
 
 
double dfs(int node,int p,vector<vi>&adj){
    int childcount=0;
    double sum=0;
    for(int neigh:adj[node]){
        if(neigh==p) 
            continue;
        childcount++;
        sum+=dfs(neigh,node,adj) +1.0; //1 is for ek edge travel krli uske liye
        
    }
    if(childcount==0) 
        return 0;
    return sum/childcount;
}
void aditi() {
    // Your problem-solving logic goes here
    int n;
    cin>>n;
    vector<vi>adj(n+1);
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=dfs(1,0,adj);
    cout<<fixed<<setprecision(15)<<ans<<endl;
}
//        1
//      / \
//      2   3
//     / \
//    4   5
 
//dfs(2)=(dfs(4)+1)+(dfs(5)+1)/2==1;
//dfs(1)=(dfs(2)+1) +(dfs(3)+1)/2==1.5
//like if there r two subtress to unki probablity is same to be chosen
//ek subtree me 100 leaves h and ek me 1 h to har leaf ki probablity 1/101 ni hogi .
//dono subtree ki 1/2 h
//to jisme ek leaf h uski 1/2
//and jisme 100 h usme 1/100*1/2
 
 
int main() {
    fastio();
    int t=1;
    // cin >> t;
    while (t--) {
        aditi();
    }
    return 0;
}
 
#endif // MY_BOILERPLATE_H
