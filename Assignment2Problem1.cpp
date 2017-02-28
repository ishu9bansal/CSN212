#include <iostream>
#include <vector>
using namespace std;
int getdp(int n, int o,vector<int> &s, vector<vector<int> > &dp){
	if(n<0)	return 0;
	if(dp[o][n]!=-1)	return dp[o][n];
	dp[0][n] = dp[1][n] = 1;
	int a,b;
	for(int i=n-1; i>=0; i--){
		a = getdp(i,0,s,dp);
		b = getdp(i,1,s,dp);
		if(s[i]>s[n]&&dp[0][n]<1+b)	dp[0][n] = 1+b;
		if(s[i]<s[n]&&dp[1][n]<1+a)	dp[1][n] = 1+a;
	}
	// int i=n; int j=n;
	// while(i>=0&&s[i]>=s[n])	i--;
	// while(j>=0&&s[j]<=s[n])	j--;
	// dp[1][n] = 1+getdp(i,0,s,dp);
	// dp[0][n] = 1+getdp(j,1,s,dp);
	return dp[o][n];
}
int longestZigZag(vector<int> s){
	int n = s.size();
	vector<vector<int> > dp(2,vector<int>(n,-1));
	int a = getdp(n-1,0,s,dp);
	int b = getdp(n-1,1,s,dp);
	if(a<b)	a=b;
	return a;
}
int main() {
	vector<vector<int> > ex(6);
	ex[0] = { 1, 7, 4, 9, 2, 5 };
	ex[1] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
	ex[2] = { 44 };
	ex[3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ex[4] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
	ex[5] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
				600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
				67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
				477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
				249, 22, 176, 279, 23, 22, 617, 462, 459, 244
				};
	for(int i=0; i<6; i++)	cout<<longestZigZag(ex[i])<<endl;
	return 0;
}
