#ifndef _INPUTLOCALHUMAN_H_INCLUDED
#define _INPUTLOCALHUMAN_H_INCLUDED 0xBEBACAFE

#include "Input.h"

class CInputLocalHuman : public CInput {
    public:
        CInputLocalHuman()
            : m_eInputType(enINPUTTYPE_LOCAL_HUMAN) {
        }
};

#endif // _INPUTLOCALHUMAN_H_INCLUDED
