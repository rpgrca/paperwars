#ifndef _ACTIONFACTORY_H_INCLUDED
#define _ACTIONFACTORY_H_INCLUDED 0xBEBACAFE

#include "Action.h"
#include "ActionWait.h"
#include "ActionHighAttack.h"
#include "ActionLowAttack.h"
#include "ActionHighBlock.h"
#include "ActionLowBlock.h"
#include "ActionHighParry.h"
#include "ActionLowParry.h"
#include "ActionDamage.h"
#include "ActionHeal.h"
#include "ActionRevive.h"
#include "ActionDestruction.h"

class CActionFactory {
    public:
        CAction *Create(const enActionType eActionType) {
            CAction *pAction = NULL;

            switch (eActionType) {
                case enACTIONTYPE_WAIT:
                    pAction = new CActionWait;
                    break;

                case enACTIONTYPE_NONE:
                    pAction = NULL;
                    break;

                case enACTIONTYPE_UNKNOWN:
                    pAction = new CAction;
                    break;

                case enACTIONTYPE_HIGH_ATTACK:
                    pAction = new CActionHighAttack;
                    break;

                case enACTIONTYPE_LOW_ATTACK:
                    pAction = new CActionLowAttack;
                    break;

                case enACTIONTYPE_HIGH_BLOCK:
                    pAction = new CActionHighBlock;
                    break;

                case enACTIONTYPE_LOW_BLOCK:
                    pAction = new CActionLowBlock;
                    break;

                case enACTIONTYPE_HIGH_PARRY:
                    pAction = new CActionHighParry;
                    break;

                case enACTIONTYPE_LOW_PARRY:
                    pAction = new CActionLowParry;
                    break;

                case enACTIONTYPE_DAMAGE:
                    pAction = new CActionDamage;
                    break;

                case enACTIONTYPE_HEAL:
                    pAction = new CActionHeal;
                    break;

                case enACTIONTYPE_REVIVE:
                    pAction = new CActionRevive;
                    break;

                case enACTIONTYPE_DESTRUCTION:
                    pAction = new CActionDestruction;
                    break;
            }

            return (pAction);
        }
};

#endif // _ACTIONFACTORY_H_INCLUDED
