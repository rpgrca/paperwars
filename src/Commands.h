#ifndef _COMMANDS_H_INCLUDED
#define _COMMANDS_H_INCLUDED 0xBEBACAFE

#include <vector>
#include "Command.h"

class CCommands {
    private:
        std::vector<CCommand *> m_pCommands;

    public:
       ~CCommands() {
            Clear();
        }

        bool Add(CCommand *pCommand) {
            bool bResult = false;

            if (pCommand != NULL) {
                if (Find(pCommand->GetID()) == NULL) {
                    m_pCommands.push_back(pCommand);
                    bResult = true;
                }
            }

            return (bResult);
        }

        void Purge() {
            CCommand *pCommand = NULL;
            std::vector<CCommand *>::iterator pIterator;

            for (pIterator = m_pCommands.begin(); pIterator != m_pCommands.end(); ++pIterator) {
                pCommand = (*pIterator);
                delete pCommand;
            }

            m_pCommands.clear();
        }

        void Clear() {
            m_pCommands.clear();
        }

        CCommand *GetAt(const unsigned long lIndex) {
            if (lIndex < m_pCommands.size())
                return (m_pCommands.at(lIndex));
            else
                return (NULL);
        }

        CCommand *Find(const long lID) {
            CCommand *pCommand = NULL;
            std::vector<CCommand *>::iterator pIterator;

            for (pIterator = m_pCommands.begin(); pIterator != m_pCommands.end(); ++pIterator) {
                pCommand = (*pIterator);
                if (pCommand->GetID() == lID) {
                    return (pCommand);
                }
            }

            return (NULL);
        }

        unsigned long GetCount() const {
            return (m_pCommands.size());
        }

        bool Remove(CCommand *pCommand) {
            CCommand *pCommandToFind = NULL;
            std::vector<CCommand *>::iterator pIterator;
            bool bResult = false;

            if (pCommand != NULL) {
                for (pIterator = m_pCommands.begin(); pIterator != m_pCommands.end(); ++pIterator) {
                    pCommandToFind = (*pIterator);
                    if (pCommandToFind->GetID() == pCommand->GetID()) {
                        m_pCommands.erase(pIterator);
                        bResult = true;
                        break;
                    }
                }
            }

            return (bResult);
        }
};

#endif // _COMMANDS_H_INCLUDED
