#ifndef _BATTLEFIELD_H_INCLUDED
#define _BATTLEFIELD_H_INCLUDED 0xBEBACAFE

#include "Position.h"
#include "Positions.h"
#include "Map.h"

class CBattlefield {
    private:
        CPositions *m_pPositions;
        CMap *m_pMap;

    public:
        CBattlefield() {
            m_pPositions = new CPositions;
            m_pMap = NULL;
        }

       ~CBattlefield() {
            m_pPositions->Clear();
            delete m_pPositions;
            m_pPositions = NULL;

            delete m_pMap;
            m_pMap = NULL;
        }

        bool Add(CPosition *pPosition) {
            return (m_pPositions->Add(pPosition));
        }

        bool Delete(CPosition *pPosition) {
            return (m_pPositions->Remove(pPosition));
        }

        void SetMap(CMap *pMap) {
            m_pMap = pMap;
        }

        CMap *GetMap() const {
            return (m_pMap);
        }
};

#endif // _BATTLEFIELD_H_INCLUDED
