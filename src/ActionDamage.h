#ifndef _ACTIONDAMAGE_H_INCLUDED
#define _ACTIONDAMAGE_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Action.h"
#include "ActionType.h"

class CActionDamage : public CAction {
    protected:
        long m_lDamage;

    public:
        CActionDamage() {
            m_szName = "ActionDamage";
            m_eActionType = enACTIONTYPE_DAMAGE;
            m_lDamage = 0;
        }

        void SetDamage(const long lDamage) {
            m_lDamage = lDamage;
        }

        long GetDamage() const {
            return (m_lDamage);
        }
};

#endif // _ACTIONDAMAGE_H_INCLUDED
