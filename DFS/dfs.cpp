#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
#define pb push_back

void dfs(int vis[], int no, vi grafo[])
{
	vis[no] = 1;

	for (int i = 0;i < (int)grafo[no].size();i++)
	{
		if (!vis[grafo[no][i]])
		{
			dfs(vis, grafo[no][i], grafo);
		}
	}
}

void imprime_vis(int vis[], int N)
{
	puts("-----------------------------");
	for(int i = 0;i < N;i++)
	{
		printf("i: %d -> %d\n", i, vis[i]);
	}
}

int main()
{
	int N = 10;
	vi grafo[N];
	int vis[10] = {};
	int no_origem, no_destino;

	for (int i = 0;i < N;i++)
	{
		scanf("%d %d", &no_origem, &no_destino);
		grafo[no_origem].pb(no_destino);
	}

	imprime_vis(vis, N);
	dfs(vis, 0, grafo);
	imprime_vis(vis, N);

}
