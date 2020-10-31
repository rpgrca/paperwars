#ifndef _WEAPONS_H_INCLUDED
#define _WEAPONS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Weapon.h"

class CWeapons {
    private:
        std::vector<CWeapon *> m_pWeapons;

    public:
       ~CWeapons() {
            Clear();
        }

        bool Add(CWeapon *pWeapon) {
            bool bResult = false;

            if (pWeapon != NULL) {
                if (Find(pWeapon->GetID()) == NULL) {
                    m_pWeapons.push_back(pWeapon);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CWeapon *pWeapon = NULL;
            std::vector<CWeapon *>::iterator pIterator;

            for (pIterator = m_pWeapons.begin(); pIterator != m_pWeapons.end(); ++pIterator) {
                pWeapon = (*pIterator);
                delete pWeapon;
            }

            m_pWeapons.clear();
        }

        void Clear() {
            m_pWeapons.clear();
        }

        CWeapon *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pWeapons.size())
                return (m_pWeapons.at(lIndex));
            else
                return (NULL);
        }

        CWeapon *Find(const long lID) {
            CWeapon *pWeapon = NULL;
            std::vector<CWeapon *>::iterator pIterator;

            for (pIterator = m_pWeapons.begin(); pIterator != m_pWeapons.end(); ++pIterator) {
                pWeapon = (*pIterator);
                if (pWeapon->GetID() == lID) {
                    return (pWeapon);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pWeapons.size());
        }

        bool Remove(CWeapon *pWeapon) {
            CWeapon *pWeaponToFind = NULL;
            std::vector<CWeapon *>::iterator pIterator;
            bool bResult = false;

            if (pWeapon != NULL) {
                for (pIterator = m_pWeapons.begin(); pIterator != m_pWeapons.end(); ++pIterator) {
                    pWeaponToFind = (*pIterator);
                    if (pWeaponToFind->GetID() == pWeapon->GetID()) {
                        m_pWeapons.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _WEAPONS_H_INCLUDED
