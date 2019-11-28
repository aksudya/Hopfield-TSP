#include "Hopfield.h"


Hopfield::Hopfield()
{
	rnd_e.seed(1);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			V_d[i][j] = 0;
		}
	}
}

void Hopfield::Input()
{
	scanf("%d", &num_citys);
	for (int i = 0; i < this->num_citys; i++)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
}

void Hopfield::Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double dist = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
			w[i][j] = w[j][i] = dist;
		}
	}
}

void Hopfield::RandomInput()
{
	uniform_real_distribution<double> ud(0, 1);
	for (int i = 0; i < N; i++)
	{
		p[i].x = ud(rnd_e);
		p[i].y = ud(rnd_e);
	}
}

void Hopfield::InitU()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			uniform_real_distribution<double> ud(-1, 1);
			U[i][j] = 0.5 * U0 * log(N - 1) + ud(rnd_e);
		}
	}
}

void Hopfield::UpdateV()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			V[i][j] = 0.5 * (1 + tanh(U[i][j] / U0));
		}
	}
}

void Hopfield::UpdateU()
{
	for (int x = 0; x < N; ++x)
	{
		for (int i = 0; i < N; ++i)
		{
			double t1 = 0;
			double t2 = 0;
			double d1 = 0;
			double du = 0;
			for (int y = 0; y< N; ++y)
			{
				t1 += V[x][y];
				t2 += V[y][i];
				d1 += w[x][y] * V[y][(i+1)%N];
			}
			du = -A * (t1 - 1 + t2 - 1) - D * d1;
			U[x][i] += du * SETP;
		}
	}
}

void Hopfield::OutPutV()
{
	for (int i = 0; i < N; ++i)
	{
		double max = 0;
		int maxp=-1;
		for (int j = 0; j < N; ++j)
		{
			if(V[j][i]>max)
			{
				max = V[j][i];
				maxp = j;
			}
		}
		if(maxp!=-1)
		{
			V_d[maxp][i] = 1;
			path[i] = maxp;
		}
	}
}

void Hopfield::test()
{
	RandomInput();
	//Input();
	Init();
	InitU();
	

	for (int i = 0; i < T; ++i)
	{
		UpdateV();
		UpdateU();
	}
	OutPutV();
	for (int i = 0; i < N; ++i)
	{
		cout << path[i] << "->";
	}
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		cout << p[path[i]].x<<" "<<p[path[i]].y<<endl;

	}
	
}


