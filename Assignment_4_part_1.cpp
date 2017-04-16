#include <iostream>
#include <vector>
using namespace std;
struct point{
	double x,y;
	point(double X=0, double Y=0) : x(X), y(Y){}
};
point leftMost(vector<point> &s){
	point left = s[0];
	for(int i=1; i<s.size(); i++){
		if(s[i].x>left.x)	continue;
		if(s[i].x==left.x&&s[i].y>left.y)	continue;
		left = s[i];
	}
	return left;
}
double area(point p1, point p2, point p3){
	p2.x -= p3.x;	p2.y -= p3.y;
	p1.x -= p3.x;	p1.y -= p3.y;
	return 0.5*(p1.x*p2.y-p1.y*p2.x);
}
vector<point> jarvis(vector<point> &s){
	point endpoint;
	vector<point> p;
	if(s.size()==0)	return p;
	point pointOnHull = leftMost(s);
	int i = 0;
	do{
		p.push_back(pointOnHull);
		endpoint = s[0];
		for(int j=1; j<s.size(); j++){
			if(endpoint.x==pointOnHull.x&&endpoint.x==pointOnHull.x)	endpoint=s[j];	
			else if(area(p[i],endpoint,s[j])>0)	endpoint = s[j];
		}
		i++;
		pointOnHull = endpoint;
	}while(endpoint.x!=p[0].x||endpoint.y!=p[0].y);
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
	vector<point> p = jarvis(s);
	for(int i=0; i<p.size(); i++)	cout<<p[i].x<<'\t'<<p[i].y<<endl;
	return 0;
}
