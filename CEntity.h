#pragma once
#include "CVector.h"
#include "CMatrix.h"

// Enum jenis entity
enum eEntityType : uint8_t
{
    ENTITY_TYPE_NONE     = 0,
    ENTITY_TYPE_BUILDING = 1,
    ENTITY_TYPE_VEHICLE  = 2,
    ENTITY_TYPE_PED      = 3,
    ENTITY_TYPE_OBJECT   = 4,
    ENTITY_TYPE_DUMMY    = 5
};

// Flag biasa dipakai untuk kondisi entity
enum eEntityFlags
{
    ENTITY_FLAG_HAS_COLLISION     = 0x00000002,
    ENTITY_FLAG_IS_VISIBLE        = 0x00000004,
    ENTITY_FLAG_IS_STATIC         = 0x00000020,
    ENTITY_FLAG_COLLISIONPROCESSED= 0x00000040,
    ENTITY_FLAG_TOUCHINGWATER     = 0x00000080,
    ENTITY_FLAG_DRAW_LAST         = 0x00000100,
    // dan seterusnya...
};

// Struktur utama
struct CEntity
{
    void*        vtable;         // 0x00
    CMatrix*     matrix;         // 0x04 - Transformasi (nullptr jika tidak pakai)
    CVector      position;       // 0x08 - World pos jika tidak pakai matrix
    uint32_t     nFlags;         // 0x14 - Entity flags
    uint16_t     nScanCode;      // 0x18 - Untuk collision scan, internal use
    uint8_t      nType;          // 0x1A - Tipe entity (eEntityType)
    uint8_t      nStatus;        // 0x1B - Status entity
    uint8_t      bHasContacted;  // 0x1C
    uint8_t      bIsStatic;      // 0x1D
    uint8_t      bIsVisible;     // 0x1E
    uint8_t      bIsBIGBuilding; // 0x1F
    uint8_t      bRenderDamaged; // 0x20
    uint8_t      bStreamingDontDelete; // 0x21
    uint8_t      bRemoveFromWorld; // 0x22
    uint8_t      padding1;       // 0x23 - padding
    void*        pRwObject;      // 0x24 - pointer ke objek rendering (RpClump / RpAtomic)
    void*        pLod;           // 0x28 - Level of detail (CEntity*)
    int16_t      nRandomSeed;    // 0x2C - seed acak entity ini
    int16_t      nLevel;         // 0x2E - level dunia (0 = normal)
    // ... lanjut ke CPhysical
};
