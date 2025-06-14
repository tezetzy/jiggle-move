#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>
#include <dlfcn.h>
#include <vector>
#include <cctype>

//#include "GTASA_Structur.h"
#include "Peds.h"
#include "Weapons.h"
#include "Vectors.h"

MYMODCFG(net.rusjj.jpatch, JPatch, 1.0, RusJJ)


union ScriptVariables
{
    int      i;
    float    f;
    uint32_t u;
    void*    p;
};

uintptr_t pGTASA;
void* hGTASA;
static constexpr float fMagic = 50.0f / 30.0f;

CPlayerInfo* WorldPlayers;
CIntVector2D* windowSize;
CWeaponInfo* aWeaponInfo;

float *ms_fTimeStep;

int ret0(int a, ...) { return 0; } // Generic
int ret1(int a, ...) { return 1; } // Generic
void RedirectToRegister(unsigned char reg, uintptr_t addr, uintptr_t to)
{
    if(!addr) return;
    uintptr_t hook[2] = {(uintptr_t)(0x10000000*reg + 0x0000F8DF), to}; // idk
    if(addr & 1)
    {
        addr &= ~1;
        if (addr & 2)
        {
            aml->PlaceNOP(addr, 1); 
            addr += 2;
        }
        //hook[0] = 0x10000000*reg + 0x0000F8DF;
    }
    aml->Write(addr, (uintptr_t)hook, sizeof(hook));
}

extern "C" void adadad(void)
{
    //asm("VMOV.F32 S0, #0.5");
    asm("LDR PC, [PC, #-0x4]");
    //asm("MOVT R1, #0x42F0");
} // This one is used internally by myself. Helps me to get patched values.

DECL_HOOKv(ControlGunMove, void* self, CVector2D* vec2D)
{
    float save = *ms_fTimeStep;
    *ms_fTimeStep = fMagic;
    ControlGunMove(self, vec2D);
    *ms_fTimeStep = save;
}
uintptr_t SwimmingResistanceBack_BackTo;
float saveStep;
DECL_HOOKv(ProcessSwimmingResistance, void* self, CPed* ped)
{
    saveStep = *ms_fTimeStep;
    if(ped->m_nPedType == PED_TYPE_PLAYER1) *ms_fTimeStep *= 0.8954f/fMagic;
    else *ms_fTimeStep *= 1.14f/fMagic;
    ProcessSwimmingResistance(self, ped);
    *ms_fTimeStep = saveStep;
}
extern "C" void SwimmingResistanceBack(void)
{
    *ms_fTimeStep = saveStep;
}
__attribute__((optnone)) __attribute__((naked)) void SwimmingResistanceBack_inject(void)
{
    asm volatile(
        "push {r0-r11}\n"
        "bl SwimmingResistanceBack\n");
    asm volatile(
        "mov r12, %0\n"
        "pop {r0-r11}\n"
        "vldr s4, [r0]\n"
        "ldr r0, [r4]\n"
        "vmul.f32 s0, s4, s0\n"
        "bx r12\n"
    :: "r" (SwimmingResistanceBack_BackTo));
}

extern "C" void OnModLoad()
{
    cfg->Bind("Author", "", "About")->SetString("Jayzxy");
    cfg->Bind("IdeasFrom", "", "About")->SetString("MTA:SA Team, re3 contributors, JuniorDjjr, ThirteenAG, Blackbird88, 0x416c69, Whitetigerswt, XMDS, Peepo");
    cfg->Bind("Discord", "", "About")->SetString("dsc.gg/jaymods");
    cfg->Bind("GitHub", "", "About")->SetString("https://github.com/poretis/jaymods");
    cfg->Save();

    logger->SetTag("JPatch");
    pGTASA = aml->GetLib("libGTASA.so");
    hGTASA = dlopen("libGTASA.so", RTLD_LAZY);

    if(cfg->Bind("FixAimingWalkRifle", true, "Gameplay")->GetBool())
    {
        HOOKPLT(ControlGunMove, pGTASA + 0x66F9D0);
    }
    // Fix slow swimming speed
    if(cfg->Bind("SwimmingSpeedFix", true, "Gameplay")->GetBool())
    {
        SwimmingResistanceBack_BackTo = pGTASA + 0x53BD3A + 0x1;
        HOOKPLT(ProcessSwimmingResistance, pGTASA + 0x66E584);
        aml->Redirect(pGTASA + 0x53BD30 + 0x1, (uintptr_t)SwimmingResistanceBack_inject);
    }
}
