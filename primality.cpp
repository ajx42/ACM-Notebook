
/******Miller Rabin Template Starts******/
long long mulmod(long long a, long long b, long long m ) {
    return (a*b - (long long)(a/(long double)m*b + 1e-3)*m + m)%m;
}
/*
lld mulmod(lld a,lld b,lld c){
    lld x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
*/
lld BigMod(lld a,lld b,lld mod){
      if(!b) return 1;
      lld x = BigMod(a,b/2,mod);
      x = mulmod(x,x,mod);
      if(b%2) x = mulmod(x,a,mod);
      return x;
}

bool isPrime(lld n){
	int a[9] = {2,3,5,7,11,13,17,19,23};
	for(int i = 0; i < 9; i++) if(a[i]==n) return true;
    if(n<2){
        return false;
    }
    if(n!=2 && n%2==0){
        return false;
    }
    int s = 0;
    lld d = n - 1;
    while(d%2==0){
    	s++;
    	d/=2;
    }
    
    for(int i = 0; i < 9; i++){
    	bool comp = BigMod(a[i],d,n)!=1;
    	if(comp){
    		for(int j = 0; j < s; j++){
    			lld fp = BigMod(a[i], (1LL<<(lld)j)*d, n);
    			if(fp==n-1){
    				comp = false;
    				break;
    			}
    		}
    	}
    	if(comp) return false;
    }
    return true;
}

/*
bool isPrime(lld n, lld k=10)
{
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;
 
   while (k>0)
   {
       lld a = 2 + rand()%(n-4);  
       if (BigMod(a, n-1, n) != 1)
          return false;
       k--;
    }
    return true;
}



*/
