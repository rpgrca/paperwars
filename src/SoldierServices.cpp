#include "SoldierServices.h"
#include "Combat.h"
#include "Global.h"

/*
bool CSoldierServices::FightRound(CSoldier *pFirstSoldier, CSoldier *pSecondSoldier) {
    CGlobal *pInstance = NULL;
    bool bResult = false;
    CCombat *pCombat = NULL;

    if ((pFirstSoldier != NULL) && (pSecondSoldier != NULL)) {
        pInstance = CGlobal::Instance();

        pCombat = pInstance->GetCombatManager()->Create();

        if (pFirstSoldier->GetSpeed() >= pSecondSoldier->GetSpeed()) {
            pCombat->SetAttacker(pFirstSoldier);
            pCombat->SetDefender(pSecondSoldier);
        }
        else {
            pCombat->SetAttacker(pSecondSoldier);
            pCombat->SetDefender(pFirstSoldier);
        }

        bResult = pCombat->Round();

        pInstance->GetCombatManager()->Delete(pCombat);
    }

    return (bResult);
}

bool CSoldierServices::Round(CSoldier *pAttacker, CSoldier *pDefender, CActions *pActions, CActions *pAllActions) {
    CGlobal *pInstance = NULL;
    CAction *pAction = NULL;
    CActionDamage *pActionDamage = NULL;
    bool bResult = false;
    long lAttack = 0;

    if ((pAttacker != NULL) && (pDefender != NULL)) {
        pActions->Clear();
        pInstance = CGlobal::Instance();

        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
        pAction->SetObject(pAttacker);
        pActions->Add(pAction);
        pAllActions->Add(pAction);
        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
        pAction->SetObject(pDefender);
        pActions->Add(pAction);
        pAllActions->Add(pAction);
        if (pInstance->GetSoldierServices()->IsAlive(pAttacker) && (pInstance->GetSoldierServices()->IsAlive(pDefender))) {
            lAttack = pInstance->GetSoldierServices()->CalculateAttack(pAttacker, pDefender);

            pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_ATTACK);
            pAction->SetObject(pAttacker);
            pActions->Add(pAction);
            pAllActions->Add(pAction);
            if (lAttack > 0) {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_BLOCK);
                pAction->SetObject(pDefender);
                pActions->Add(pAction);
                pAllActions->Add(pAction);
                pInstance->GetSoldierServices()->Hurt(pDefender, lAttack);
                pActionDamage = dynamic_cast<CActionDamage *>(pInstance->GetActionManager()->Create(enACTIONTYPE_DAMAGE));
                pActionDamage->SetDamage(lAttack);
                pActionDamage->SetObject(pDefender);
                pActions->Add(pActionDamage);
                pAllActions->Add(pActionDamage);

                if (! pInstance->GetSoldierServices()->IsAlive(pDefender)) {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_DESTRUCTION);
                    pAction->SetObject(pDefender);
                    pActions->Add(pAction);
                    pAllActions->Add(pAction);
                    bResult = true;
                }
            }
            else {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_BLOCK);
                pAction->SetObject(pDefender);
                pActions->Add(pAction);
                pAllActions->Add(pAction);
            }

            if (! bResult) {
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
                pAction->SetObject(pAttacker);
                pActions->Add(pAction);
                pAllActions->Add(pAction);
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_WAIT);
                pAction->SetObject(pDefender);
                pActions->Add(pAction);
                pAllActions->Add(pAction);
                lAttack = pInstance->GetSoldierServices()->CalculateAttack(pDefender, pAttacker);
                pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_ATTACK);
                pAction->SetObject(pDefender);
                pActions->Add(pAction);
                pAllActions->Add(pAction);
                if (lAttack > 0) {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_HIGH_BLOCK);
                    pAction->SetObject(pAttacker);
                    pActions->Add(pAction);
                    pAllActions->Add(pAction);
                    pInstance->GetSoldierServices()->Hurt(pAttacker, lAttack);
                    pActionDamage = dynamic_cast<CActionDamage *>(pInstance->GetActionManager()->Create(enACTIONTYPE_DAMAGE));
                    pActionDamage->SetDamage(lAttack);
                    pActionDamage->SetObject(pAttacker);
                    pActions->Add(pActionDamage);
                    pAllActions->Add(pActionDamage);

                    if (! pInstance->GetSoldierServices()->IsAlive(pAttacker)) {
                        pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_DESTRUCTION);
                        pAction->SetObject(pAttacker);
                        pActions->Add(pAction);
                        pAllActions->Add(pAction);
                        bResult = true;
                    }
                }
                else {
                    pAction = pInstance->GetActionManager()->Create(enACTIONTYPE_LOW_BLOCK);
                    pAction->SetObject(pAttacker);
                    pActions->Add(pAction);
                    pAllActions->Add(pAction);
                }
            }
        }
    }

    return (bResult);
}
*/
