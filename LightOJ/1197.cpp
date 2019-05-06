#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long  ll;
using namespace std;
int prime[100005],vis[100005],visab[100005];
int t,ans=0,cnt=0;
ll a,b;

int main()
{
	memset(vis,0,sizeof(vis));
	cin >> t;
	vis[0]=vis[1]=0;
	for (int i=2;i*i<=100000;i++)
	{
		if (!vis[i])
		{
			for (int j=i*i;j<=100000;j+=i)
				vis[j]=1;
		}
	}
	for (int i=2;i<=100000;i++)
		if (!vis[i]) prime[cnt++]=i;
	for (int m=1;m<=t;m++)
	{
		ans=0;
		scanf("%lld%lld",&a,&b);
		memset(visab,0,sizeof(visab));
		for(int i=0;i<cnt&&(ll)prime[i]*prime[i]<=b;i++)
		{
			ll st=max(a/prime[i]*prime[i],(ll)prime[i]*prime[i]);
			for(ll j=st;j<=b;j+=prime[i])
				if(j>=a) visab[j-a]=1;
		}
		for(ll i=0;i<=b-a;i++)
		{
			if(!visab[i])
				ans++;
		}
		if (a==1) ans--;
		printf("Case %d: %d\n",m,ans);
	}
	return 0;
}
