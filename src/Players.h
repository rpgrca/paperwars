#ifndef _PLAYERS_H_INCLUDED
#define _PLAYERS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Player.h"

class CPlayers {
    private:
        std::vector<CPlayer *> m_pPlayers;

    public:
       ~CPlayers() {
            Clear();
        }

        bool Add(CPlayer *pPlayer) {
            bool bResult = false;

            if (pPlayer != NULL) {
                if (Find(pPlayer->GetID()) == NULL) {
                    m_pPlayers.push_back(pPlayer);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CPlayer *pPlayer = NULL;
            std::vector<CPlayer *>::iterator pIterator;

            for (pIterator = m_pPlayers.begin(); pIterator != m_pPlayers.end(); ++pIterator) {
                pPlayer = (*pIterator);
                delete pPlayer;
            }

            m_pPlayers.clear();
        }

        void Clear() {
            m_pPlayers.clear();
        }

        CPlayer *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pPlayers.size())
                return (m_pPlayers.at(lIndex));
            else
                return (NULL);
        }

        CPlayer *Find(const long lID) {
            CPlayer *pPlayer = NULL;
            std::vector<CPlayer *>::iterator pIterator;

            for (pIterator = m_pPlayers.begin(); pIterator != m_pPlayers.end(); ++pIterator) {
                pPlayer = (*pIterator);
                if (pPlayer->GetID() == lID) {
                    return (pPlayer);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pPlayers.size());
        }

        bool Remove(CPlayer *pPlayer) {
            CPlayer *pPlayerToFind = NULL;
            std::vector<CPlayer *>::iterator pIterator;
            bool bResult = false;

            if (pPlayer != NULL) {
                for (pIterator = m_pPlayers.begin(); pIterator != m_pPlayers.end(); ++pIterator) {
                    pPlayerToFind = (*pIterator);
                    if (pPlayerToFind->GetID() == pPlayer->GetID()) {
                        m_pPlayers.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _PLAYERS_H_INCLUDED
