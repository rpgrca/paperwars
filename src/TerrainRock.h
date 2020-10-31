#ifndef _TERRAINROCK_H_INCLUDED
#define _TERRAINROCK_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainRock : public CTerrain {
    public:
        CTerrainRock() {
            m_szName = "Rock";
            m_eType = enTERRAINTYPE_ROCK;
        }
};

#endif // _TERRAINROCK_H_INCLUDED
