#ifndef _COMBATS_H_INCLUDED
#define _COMBATS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Combat.h"

class CCombats {
    private:
        std::vector<CCombat *> m_pCombats;

    public:
       ~CCombats() {
            Clear();
        }

        bool Add(CCombat *pCombat) {
            bool bResult = false;

            if (pCombat != NULL) {
                if (Find(pCombat->GetID()) == NULL) {
                    m_pCombats.push_back(pCombat);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CCombat *pCombat = NULL;
            std::vector<CCombat *>::iterator pIterator;

            for (pIterator = m_pCombats.begin(); pIterator != m_pCombats.end(); ++pIterator) {
                pCombat = (*pIterator);
                delete pCombat;
            }

            m_pCombats.clear();
        }

        void Clear() {
            m_pCombats.clear();
        }

        CCombat *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pCombats.size())
                return (m_pCombats.at(lIndex));
            else
                return (NULL);
        }

        CCombat *Find(const long lID) {
            CCombat *pCombat = NULL;
            std::vector<CCombat *>::iterator pIterator;

            for (pIterator = m_pCombats.begin(); pIterator != m_pCombats.end(); ++pIterator) {
                pCombat = (*pIterator);
                if (pCombat->GetID() == lID) {
                    return (pCombat);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pCombats.size());
        }

        bool Remove(CCombat *pCombat) {
            CCombat *pCombatToFind = NULL;
            std::vector<CCombat *>::iterator pIterator;
            bool bResult = false;

            if (pCombat != NULL) {
                for (pIterator = m_pCombats.begin(); pIterator != m_pCombats.end(); ++pIterator) {
                    pCombatToFind = (*pIterator);
                    if (pCombatToFind->GetID() == pCombat->GetID()) {
                        m_pCombats.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _COMBATS_H_INCLUDED
