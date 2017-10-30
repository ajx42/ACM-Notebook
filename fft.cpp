
const double PI = 4*atan(1);
typedef complex <double> base;
 
vector <base> omega; // omega
 
lld FFT_N;
 
void init_fft(lld n){
	FFT_N = n;
	omega.resize(n);
	ldb angle = 2*PI/n;
	for(int i = 0; i < n; i++){
		omega[i] = base(cos(i*angle), sin(i*angle));
	}
}
 
void fft(vector <base> &a){
	lld n = a.size();
	if(n == 1) return;
	lld md = n >> 1;
	vector <base> even(md), odd(md);
	for(int i = 0, j = 0; i < n; i+=2, j++){
		even[j] = a[i];
		odd[j] = a[i+1];
	}
	fft(even);
	fft(odd);
	for(int i = 0, fac = FFT_N/n; i < md; i++){
		base tmp = odd[i] * omega[i*fac];
		a[i] = even[i] + tmp;
		a[i + md] = even[i] - tmp;
	}
}
 
void multiply(vector <lld> &a, vector <lld> &b, vector <lld> &res){
	vector <base> fa(all(a));
	vector <base> fb(all(b));
	lld n;
	for(n = 1; n < 2*max(a.size(), b.size()); n<<=1);
	fa.resize(n); fb.resize(n);
	init_fft(n);
	fft(fa); 
	fft(fb);
	for(int i = 0; i < n; i++){
		fa[i] = conj(fa[i]*fb[i]);
	}
	fft(fa);
	res.resize(n);
	for(int i = 0; i < n; i++){
		res[i] = (lld)(fa[i].real()/n + 0.5);
		res[i] %= mod;
	}
}
