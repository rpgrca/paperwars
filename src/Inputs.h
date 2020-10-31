#ifndef _INPUTS_H_INCLUDED
#define _INPUTS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Input.h"

class CInputs {
    private:
        std::vector<CInput *> m_pInputs;

    public:
       ~CInputs() {
            Clear();
        }

        bool Add(CInput *pInput) {
            bool bResult = false;

            if (pInput != NULL) {
                if (Find(pInput->GetID()) == NULL) {
                    m_pInputs.push_back(pInput);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CInput *pInput = NULL;
            std::vector<CInput *>::iterator pIterator;

            for (pIterator = m_pInputs.begin(); pIterator != m_pInputs.end(); ++pIterator) {
                pInput = (*pIterator);
                delete pInput;
            }

            m_pInputs.clear();
        }

        void Clear() {
            m_pInputs.clear();
        }

        CInput *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pInputs.size())
                return (m_pInputs.at(lIndex));
            else
                return (NULL);
        }

        CInput *Find(const long lID) {
            CInput *pInput = NULL;
            std::vector<CInput *>::iterator pIterator;

            for (pIterator = m_pInputs.begin(); pIterator != m_pInputs.end(); ++pIterator) {
                pInput = (*pIterator);
                if (pInput->GetID() == lID) {
                    return (pInput);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pInputs.size());
        }

        bool Remove(CInput *pInput) {
            CInput *pInputToFind = NULL;
            std::vector<CInput *>::iterator pIterator;
            bool bResult = false;

            if (pInput != NULL) {
                for (pIterator = m_pInputs.begin(); pIterator != m_pInputs.end(); ++pIterator) {
                    pInputToFind = (*pIterator);
                    if (pInputToFind->GetID() == pInput->GetID()) {
                        m_pInputs.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _INPUTS_H_INCLUDED
