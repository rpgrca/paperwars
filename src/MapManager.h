#ifndef _MAPMANAGER_H_INCLUDED
#define _MAPMANAGER_H_INCLUDED 0xBEBACAFE

#include "MapFactory.h"
#include "Maps.h"
#include "Map.h"

class CMapManager {
    private:
        CMaps m_pMaps;

    public:
       ~CMapManager() {
            m_pMaps.Purge();
        }

        CMap *Create(const long lWidth = 0, const long lHeight = 0) {
            CMap *pMap = NULL;
            CMapFactory *pMapFactory = NULL;

            pMapFactory = new CMapFactory;
            pMap = pMapFactory->Create();
            delete pMapFactory;

            if ((lWidth > 0) && (lHeight > 0))
                pMap->Create(lWidth, lHeight);

            m_pMaps.Add(pMap);
            return (pMap);
        }

        bool Delete(CMap *pMap) {
            bool bResult = false;

            if (m_pMaps.Remove(pMap)) {
                delete pMap;
                pMap = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CMap *Find(long lID) {
            return (m_pMaps.Find(lID));
        }
};

#endif // _MAPMANAGER_H_INCLUDED
