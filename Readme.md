## Compilation Commands

```bash
g++ -o main main.cpp linearregression.cpp

```

---

# 📘 Linear Regression – A Complete Guide

This repository is a study resource for understanding **simple linear regression**.
It explains the theory step by step, including definitions, derivations, and key concepts such as random variables, mean-centered form, and regression sums of squares.

---

## 1. Introduction

Linear regression is one of the most fundamental methods in statistics and machine learning.

**Goal of Linear Regression:**
The primary goal is to find the best-fitting straight line through a set of data points to predict or understand the relationship between variables. Specifically, we aim to:

- **Predict** future values of Y based on known values of X
- **Quantify** the strength and direction of the linear relationship
- **Minimize** the prediction errors by finding optimal coefficients

![Linear Regression Visualization](image.png)

> **📊 The orange line represents the best-fitting regression line through the data points.**

Linear regression models the relationship between a dependent variable (Y) and an independent variable (X) using a straight line:

$$Y \approx b_0 + b_1 X$$

where:

- $b_0$ = intercept (the value of Y when X=0)
- $b_1$ = slope (the rate of change in Y for a one-unit increase in X)

---
# Deriving Linear Regression 

The aim of linear regression is to find the best-fitting straight line that describes the relationship between an independent variable (x) and a dependent variable (y).

---

## Key concepts

### Expectation (mean)

The mean (expected value) of a set $X = \{x_1, x_2, \dots, x_n\}$ is
$$E(X) = \bar{x} = \frac{1}{n}\sum_{i=1}^{n} x_i$$
(where $\sum$ is the summation symbol: $\sum_{i=1}^{n} x_i = x_1 + x_2 + \dots + x_n$.)

### Standard deviation and variance

The (population) variance measures the average squared deviation from the mean:
$$\text{Var}(X) = E\big[(X - E(X))^2\big] = \frac{1}{n}\sum_{i=1}^{n} (x_i - \bar{x})^2$$
The (population) standard deviation $\sigma$ is the square root of the variance:
$$\sigma_X = \sqrt{\text{Var}(X)}$$
(For sample estimates you will often see the denominator $n-1$ instead of $n$: $s^2 = \frac{1}{n-1}\sum (x_i-\bar{x})^2$.)

#### Useful identity (proof)

Start from $\text{Var}(X)=E\big[(X - \mu)^2\big]$ with $\mu=E(X)$:
$$\begin{aligned}
\text{Var}(X)
&= E(X^2 - 2\mu X + \mu^2) \\
&= E(X^2) - 2\mu E(X) + \mu^2 \\
&= E(X^2) - 2\mu^2 + \mu^2 \\
&= E(X^2) - \big(E(X)\big)^2.
\end{aligned}$$
So a compact form is:
$$\boxed{\text{Var}(X) = E(X^2) - [E(X)]^2}$$

---

## Calculating the best-fitting line (Least Squares)

Assume the regression line has the form
$$y = b_0 + b_1 x$$
For observations $(x_i, y_i)$ for $i=1,\dots,n$, the predicted value is
$$\hat{y}_i = b_0 + b_1 x_i$$
and the residual (error) is $e_i = y_i - \hat{y}_i$.

We choose $b_0$ and $b_1$ to minimize the sum of squared residuals:
$$S(b_0,b_1) = \sum_{i=1}^{n} \big(y_i - (b_0 + b_1 x_i)\big)^2$$
We square the differences so that positive and negative errors do not cancel and to penalize larger errors more.

### Derivation (step-by-step)

Set partial derivatives of $S$ with respect to $b_0$ and $b_1$ equal to zero.

1. Derivative w.r.t. $b_0$:
   $$\frac{\partial S}{\partial b_0}
   = -2\sum_{i=1}^{n} \big(y_i - b_0 - b_1 x_i\big)
   \overset{!}{=} 0
   \quad\Rightarrow\quad
   \sum_{i=1}^{n} y_i = n b_0 + b_1 \sum_{i=1}^{n} x_i$$
   Rewrite using means $\bar{x}=\frac{1}{n}\sum x_i$ and $\bar{y}=\frac{1}{n}\sum y_i$:
   $$\boxed{\bar{y} = b_0 + b_1 \bar{x}} \qquad\text{(Equation A)}$$

2. Derivative w.r.t. $b_1$:
   $$\frac{\partial S}{\partial b_1}
   = -2\sum_{i=1}^{n} x_i\big(y_i - b_0 - b_1 x_i\big)
   \overset{!}{=} 0
   \quad\Rightarrow\quad
   \sum_{i=1}^{n} x_i y_i = b_0 \sum_{i=1}^{n} x_i + b_1 \sum_{i=1}^{n} x_i^2$$
   (Equation B)

