#ifndef _COMBATSOLDIERAGAINSTBATTALION_H_INCLUDED
#define _COMBATSOLDIERAGAINSTBATTALION_H_INCLUDED 0xBEBACAFE

#include "Combat.h"
#include "CombatType.h"

class CCombatSoldierAgainstBattalion : public CCombat {
    public:
        CCombatSoldierAgainstBattalion() {
            m_eType = enCOMBATTYPE_SOLDIER_AGAINST_BATTALION;
        }

        bool Round();
};

#endif // _COMBATSOLDIERAGAINSTBATTALION_H_INCLUDED
