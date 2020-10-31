#ifndef _ARMOURS_H_INCLUDED
#define _ARMOURS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Armour.h"

class CArmours {
    private:
        std::vector<CArmour *> m_pArmours;

    public:
       ~CArmours() {
            Clear();
        }

        bool Add(CArmour *pArmour) {
            bool bResult = false;

            if (pArmour != NULL) {
                if (Find(pArmour->GetID()) == NULL) {
                    m_pArmours.push_back(pArmour);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CArmour *pArmour = NULL;
            std::vector<CArmour *>::iterator pIterator;

            for (pIterator = m_pArmours.begin(); pIterator != m_pArmours.end(); ++pIterator) {
                pArmour = (*pIterator);
                delete pArmour;
            }

            m_pArmours.clear();
        }

        void Clear() {
            m_pArmours.clear();
        }

        CArmour *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pArmours.size())
                return (m_pArmours.at(lIndex));
            else
                return (NULL);
        }

        CArmour *Find(const long lID) {
            CArmour *pArmour = NULL;
            std::vector<CArmour *>::iterator pIterator;

            for (pIterator = m_pArmours.begin(); pIterator != m_pArmours.end(); ++pIterator) {
                pArmour = (*pIterator);
                if (pArmour->GetID() == lID) {
                    return (pArmour);
                }
            }

            return (NULL);
        }

        CArmour *Find(const enArmourType eType) {
            CArmour *pArmour = NULL;
            std::vector<CArmour *>::iterator pIterator;

            for (pIterator = m_pArmours.begin(); pIterator != m_pArmours.end(); ++pIterator) {
                pArmour = (*pIterator);
                if (pArmour->GetType() == eType) {
                    return (pArmour);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pArmours.size());
        }

        bool Remove(CArmour *pArmour) {
            CArmour *pArmourToFind = NULL;
            std::vector<CArmour *>::iterator pIterator;
            bool bResult = false;

            if (pArmour != NULL) {
                for (pIterator = m_pArmours.begin(); pIterator != m_pArmours.end(); ++pIterator) {
                    pArmourToFind = (*pIterator);
                    if (pArmourToFind->GetID() == pArmour->GetID()) {
                        m_pArmours.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _ARMOURS_H_INCLUDED
