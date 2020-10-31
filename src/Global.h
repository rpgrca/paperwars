#ifndef _GLOBAL_H_INCLUDED
#define _GLOBAL_H_INCLUDED 0xBEBACAFE

#include "SoldierManager.h"
#include "ActionManager.h"
#include "CombatManager.h"
#include "PositionManager.h"
#include "ObjectServices.h"
#include "SoldierServices.h"
#include "TerrainServices.h"
#include "MapManager.h"
#include "MapServices.h"
#include "ArmourManager.h"
#include "WeaponManager.h"

class CGlobal {
    private:
        CSoldierManager *m_pSoldierManager;
        CActionManager *m_pActionManager;
        CCombatManager *m_pCombatManager;
        CPositionManager *m_pPositionManager;
        CSoldierServices *m_pSoldierServices;
        CObjectServices *m_pObjectServices;
        CTerrainServices *m_pTerrainServices;
        CMapManager *m_pMapManager;
        CMapServices *m_pMapServices;
        CArmourManager *m_pArmourManager;
        CWeaponManager *m_pWeaponManager;
        static CGlobal s_pInstance;

    protected:
        CGlobal();
        CGlobal(const CGlobal &) {
        }

        CGlobal &operator=(const CGlobal &) {
            return (s_pInstance);
        }

       ~CGlobal();

    public:
        static CGlobal *Instance() {
            return &s_pInstance;
        }

        CSoldierServices *GetSoldierServices() {
            return (m_pSoldierServices);
        }

        CSoldierManager *GetSoldierManager() {
            return (m_pSoldierManager);
        }

        CActionManager *GetActionManager() {
            return (m_pActionManager);
        }

        CPositionManager *GetPositionManager() {
            return (m_pPositionManager);
        }

        CCombatManager *GetCombatManager() {
            return (m_pCombatManager);
        }

        CObjectServices *GetObjectServices() {
            return (m_pObjectServices);
        }

        CTerrainServices *GetTerrainServices() {
            return (m_pTerrainServices);
        }

        CMapManager *GetMapManager() {
            return (m_pMapManager);
        }

        CMapServices *GetMapServices() {
            return (m_pMapServices);
        }

        CArmourManager *GetArmourManager() {
            return (m_pArmourManager);
        }

        CWeaponManager *GetWeaponManager() {
            return (m_pWeaponManager);
        }
};

#endif // _GLOBAL_H_INCLUDED
