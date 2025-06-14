#pragma once
#include "Types.h"

struct CVector
{
    float x, y, z;
};

struct CVector2D
{
    float x, y;
};

struct CIntVector2D
{
    int x, y;
};

struct CMatrix
{
    CVector right;
    DWORD flags1;
    CVector up;
    DWORD flags2;
    CVector at;
    DWORD flags3;
    CVector pos;
    DWORD flags4;
};
