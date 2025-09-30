#ifndef LR_HPP
#define LR_HPP
#define MAX 100

class LinearRegression
{

private:
    int size;
    float b0;
    float b1;
    float x_values[MAX];
    float y_values[MAX];
    void set(float[], float[]);
    void calcb1();
    void calcb0();
    float CrossSum();
    float sum(float arr[]);

public:
    void fit(float[], float[], int);
    float predict(int x);
};

#endif