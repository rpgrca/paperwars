#ifndef _TERRAIN_H_INCLUDED
#define _TERRAIN_H_INCLUDED 0xBEBACAFE

#include "Object.h"
#include "TerrainType.h"
#include "TerrainProperty.h"

class CTerrain : public CObject {
    protected:
        enTerrainType m_eType;
        enTerrainProperty m_eProperty;

    public:
        CTerrain()
            : m_eType(enTERRAINTYPE_UNKNOWN) {
            m_szName = "Unknown";
        }

        enTerrainType GetType() const {
            return (m_eType);
        }

        enTerrainProperty GetProperty() const {
            return (m_eProperty);
        }

        void SetProperty(enTerrainProperty eTerrainProperty) {
            m_eProperty = eTerrainProperty;
        }
};

#endif // _TERRAIN_H_INCLUDED
