#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#include "vectors.h"

Vec2 vec2Add(const Vec2 a, const Vec2 b)
{
    Vec2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

Vec2 vec2Sub(const Vec2 a, const Vec2 b)
{
    Vec2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

Vec2 vec2Mul(const Vec2 a, const double b)
{
    Vec2 result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

Vec2 vec2Div(const Vec2 a, const double b)
{
    Vec2 result;
    result.x = a.x / b;
    result.y = a.y / b;
    return result;
}

Vec2 vec2Neg(const Vec2 a)
{
    Vec2 result;
    result.x = -a.x;
    result.y = -a.y;
    return result;
}

double vec2Mag(const Vec2 a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

Vec2 vec2Norm(const Vec2 a)
{
    return vec2Div(a, vec2Mag(a));
}

double vec2Dot(const Vec2 a, const Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

Vec2 vec2Prod(const Vec2 a, const Vec2 b)
{
    Vec2 result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    return result;
}

Vec3 vec3Add(const Vec3 a, const Vec3 b)
{
    Vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vec3 vec3Sub(const Vec3 a, const Vec3 b)
{
    Vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vec3 vec3Mul(const Vec3 a, const double b)
{
    Vec3 result;
    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;
    return result;
}

Vec3 vec3Div(const Vec3 a, const double b)
{
    Vec3 result;
    result.x = a.x / b;
    result.y = a.y / b;
    result.z = a.z / b;
    return result;
}

Vec3 vec3Neg(Vec3 a)
{
    Vec3 result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    return result;
}

double vec3Mag(const Vec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vec3 vec3Norm(const Vec3 a)
{
    return vec3Div(a, vec3Mag(a));
}

double vec3Dot(const Vec3 a, const Vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec3Cross(const Vec3 a, const Vec3 b)
{
    Vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

Vec3 vec3Prod(const Vec3 a, const Vec3 b)
{
    Vec3 result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return result;
}

Vec3 vec3PPM(const Vec3 a)
{
    Vec3 result;
    result.x = fmin(fmax(0, a.x * PPM_DEPTH), PPM_DEPTH);
    result.y = fmin(fmax(0, a.y * PPM_DEPTH), PPM_DEPTH);
    result.z = fmin(fmax(0, a.z * PPM_DEPTH), PPM_DEPTH);
    return result;
}

Vec4 vec4Add(const Vec4 a, const Vec4 b)
{
    Vec4 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

Vec4 vec4Sub(const Vec4 a, const Vec4 b)
{
    Vec4 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

Vec4 vec4Mul(const Vec4 a, const double b)
{
    Vec4 result;
    result.x = a.x * b;
    result.y = a.y * b;
    result.z = a.z * b;
    result.w = a.w * b;
    return result;
}

Vec4 vec4Div(const Vec4 a, const double b)
{
    Vec4 result;
    result.x = a.x / b;
    result.y = a.y / b;
    result.z = a.z / b;
    result.w = a.w / b;
    return result;
}

Vec4 vec4Neg(const Vec4 a)
{
    Vec4 result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    result.w = -a.w;
    return result;
}

double vec4Mag(const Vec4 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

Vec4 vec4Norm(const Vec4 a)
{
    return vec4Div(a, vec4Mag(a));
}

double vec4Dot(const Vec4 a, const Vec4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec4 vec4Prod(Vec4 a, Vec4 b)
{
    Vec4 result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    result.w = a.w * b.w;
    return result;
}

Vec4 vec4Reflect(const Vec4 vec, const Vec4 normal)
{
    return vec4Sub(vec, vec4Mul(normal, 2 * vec4Dot(vec, normal)));
}

bool mat2Eq(const Mat2 a, const Mat2 b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (fabs(a.elem[i][j] - b.elem[i][j]) >= MAT_EPSILON)
            {
                return false;
            }
        }
    }
    return true;
}

bool mat3Eq(const Mat3 a, const Mat3 b)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (fabs(a.elem[i][j] - b.elem[i][j]) >= MAT_EPSILON)
            {
                return false;
            }
        }
    }
    return true;
}

bool mat4Eq(const Mat4 a, const Mat4 b)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (fabs(a.elem[i][j] - b.elem[i][j]) >= MAT_EPSILON)
            {
                return false;
            }
        }
    }
    return true;
}

Mat2 mat2Mul(const Mat2 a, const Mat2 b)
{
    Mat2 result;
    result.elem[0][0] = a.elem[0][0] * b.elem[0][0] + a.elem[0][1] * b.elem[1][0];
    result.elem[0][1] = a.elem[0][0] * b.elem[0][1] + a.elem[0][1] * b.elem[1][1];
    result.elem[1][0] = a.elem[1][0] * b.elem[0][0] + a.elem[1][1] * b.elem[1][0];
    result.elem[1][1] = a.elem[1][0] * b.elem[0][1] + a.elem[1][1] * b.elem[1][1];
    return result;
}

Mat3 mat3Mul(const Mat3 a, const Mat3 b)
{
    Mat3 result = {0};
    for (size_t row = 0; row < 3; row++)
    {
        for (size_t col = 0; col < 3; col++)
        {
            for (size_t i = 0; i < 3; i++)
            {
                result.elem[row][col] += a.elem[row][i] * b.elem[i][col];
            }
        }
    }
    return result;
}

Mat4 mat4Mul(const Mat4 a, const Mat4 b)
{
    Mat4 result = {0};
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++)
        {
            for (size_t i = 0; i < 4; i++)
            {
                result.elem[row][col] += a.elem[row][i] * b.elem[i][col];
            }
        }
    }
    return result;
}

Vec2 mat2VecMul(const Mat2 mat, const Vec2 vec)
{
    Vec2 result;
    result.x = vec.x * mat.elem[0][0] + vec.y * mat.elem[0][1];
    result.y = vec.x * mat.elem[1][0] + vec.y * mat.elem[1][1];
    return result;
}

Vec3 mat3VecMul(const Mat3 mat, const Vec3 vec)
{
    Vec3 result;
    result.x = vec.x * mat.elem[0][0] + vec.y * mat.elem[0][1] + vec.z * mat.elem[0][2];
    result.y = vec.x * mat.elem[1][0] + vec.y * mat.elem[1][1] + vec.z * mat.elem[1][2];
    result.z = vec.x * mat.elem[2][0] + vec.y * mat.elem[2][1] + vec.z * mat.elem[2][2];
    return result;
}

Vec4 mat4VecMul(const Mat4 mat, const Vec4 vec)
{
    Vec4 result;
    result.x = vec.x * mat.elem[0][0] + vec.y * mat.elem[0][1] + vec.z * mat.elem[0][2] + vec.w * mat.elem[0][3];
    result.y = vec.x * mat.elem[1][0] + vec.y * mat.elem[1][1] + vec.z * mat.elem[1][2] + vec.w * mat.elem[1][3];
    result.z = vec.x * mat.elem[2][0] + vec.y * mat.elem[2][1] + vec.z * mat.elem[2][2] + vec.w * mat.elem[2][3];
    result.w = vec.x * mat.elem[3][0] + vec.y * mat.elem[3][1] + vec.z * mat.elem[3][2] + vec.w * mat.elem[3][3];
    return result;
}

Mat2 mat2Trans(const Mat2 a)
{
    Mat2 result;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            result.elem[i][j] = a.elem[j][i];
            result.elem[j][i] = a.elem[i][j];
        }
    }
    return result;
}

Mat3 mat3Trans(const Mat3 a)
{
    Mat3 result;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            result.elem[i][j] = a.elem[j][i];
            result.elem[j][i] = a.elem[i][j];
        }
    }
    return result;
}

