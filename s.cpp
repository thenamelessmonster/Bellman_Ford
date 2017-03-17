#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include <ctime>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007LL
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<ll,ll>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
#define inf 1000000000
using namespace std;
vector<pii> g;
map<pii,int>wt ;
int dt[1003];
void print_that(int wer ,int n)
{
    cout<<"distances from "<<wer<<"->";
	for(int i=1;i<=n;i++)
	{
			cout<<dt[i]<<" ";
	}
	cout<<endl;
	return;
}
void solve_that(int wer,int n)
{
	int dt[n+1];
	for(int i=1;i<=n;i++)
		dt[i]=inf;
	dt[wer]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<sz(g);j++)
		{
			int u=g[j].F;
			int v=g[j].S;
			if(dt[u]+wt[m_p(u,v)]<dt[v]&&dt[u]!=inf)
				dt[v]=dt[u]+wt[m_p(u,v)];
		}

	}
	print_that(wer,n);
	return ;
}
int main()
{
    ios::sync_with_stdio(0);
    int start_s=clock();
    //freopen("out.txt","r",stdin);
    //freopen("in.txt","w",stdout);
    cout<<"enter the number of vertices\n";
  	int n;
  	cin>>n;
  	cout<<"enter the adjacency matrix\n";
  	int a;
  	for(int i=1;i<=n;i++)
  		for(int j=1;j<=n;j++)
  		{
  			cin>>a;
  			if(a!=0)
  			{
  				g.pb(m_p(i,j));
  				wt[m_p(i,j)]=a;
  			}
  		}
  	cout<<"by bellman-ford algorithm\n";
  	for(int i=1;i<=n;i++)
  		solve_that(i,n);
  	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}
