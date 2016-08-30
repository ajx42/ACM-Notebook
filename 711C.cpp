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
lld dp[110][110][110];
vector <lld> col(110);
lld p[110][110];
main(){
    lld n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> col[i];
    }
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin >> p[i][j];
        }
    }
    for(int i=0;i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int t=0; t<=k; t++){
                dp[i][j][t] = INF;
            }
        }
    }
    if(col[1]==0){
        for(int j=1; j<=m; j++){
            dp[1][j][1] = p[1][j];
        }
    }
    else dp[1][col[1]][1] = 0;
    lld buff;
    for(int i=2; i<=n; i++){
        if(col[i]==0){
            for(int t=1;t<=k; t++){
                for(int j=1; j<=m; j++){
                    dp[i][j][t] = min(dp[i][j][t], dp[i-1][j][t]+p[i][j]);
                    for(int u=1; u<=m; u++){
                        if(j==u) continue;
                        dp[i][j][t+1] = min(dp[i][j][t+1], dp[i-1][u][t]+p[i][j]);
                    }
                }
            }
        }
        else{
            for(int j=1; j<=m; j++){
                for(int t=1; t<=k; t++){
                    if(dp[i-1][j][t] == INF) continue;

                    if(j==col[i]){
                        dp[i][j][t] = min(dp[i][j][t],dp[i-1][j][t]);
                    }
                    else{
                        dp[i][col[i]][t+1] = min(dp[i][col[i]][t+1],dp[i-1][j][t]);
                    }

                }
            }
        }
    }
    lld ans = INF;
    for(int j=1; j<=m; j++){
        ans = min(ans, dp[n][j][k]);
    }
    if(ans==INF) return cout << "-1",0;
    cout << ans << endl;
}
