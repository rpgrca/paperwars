#ifndef _BATTALIONS_H_INCLUDED
#define _BATTALIONS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Battalion.h"

class CBattalions {
    private:
        std::vector<CBattalion *> m_pBattalions;

    public:
       ~CBattalions() {
            Clear();
        }

        bool Add(CBattalion *pBattalion) {
            bool bResult = false;

            if (pBattalion != NULL) {
                if (Find(pBattalion->GetID()) == NULL) {
                    m_pBattalions.push_back(pBattalion);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CBattalion *pBattalion = NULL;
            std::vector<CBattalion *>::iterator pIterator;

            for (pIterator = m_pBattalions.begin(); pIterator != m_pBattalions.end(); ++pIterator) {
                pBattalion = (*pIterator);
                delete pBattalion;
            }

            m_pBattalions.clear();
        }

        void Clear() {
            m_pBattalions.clear();
        }

        CBattalion *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pBattalions.size())
                return (m_pBattalions.at(lIndex));
            else
                return (NULL);
        }

        CBattalion *Find(const long lID) {
            CBattalion *pBattalion = NULL;
            std::vector<CBattalion *>::iterator pIterator;

            for (pIterator = m_pBattalions.begin(); pIterator != m_pBattalions.end(); ++pIterator) {
                pBattalion = (*pIterator);
                if (pBattalion->GetID() == lID) {
                    return (pBattalion);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pBattalions.size());
        }

        bool Remove(CBattalion *pBattalion) {
            CBattalion *pBattalionToFind = NULL;
            std::vector<CBattalion *>::iterator pIterator;
            bool bResult = false;

            if (pBattalion != NULL) {
                for (pIterator = m_pBattalions.begin(); pIterator != m_pBattalions.end(); ++pIterator) {
                    pBattalionToFind = (*pIterator);
                    if (pBattalionToFind->GetID() == pBattalion->GetID()) {
                        m_pBattalions.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _BATTALIONS_H_INCLUDED
