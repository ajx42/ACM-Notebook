#include <bits/stdc++.h>
using namespace std;

int pre[100010];
string text, pattern;

void process(string str){
	int n = str.length();
	pre[0] = 0;
	for(int j=0, i=1; i<n; i++){
		while(j>0 and str[i]!=str[j]){
			j = pre[j-1];
		}
		if(str[i]==str[j]) j++;
		pre[i] = j;
	}
}

int kmp(string s){
	process(s);
	int i = 0, j = 0;
	int n = text.length();
	int m = s.length();
	while(1){
		if(j==n){
			return -1;
		}
		if(text[j]==s[i]){
			i++; j++;
			if(i==m){
				return j-i;
			}
		}
		else if(i>0) i = pre[i];
		else j++;
		
	}
}

main(){
	cin >> text;// >> pattern;
	process(text);
	for(int i=0; i<text.length(); ++i) cout << pre[i] << " ";
		cout << endl;
	//int z = kmp(pattern);
	//cout << z << endl;
}