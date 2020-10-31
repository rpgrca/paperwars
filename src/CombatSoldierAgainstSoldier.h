#ifndef _COMBATSOLDIERAGAINSTSOLDIER_H_INCLUDED
#define _COMBATSOLDIERAGAINSTSOLDIER_H_INCLUDED 0xBEBACAFE

#include "Combat.h"
#include "CombatType.h"

class CCombatSoldierAgainstSoldier : public CCombat {
    public:
        CCombatSoldierAgainstSoldier() {
            m_eType = enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER;
        }

        bool Round();
};

#endif // _COMBATSOLDIERAGAINSTSOLDIER_H_INCLUDED
