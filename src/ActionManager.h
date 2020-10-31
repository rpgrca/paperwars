#ifndef _ACTIONMANAGER_H_INCLUDED
#define _ACTIONMANAGER_H_INCLUDED 0xBEBACAFE

#include "ActionFactory.h"
#include "Actions.h"
#include "Action.h"
#include "ActionType.h"

class CActionManager {
    private:
        CActions m_pActions;

    public:
       ~CActionManager() {
            m_pActions.Purge();
        }

        CAction *Create(const enActionType eActionType = enACTIONTYPE_UNKNOWN) {
            CAction *pAction = NULL;
            CActionFactory *pActionFactory = NULL;

            pActionFactory = new CActionFactory;
            pAction = pActionFactory->Create(eActionType);
            delete pActionFactory;

            m_pActions.Add(pAction);
            return (pAction);
        }

        CAction *CreateRandomAttack() {
            CAction *pAction = NULL;
            CActionFactory *pActionFactory = NULL;
            const enActionType eActions[] = {
                enACTIONTYPE_HIGH_ATTACK,
                enACTIONTYPE_LOW_ATTACK
            };

            pActionFactory = new CActionFactory;
            pAction = Create(eActions[rand() % (sizeof(eActions) / sizeof(enActionType))]);
            delete pActionFactory;

            m_pActions.Add(pAction);
            return (pAction);
        }

        CAction *CreateRandomDefense() {
            CAction *pAction = NULL;
            CActionFactory *pActionFactory = NULL;
            const enActionType eActions[] = {
                enACTIONTYPE_HIGH_BLOCK,
                enACTIONTYPE_LOW_BLOCK,
                enACTIONTYPE_HIGH_PARRY,
                enACTIONTYPE_LOW_PARRY
            };

            pActionFactory = new CActionFactory;
            pAction = Create(eActions[rand() % (sizeof(eActions) / sizeof(enActionType))]);
            delete pActionFactory;

            m_pActions.Add(pAction);
            return (pAction);
        }

        bool Delete(CAction *pAction) {
            bool bResult = false;

            if (m_pActions.Remove(pAction)) {
                delete pAction;
                pAction = NULL;
                bResult = true;
            }

            return (bResult);
        }

        CAction *Find(long lID) {
            return (m_pActions.Find(lID));
        }
};

#endif // _ACTIONMANAGER_H_INCLUDED
