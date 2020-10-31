#ifndef _INPUTNETWORKCPU_H_INCLUDED
#define _INPUTNETWORKCPU_H_INCLUDED 0xBEBACAFE

#include "Input.h"

class CInputNetworkCPU : public CInput {
    public:
        CInputNetworkCPU()
            : m_eInputType(enINPUTTYPE_NETWORK_CPU) {
        }
};

#endif // _INPUTNETWORKCPU_H_INCLUDED
