#ifndef _ACTIONLOWBLOCK_H_INCLUDED
#define _ACTIONLOWBLOCK_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionLowBlock : public CAction {
    public:
        CActionLowBlock() {
            m_szName = "ActionLowBlock";
            m_eActionType = enACTIONTYPE_LOW_BLOCK;
        }
};

#endif // _ACTIONLOWBLOCK_H_INCLUDED
