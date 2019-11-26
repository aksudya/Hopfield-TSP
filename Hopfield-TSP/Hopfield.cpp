#include "Hopfield.h"

Hopfield::Hopfield()
{

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
	for (int i = 0; i < num_citys; i++)
	{
		for (int j = i + 1; j < num_citys; j++)
		{
			double dist = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
			w[i][j] = w[j][i] = dist;
		}
	}



}
