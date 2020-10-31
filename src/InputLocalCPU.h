#ifndef _INPUTLOCALCPU_H_INCLUDED
#define _INPUTLOCALCPU_H_INCLUDED 0xBEBACAFE

#include "Input.h"

class CInputLocalCPU : public CInput {
    public:
        CInputLocalCPU()
            : m_eInputType(enINPUTTYPE_LOCAL_CPU) {
        }
};

#endif // _INPUTLOCALCPU_H_INCLUDED
