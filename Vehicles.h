#pragma once
#include "Vectors.h"

struct CMatrix;

struct CVehicle
{
    DWORD vtable;
    DWORD m_dwFlags;
    DWORD m_nVehicleType;
    CMatrix* m_pMatrix;
    CVector m_vecMoveSpeed;
    CVector m_vecTurnSpeed;
    float m_fMass;
    DWORD m_nModelIndex;
    BYTE m_nPrimaryColor;
    BYTE m_nSecondaryColor;
};
