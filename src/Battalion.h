#ifndef _BATTALION_H_INCLUDED
#define _BATTALION_H_INCLUDED 0xBEBACAFE

#include "Object.h"
#include "Soldier.h"
#include "Soldiers.h"

class CBattalion : public CObject {
    private:
        CSoldiers m_pSoldiers;

    public:
       ~CBattalion() {
            m_pSoldiers.Clear();
        }

        bool Add(CSoldier *pSoldier) {
            return (m_pSoldiers.Add(pSoldier));
        }

        bool Remove(CSoldier *pSoldier) {
            return (m_pSoldiers.Remove(pSoldier));
        }

        unsigned long GetCount() const {
            return (m_pSoldiers.GetCount());
        }

        CSoldier *GetAt(long lIndex) {
            return (m_pSoldiers.GetAt(lIndex));
        }

        CSoldier *GetRandomSoldier();

        long GetAttack() {
            CSoldier *pSoldier = NULL;
            long lResult = 0;
            unsigned long lIndex = 0;

            for (lIndex = 0; lIndex < m_pSoldiers.GetCount(); lIndex++) {
                pSoldier = m_pSoldiers.GetAt(lIndex);
                lResult += pSoldier->GetAttack();
            }

            return (lResult);
        }

        long GetDefense() {
            CSoldier *pSoldier = NULL;
            long lResult = 0;
            unsigned long lIndex = 0;

            for (lIndex = 0; lIndex < m_pSoldiers.GetCount(); lIndex++) {
                pSoldier = m_pSoldiers.GetAt(lIndex);
                lResult += pSoldier->GetDefense();
            }

            return (lResult);
        }

        void Purge() {
            m_pSoldiers.Purge();
        }
};

#endif // _BATTALION_H_INCLUDED
