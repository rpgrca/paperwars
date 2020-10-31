#ifndef _TERRAINSAND_H_INCLUDED
#define _TERRAINSAND_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"

class CTerrainSand : public CTerrain {
    public:
        CTerrainSand() {
            m_szName = "Sand";
            m_eType = enTERRAINTYPE_SAND;
        }
};

#endif // _TERRAINSAND_H_INCLUDED
