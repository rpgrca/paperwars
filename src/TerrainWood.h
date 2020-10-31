#ifndef _TERRAINWOOD_H_INCLUDED
#define _TERRAINWOOD_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainWood : public CTerrain {
    public:
        CTerrainWood() {
            m_szName = "Wood";
            m_eType = enTERRAINTYPE_WOOD;
        }
};

#endif // _TERRAINWOOD_H_INCLUDED
