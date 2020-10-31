#ifndef _ACTIONS_H_INCLUDED
#define _ACTIONS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Action.h"

class CActions {
    private:
        std::vector<CAction *> m_pActions;

    public:
       ~CActions() {
            Clear();
        }

        bool Add(CAction *pAction) {
            bool bResult = false;

            if (pAction != NULL) {
                if (Find(pAction->GetID()) == NULL) {
                    m_pActions.push_back(pAction);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CAction *pAction = NULL;
            std::vector<CAction *>::iterator pIterator;

            for (pIterator = m_pActions.begin(); pIterator != m_pActions.end(); ++pIterator) {
                pAction = (*pIterator);
                delete pAction;
            }

            m_pActions.clear();
        }

        void Clear() {
            m_pActions.clear();
        }

        CAction *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pActions.size())
                return (m_pActions.at(lIndex));
            else
                return (NULL);
        }

        CAction *Find(const long lID) {
            CAction *pAction = NULL;
            std::vector<CAction *>::iterator pIterator;

            for (pIterator = m_pActions.begin(); pIterator != m_pActions.end(); ++pIterator) {
                pAction = (*pIterator);
                if (pAction->GetID() == lID) {
                    return (pAction);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pActions.size());
        }

        bool Remove(CAction *pAction) {
            CAction *pActionToFind = NULL;
            std::vector<CAction *>::iterator pIterator;
            bool bResult = false;

            if (pAction != NULL) {
                for (pIterator = m_pActions.begin(); pIterator != m_pActions.end(); ++pIterator) {
                    pActionToFind = (*pIterator);
                    if (pActionToFind->GetID() == pAction->GetID()) {
                        m_pActions.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _ACTIONS_H_INCLUDED
