#ifndef _TERRAINPATH_H_INCLUDED
#define _TERRAINPATH_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainPath : public CTerrain {
    public:
        CTerrainPath() {
            m_szName = "Path";
            m_eType = enTERRAINTYPE_PATH;
        }
};

#endif // _TERRAINPATH_H_INCLUDED
