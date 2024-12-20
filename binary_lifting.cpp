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

class Solution{
    public:
        void solve(){
            int n,queries;
            cin>>n>>queries;
            vector<int>parents(n);
            vector<int>tree[n];
            for(int i=1;i<n;i++){
                int boss;
                cin>>boss;
                parents[i]=boss-1;
                tree[boss-1].push_back(i);
            }
            parents[0]=-1;
            vector<vector<int>>binJump(n,vector<int>(100,-1));
            int depth=0;
            queue<int>q;
            q.push(0);
            while(!q.empty()){
                int len=q.size();
                while(len--){
                    int top=q.front();
                    q.pop();
                    binJump[top][0]=parents[top];
                    for(int i=1;i<20;i++){
                        if(binJump[top][i-1]==-1)break;
                        binJump[top][i]=binJump[binJump[top][i-1]][i-1];
                    }
                    for(int child:tree[top]){
                        q.push(child);
                    }
                }
                depth++;
            }
            while(queries--){
                int start,jump;
                cin>>start>>jump;  
                start-=1;
                vector<int>ones;
                for(int i=19;i>=0;i--){
                    if(((jump>>i)&1)){
                        ones.push_back(i);
                    }
                }
                for(int one:ones){
                    start=binJump[start][one];
                    if(start==-1)break;
                }
                if(start==-1){
                    cout<<-1<<endl;
                }
                else{
                    cout<<start+1<<endl;
                }
            }
            // for(auto it:binJump){
            //     for(auto j:it){
            //         cout<<j<<" ";
            //     }
            //     cout<<endl;
            // }
            
            
        }
};
int main()
{   
  
    ll cases=1;
    // cin>>cases;
    Solution solver;
    while(cases--){
        solver.solve();
        // cout<<endl;
        // cout<<"----------------"<<endl;
    }
    return 0;
}