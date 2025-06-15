#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>
#include <dlfcn.h>
#include <vector>
#include <cctype>

//#include "GTASA_Structur.h"
#include "Weapons.h"
#include "Peds.h"
#include "Vehicles.h"
#include "Vectors.h"
#include "RenderWare.h"
#include "Types.h"
#include "PlayerInfo.h"
#include "CEntity.h"

MYMODCFG(net.jaymods.sfx, SpreadFix, 1.0, Jayzxy)

uintptr_t pGTASA;
void* hGTASA;
float *fPlayerAimRotRate;
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
DECL_HOOK(bool, FireInstantHit, CWeapon *self, CEntity *a2, CVector *a3, CVector *a4, CEntity *a5, CVector *a6, CVector *a7, int a8, int a9)
{
    *fPlayerAimRotRate = (rand() * 2.0f * M_PI) / (float)RAND_MAX;
    return FireInstantHit(self, a2, a3, a4, a5, a6, a7, a8, a9);
}
extern "C" void OnModLoad()
{
    logger->SetTag("SpreadFix");
    pGTASA = aml->GetLib("libGTASA.so");
    hGTASA = dlopen("libGTASA.so", RTLD_LAZY);
    cfg->Bind("Author", "", "About")->SetString("Jayzxy"); cfg->ClearLast();
    cfg->Bind("IdeasFrom", "", "About")->SetString("MTA:SA Team, Peepo"); cfg->ClearLast();
    cfg->Bind("Discord", "", "About")->SetString("dsc.gg/jaymods"); cfg->ClearLast();
    cfg->Bind("GitHub", "", "About")->SetString("https://github.com/poretis/jaymods"); cfg->ClearLast();

if(cfg->GetBool("WSFXV1JAY", true, "Gameplay"))
    {
       SET_TO(fPlayerAimRotRate,       aml->GetSym(hGTASA, "fPlayerAimRotRate"));
       HOOK(FireInstantHit, aml->GetSym(hGTASA, "_ZN7CWeapon14FireInstantHitEP7CEntityP7CVectorS3_S1_S3_S3_bb"));
    }
}