3. Solve the two normal equations. From Equation A:
   $$b_0 = \bar{y} - b_1 \bar{x}$$
   Substitute into Equation B and simplify:
   $$\sum_{i=1}^{n} x_i y_i
   = (\bar{y} - b_1 \bar{x})\sum_{i=1}^{n} x_i + b_1 \sum_{i=1}^{n} x_i^2
   = n\bar{x}\bar{y} - b_1 n\bar{x}^2 + b_1 \sum_{i=1}^{n} x_i^2$$
   Rearrange to isolate $b_1$:
   $$\sum_{i=1}^{n} x_i y_i - n\bar{x}\bar{y}
   = b_1\left(\sum_{i=1}^{n} x_i^2 - n\bar{x}^2\right)$$
   Recognize the numerator and denominator as centered sums:
   $$\sum_{i=1}^{n} (x_i - \bar{x})(y_i - \bar{y})
   = \sum_{i=1}^{n} x_i y_i - n\bar{x}\bar{y}$$
   $$\sum_{i=1}^{n} (x_i - \bar{x})^2
   = \sum_{i=1}^{n} x_i^2 - n\bar{x}^2$$
   Thus
   $$\boxed{b_1 = \frac{\sum_{i=1}^{n} (x_i - \bar{x})(y_i - \bar{y})}
   {\sum_{i=1}^{n} (x_i - \bar{x})^2}}$$
   and then
   $$\boxed{b_0 = \bar{y} - b_1 \bar{x}}$$

Equivalently (using covariance and variance notation):
$$b_1 = \frac{\text{Cov}(X,Y)}{\text{Var}(X)}, \quad\text{where }\text{Cov}(X,Y)=\frac{1}{n}\sum (x_i-\bar{x})(y_i-\bar{y})$$

---

## Quick algorithm / pseudocode

1. Compute $\bar{x}$ and $\bar{y}$.
2. Compute numerator $=\sum (x_i - \bar{x})(y_i - \bar{y})$.
3. Compute denominator $=\sum (x_i - \bar{x})^2$.
4. Set $b_1 =$ numerator / denominator.
5. Set $b_0 = \bar{y} - b_1 \bar{x}$.

---

## Small numeric example

Data: $x=[1,2,3]$, $y=[2,3,5]$.

1. Means: $\bar{x}=(1+2+3)/3=2$, $\bar{y}=(2+3+5)/3=10/3$.
2. Numerator:
   $$\sum (x_i-\bar{x})(y_i-\bar{y})
   = (-1)\cdot(2-\tfrac{10}{3}) + 0\cdot(3-\tfrac{10}{3}) + 1\cdot(5-\tfrac{10}{3})
   = 1.3333\ldots + 0 + 1.6666\ldots = 3$$
3. Denominator:
   $$\sum (x_i-\bar{x})^2 = (-1)^2 + 0^2 + 1^2 = 2$$
4. Slope: $b_1 = 3 / 2 = 1.5$.
5. Intercept: $b_0 = \bar{y} - b_1\bar{x} = \tfrac{10}{3} - 1.5\cdot 2 = \tfrac{1}{3}$.

So the fitted line is:
$$\boxed{\hat{y} = \tfrac{1}{3} + 1.5x}$$

---

## Notes

* The formulas above are for **simple** linear regression (one predictor). For multiple predictors, the normal equations generalize to linear algebra form: $\boldsymbol{\beta} = (X^\top X)^{-1} X^\top y$.
* Use the sample versions (divide by $n-1$) when computing sample variances/covariances for inference (t-tests, confidence intervals).
* Squared errors (least squares) produce the best linear unbiased estimator under common assumptions (Gauss–Markov).


##  Making Predictions

Once we have our regression coefficients $b_0, b_1$, we can make predictions for new values of X:

$$\hat{y} = b_0 + b_1 \cdot x_{new}$$

![Prediction Example](image-1.png)

> **📈 Example of making predictions with the fitted regression line.**

**Why Linear Regression is Essential in Machine Learning:**

1. **Foundation for Complex Models**: Linear regression serves as the building block for more advanced ML algorithms like logistic regression, neural networks, and ensemble methods.

2. **Interpretability**: Unlike black-box models, linear regression provides clear insights into how each input variable affects the output, making it valuable for decision-making.

3. **Speed and Efficiency**: Training is fast and computationally inexpensive, making it ideal for real-time applications and large datasets.

4. **Baseline Model**: It's often used as a benchmark to compare the performance of more complex models.

5. **Feature Selection**: Helps identify which variables are most important for prediction through coefficient analysis.

**Real-world Applications:**

- Predicting house prices based on size, location, features
- Forecasting sales revenue from advertising spend
- Estimating medical costs from patient characteristics
- Stock price prediction using economic indicators

---