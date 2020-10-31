#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED 0xBEBACAFE

#include <cstring>

template<typename T>
class CMatrix {
    private:
        long m_lWidth;
        long m_lHeight;
        T *m_pMatrix;

    public:
        CMatrix(long lWidth, long lHeight)
            : m_lWidth(lWidth), m_lHeight(lHeight) {
            long lLength = lWidth * lHeight;

            if (lLength > 0) {
                m_pMatrix = new T[lLength];
                memset(m_pMatrix, 0, sizeof(T) * lLength);
            }
        }

        CMatrix()
            : m_lWidth(0), m_lHeight(0), m_pMatrix(NULL) {
        }

        CMatrix(const CMatrix &pMatrix) {
            long lLength = pMatrix.m_lWidth * pMatrix.m_lHeight;
            long lPositionX;
            long lPositionY;

            m_lWidth = pMatrix.m_lWidth;
            m_lHeight = pMatrix.m_lHeight;
            m_pMatrix = (lLength > 0)? new T[lLength] : NULL;

            for (lPositionX = 0; lPositionX < m_lWidth; lPositionX++)
                for (lPositionY = 0; lPositionY < m_lHeight; lPositionY++)
                    m_pMatrix[lPositionY][lPositionX] = pMatrix[lPositionY][lPositionX];
        }

       ~CMatrix() {
            if (m_pMatrix)
                delete [] m_pMatrix;
        }

        T* operator[](long lIndex) {
            return (m_pMatrix + (m_lWidth * lIndex));
        }

//        T const * const operator[](long lIndex) const {
//            return (m_pMatrix + (m_lWidth * lIndex));
//        }

        long GetWidth() const {
            return (m_lWidth);
        }

        long GetHeight() const {
            return (m_lHeight);
        }
};

#endif // _MATRIX_H_INCLUDED
