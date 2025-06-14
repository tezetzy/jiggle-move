#pragma once
#include "Vectors.h"

typedef unsigned int DWORD;
typedef unsigned char BYTE;

struct CTaskManager {};

enum ePedType
{
    PED_TYPE_PLAYER1 = 0,
    PED_TYPE_PLAYER2,
    PED_TYPE_CIVMALE,
    PED_TYPE_CIVFEMALE,
    PED_TYPE_COP,
    PED_TYPE_GANG1,
    PED_TYPE_GANG2,
    PED_TYPE_MEDIC,
    PED_TYPE_CRIMINAL,
    PED_TYPE_FIREMAN,
    PED_TYPE_BUM,
    PED_TYPE_PROSTITUTE,
    PED_TYPE_SPECIAL,
    PED_TYPE_MISSION1,
    PED_TYPE_MISSION2,
    PED_TYPE_MISSION3,
    PED_TYPE_MISSION4,
    PED_TYPE_MISSION5,
    PED_TYPE_MISSION6,
    PED_TYPE_MISSION7,
    PED_TYPE_MISSION8,
    PED_TYPE_UNUSED1,
    PED_TYPE_GANG9,
    PED_TYPE_GANG10,
    PED_TYPE_GANG11,
    PED_TYPE_GANG12,
};

struct CPed
{
    DWORD vtable;
    DWORD m_dwUnk1;
    ePedType m_nPedType;
    DWORD m_nStatType;
    CTaskManager* m_pTaskMgr;
};

struct CPlayerPed : public CPed
{
    DWORD m_nPlayerNumber;
    bool m_bCanBeDamaged;
    float m_fStamina;
};
