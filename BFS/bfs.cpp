#include <bits/stdc++.h>
#include "../helpers.h"
using namespace std;
typedef vector <int> vi;
#define pb push_back


void bfs(int vis[], int no, vi grafo[])
{
	vis[no] = 1;
	queue <int> fila;
	fila.push(no);

	while(!fila.empty())
	{
		int no_vizinho = fila.front();
		fila.pop();

		for(int i = 0;i < (int)grafo[no_vizinho].size();i++)
		{
			if (!vis[grafo[no_vizinho][i]])
			{
				fila.push(grafo[no_vizinho][i]);
				vis[grafo[no_vizinho][i]] = 1;
			}
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
	bfs(vis, 0, grafo);
	print_int_array(vis, N);
}
