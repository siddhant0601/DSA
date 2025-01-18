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
#define si set<int>
#define sc set<char>
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
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
vll tree[200001];
ll parents[200001];
ll childCount[200001];
ll maxDist[200001];
ll rootSum;
ll totalNodes;
ll initalizeHeight(ll node,ll parent){
    totalNodes++;
    ll cnt=1;
    for(auto it:tree[node]){
        if(it==parent)continue;
        cnt+=initalizeHeight(it,node);
    }
    return childCount[node]=cnt;
}

void getRootSum(ll node,ll parent,ll depth){
    rootSum+=depth;
    for(auto it:tree[node]){
        if(it==parent)continue;
        getRootSum(it,node,depth+1);
    }
}
void dfs(ll node, ll parent , ll parentSum){
    ll currSum=parentSum-(childCount[node])+totalNodes-(childCount[node]);
    if(node==0){
        currSum=parentSum;
    }
    // print4(node,currSum,parentSum,childCount[node]);
    maxDist[node]=currSum;
    for(auto it:tree[node]){
        if(it==parent)continue;
        dfs(it,node,currSum);
    }
}
void solve(){
    ll n;
    cin>>n;
    fz(i,n-1){
        ll a,b;
        inp2(a,b);
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    getRootSum(0,-1,0);
    initalizeHeight(0,-1);
    // print1(rootSum);
    dfs(0,-1,rootSum);
    maxDist[0]=rootSum;
    fz(i,n){
        cout<<maxDist[i]<<" ";
    }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    rootSum=0;
    totalNodes=0;
    ll cases=1;

    // memset(tree, null, sizeof(tree));

    // cin>>cases;
    while(cases--){
        solve();
        // cout<<endl;
        // cout<<"----------------"<<endl;
    }
    return 0;
}