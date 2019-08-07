#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define MAXN 200005
using namespace std;

struct node {
	int x,id;
}s[MAXN<<2];

int T,n,ans,Map[MAXN<<2][2],col[MAXN<<2],vis[MAXN<<2];

bool cmp(node a,node b) {
	return a.x<b.x;
}

void pushdown(int rt) {
	if (col[rt]) {
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=0;
	}
}

void update(int L,int R,int c,int l,int r,int rt) {
	if (L<=l&&r<=R) {
		col[rt]=c;
		return;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if (L<=m) update(L,R,c,lson);
	if (m<R) update(L,R,c,rson);
}

void query(int l,int r,int rt) {
	if (col[rt]) {
		if (!vis[col[rt]]) {
			ans++;
			vis[col[rt]]=1;
		}
		return;
	}
	if (l==r) return;
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}

int main() {
	cin >> T;
	while(T--) {
		memset(col,0,sizeof(col));
		memset(vis,0,sizeof(vis));
		cin >> n;
		for (int i=0;i<n;i++) {
			scanf("%d%d",&Map[i+1][0],&Map[i+1][1]);
			s[i<<1].x=Map[i+1][0];
			s[i<<1|1].x=Map[i+1][1];
			s[i<<1].id=-(i+1);
			s[i<<1|1].id=i+1;
		}
		sort(s,s+2*n,cmp);
		int tmp=s[0].x,cnt=1;
		for (int i=0;i<2*n;i++) {
			if (tmp!=s[i].x) {
				cnt++;
				tmp=s[i].x;
			}
			if (s[i].id<0) {
				Map[-s[i].id][0]=cnt;
			} else {
				Map[s[i].id][1]=cnt;
            }
		}
		for (int i=1;i<=n;i++){
			update(Map[i][0],Map[i][1],i,1,cnt,1);
		}
		ans=0;
		query(1,cnt,1);
		printf("%d\n",ans);
	}
	return 0;
}
