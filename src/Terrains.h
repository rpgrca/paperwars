#ifndef _TERRAINS_H_INCLUDED
#define _TERRAINS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Terrain.h"

class CTerrains {
    private:
        std::vector<CTerrain *> m_pTerrains;

    public:
       ~CTerrains() {
            Clear();
        }

        bool Add(CTerrain *pTerrain) {
            bool bResult = false;

            if (pTerrain != NULL) {
                if (Find(pTerrain->GetID()) == NULL) {
                    m_pTerrains.push_back(pTerrain);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CTerrain *pTerrain = NULL;
            std::vector<CTerrain *>::iterator pIterator;

            for (pIterator = m_pTerrains.begin(); pIterator != m_pTerrains.end(); ++pIterator) {
                pTerrain = (*pIterator);
                delete pTerrain;
            }

            m_pTerrains.clear();
        }

        void Clear() {
            m_pTerrains.clear();
        }

        CTerrain *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pTerrains.size())
                return (m_pTerrains.at(lIndex));
            else
                return (NULL);
        }

        CTerrain *Find(const long lID) {
            CTerrain *pTerrain = NULL;
            std::vector<CTerrain *>::iterator pIterator;

            for (pIterator = m_pTerrains.begin(); pIterator != m_pTerrains.end(); ++pIterator) {
                pTerrain = (*pIterator);
                if (pTerrain->GetID() == lID) {
                    return (pTerrain);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pTerrains.size());
        }

        bool Remove(CTerrain *pTerrain) {
            CTerrain *pTerrainToFind = NULL;
            std::vector<CTerrain *>::iterator pIterator;
            bool bResult = false;

            if (pTerrain != NULL) {
                for (pIterator = m_pTerrains.begin(); pIterator != m_pTerrains.end(); ++pIterator) {
                    pTerrainToFind = (*pIterator);
                    if (pTerrainToFind->GetID() == pTerrain->GetID()) {
                        m_pTerrains.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _TERRAINS_H_INCLUDED
