#ifndef _MAPS_H_INCLUDED
#define _MAPS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Map.h"

class CMaps {
    private:
        std::vector<CMap *> m_pMaps;

    public:
       ~CMaps() {
            Clear();
        }

        bool Add(CMap *pMap) {
            bool bResult = false;

            if (pMap != NULL) {
                if (Find(pMap->GetID()) == NULL) {
                    m_pMaps.push_back(pMap);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CMap *pMap = NULL;
            std::vector<CMap *>::iterator pIterator;

            for (pIterator = m_pMaps.begin(); pIterator != m_pMaps.end(); ++pIterator) {
                pMap = (*pIterator);
                delete pMap;
            }

            m_pMaps.clear();
        }

        void Clear() {
            m_pMaps.clear();
        }

        CMap *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pMaps.size())
                return (m_pMaps.at(lIndex));
            else
                return (NULL);
        }

        CMap *Find(const long lID) {
            CMap *pMap = NULL;
            std::vector<CMap *>::iterator pIterator;

            for (pIterator = m_pMaps.begin(); pIterator != m_pMaps.end(); ++pIterator) {
                pMap = (*pIterator);
                if (pMap->GetID() == lID) {
                    return (pMap);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pMaps.size());
        }

        bool Remove(CMap *pMap) {
            CMap *pMapToFind = NULL;
            std::vector<CMap *>::iterator pIterator;
            bool bResult = false;

            if (pMap != NULL) {
                for (pIterator = m_pMaps.begin(); pIterator != m_pMaps.end(); ++pIterator) {
                    pMapToFind = (*pIterator);
                    if (pMapToFind->GetID() == pMap->GetID()) {
                        m_pMaps.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};


#endif // _MAPS_H_INCLUDED
