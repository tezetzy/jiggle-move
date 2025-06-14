#ifndef GTASA_STRUCTS_H
#define GTASA_STRUCTS_H

#include <cmath>
#include <cstdint>
/*
OFFSET GTASA v2.00
0x8B93FC - PlayerPed
0x8B8CC0 - Playerinfo
0x95B938 - Gametime
0x8B908C - Vehicle Pool
*/
/*
OFFSET GTASA V1.80
0x8B93FC - CPed
0x5A0 – Pointer ke slot senjata pertama
0x5A4 – Pointer ke slot senjata kedua
0x5A8 – Pointer ke slot senjata ketiga
0x5AC – Pointer ke slot senjata keempat
0x5B0 – Pointer ke slot senjata kelima
0xBA18FC - CVeh
0x37C – Status nitro (boolean)
0x38C – Flag kendaraan (bitmask)
0x48A – Jumlah slot nitro
0x8A4 – Timer nitro (float)
0x978 – Particle efek nitro 1
0x97C – Particle efek nitro 2
0x8B8CC0 - CEntity
0x36 – Jenis entitas (byte)
0x48 – Posisi X (float)
0x4C – Posisi Y (float)
0x50 – Posisi Z (float)
0x54 – Rotasi X (float)
0x58 – Rotasi Y (float)
0x5C – Rotasi Z (float)
*/
//
// CVector - 3D Vector
//
struct CVector
{
    float x, y, z;

    CVector() : x(0.0f), y(0.0f), z(0.0f) {}
    CVector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    CVector operator+(const CVector& rhs) const {
        return CVector(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    CVector operator-(const CVector& rhs) const {
        return CVector(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    float Magnitude() const {
        return std::sqrt(x*x + y*y + z*z);
    }
};

//
// CVector2D - 2D Vector
//
struct CVector2D
{
    float x, y;

    CVector2D() : x(0.0f), y(0.0f) {}
    CVector2D(float _x, float _y) : x(_x), y(_y) {}

    CVector2D operator+(const CVector2D& rhs) const {
        return CVector2D(x + rhs.x, y + rhs.y);
    }

    CVector2D operator-(const CVector2D& rhs) const {
        return CVector2D(x - rhs.x, y - rhs.y);
    }

    float Magnitude() const {
        return std::sqrt(x*x + y*y);
    }
};

//
// RwV3d - Raw 3D vector (RenderWare)
//
struct RwV3d
{
    float x, y, z;
};

//
// CMatrix - Transformation matrix
//
struct CMatrix
{
    CVector right;  // X-axis
    CVector up;     // Y-axis
    CVector at;     // Z-axis (direction)
    CVector pos;    // Position in world
};

//
// CEntity - Base game object
//
struct CEntity
{
    void* vtable;       // Virtual function table
    CMatrix* matrix;    // Pointer to transformation matrix
    uint32_t flags;     // Entity flags
    uint16_t modelIndex;
    uint8_t type;       // Type: ped, vehicle, object
    uint8_t status;     // Status: active, inactive, etc.
};
/* CPed */
struct CPed {
    DWORD vtable;          // Virtual table pointer
    DWORD unknown1;
    CEntity *pEntity;      // Pointer ke entitas umum
    DWORD pedType;
    DWORD pedStats;
    CTaskManager *pTaskManager;
    // Banyak data lainnya tergantung versi game
};
/* CVeh */
struct CVehicle {
    DWORD vtable;
    CEntity *pEntity;
    DWORD vehicleType;
    float health;
    DWORD modelIndex;
    BYTE color1, color2;
    // dsb
};
struct CPlayerInfo {
    CPed* pPed;           // Pointer ke CPed pemain
    uint32_t nMoney;      // Uang
    float fFat;
    float fStamina;
    uint8_t nWeaponSlots[13]; // senjata
    // dst, tergantung versi
};
struct CWeapon {
    uint32_t type;
    uint32_t ammo;
    uint32_t state;
};
struct CGame {
    CPed* playerPed;
    CVehicle* currentVehicle;
    uint32_t gameState;
    float gameTime;
};
struct RwTexture {
    RwRaster* raster;
    char name[32];
    // dsb
};
struct CModelInfo {
    uint16_t modelID;
    RwObject* pRwObject;
    uint32_t flags;
    // dsb
};
struct CWorld {
    CPed* pPeds[100];
    CVehicle* pVehicles[200];
    CObject* pObjects[350];
    int32_t numPeds;
    int32_t numVehicles;
    // dst
};
#endif // GTASA_STRUCTS_H
