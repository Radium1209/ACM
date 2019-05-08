#include <cstdio>
#include <iostream>
using namespace std;

int n,x;
int t1=0,t2=0;

int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x==1)
			t1++;
		else
			t2++;
	}
	if (t1==0)
	{
		for (int i=1;i<=n;i++)
			printf("2 ");
	}
	else if (t2==0)
	{
		for (int i=1;i<=n;i++)
			printf("1 ");
	}
	else
	{
		printf("2 1 ");
		for (int i=1;i<=t2-1;i++)
			printf("2 ");
		for (int i=1;i<=t1-1;i++)
			printf("1 ");
	}
	return 0;
}
