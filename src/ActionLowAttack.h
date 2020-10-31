#ifndef _ACTIONLOWATTACK_H_INCLUDED
#define _ACTIONLOWATTACK_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "Action.h"
#include "ActionType.h"

class CActionLowAttack : public CAction {
    public:
        CActionLowAttack() {
            m_szName = "ActionLowAttack";
            m_eActionType = enACTIONTYPE_LOW_ATTACK;
        }
};

#endif // _ACTIONLOWATTACK_H_INCLUDED
