#pragma once
#include "Peds.h"

struct CPlayerInfo
{
    CPed* m_pPed;
    DWORD m_nMoney;
    DWORD m_nScore;
    float m_fFat;
    float m_fStamina;
    float m_fMuscle;
    DWORD m_nModelIndex;
    // dan properti lainnya sesuai kebutuhan
};
