#pragma once
#include "Vectors.h"
#include "RenderWare.h"

struct CEntity
{
    RwObject* m_pRwObject;
    BYTE m_nType;      // entity type (ped, vehicle, object, etc.)
    BYTE m_nStatus;
    WORD m_wFlags;
};

struct CPhysical : public CEntity
{
    CVector m_vecMoveSpeed;
    CVector m_vecTurnSpeed;
    CVector m_vecForce;
    CVector m_vecTorque;
    float m_fMass;
    float m_fTurnMass;
    float m_fVelocity;
    float m_fAirResistance;
    float m_fElasticity;
    float m_fBuoyancyConstant;
};

struct CObject : public CPhysical
{
    DWORD m_nObjectID;
    bool m_bIsStatic;
    bool m_bIsPickup;
    bool m_bHasCollision;
    float m_fScale;
    CMatrix* m_pMatrix;
};
