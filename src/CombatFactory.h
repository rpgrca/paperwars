#ifndef _COMBATFACTORY_H_INCLUDED
#define _COMBATFACTORY_H_INCLUDED 0xBEBACAFE

#include "Combat.h"
#include "CombatType.h"
#include "CombatSimple.h"
#include "CombatSoldierAgainstSoldier.h"
#include "CombatSoldierAgainstBattalion.h"
#include "CombatBattalionAgainstSoldier.h"
#include "CombatBattalionAgainstBattalion.h"

class CCombatFactory {
    public:
        CCombat *Create(const enCombatType eCombatType = enCOMBATTYPE_UNKNOWN) {
            CCombat *pCombat = NULL;

            switch (eCombatType) {
                case enCOMBATTYPE_NONE:
                    pCombat = NULL;
                    break;

                case enCOMBATTYPE_UNKNOWN:
                    pCombat = new CCombatSimple;
                    break;

                case enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER:
                    pCombat = new CCombatSoldierAgainstSoldier;
                    break;

                case enCOMBATTYPE_SOLDIER_AGAINST_BATTALION:
                    pCombat = new CCombatSoldierAgainstBattalion;
                    break;

                case enCOMBATTYPE_BATTALION_AGAINST_SOLDIER:
                    pCombat = new CCombatBattalionAgainstSoldier;
                    break;

                case enCOMBATTYPE_BATTALION_AGAINST_BATTALION:
                    pCombat = new CCombatBattalionAgainstBattalion;
                    break;
            }

            return (pCombat);
        }
};

#endif // _COMBATFACTORY_H_INCLUDED
