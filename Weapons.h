#pragma once
#include "Vectors.h"

struct CWeapon
{
    DWORD m_nType;
    DWORD m_nState;
    DWORD m_nAmmoInClip;
    DWORD m_nTotalAmmo;
    float m_fTargetRange;
    float m_fAccuracy;
    CVector m_vecFireOffset;
};

struct CWeaponInfo
{
    DWORD m_nWeaponFireType;
    DWORD m_nWeaponType;
    DWORD m_nSlot;
    DWORD m_dwFlags;
    float m_fTargetRange;
    float m_fAccuracy;
    float m_fMoveSpeed;
    float m_fAnimLoopStart;
    float m_fAnimLoopEnd;
    float m_fAnimFireTime;
    float m_fAnim2LoopStart;
    float m_fAnim2LoopEnd;
    float m_fAnim2FireTime;
    DWORD m_nModelID1;
    DWORD m_nModelID2;
};
