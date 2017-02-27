#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;
typedef long long ll;
bool strfun(int a,int b,int c,int d,unordered_set<string> &h){
	if(c<0||d<0)	return false;
	stringstream ss1,ss2;
	ss1<<a<<' '<<b<<' '<<c<<' '<<d;
	ss2<<c<<' '<<d<<' '<<a<<' '<<b;
	if(h.find(ss1.str())==h.end()&&h.find(ss2.str())==h.end())	return true;
	return false;
}
ll getdp(int w, int h, unordered_set<string> &b, vector<vector<ll> > &dp){
	if(w<0||h<0)	return 0;
	if(dp[w][h]!=-1)	return dp[w][h];
	dp[w][h] = 0;
	if(strfun(w,h,w-1,h,b))	dp[w][h] += getdp(w-1,h,b,dp);
	if(strfun(w,h,w,h-1,b))	dp[w][h] += getdp(w,h-1,b,dp);
	return dp[w][h];
}
ll paths(int w, int h, vector<string> bad){
	unordered_set<string> b(bad.begin(),bad.end());
	vector<vector<ll> > dp(w+1,vector<ll>(h+1,-1));
	dp[0][0] = 1;
	return getdp(w,h,b,dp);
}
int main() {
	vector<vector<string> > vs(4);
	vs[0] = {"0 0 0 1","6 6 5 6"};
	vs[3] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
	vector<int> w(4);
	vector<int> h(4);
	w = {6,1,35,2};
	h = {6,1,31,2};
	for(int i=0; i<4; i++)	cout<<paths(w[i],h[i],vs[i])<<endl;
	return 0;
}
