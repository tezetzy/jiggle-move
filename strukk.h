#pragma once

typedef unsigned int DWORD;
typedef unsigned char BYTE;

// Dummy RenderWare types
struct RwRaster {};
struct RwObject {};

// Vector structures
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

// Dummy engine types
struct CTaskManager {};
struct CWeaponInfo {};
struct CObject {};
struct CMatrix {}; // Tambahan jika kamu pakai CMatrix

// Ped types enum (as seen in re3 / MobileHook)
enum ePedType
{
    PED_TYPE_PLAYER1 = 0,
    PED_TYPE_PLAYER2,
    PED_TYPE_CIVMALE,
    PED_TYPE_CIVFEMALE,
    PED_TYPE_COP,
    PED_TYPE_GANG1,
    PED_TYPE_GANG2,
    PED_TYPE_GANG3,
    PED_TYPE_GANG4,
    PED_TYPE_GANG5,
    PED_TYPE_GANG6,
    PED_TYPE_GANG7,
    PED_TYPE_GANG8,
    PED_TYPE_GANG9,
    PED_TYPE_GANG10,
    PED_TYPE_DEALER,
    PED_TYPE_MEDIC,
    PED_TYPE_FIREMAN,
    PED_TYPE_CRIMINAL,
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
    PED_TYPE_UNUSED2,
    PED_TYPE_EMERGENCY,
    PED_TYPE_PLAYER_UNUSED,
    PED_TYPE_GANG_UNUSED,
    PED_TYPE_GANG11,
    PED_TYPE_GANG12,
};

// CPed struct versi lebih asli
struct CPed
{
    DWORD vtable;                // 0x00 - vtable pointer
    DWORD m_dwUnknown1;          // 0x04 - dummy
    ePedType m_nPedType;         // 0x08 - tipe ped (PLAYER1, COP, dll)
    DWORD m_nStatType;           // 0x0C
    CTaskManager* m_pTaskMgr;    // 0x10
    // Tambahkan lagi jika kamu perlu field lain
};

// CVehicle versi asli
struct CVehicle
{
    DWORD vtable;                // 0x00
    DWORD m_dwFlags;            // 0x04
    DWORD m_nVehicleType;       // 0x08
    CMatrix* m_pMatrix;         // 0x0C
    CVector m_vecMoveSpeed;     // 0x10
    CVector m_vecTurnSpeed;     // 0x1C
    float m_fMass;              // 0x28
    DWORD m_nModelIndex;        // 0x2C
    BYTE m_nPrimaryColor;       // 0x30
    BYTE m_nSecondaryColor;     // 0x31
    // Tambah sesuai kebutuhan
};



// Rw-related wrapper
struct CEntity
{
    RwObject* m_pRwObject;
    // Tambah jika perlu
};

// CWorld dummy
struct CWorld
{
    CObject* pObjects[350];
};
struct CWeapon
{
    DWORD m_nType;         // jenis senjata (mis. WEAPON_PISTOL)
    DWORD m_nState;        // state senjata (idle, reload, dll)
    DWORD m_nAmmoInClip;
    DWORD m_nTotalAmmo;
    float m_fTargetRange;
    float m_fAccuracy;
    CVector m_vecFireOffset; // offset peluru keluar
};
struct CPlayerPed : public CPed
{
    DWORD m_nPlayerNumber;
    bool m_bCanBeDamaged;
    float m_fStamina;
    // Tambahkan lain sesuai kebutuhan
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
struct CObject
{
    DWORD vtable;
    DWORD m_nObjectID;
    CVector m_vecPosition;
    float m_fScale;
    bool m_bIsStatic;
    // Tambahkan jika butuh (mis. m_pEntity)
};
