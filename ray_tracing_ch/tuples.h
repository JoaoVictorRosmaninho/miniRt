#ifndef TUPLES_H
#define TUPLES_H

#define color(red, green, blue) vector(red, green, blue)
#define PPM_DEPTH 255

typedef struct
{
    double x, y, z;
    double w;
} Tuple;

Tuple point(double x, double y, double z);
Tuple vector(double x, double y, double z);

Tuple tupleAdd(Tuple a, Tuple b);
Tuple tupleSub(Tuple a, Tuple b);
Tuple tupleNeg(Tuple a);
Tuple tupleMul(Tuple a, double c);
Tuple tupleDiv(Tuple a, double c);

double tupleMag(Tuple a);
Tuple tupleNorm(Tuple a);

double tupleDot(Tuple a, Tuple b);
Tuple tupleCross(Tuple a, Tuple b);
Tuple tupleProd(Tuple a, Tuple b);
Tuple tuplePPM(Tuple a);

#endif