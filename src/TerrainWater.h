#ifndef _TERRAINWATER_H_INCLUDED
#define _TERRAINWATER_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainWater : public CTerrain {
    public:
        CTerrainWater() {
            m_szName = "Water";
            m_eType = enTERRAINTYPE_WATER;
        }
};

#endif // _TERRAINWATER_H_INCLUDED
