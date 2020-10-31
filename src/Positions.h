#ifndef _POSITIONS_H_INCLUDED
#define _POSITIONS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Position.h"

class CPositions {
    private:
        std::vector<CPosition *> m_pPositions;

    public:
       ~CPositions() {
            Clear();
        }

        bool Add(CPosition *pPosition) {
            bool bResult = false;

            if (pPosition != NULL) {
                if (Find(pPosition->GetID()) == NULL) {
                    m_pPositions.push_back(pPosition);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CPosition *pPosition = NULL;
            std::vector<CPosition *>::iterator pIterator;

            for (pIterator = m_pPositions.begin(); pIterator != m_pPositions.end(); ++pIterator) {
                pPosition = (*pIterator);
                delete pPosition;
            }

            m_pPositions.clear();
        }

        void Clear() {
            m_pPositions.clear();
        }

        CPosition *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pPositions.size())
                return (m_pPositions.at(lIndex));
            else
                return (NULL);
        }

        CPosition *Find(const long lID) {
            CPosition *pPosition = NULL;
            std::vector<CPosition *>::iterator pIterator;

            for (pIterator = m_pPositions.begin(); pIterator != m_pPositions.end(); ++pIterator) {
                pPosition = (*pIterator);
                if (pPosition->GetID() == lID) {
                    return (pPosition);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pPositions.size());
        }

        bool Remove(CPosition *pPosition) {
            CPosition *pPositionToFind = NULL;
            std::vector<CPosition *>::iterator pIterator;
            bool bResult = false;

            if (pPosition != NULL) {
                for (pIterator = m_pPositions.begin(); pIterator != m_pPositions.end(); ++pIterator) {
                    pPositionToFind = (*pIterator);
                    if (pPositionToFind->GetID() == pPosition->GetID()) {
                        m_pPositions.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _POSITIONS_H_INCLUDED
