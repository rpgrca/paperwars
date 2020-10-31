#ifndef _ACTIONHIGHBLOCK_H_INCLUDED
#define _ACTIONHIGHBLOCK_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionHighBlock : public CAction {
    public:
        CActionHighBlock() {
            m_szName = "ActionHighBlock";
            m_eActionType = enACTIONTYPE_HIGH_BLOCK;
        }
};

#endif // _ACTIONHIGHBLOCK_H_INCLUDED
