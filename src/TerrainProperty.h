#ifndef _TERRAINPROPERTY_H_INCLUDED
#define _TERRAINPROPERTY_H_INCLUDED 0xBEBACAFE

typedef enum enTerrainProperty {
    enTERRAINPROPERTY_NONE = 0,
    enTERRAINPROPERTY_UNKNOWN = 1,
    enTERRAINPROPERTY_IMPASSABLE = 2,
    enTERRAINPROPERTY_BLOCK_LOW = 4,
    enTERRAINPROPERTY_INVISIBLE = 8,
    enTERRAINPROPERTY_HOLE = 16
} enTerrainProperty;

#endif // _TERRAINPROPERTY_H_INCLUDED