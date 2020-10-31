#ifndef _SOLDIERFACTORY_H_INCLUDED
#define _SOLDIERFACTORY_H_INCLUDED 0xBEBACAFE

#include <cstdlib>
#include <string>
#include "Soldier.h"
#include "SoldierType.h"
#include "SoldierFootman.h"
#include "SoldierPikeman.h"
#include "SoldierArcher.h"
#include "SoldierCleric.h"
#include "SoldierMage.h"
#include "SoldierCavalier.h"
#include "SoldierMessenger.h"

class CSoldierFactory {
    public:
        CSoldier *Create(const enSoldierType eSoldierType) {
            CSoldier *pSoldier = NULL;

            switch (eSoldierType) {
                case enSOLDIERTYPE_FOOTMAN:
                    pSoldier = new CSoldierFootman();
                    break;

                case enSOLDIERTYPE_PIKEMAN:
                    pSoldier = new CSoldierPikeman();
                    break;

                case enSOLDIERTYPE_ARCHER:
                    pSoldier = new CSoldierArcher();
                    break;

                case enSOLDIERTYPE_CLERIC:
                    pSoldier = new CSoldierCleric();
                    break;

                case enSOLDIERTYPE_MAGE:
                    pSoldier = new CSoldierMage();
                    break;

                case enSOLDIERTYPE_CAVALIER:
                    pSoldier = new CSoldierCavalier();
                    break;

                case enSOLDIERTYPE_MESSENGER:
                    pSoldier = new CSoldierMessenger();
                    break;

                case enSOLDIERTYPE_UNKNOWN:
                    pSoldier = new CSoldier(enSOLDIERTYPE_UNKNOWN);
                    break;

                case enSOLDIERTYPE_NONE:
                    pSoldier = NULL;
                    break;
            }

            return (pSoldier);
        }
};

#endif // _SOLDIERFACTORY_H_INCLUDED
