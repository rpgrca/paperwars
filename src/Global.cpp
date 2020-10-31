#include <ctime>
#include <cstdlib>
#include "Global.h"
#include "SoldierManager.h"
#include "CombatManager.h"
#include "SoldierServices.h"
#include "ObjectServices.h"
#include "TerrainServices.h"
#include "MapManager.h"
#include "MapServices.h"
#include "ArmourManager.h"
#include "WeaponManager.h"

CGlobal CGlobal::s_pInstance;

CGlobal::CGlobal() {
    srand(time(NULL));

    m_pSoldierManager = new CSoldierManager;
    m_pSoldierServices = new CSoldierServices;
    m_pActionManager = new CActionManager;
    m_pCombatManager = new CCombatManager;
    m_pPositionManager = new CPositionManager;
    m_pObjectServices = new CObjectServices;
    m_pTerrainServices = new CTerrainServices;
    m_pMapManager = new CMapManager;
    m_pMapServices = new CMapServices;
    m_pArmourManager = new CArmourManager;
    m_pWeaponManager = new CWeaponManager;
}

CGlobal::~CGlobal() {
    delete m_pSoldierManager;
    m_pSoldierManager = NULL;

    delete m_pSoldierServices;
    m_pSoldierServices = NULL;

    delete m_pActionManager;
    m_pActionManager = NULL;

    delete m_pPositionManager;
    m_pPositionManager = NULL;

    delete m_pCombatManager;
    m_pCombatManager = NULL;

    delete m_pObjectServices;
    m_pObjectServices = NULL;

    delete m_pTerrainServices;
    m_pTerrainServices = NULL;

    delete m_pMapManager;
    m_pMapManager = NULL;

    delete m_pMapServices;
    m_pMapServices = NULL;

    delete m_pArmourManager;
    m_pArmourManager = NULL;

    delete m_pWeaponManager;
    m_pWeaponManager = NULL;
}
