#pragma once
#include <iostream>
#include <vector>
using namespace std;

#define N 30
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

	int num_citys;

	Point p[N];
	double w[N][N];
	double 
};

