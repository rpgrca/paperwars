#ifndef _TERRAINSERVICES_H_INCLUDED
#define _TERRAINSERVICES_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainProperty.h"

class CTerrainServices {
    public:
        bool IsImpassable(CTerrain *pTerrain) {
            return (pTerrain->GetProperty() & enTERRAINPROPERTY_IMPASSABLE);
        }

        bool IsBlockLow(CTerrain *pTerrain) {
            return (pTerrain->GetProperty() & enTERRAINPROPERTY_BLOCK_LOW);
        }

        bool IsInvisible(CTerrain *pTerrain) {
            return (pTerrain->GetProperty() & enTERRAINPROPERTY_INVISIBLE);
        }

        bool IsHole(CTerrain *pTerrain) {
            return (pTerrain->GetProperty() & enTERRAINPROPERTY_HOLE);
        }
};

#endif // _TERRAINSERVICES_H_INCLUDED
