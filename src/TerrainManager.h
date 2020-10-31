#ifndef _TERRAINMANAGER_H_INCLUDED
#define _TERRAINMANAGER_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "Terrains.h"
#include "TerrainFactory.h"
#include "TerrainType.h"
#include "TerrainProperty.h"

class CTerrainManager {
    private:
        CTerrains m_pTerrains;

    public:
       ~CTerrainManager() {
            m_pTerrains.Purge();
        }

        CTerrain *Create(const enTerrainType eTerrainType = enTERRAINTYPE_UNKNOWN, const enTerrainProperty eTerrainProperty = enTERRAINPROPERTY_UNKNOWN) {
            CTerrainFactory *pTerrainFactory = NULL;
            CTerrain *pTerrain = NULL;

            pTerrainFactory = new CTerrainFactory;
            pTerrain = pTerrainFactory->Create(eTerrainType);
            delete pTerrainFactory;

            if (pTerrain != NULL)
                pTerrain->SetProperty(eTerrainProperty);

            m_pTerrains.Add(pTerrain);
            return (pTerrain);
        }

        bool Delete(CTerrain *pTerrain) {
            bool bResult = false;

            if (m_pTerrains.Remove(pTerrain)) {
                delete pTerrain;
                pTerrain = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CTerrain *Find(long lID) {
            return (m_pTerrains.Find(lID));
        }
};

#endif // _TERRAINMANAGER_H_INCLUDED
