#include <iostream>
#include "LinearRegression.hpp"

float LinearRegression::sum(float arr[])
{
    float res = 0;
    for (int i = 0; i < size; i++)
    {
        res += arr[i];
    }
    return res;
}

float LinearRegression::CrossSum()
{
    float res = 0;
    for (int i = 0; i < size; i++)
    {
        res += x_values[i] * y_values[i];
    }
    return res;
}
void LinearRegression::set(float arr[], float arr2[])
{
    for (int i = 0; i < size; i++)
    {
        x_values[i] = arr[i];
        y_values[i] = arr2[i];
    }
}

void LinearRegression::fit(float X[], float Y[], int size)
{
    this->size = size;
    set(X, Y);
    calcb1();
    calcb0();
}

void LinearRegression::calcb1()
{
    float deviation_XY[MAX]; // "sum of crossproduct" of deviations between x and y -> Sxy
    float deviation_XX[MAX]; // "sum of squares" of deviations of x -----------------> Sxx

    float x_mean = sum(x_values) / size;
    float y_mean = sum(y_values) / size;

    float sumXY = 0;
    float sumXX = 0;

    for (int i = 0; i < size; i++)
    {
        deviation_XY[i] = (x_values[i] - x_mean) * (y_values[i] - y_mean);
        deviation_XX[i] = (x_values[i] - x_mean) * (x_values[i] - x_mean);
        sumXY += deviation_XY[i];
        sumXX += deviation_XX[i];
    }

    b1 = sumXY / sumXX;
}

void LinearRegression::calcb0()
{
    float sumy = sum(y_values);
    float sumx = sum(x_values);

    b0 = (sumy - b1 * sumx) / size;
}

float LinearRegression::predict(int x)
{
    return b1 * x + b0;
}
