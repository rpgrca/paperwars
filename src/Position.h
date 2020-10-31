#ifndef _POSITION_H_INCLUDED
#define _POSITION_H_INCLUDED 0xBEBACAFE

#include "Object.h"

class CPosition : public CObject {
    protected:
        static const long c_lPositionX = 0;
        static const long c_lPositionY = 0;
        static const long c_lLevel = 0;

        CObject *m_pObject;
        long m_lDefaultPositionX;
        long m_lDefaultPositionY;
        long m_lDefaultLevel;
        long m_lPositionX;
        long m_lPositionY;
        long m_lLevel;

    public:
        CPosition() :
            m_pObject(NULL), m_lDefaultPositionX(c_lPositionX), m_lDefaultPositionY(c_lPositionY), m_lDefaultLevel(c_lLevel) {
            m_lPositionX = m_lDefaultPositionX;
            m_lPositionY = m_lDefaultPositionY;
            m_lLevel = m_lDefaultLevel;
        }

        CPosition(long lPositionX, long lPositionY)
            : m_pObject(NULL), m_lDefaultPositionX(c_lPositionX), m_lDefaultPositionY(c_lPositionY), m_lDefaultLevel(c_lLevel) {
            m_lPositionX = lPositionX;
            m_lPositionY = lPositionY;
            m_lLevel = m_lDefaultLevel;
        }

        CPosition(long lPositionX, long lPositionY, long lLevel)
            : m_pObject(NULL), m_lDefaultPositionX(c_lPositionX), m_lDefaultPositionY(c_lPositionY), m_lDefaultLevel(c_lLevel) {
            m_lPositionX = lPositionX;
            m_lPositionY = lPositionY;
            m_lLevel = lLevel;
        }

       ~CPosition() {
            m_pObject = NULL;
        }

        void SetObject(CObject *pObject) {
            m_pObject = pObject;
        }

        CObject *GetObject() const {
            return (m_pObject);
        }

        long GetPositionX() const {
            return (m_lPositionX);
        }

        void SetPositionX(const long lPositionX) {
            m_lPositionX = lPositionX;
        }

        long GetPositionY() const {
            return (m_lPositionY);
        }

        void SetPositionY(const long lPositionY) {
            m_lPositionY = lPositionY;
        }

        void SetPosition(const long lPositionX, const long lPositionY) {
            m_lPositionX = lPositionX;
            m_lPositionY = lPositionY;
        }

        long GetLevel() const {
            return (m_lLevel);
        }

        void SetLevel(const long lLevel) {
            m_lLevel = lLevel;
        }

        long GetDefaultPositionX() const {
            return (m_lDefaultPositionX);
        }

        long GetDefaultPositionY() const {
            return (m_lDefaultPositionY);
        }

        long GetDefaultLevel() const {
            return (m_lDefaultLevel);
        }
};

#endif // _POSITION_H_INCLUDED
