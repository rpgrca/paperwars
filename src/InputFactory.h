#ifndef _INPUTFACTORY_H_INCLUDED
#define _INPUTFACTORY_H_INCLUDED 0xBEBACAFE

#include "Input.h"
#include "InputType.h"
#include "InputLocalHuman.h"
#include "InputNetworkHuman.h"
#include "InputLocalCPU.h"
#include "InputNetworkCPU.h"

class CInputFactory {
    public:
        CInput *Create(const enInputType eInputType) {
            CInput *pInput = NULL;

            switch (eInputType) {
                case enINPUTTYPE_NONE:
                    break;

                case enINPUTTYPE_UNKNOWN:
                    pInput = new CInput;
                    break;

                case enINPUTTYPE_LOCAL_HUMAN:
                    pInput = new CInputLocalHuman;
                    break;

                case enINPUTTYPE_NETWORK_HUMAN:
                    pInput = new CInputNetworkHuman;
                    break;

                case enINPUTTYPE_LOCAL_CPU:
                    pInput = new CInputLocalCPU;
                    break;

                case enINPUTTYPE_NETWORK_CPU:
                    pInput = new CInputNetworkCPU;
                    break;
            }

            return (pInput);
        }
};

#endif // _INPUTFACTORY_H_INCLUDED
