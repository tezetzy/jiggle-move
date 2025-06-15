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

enum eWeaponType {
    WEAPON_BRASSKNUCKLE = 0,
    WEAPON_GOLFCLUB,
    WEAPON_NITESTICK,
    WEAPON_KNIFE,
    WEAPON_BAT,
    WEAPON_SHOVEL,
    WEAPON_POOLSTICK,
    WEAPON_KATANA,
    WEAPON_CHAINSAW,
    WEAPON_DILDO1,
    WEAPON_DILDO2,
    WEAPON_VIBE1,
    WEAPON_VIBE2,
    WEAPON_FLOWERS,
    WEAPON_CANE,
    WEAPON_GRENADE,
    WEAPON_TEARGAS,
    WEAPON_MOLOTOV,
    WEAPON_COLT45,
    WEAPON_SILENCED,
    WEAPON_DEAGLE,
    WEAPON_SHOTGUN,
    WEAPON_SAWEDOFF,
    WEAPON_SPAS12,
    WEAPON_UZI,
    WEAPON_MP5,
    WEAPON_AK47,
    WEAPON_M4,
    WEAPON_TEC9,
    WEAPON_RIFLE,
    WEAPON_SNIPERRIFLE,
    // ...
};

bool IsWeaponUsingScope(int weaponID)
{
    return weaponID == WEAPON_SNIPERRIFLE || weaponID == WEAPON_RIFLE || weaponID == WEAPON_M4;
}

bool FireInstantHit(
    CEntity* shooter,       // a2
    CVector* origin,        // a3
    CVector* target,        // a4
    CEntity* victim,        // a5
    CVector* victimPos,     // a6
    CVector* shootDir,      // a7
    int damage,             // a8
    int weaponType          // a9
);
