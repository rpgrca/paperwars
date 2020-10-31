#ifndef _INPUTNETWORKHUMAN_H_INCLUDED
#define _INPUTNETWORKHUMAN_H_INCLUDED 0xBEBACAFE

#include "Input.h"

class CInputNetworkHuman : public CInput {
    public:
        CInputType()
            : m_eInputType(enINPUTTYPE_NETWORK_HUMAN) {
        }
};

#endif // _INPUTNETWORKHUMAN_H_INCLUDED
