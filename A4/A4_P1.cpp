#include<bits/stdc++.h>
#define N 100000
#define inf 2000000001
using namespace std;
struct node{
	int id,w;
	friend bool operator < (node a,node b){
		return a.w>b.w;
	}
	node(int id1,int w1):id(id1),w(w1){};
};
struct edge{
	int v,w;
	friend bool operator < (edge a,edge b){
		return a.v<b.v||a.v==b.v&&a.w<b.w;
	}
	edge(int v1,int w1):v(v1),w(w1){};
};
bool cmp(edge a,edge b){
	return a.v==b.v;
}
vector<edge>adj[N+5];
vector<edge>adj1[N+5];
priority_queue<node>q;
map<edge,int>mp;
bool vis[N+5]={0};
int n,m,k,b=1,s,x,y,w,e[N+5],e0[N+5],e1[N+5]={0};
long long d[N+5];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	s=1;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&w);
		adj[x].push_back(edge(y,w));
		adj[y].push_back(edge(x,w));
		adj1[x].push_back(edge(y,w));
		adj1[y].push_back(edge(x,w));
		mp[edge(y,x)]=w;
		mp[edge(x,y)]=w;
	}
	for(int i=1;i<=n;i++)e[i]=adj[i].size();
	while(b==1){
		b=0;
		for(int i=1;i<=n;i++)e0[i]=e1[i],e1[i]=adj[i].size();
		for(int nd=1;nd<=n;nd++){
			for(int i=e0[nd];i<e1[nd];i++)
				for(int j=0;j<e[nd];j++){
					if(i==j)continue;
					if(adj[nd][i].v==adj[nd][j].v)continue;
					if(adj[nd][i].w*k==adj[nd][j].w){
						int p=mp[edge(adj[nd][j].v,adj[nd][i].v)];
						if(p>0&&p<=adj[nd][j].w)continue;
						adj[adj[nd][j].v].push_back(edge(adj[nd][i].v,adj[nd][j].w));
						adj1[adj[nd][i].v].push_back(edge(adj[nd][j].v,adj[nd][j].w));
						mp[edge(adj[nd][j].v,adj[nd][i].v)]=adj[nd][j].w;
						b=1;
					}
				}
		}
	}
	for(int i=1;i<=n;i++){
		sort(adj1[i].begin(),adj1[i].end());
		adj1[i].erase(unique(adj1[i].begin(),adj1[i].end(),cmp),adj1[i].end());
	}
	for(int i=1;i<=n;i++)d[i]=inf;
	d[s]=0;q.push(node(s,0));
	while(!q.empty()){
		node cur=q.top();q.pop();
		int u=cur.id;
		if(vis[u])continue;vis[u]=1;
		for(int i=0;i<adj1[u].size();i++){
			int w=adj1[u][i].w,v=adj1[u][i].v;
			if(vis[v])continue;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push(node(v,d[v]));
			}
		}
	}
	cout<<d[1];
	for(int i=2;i<=n;i++)
	if(d[i]==inf)cout<<" "<<-1;
	else cout<<" "<<d[i];
}