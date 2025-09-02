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
#include <iomanip>

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

bool func(vector<pair<ll,ll>>&p,int k){
    ll currmin=0;
    ll currmax=0;
    //if we start from (0) and can move k distance
    //we can be anywhere from(0-k,0+k) == {-k,k};
    
    //segment 1 ke inside land krna h
    //we take intersection of (-k,k) and first segment
    //eg k=6
    //first interval is (3,8) 
    //but we can move from(-6,6)
    //so intersection is (3,6)
    //so after first move we will be in (3,6) 
    //now also we can do only(-6,6)
    //so from 3 -6 we can go to -3
    //similary 6+6=12
    //(-3,12) 
    for(auto it:p){
        currmin-=k;
        currmax+=k;
        ll l=it.first;
        ll r=it.second;
        ll sr=max(currmin,l); //reachable start
        ll re=min(currmax,r); //reachable end
        if(sr>re) return 0;
        
        currmin=sr;
        currmax=re;
    }
    return true;
    
}
void aditi() {
    // Your problem-solving logic goes here
    ll n;
    cin>>n;
    vector<pair<ll,ll>>p;
    rep(i,0,n){
        int u,v;
        cin>>u>>v;
        p.push_back({u,v});
    }
    ll low=0;
    ll high=1e10;
    ll ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(func(p,mid)==1){
            ans=mid;
            high=mid-1; //we will try to findd smaller k
        }
        else low=mid+1; //moveto bigger k
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        aditi();
    }
    return 0;
}

#endif // MY_BOILERPLATE_H
