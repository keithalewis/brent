// brent.h - zeroin and fminbr routines
#pragma once

double zeroin(double ax, double bx, double(*f)(double), double tol);
double fminbr(double a, double b, double (*f)(double), double tol);