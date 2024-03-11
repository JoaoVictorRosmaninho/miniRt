#include <math.h>
#include <stddef.h>

#include "tuples.h"

Tuple point(const double x, const double y, const double z)
{
    return (Tuple){x, y, z, 1};
}

Tuple vector(const double x, const double y, const double z)
{
    return (Tuple){x, y, z, 0};
}

Tuple tupleAdd(const Tuple a, const Tuple b)
{
    return (Tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};
}

Tuple tupleSub(const Tuple a, const Tuple b)
{
    return (Tuple){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};
}

Tuple tupleNeg(const Tuple a)
{
    return (Tuple){-a.x, -a.y, -a.z, -a.w};
}

Tuple tupleMul(const Tuple a, const double c)
{
    return (Tuple){c * a.x, c * a.y, c * a.z, c * a.w};
}

Tuple tupleDiv(const Tuple a, const double c)
{
    return (Tuple){a.x / c, a.y / c, a.z / c, a.w / c};
}

double tupleMag(const Tuple a)
{
    return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.w, 2));
}

Tuple tupleNorm(const Tuple a)
{
    double mag = tupleMag(a);
    return (Tuple){a.x / mag, a.y / mag, a.z / mag, a.w / mag};
}

double tupleDot(const Tuple a, const Tuple b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Tuple tupleCross(const Tuple a, const Tuple b)
{
    return (Tuple){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0};
}

Tuple tupleProd(const Tuple a, const Tuple b)
{
    return (Tuple){a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w};
}

Tuple tuplePPM(const Tuple a)
{
    return (Tuple){.x = fmin(fmax(0, a.x * PPM_DEPTH), PPM_DEPTH),
                   .y = fmin(fmax(0, a.y * PPM_DEPTH), PPM_DEPTH),
                   .z = fmin(fmax(0, a.z * PPM_DEPTH), PPM_DEPTH),
                   .w = fmin(fmax(0, a.w * PPM_DEPTH), PPM_DEPTH)};
}