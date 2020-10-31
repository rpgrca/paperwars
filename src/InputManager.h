#ifndef _INPUTMANAGER_H_INCLUDED
#define _INPUTMANAGER_H_INCLUDED 0xBEBACAFE

#include "Input.h"
#include "InputType.h"
#include "InputFactory.h"
#include "Inputs.h"

class CInputManager {
    private:
        CInputs m_pInputs;

    public:
       ~CInputManager() {
            m_pInputs.Purge();
        }

        CInput *Create(const enInputType eInputType) {
            CInput *pInput = NULL;
            CInputFactory *pInputFactory = NULL;

            if (eInputType != NULL) {
                pInputFactory = new CInputFactory
                pInput = pInputFactory->Create(eInputType);
                delete pInputFactory;
            }

            return (pInput);
        }

        bool Delete(CInput *pInput) {
            bool bResult = false;

            if (m_pInputs.Remove(pInput)) {
                delete pInput;
                pInput = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CInput *Find(const long lID) {
            return (m_pInputs.Find(lID));
        }
};

#endif // _INPUTMANAGER_H_INCLUDED
