#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct edge{
	int src,des,wgt;
};
vector<int> bellmanFord(int v,vector<edge> e, int s){
	vector<int> d(v,INT_MAX),emp;
	d[s] = 0;	int x;
	for(int j=0; j<v-1; j++){
		for(int i=0; i<e.size(); i++){
			x = d[e[i].src];
			x = (x==INT_MAX?INT_MAX:x+e[i].wgt);
			if(d[e[i].des]>x)	d[e[i].des] = x;
		}	
	}
	for(int i=0; i<e.size(); i++){
		x = d[e[i].src];
		x = (x==INT_MAX?INT_MAX:x+e[i].wgt);
		if(d[e[i].des]>x)	return emp;
	}
	return d;
}
int main() {
	vector<int> d;
	vector<edge> e;
	int v,s;
	cin>>v>>s;		//number of vertices and edges input
	edge temp;
	for(int i=0; i<s; i++){
		cin>>temp.src>>temp.des>>temp.wgt;
		e.push_back(temp);
	}
	cin>>s;			// reused variable s to store the source vectex
	
	d = bellmanFord(v,e,s);
	
	if(d.empty())	cout<<"Graph contains a negative cycle."<<endl;
	else{
		cout<<"Vertex\tDistance"<<endl;
		for(int i=0; i<v; i++)	cout<<i<<"\t\t"<<(d[i]==INT_MAX?"Infinity":to_string(d[i]))<<endl;
	}
	return 0;
}
