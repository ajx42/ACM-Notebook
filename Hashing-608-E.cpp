	/*
 * firehawk ~~~> 4d!ty@
 * from: INDIAN INSTITUTE OF TECHNOLOGY INDORE
 * *******************************************
 */

#include <bits/stdc++.h>
using namespace std;

#define f 	first
#define s 	second
#define pp 	push
#define pb 	push_back
#define pf 	push_front
#define mp 	make_pair

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
typedef stack<int>	stki;
typedef stack<lld> 	stkl;
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

#define INF 1e9

const lld mod = 1e9 + 7;

lld powmod(lld x,lld n,lld m = mod){
	lld ans=1;
	while(n>0){
		if(n&1) ans*=x;
		x*=x;
		x%=m;
		ans%=m;
		n/=2;
	}
	return ans;
}
class StringHash {
	const static lld MAX = 1000010;
    const static lld b = 789456123;
    const static lld m = 1000000007;
    lld B[MAX], inverseB[MAX];

public:
    void initialize() {
        B[0]=1;
        for (int i = 1; i < MAX; i++) {
            B[i]=(B[i-1]*b)%m;
        }
        inverseB[MAX-1]=powmod(B[MAX-1], m-2, m);
        for (int i = MAX-2; i >= 0; i--) {
            inverseB[i]=(inverseB[i+1]*b)%m;
        }
    }

    lld getHash(string &s) {
        lld h = 0;
        for (int i = 0; i<s.size() ; i++) {
            h = (h + (s[i]-'a')*B[i]) % m;
        }
        return h;
    }

    int length;
    lld h[MAX], revh[MAX];
    lld construct(string &s) {
        length = s.size();
        h[0]=0, revh[length+1]=0;
        for (int i = 0, j = 1; i<s.size(); i++, j++) {
            h[j] = (h[j-1] + ((s[i]-'a') * B[i]) % m) % m ;
        }
        for (int i = length-1, j = length, k = 0; i >= 0; i--, j--, k++){
            revh[j] = (revh[j+1] + ((s[i]-'a') * B[k]) % m) % m;
        }
        return h[length];
    }

    lld getSubHash(int i, int j) {
        i++, j++;
        return ((h[j] + (m-h[i-1])) * inverseB[i-1]) % m;
    }

    lld getRevHash(int i, int j) {
        i++, j++;
        return ((revh[i] + (m-revh[j+1])) * inverseB[length-j]) % m;
    }
};

main(){
	
	int n;
	cin >> n;
	--n;
	string str1, str2;
	cin >> str1 >> str2;
	for(int i=0; i<n; i++){
		if(str2[i]=='N'){
			str2[i]='S';
		}
		else if(str2[i]=='S'){
			str2[i]='N';
		}
		else if(str2[i]=='E'){
			str2[i]='W';
		}
		else if(str2[i]=='W'){
			str2[i]='E';
		}
	}
	reverse(all(str2));
	StringHash h1, h2;
	h1.initialize();
	h2.initialize();
	h1.construct(str1);
	h2.construct(str2);
	for(int i=0;i<n;i++){
		if(h1.getSubHash(i,n-1)==h2.getSubHash(0,n-i-1)){
			return cout << "NO",0;
		}
	}
	return cout << "YES",0;
}
