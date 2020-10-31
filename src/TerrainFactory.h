#ifndef _TERRAINFACTORY_H_INCLUDED
#define _TERRAINFACTORY_H_INCLUDED 0xBEBACAFE

#include "Terrain.h"
#include "TerrainType.h"
#include "TerrainGrass.h"
#include "TerrainRock.h"
#include "TerrainWater.h"
#include "TerrainSand.h"
#include "TerrainWood.h"
#include "TerrainPath.h"

class CTerrainFactory {
    public:
        CTerrain *Create(const enTerrainType eTerrainType) {
            CTerrain *pTerrain = NULL;

            switch (eTerrainType) {
                case enTERRAINTYPE_NONE:
                    pTerrain = NULL;
                    break;

                case enTERRAINTYPE_UNKNOWN:
                    pTerrain = new CTerrain;
                    break;

                case enTERRAINTYPE_GRASS:
                    pTerrain = new CTerrainGrass;
                    break;

                case enTERRAINTYPE_ROCK:
                    pTerrain = new CTerrainRock;
                    break;

                case enTERRAINTYPE_WATER:
                    pTerrain = new CTerrainWater;
                    break;

                case enTERRAINTYPE_SAND:
                    pTerrain = new CTerrainSand;
                    break;

                case enTERRAINTYPE_WOOD:
                    pTerrain = new CTerrainWood;
                    break;

                case enTERRAINTYPE_PATH:
                    pTerrain = new CTerrainPath;
                    break;
            }

            return (pTerrain);
        }
};

#endif // _TERRAINFACTORY_H_INCLUDED
