#ifndef _COMBATBATTALIONAGAINSTBATTALION_H_INCLUDED
#define _COMBATBATTALIONAGAINSTBATTALION_H_INCLUDED 0xBEBACAFE

#include <cstdlib>
#include "Combat.h"
#include "CombatType.h"

class CCombatBattalionAgainstBattalion : public CCombat {
    public:
        CCombatBattalionAgainstBattalion() {
            m_eType = enCOMBATTYPE_BATTALION_AGAINST_BATTALION;
        }

        bool Round();
};

#endif // _COMBATBATTALIONAGAINSTBATTALION_H_INCLUDED
