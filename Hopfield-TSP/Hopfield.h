#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

#define N 10
#define U0 0.02
#define A 1.5
#define D 0.5
#define T 50000
#define SETP 0.05

struct Point
{
	double x, y;
};


class Hopfield
{
public:
	Hopfield();
	void Input();
	void Init();
	void RandomInput();

	int num_citys;

	default_random_engine rnd_e;

	Point p[N];
	double w[N][N];
	double U[N][N];
	double V[N][N];

	int V_d[N][N];

	int path[N];

	void InitU();
	void UpdateV();
	void UpdateU();
	void OutPutV();
	void test();
};

