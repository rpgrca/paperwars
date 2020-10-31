#ifndef _COMBATBATTALIONAGAINSTSOLDIER_H_INCLUDED
#define _COMBATBATTALIONAGAINSTSOLDIER_H_INCLUDED 0xBEBACAFE

#include <cstdlib>
#include "Combat.h"
#include "CombatType.h"

class CCombatBattalionAgainstSoldier : public CCombat {
    public:
        CCombatBattalionAgainstSoldier() {
            m_eType = enCOMBATTYPE_BATTALION_AGAINST_SOLDIER;
        }

        bool Round();
};

#endif // _COMBATBATTALIONAGAINSTSOLDIER_H_INCLUDED
