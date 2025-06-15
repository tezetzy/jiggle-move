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

MYMODCFG(net.jaymods.stylepc, StylePc, 1.1, Jayzxy)

uintptr_t pGTASA;
void* hGTASA;

uintptr_t DrawMoney_BackTo;
extern "C" const char* DrawMoney_Patch(int isPositive)
{
    static const char* positiveT = "$%08d";
    static const char* negativeT = "-$%07d";
    
    return isPositive ? positiveT : negativeT;
}
__attribute__((optnone)) __attribute__((naked)) void DrawMoney_Inject(void)
{
    asm volatile(
        "LDR R5, [R0]\n"
        "SMLABB R0, R1, R11, R5\n"
        "PUSH {R0-R11}\n"
        "LDR R0, [SP, #8]\n"
        "BL DrawMoney_Patch\n"
        "STR R0, [SP, #4]\n");
    asm volatile(
        "MOV R12, %0\n"
        "POP {R0-R11}\n"
        "BX R12\n"
    :: "r" (DrawMoney_BackTo));
}

extern "C" void OnModLoad()
{
    logger->SetTag("StylePc");
    pGTASA = aml->GetLib("libGTASA.so");
  
    cfg->Bind("Author", "", "About")->SetString("JAYMODS 1.1r"); cfg->ClearLast();
    cfg->Bind("Discord", "", "About")->SetString("dsc.gg/jaymods"); cfg->ClearLast();
    cfg->Bind("GitHub", "", "About")->SetString("github.com/peterins/stylepc11"); cfg->ClearLast();

if(cfg->GetBool("StylePcJayMODS", true, "Visual"))
    {
        DrawMoney_BackTo = pGTASA + 0x2BD260 + 0x1;
        aml->Redirect(pGTASA + 0x2BD258 + 0x1, (uintptr_t)DrawMoney_Inject);
    }
}
