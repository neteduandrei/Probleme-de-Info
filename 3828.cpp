
#include <iostream>

using namespace std;

int v[11100] = { 1, 2, 3, 4, 5, 2 }, fr[6] = { 999999, 1, 2, 1, 1, 1 };

int best(int v1, int v2, int v3, int *fr)
{
	int i, minim = 0;
	for (i = 1; i <= 5; i++)
	{
		if (fr[i] < fr[minim] && i != v1 && i != v2 && i != v3) minim = i;
	}
	return minim;
}

int main()
{
	int step, prevstep = 0, latura = 1, hexcurent = 6;
	for (step = 6; step <= 11000; step++)
	{
		if (step == hexcurent)
		{
			latura++;
			hexcurent = hexcurent + latura * 6;
			v[step] = best(v[prevstep], v[prevstep+1], v[step-1], fr);
			fr[v[step]]++;
			v[step + 1] = best(0, v[prevstep+1], v[step], fr);
			fr[v[step + 1]]++;
			step+=1;
			prevstep++;
		}
		else if (step % latura == 0)
		{
			v[step] = best(0, v[prevstep], v[step - 1], fr);
			fr[v[step]]++;
		}
		else
		{
			prevstep++;
			v[step] = best(v[prevstep], v[prevstep - 1], v[step - 1], fr);
			fr[v[step]]++;
		}
	}
	int t,n;
	cin >> t;
	for (; t > 0; t--)
	{
		cin >> n;
		cout << v[n - 1] << '\n';
	}
	return 0;
}

