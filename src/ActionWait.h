#ifndef _ACTIONWAIT_H_INCLUDED
#define _ACTIONWAIT_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionWait : public CAction {
    public:
        CActionWait() {
            m_szName = "ActionWait";
            m_eActionType = enACTIONTYPE_WAIT;
        }
};

#endif // _ACTIONWAIT_H_INCLUDED
