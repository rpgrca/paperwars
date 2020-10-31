#ifndef _ACTIONHEAL_H_INCLUDED
#define _ACTIONHEAL_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionHeal : public CAction {
    public:
        CActionHeal() {
            m_szName = "ActionHeal";
            m_eActionType = enACTIONTYPE_HEAL;
        }
};

#endif // _ACTIONHEAL_H_INCLUDED
