#ifndef _PLAYERFACTORY_H_INCLUDED
#define _PLAYERFACTORY_H_INCLUDED 0xBEBACAFE

#include "PlayerType.h"
#include "Player.h"

class CPlayerFactory {
    public:
        CPlayer *Create(const enPlayerType ePlayerType) {
            CPlayer *pPlayer = NULL;

            switch (ePlayerType) {
                case enPLAYERTYPE_HUMAN:
                    pPlayer = new CPlayerHuman;
                    break;

                case enPLAYERTYPE_CPU:
                    pPlayer = new CPlayerCPU;
                    break;
            }

            return (pPlayer);
        }
};

#endif // _PLAYERFACTORY_H_INCLUDED
