#ifndef _COMBATMANAGER_H_INCLUDED
#define _COMBATMANAGER_H_INCLUDED 0xBEBACAFE

#include "Object.h"
#include "CombatType.h"
#include "CombatFactory.h"
#include "Combat.h"
#include "Combats.h"

class CCombatManager {
    private:
        CCombats m_pCombats;

    public:
       ~CCombatManager() {
            m_pCombats.Purge();
        }

        CCombat *Create(const enCombatType eCombatType = enCOMBATTYPE_UNKNOWN, CObject *pAttacker = NULL, CObject *pDefender = NULL) {
            CCombat *pCombat = NULL;
            CCombatFactory *pCombatFactory = NULL;
            enCombatType eType = enCOMBATTYPE_UNKNOWN;

            eType = eCombatType;
            if (eType == enCOMBATTYPE_UNKNOWN) {
                if ((pAttacker != NULL) && (pDefender != NULL)) {
                    if (dynamic_cast<CSoldier *>(pAttacker) != NULL)
                        if (dynamic_cast<CSoldier *>(pDefender) != NULL)
                            eType = enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER;
                        else
                            eType = enCOMBATTYPE_SOLDIER_AGAINST_BATTALION;
                    else
                        if (dynamic_cast<CSoldier *>(pDefender) != NULL)
                            eType = enCOMBATTYPE_BATTALION_AGAINST_SOLDIER;
                        else
                            eType = enCOMBATTYPE_BATTALION_AGAINST_BATTALION;
                }
            }

            pCombatFactory = new CCombatFactory;
            pCombat = pCombatFactory->Create(eType);
            delete pCombatFactory;

            if (pAttacker != NULL)
                pCombat->SetAttacker(pAttacker);

            if (pDefender != NULL)
                pCombat->SetDefender(pAttacker);

            m_pCombats.Add(pCombat);
            return (pCombat);
        }

        bool Delete(CCombat *pCombat) {
            bool bResult = false;

            if (m_pCombats.Remove(pCombat)) {
                delete pCombat;
                pCombat = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CCombat *Find(long lID) {
            return (m_pCombats.Find(lID));
        }
};

#endif // _COMBATMANAGER_H_INCLUDED
