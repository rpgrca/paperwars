#ifndef _SOLDIERS_H_INCLUDED
#define _SOLDIERS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Soldier.h"

class CSoldiers {
    private:
        std::vector<CSoldier *> m_pSoldiers;

    public:
       ~CSoldiers() {
            Clear();
        }

        bool Add(CSoldier *pSoldier) {
            bool bResult = false;

            if (pSoldier != NULL) {
                if (Find(pSoldier->GetID()) == NULL) {
                    m_pSoldiers.push_back(pSoldier);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CSoldier *pSoldier = NULL;
            std::vector<CSoldier *>::iterator pIterator;

            for (pIterator = m_pSoldiers.begin(); pIterator != m_pSoldiers.end(); ++pIterator) {
                pSoldier = (*pIterator);
                delete pSoldier;
            }

            m_pSoldiers.clear();
        }

        void Clear() {
            m_pSoldiers.clear();
        }

        CSoldier *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pSoldiers.size())
                return (m_pSoldiers.at(lIndex));
            else
                return (NULL);
        }

        CSoldier *Find(const long lID) {
            CSoldier *pSoldier = NULL;
            std::vector<CSoldier *>::iterator pIterator;

            for (pIterator = m_pSoldiers.begin(); pIterator != m_pSoldiers.end(); ++pIterator) {
                pSoldier = (*pIterator);
                if (pSoldier->GetID() == lID) {
                    return (pSoldier);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pSoldiers.size());
        }

        bool Remove(CSoldier *pSoldier) {
            CSoldier *pSoldierToFind = NULL;
            std::vector<CSoldier *>::iterator pIterator;
            bool bResult = false;

            if (pSoldier != NULL) {
                for (pIterator = m_pSoldiers.begin(); pIterator != m_pSoldiers.end(); ++pIterator) {
                    pSoldierToFind = (*pIterator);
                    if (pSoldierToFind->GetID() == pSoldier->GetID()) {
                        m_pSoldiers.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }

        bool UpdateElement(const CSoldier *pSoldier) {
            CSoldier *pSoldierToUpdate = NULL;
            bool bResult = false;

            pSoldierToUpdate = Find(pSoldier->GetID());
            if (pSoldierToUpdate != NULL) {
                if (pSoldierToUpdate != pSoldier) {
                    pSoldierToUpdate->SetName(pSoldier->GetName());
                    pSoldierToUpdate->SetHealth(pSoldier->GetHealth());
                    pSoldierToUpdate->SetMaximumHealth(pSoldier->GetMaximumHealth());
                    pSoldierToUpdate->SetAttack(pSoldier->GetAttack());
                    pSoldierToUpdate->SetMaximumAttack(pSoldier->GetMaximumAttack());
                    pSoldierToUpdate->SetDefense(pSoldier->GetDefense());
                    pSoldierToUpdate->SetMaximumDefense(pSoldier->GetMaximumDefense());
                    pSoldierToUpdate->SetLevel(pSoldier->GetLevel());
                    pSoldierToUpdate->SetExperience(pSoldier->GetExperience());
                    bResult = true;
                }
            }

            return (bResult);
        }
};

#endif // _SOLDIERS_H_INCLUDED
