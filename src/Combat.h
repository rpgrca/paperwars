#ifndef _COMBATINTERFACE_H_INCLUDED
#define _COMBATINTERFACE_H_INCLUDED 0xBEBACAFE

#include <cstdlib>
#include "CombatType.h"
#include "Object.h"
#include "Actions.h"

class CCombat : public CObject {
    protected:
        CObject *m_pAttacker;
        CObject *m_pDefender;
        CActions *m_pActions;
        CActions *m_pAllActions;
        enCombatType m_eType;

    public:
        CCombat()
            : m_eType(enCOMBATTYPE_UNKNOWN) {
            m_pAllActions = new CActions;
            m_pActions = new CActions;
        }

        virtual ~CCombat() {
            m_pAllActions->Clear();
            delete m_pAllActions;
            m_pAllActions = NULL;

            m_pActions->Clear();
            delete m_pActions;
            m_pActions = NULL;

            m_pAttacker = NULL;
            m_pDefender = NULL;
        }

        CActions *GetActions(bool bLastRoundOnly = true) const {
            if (bLastRoundOnly)
                return (m_pActions);
            else
                return (m_pAllActions);
        }

        enCombatType GetType() const {
            return (m_eType);
        }

        virtual bool Round() = 0;

        void SetAttacker(CObject *pAttacker) {
            m_pAttacker = pAttacker;
        }

        void SetDefender(CObject *pDefender) {
            m_pDefender = pDefender;
        }
};

#endif // _COMBATINTERFACE_H_INCLUDED
