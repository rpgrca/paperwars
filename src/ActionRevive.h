#ifndef _ACTIONREVIVE_H_INCLUDED
#define _ACTIONREVIVE_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionRevive : public CAction {
    public:
        CActionRevive() {
            m_szName = "ActionRevive";
            m_eActionType = enACTIONTYPE_REVIVE;
        }
};

#endif // _ACTIONREVIVE_H_INCLUDED
