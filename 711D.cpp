// in the name of god
#include <bits/stdc++.h>
using namespace std;

#define f 	first
#define s 	second
#define pp 	push
#define pb 	push_back
#define pf 	push_front
#define mp 	make_pair

typedef unsigned long long int ulld;
typedef long long int 	lld;
typedef long double 	ldb;

typedef vector<int> 	vi;
typedef vector<lld> 	vl;
typedef pair<int,int> 	pii;
typedef pair<lld,lld> 	pll;
typedef map<int,int> 	mii;
typedef map<lld,lld> 	mll;
typedef set<int> 	si;
typedef set<lld> 	sl;
typedef vector<pii> 	vii;
typedef vector<pll> 	vll;

#define pi(x) 	printf("%d", x)
#define gi(x) 	scanf("%d", &x)
#define gl(x) 	scanf("%lld", &x)
#define pl(x) 	printf("%lld", x)
#define g64(x) 	scanf("%I64d", &x)
#define p64(x) 	printf("%I64d", x)
#define gc(x)	scanf("%c", &x)
#define pc(x)	printf("%c", x)
#define nl 	printf("\n")
#define sp 	printf(" ")

#define all(c) c.begin(),c.end()
#define tr(it,c) for(__typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define fre freopen("output.txt","wt",stdout);freopen("input.txt","rt",stdin)
#define dbg(x) cerr << #x << " = " << x << endl

template <typename T> vector<T> readVector(int n) {
	vector<T> res(n);
	for (int i = 0 ; i < n ; i++) cin >> res[i];
	return res;
}

template <typename T> void printVector(vector <T> in) {
	int n = in.size();
	for (int i = 0 ; i < n ; i++){
		cout << in[i] << " \n"[i==n-1];
	}
}

#define INF 1e14
#define MAX 100010
const lld mod = 1e9 + 7;

vi a(2*MAX);
vi adj[2*MAX];
lld vis[2*MAX];
lld cnt = 0;
lld cycle = 0;
lld step[2*MAX];

lld powmod(lld base, lld exp, lld M = mod){
	lld ans=1;
	while(exp){
		while(exp%2==0){
			base=(base*base)%M;
			exp/=2;
		}
		exp--;
		ans=(ans*base)%M;
	}
	return ans;
}

void dfs(lld i, lld ddf, lld steps, lld pre){

    if(vis[i]==ddf){
        cycle = step[pre] - step[i]+1;
        cnt -= cycle;

        return;
    }
    if(vis[i]) return;
    cnt++;
    step[i] = steps;
    vis[i] = ddf;
    dfs(a[i], ddf, steps+1, i);
}

main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int df = 1;
    lld ans = 1;
    for(int i=1; i<=n; i++){
        cnt = 0 , cycle = 0;
        if(!vis[i]){
            dfs(i,df,1,-1);
            df++;
            ans = (ans*(((powmod(2,cnt)*((powmod(2,cycle)-(cycle>0)*2+mod)%mod))%mod)))%mod;
        }
    }
    cout << ans << endl;
}
