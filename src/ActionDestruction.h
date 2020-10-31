#ifndef _ACTIONDESTRUCTION_H_INCLUDED
#define _ACTIONDESTRUCTION_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionDestruction : public CAction {
    public:
        CActionDestruction() {
            m_szName = "ActionDestruction";
            m_eActionType = enACTIONTYPE_DESTRUCTION;
        }
};

#endif // _ACTIONDESTRUCTION_H_INCLUDED
