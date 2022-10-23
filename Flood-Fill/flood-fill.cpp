#include <bits/stdc++.h>
using namespace std;

int eixo_x[] = {0,1,0,1,-1,0,-1,1};
int eixo_y[] = {0,1,1,0,0,-1,1,-1};
char matriz[5000][5000];

void flood_fill(int i, int j, int quant_linhas, int quant_colunas, char value, char new_value)
{
	if (i < 0 || j < 0 || i >= quant_linhas || j >= quant_colunas || matriz[i][j] != value)
		return;

	matriz[i][j] = new_value;
	for (int posicao = 0;posicao < 8;posicao++)
		flood_fill(eixo_x[i] + i, eixo_y[i] + j, quant_linhas, quant_colunas, value, new_value);
}

void imprime_matriz(int quant_linhas,int quant_colunas)
{
	puts("--------------------");
	for (int i = 0;i < quant_linhas;i++)
	{
		for (int j = 0;j < quant_colunas;j++)
		{
			printf("%c ", matriz[i][j]);
		}
		puts("");
	}

}

void preenche_matriz(int quant_linhas, int quant_colunas)
{
	for (int i = 0;i < quant_linhas;i++)
	{
		for (int j = 0;j < quant_colunas;j++)
		{
			scanf("%c ", &matriz[i][j]);
		}
	}
}

int main()
{
	char value = '*';
	char new_value = '#';
	int quant_linhas = 10;
	int quant_colunas = 10;

	preenche_matriz(quant_linhas, quant_colunas);

	imprime_matriz(quant_linhas, quant_colunas);

	for (int i = 0;i < quant_linhas;i++)
	{
		for (int j = 0;j < quant_colunas;j++)
		{
			if (matriz[i][j] == value)
				flood_fill(i, j, quant_linhas, quant_colunas, value, new_value);
		}
	}

	imprime_matriz(quant_linhas, quant_colunas);
}
