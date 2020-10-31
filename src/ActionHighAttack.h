#ifndef _ACTIONHIGHATTACK_H_INCLUDED
#define _ACTIONHIGHATTACK_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "Action.h"
#include "ActionType.h"

class CActionHighAttack : public CAction {
    public:
        CActionHighAttack() {
            m_szName = "ActionHighAttack";
            m_eActionType = enACTIONTYPE_HIGH_ATTACK;
        }
};

#endif // _ACTIONHIGHATTACK_H_INCLUDED
