#include <cstdlib>
#include "Global.h"
#include "Battalion.h"
#include "Soldiers.h"
#include "Soldier.h"

CSoldier *CBattalion::GetRandomSoldier() {
    CSoldiers pSoldiers;
    unsigned long lIndex = 0;
    CSoldier *pSoldier = NULL;
    CGlobal *pGlobal = NULL;

    pGlobal = CGlobal::Instance();
    for (lIndex = 0; lIndex < m_pSoldiers.GetCount(); lIndex++) {
        pSoldier = m_pSoldiers.GetAt(lIndex);

        if (pGlobal->GetSoldierServices()->IsAlive(pSoldier)) {
            pSoldiers.Add(pSoldier);
        }
    }

    if (pSoldiers.GetCount() > 0) {
        lIndex = rand() % pSoldiers.GetCount();
        pSoldier = pSoldiers.GetAt(lIndex);
    }
    else
        pSoldier = NULL;

    return (pSoldier);
}
