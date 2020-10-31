#ifndef _ACTIONHIGHPARRY_H_INCLUDED
#define _ACTIONHIGHPARRY_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionHighParry : public CAction {
    public:
        CActionHighParry() {
            m_szName = "ActionHighParry";
            m_eActionType = enACTIONTYPE_HIGH_PARRY;
        }
};

#endif // _ACTIONHIGHPARRY_H_INCLUDED
