#ifndef _TERRAINGRASS_H_INCLUDED
#define _TERRAINGRASS_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainGrass : public CTerrain {
    public:
        CTerrainGrass() {
            m_szName = "Grass";
            m_eType = enTERRAINTYPE_GRASS;
        }
};

#endif // _TERRAINGRASS_H_INCLUDED
