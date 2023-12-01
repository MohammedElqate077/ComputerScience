#include <stdio.h>
#include <stdlib.h>

int kaprekar(int N);
int chifre(int N, int *T);
void trie_croi(int *T, int nb);
int getn1(int T[], int nb);
int getn2(int T[], int nb);

int main()
{
	int k, N, imax, i = 0;

	printf("entrer un nb quelqon : ");
	scanf("%d", &N);
	printf("entrer le nb maximale d\'iteration : ");
	scanf("%d", &imax);
	k = N;
	do
	{
		N = k;
		k = kaprekar(N);
		i++;
	} while (!(i >= imax || k == 0 || k == N));
}

int kaprekar(int N)
{
	int k, n1, n2, nb, T[10];
	nb = chifre(N, T); //T[nb];
	trie_croi(T, nb);
	n1 = getn1(T, nb);
	n2 = getn2(T, nb);
	k = n2 - n1;
	printf("k = %d-%d\t=%d\n", n2, n1, k);
	return k;
}

int chifre(int N, int *T)
{
	int compt = 0, i = 0;
	while (N != 0)
	{
		T[i] = N % 10;
		N /= 10;
		compt++;
		i++;
	}
	return compt;
}

void trie_croi(int *T, int nb)
{
	int j;
	for (int i = 0; i < nb; i++)
	{
		int min = i;
		for (j = i + 1; j < nb; j++)
		{
			if (T[min] > T[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			j = T[i];
			T[i] = T[min];
			T[min] = j;
		}
	}
}

int getn1(int T[], int nb)
{
	int v = 0;
	for (int i = 0; i < nb - 1; i++)
	{
		v = (v + T[i]) * 10;
	}
	return v + T[nb - 1];
}

int getn2(int T[], int nb)
{
	int v = 0;
	for (int i = nb - 1; i > 0; i--)
	{
		v = (v + T[i]) * 10;
	}
	return v + T[0];
}
