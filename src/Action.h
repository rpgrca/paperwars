#ifndef _ACTION_H_INCLUDED
#define _ACTION_H_INCLUDED 0xBEBACAFE

#include <string>
#include "Object.h"
#include "ActionType.h"

class CAction : public CObject {
    protected:
        enActionType m_eActionType;
        CObject *m_pObject;

    public:
        CAction()
            : m_eActionType(enACTIONTYPE_UNKNOWN), m_pObject(NULL) {
            m_szName = "Unknown";
        }

        virtual ~CAction() {
        }

        enActionType GetType() const {
            return (m_eActionType);
        }

        void SetObject(CObject *pObject) {
            m_pObject = pObject;
        }

        CObject *GetObject() const {
            return (m_pObject);
        }
};

#endif // _ACTION_H_INCLUDED
