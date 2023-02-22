#include <math.h>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>

std::default_random_engine defo(time(0));
std::uniform_real_distribution<double> rando(-1, 1);

void generatepts(double xval, double yval, const double rad);

int main()
{

    generatepts(1, 2, 1);
    generatepts(5, 4, 1);
}

void generatepts(double xval, double yval, const double rad)
{
    int numpts = 1;
    std::vector<double> pointsx;
    std::vector<double> pointsy;
    pointsx.push_back(xval);
    pointsy.push_back(yval);

    while (numpts < 50)
    {
        double nux = rando(defo);
        double nuy = rando(defo);

        if (sqrt((nux * nux) + (nuy * nuy)) < rad)
        {
            pointsx.push_back(xval + nux);
            pointsy.push_back(yval + nuy);
            numpts++;
        }
    }

    for (int i = 0; i < 50; i++)
    {
        std::cout << pointsx[i] << ", " << pointsy[i] << "\n";
    }
}