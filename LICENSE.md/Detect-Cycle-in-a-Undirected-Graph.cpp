//Sunny Singh Yadav IIIT-Allahabad
//isc2013008@iiita.ac.in

#define Code Detect cycle in an undirected graph

#include<bits/stdc++.h>
#include<list>
#include<vector>

#define ll long long

using namespace std;

vector<vector<ll> > arr(100000);
ll n;

bool check = true;

bool iscycle(bool Visited[] , ll p , ll s) 
{
	if(!Visited[s]) {
		Visited[s] = true;
		
		vector<ll>::iterator it;
		
		for(it = arr[s].begin() ; it != arr[s].end(); it++) {
			if(Visited[*it] == false) {
				if(iscycle(Visited , s , *it) ) return true;
			}
			else if(p != *it) 
				return true;
		}
	}
	
	return false;
}

void solve()
{
	bool *Visited = new bool[n];
	ll parent = -1;
	
	for(ll i = 0 ; i < n; i++) {
		Visited[i] = false;
	}
	
	if(iscycle(Visited , parent , 0) == false){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
}

int main()
{
	ll i , j , k , l , m , E , a , b;
	
	cin>>n;
	cin>>E;
	
	for(i = 0; i < n; i++) {
		cin>>a;
		cin>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	solve();	
}
