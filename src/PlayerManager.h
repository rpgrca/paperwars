#ifndef _PLAYERMANAGER_H_INCLUDED
#define _PLAYERMANAGER_H_INCLUDED 0xBEBACAFE

#include "Player.h"
#include "PlayerType.h"
#include "PlayerFactory.h"

class CPlayerManager {
    private:
        CPlayers m_pPlayers;

    public:
       ~CPlayerManager() {
            m_pPlayers.Purge();
        }

        CPlayer *Create(const enPlayerType ePlayerType) {
            CPlayerFactory *pPlayerFactory = NULL;
            CPlayer *pPlayer = NULL;

            if (ePlayerType != enPLAYERTYPE_NONE) {
                pPlayerFactory = new CPlayerFactory;
                pPlayer = pPlayerFactory->Create(ePlayerType);
                delete pPlayerFactory;

                m_pPlayers.Add(pPlayer);
            }

            return (pPlayer);
        }
};

#endif // _PLAYERMANAGER_H_INCLUDED
