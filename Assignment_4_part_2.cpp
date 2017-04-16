#include <bits/stdc++.h>
using namespace std;
extern const _Placeholder<1> _1;
extern const _Placeholder<2> _2;
struct point{
	double x,y;
	point(double X=0, double Y=0) : x(X), y(Y){}
};
double area(point p1, point p2, point p3){
	p2.x -= p3.x;	p2.y -= p3.y;
	p1.x -= p3.x;	p1.y -= p3.y;
	return 0.5*(p1.x*p2.y-p1.y*p2.x);
}
bool compare(const point &a, const point &b, const point &c){
	return area(a,b,c)>0;
}
point leftMost(vector<point> &s){
	point left = s[0];
	for(int i=1; i<s.size(); i++){
		if(s[i].x>left.x)	continue;
		if(s[i].x==left.x&&s[i].y>left.y)	continue;
		left = s[i];
	}
	return left;
}
int lowerMost(vector<point> &s){
	int j=0;
	for(int i=1; i<s.size(); i++){
		if(s[i].y>s[j].y)	continue;
		if(s[i].y==s[j].y&&s[i].x>s[j].x)	continue;
		j=i;
	}
	return j;
}
void sortPoints(vector<point> &s){
	if(s.size()<2)	return;
	int ind = lowerMost(s);
	swap(s[ind],s[0]);
	sort(s.begin()+1, s.end(), bind(compare, _1, _2, s[0]));
	return;
}
vector<point> grahams(vector<point> &s){
	int n = s.size();
	sortPoints(s);
	if(n<4)	return s;
	vector<point> p;
	p.push_back(s[0]);
	p.push_back(s[1]);
	p.push_back(s[2]);
	int l;
	for(int i=3; i<s.size(); i++){
		l = p.size()-1;
		if(!compare(p[l-1],p[l],s[i])){
			p.pop_back();	i--;	continue;
		}
		p.push_back(s[i]);
	}
	return p;
}
int main() {
	int n=0;
	cin>>n;
	vector<point> s;
	point temp;
	while(n--){
		cin>>temp.x>>temp.y;
		s.push_back(temp);
	}
	vector<point> p = grahams(s);
	for(int i=0; i<p.size(); i++)	cout<<p[i].x<<'\t'<<p[i].y<<endl;
	return 0;
}
