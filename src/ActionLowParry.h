#ifndef _ACTIONLOWPARRY_H_INCLUDED
#define _ACTIONLOWPARRY_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionLowParry : public CAction {
    public:
        CActionLowParry() {
            m_szName = "ActionLowParry";
            m_eActionType = enACTIONTYPE_LOW_PARRY;
        }
};

#endif // _ACTIONLOWPARRY_H_INCLUDED
