    #include<bits/stdc++.h> 
    #include <map>
    #include <string>
    #include <unordered_map>
    #include <unordered_set>
    #include <set>  
    #include <vector>
    #include <stack>
    using namespace std;
    /* TYPES  */
    #define ll long long
    #define pii pair<int, int>
    #define pll pair<long long, long long>
    #define vi vector<int>
    #define vll vector<long long>
    #define vvll vector<vector<ll>>
    #define mii map<int, int>
    #define mll map<ll,ll>
    #define si set<int>

    #define all(x) x.begin(),x.end()
    #define rall(x) x.rbegin(),x.rend()
    #define sortA(x) sort(all(x))
    #define sortD(x) sort(x.rbegin(),x.rend()) 
    #define maxele(x) max_element(x.begin(), x.end());
    #define minele(x) min_element(x.begin(), x.end());
    #define upmax(x, y) x = max(x, y);
    #define upmax3(x, y,z) x = max(x,max(y,z));
    #define upmin(x, y) x = min(x, y);
    #define upmin3(x, y,z) x = min(x,,min(y,z));
    #define spc << " " <<
    #define print1(x)cout<<x<<endl;
    #define print2(x,y)cout<<x spc y<<endl;
    #define print3(x,y,z)cout<<x spc y spc z<<endl;
    #define print4(a,b,c,d)cout<<a spc b spc c spc d<<endl;
    #define print5(a,b,c,d,e)cout<<a spc b spc c spc d spc e<<endl;
    #define print6(a,b,c,d,e,f)cout<<a spc b spc c spc d spc e spc f<<endl;
    #define print7(a,b,c,d,e,f,g)cout<<a spc b spc c spc d spc e spc f spc g<<endl;
    #define inp1(x)cin>>x;
    #define inp2(x,y)cin>>x>>y;
    #define inp3(x,y,z)cin>>x>>y>>z;
    
    /* FUNCTIONS */
    #define f(i,s,e) for(long long int i=s;i<e;i++)
    #define fz(i,e) for(long long int i=0;i<e;i++)
    #define cf(i,s,e) for(long long int i=s;i<=e;i++)
    #define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
    #define pb push_back
    #define eb emplace_back
    #define fi first
    #define se second
    #define fr front()
    #define bk back()
    #define ppb pop_back
    
    /* PRINTS */
    template <class T>
    void printv(vector<T> v) { for (auto x : v) cout << x << " "; cout <<endl; }
    template <class T>
    void printvv(vector<vector<T>> v) { for (auto it : v){for (auto x:it) cout << x << " "; cout <<endl;} }
    void printflag(bool flag) { if(flag)cout<<"YES";else{cout<<"NO";} cout<<endl; }
    template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void makevector(vector <T> &v,int len) {for (ll i=0;i<len;i++) { T t;cin>>t;v.push_back(t);}}
    #define MOD 1000000007

    #define PI 3.1415926535897932384626433832795
    #define read(type) readInt<type>()
    ll min(ll a,int b) { if (a<b) return a; return b; }
    ll min(int a,ll b) { if (a<b) return a; return b; }
    ll max(ll a,int b) { if (a>b) return a; return b; }
    ll max(int a,ll b) { if (a>b) return a; return b; }
    ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
    ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
    ll sumFirstN(ll n){
        return (n*(n+1))/2;
    }
    string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
    string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
    bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
    void yes() { cout<<"YES\n"; }
    void no() { cout<<"NO\n"; }
    
    typedef long int int32;
    typedef unsigned long int uint32;
    typedef long long int int64;
    typedef unsigned long long int  uint64;
    class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
    #define _v(n, v)vll v(n); fz(i, n) cin >> v[i];
    #define _v2(n, v,v2)_v(n,v); _v(n,v2);
    #define _lv(n, v)ll n;cin>>n;vll v(n); fz(i, n) cin >> v[i];
    #define _l(n)ll n;cin>>n;
    #define _l2(a,b)ll a,b;cin>>a>>b;
    #define _l3(a,b,c)ll a,b,c;cin>>a>>b>>c;
    #define _l4(a,b,c,d)ll a,b,c,d;cin>>a>>b>>c>>d;
    #define _s(s)string s;cin>>s;
    #define _l2v(a,b,v) _l2(a,b); _v(a,v);

    void solve(){
       
        
    }   



    int main()
    {   
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //initialzie array , gloabl -> stack memory fast access , local vector heap , allocation and deacllocation and references so slow  //memset(name,initialvalue,sizeof(name));
        ll cases=1;
        cin>>cases;
        while(cases--){
            solve();
        }

        return 0;
    }
