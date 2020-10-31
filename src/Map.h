#ifndef _MAP_H_INCLUDED
#define _MAP_H_INCLUDED 0xBEBACAFE

#include "Matrix.h"
#include "Object.h"
#include "Terrain.h"
#include "Positions.h"

class CMap : public CObject {
    private:
        long m_lWidth;
        long m_lHeight;
        CMatrix<CTerrain *> *m_pMatrix;
        CPositions m_pPositions;

    public:
        CMap(long lWidth, long lHeight)
            : m_lWidth(lWidth), m_lHeight(lHeight) {
            m_pMatrix = new CMatrix<CTerrain *>(lWidth, lHeight);
        }

        CMap()
            : m_lWidth(0), m_lHeight(0), m_pMatrix(NULL) {
        }

       ~CMap() {
            if (m_pMatrix != NULL) {
                delete m_pMatrix;
                m_pMatrix = NULL;
            }

            m_pPositions.Clear();
        }

        bool Create(long lWidth, long lHeight) {
            m_pMatrix = new CMatrix<CTerrain *>(lWidth, lHeight);
            return (m_pMatrix != NULL);
        }

        CTerrain *GetAt(long lPositionX, long lPositionY) const {
            return ((*m_pMatrix)[lPositionY][lPositionX]);
        }

        void SetAt(long lPositionX, long lPositionY, CTerrain *pTerrain) {
            (*m_pMatrix)[lPositionY][lPositionX] = pTerrain;
        }

        CTerrain** operator[](long lIndex) {
            return (*m_pMatrix)[lIndex];
        }

        long GetWidth() const {
            return (m_lWidth);
        }

        long GetHeight() const {
            return (m_lHeight);
        }

        void Purge() {
            long lPositionX = 0;
            long lPositionY = 0;

            for (lPositionY = 0; lPositionY < m_lHeight; lPositionY++)
                for (lPositionX = 0; lPositionX < m_lWidth; lPositionX++)
                    delete (*m_pMatrix)[lPositionY][lPositionX];

            m_pPositions.Clear();
        }

        CPositions *GetPositions() {
            return (&m_pPositions);
        }
};

#endif // _MAP_H_INCLUDED