Mat4 mat4Trans(const Mat4 a)
{
    Mat4 result;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            result.elem[i][j] = a.elem[j][i];
            result.elem[j][i] = a.elem[i][j];
        }
    }
    return result;
}

double mat2Det(const Mat2 a)
{
    return a.elem[0][0] * a.elem[1][1] - a.elem[1][0] * a.elem[0][1];
}

Mat2 mat3SubM(const size_t row, const size_t col, const Mat3 a)
{
    size_t skipRow = 0;
    size_t skipCol = 0;
    Mat2 result;
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if (i == row || j == col)
            {
                if (i == row)
                {
                    skipRow = 1;
                    result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
                }
                if (j == col)
                {
                    skipCol = 1;
                    result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
                }
            }
            else
            {
                result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
            }
        }
        skipCol = 0;
    }
    return result;
}

Mat3 mat4SubM(const size_t row, const size_t col, const Mat4 a)
{
    size_t skipRow = 0;
    size_t skipCol = 0;
    Mat3 result;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (i == row || j == col)
            {
                if (i == row)
                {
                    skipRow = 1;
                    result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
                }
                if (j == col)
                {
                    skipCol = 1;
                    result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
                }
            }
            else
            {
                result.elem[i][j] = a.elem[i + skipRow][j + skipCol];
            }
        }
        skipCol = 0;
    }
    return result;
}

double mat3Min(const size_t row, const size_t col, const Mat3 a)
{
    return mat2Det(mat3SubM(row, col, a));
}

double mat3Cof(const size_t row, const size_t col, const Mat3 a)
{
    if (row % 2 != col % 2)
    {
        return -mat3Min(row, col, a);
    }
    else
    {
        return mat3Min(row, col, a);
    }
}

double mat3Det(const Mat3 a)
{
    double determinant = 0;
    for (size_t col = 0; col < 3; col++)
    {
        determinant += a.elem[0][col] * mat3Cof(0, col, a);
    }
    return determinant;
}

double mat4Min(const size_t row, const size_t col, const Mat4 a)
{
    return mat3Det(mat4SubM(row, col, a));
}

double mat4Cof(const size_t row, const size_t col, const Mat4 a)
{
    if (row % 2 != col % 2)
    {
        return -mat4Min(row, col, a);
    }
    else
    {
        return mat4Min(row, col, a);
    }
}

double mat4Det(const Mat4 a)
{
    double determinant = 0;
    for (size_t col = 0; col < 4; col++)
    {
        determinant += a.elem[0][col] * mat4Cof(0, col, a);
    }
    return determinant;
}

Mat4 mat4Inv(const Mat4 a)
{
    double determinant = mat4Det(a);
    Mat4 inverted;
    for (size_t col = 0; col < 4; col++)
    {
        for (size_t row = 0; row < 4; row++)
        {
            inverted.elem[col][row] = mat4Cof(row, col, a) / determinant;
        }
    }
    return inverted;
}

Mat4 viewTransform(const Vec4 origin, const Vec4 destination, Vec4 up)
{
    const Vec3 forward = vec3Norm(vec3Sub(destination.xyz, origin.xyz));
    up.xyz = vec3Norm(up.xyz);
    const Vec3 left = vec3Cross(forward, up.xyz);
    up.xyz = vec3Cross(left, forward);
    Mat4 viewTransform = {{{left.x, left.y, left.z, 0},
                           {up.x, up.y, up.z, 0},
                           {-forward.x, -forward.y, -forward.z, 0},
                           {0, 0, 0, 1}}};
    return mat4Mul(viewTransform, translation(-origin.x, -origin.y, -origin.z));
}