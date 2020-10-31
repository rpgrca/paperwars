#include <iostream>
#include <iomanip>
#include <vector>
#include "ITest.h"
#include "Soldier.h"
#include "Soldiers.h"
#include "SoldierType.h"
#include "SoldierFactory.h"
#include "SoldierManager.h"
#include "SoldierServices.h"
#include "Combat.h"
#include "CombatSimple.h"
#include "Combats.h"
#include "CombatFactory.h"
#include "CombatManager.h"
#include "Action.h"
#include "Actions.h"
#include "ActionType.h"
#include "ActionFactory.h"
#include "ActionManager.h"
#include "Position.h"
#include "Positions.h"
#include "PositionFactory.h"
#include "PositionManager.h"
#include "PositionServices.h"
#include "Battalion.h"
#include "Battalions.h"
#include "BattalionFactory.h"
#include "BattalionManager.h"
#include "BattalionServices.h"
#include "Matrix.h"
#include "Terrain.h"
#include "TerrainFactory.h"
#include "TerrainManager.h"
#include "Map.h"
#include "Maps.h"
#include "MapFactory.h"
#include "MapManager.h"
#include "MapServices.h"
#include "Battlefield.h"
#include "Weapon.h"
#include "WeaponType.h"
#include "Weapons.h"
#include "WeaponFactory.h"
#include "WeaponManager.h"
#include "Armour.h"
#include "ArmourType.h"
#include "Armours.h"
#include "ArmourFactory.h"
#include "ArmourManager.h"
#include "Shop.h"
#include "Shops.h"
#include "ShopFactory.h"
#include "ShopManager.h"
#include "Input.h"

using namespace std;

long ITest::s_lTestID = 1;
bool m_bDump = false;

bool CheckAgainstDefaultSoldierValues(CSoldier *pSoldier) {
    bool bResult = true;

    bResult &= (pSoldier->GetName() == pSoldier->GetDefaultName());
    bResult &= (pSoldier->GetHealth() == pSoldier->GetDefaultHealth());
    bResult &= (pSoldier->GetMaximumHealth() == pSoldier->GetDefaultMaximumHealth());
    bResult &= (pSoldier->GetAttack() == pSoldier->GetDefaultAttack());
    bResult &= (pSoldier->GetMaximumAttack() == pSoldier->GetDefaultMaximumAttack());
    bResult &= (pSoldier->GetDefense() == pSoldier->GetDefaultDefense());
    bResult &= (pSoldier->GetMaximumDefense() == pSoldier->GetDefaultMaximumDefense());
    bResult &= (pSoldier->GetLevel() == pSoldier->GetDefaultLevel());
    bResult &= (pSoldier->GetExperience() == pSoldier->GetDefaultExperience());
    bResult &= (pSoldier->GetType() == pSoldier->GetDefaultType());
    bResult &= (pSoldier->GetSpeed() == pSoldier->GetDefaultSpeed());

    return (bResult);
}

bool CheckAgainstDefaultPositionValues(CPosition *pPosition) {
    bool bResult = true;

    bResult &= (pPosition->GetPositionX() == pPosition->GetDefaultPositionX());
    bResult &= (pPosition->GetPositionY() == pPosition->GetDefaultPositionY());
    bResult &= (pPosition->GetLevel() == pPosition->GetDefaultLevel());
    bResult &= (pPosition->GetObject() == NULL);

    return (bResult);
}

void DumpMap(CMap *pMap) {
    long lPositionX = 0;
    long lPositionY = 0;

    for (lPositionY = 0; lPositionY < pMap->GetHeight(); lPositionY++) {
        cout << "\t";
        for (lPositionX = 0; lPositionX < pMap->GetWidth(); lPositionX++) {
            cout <<(*pMap)[lPositionY][lPositionX]->GetType();
        }

        cout << endl;
    }
}

void DumpActions(CActions *pActions) {
    unsigned long lIndex = 0;
    CAction *pAction = NULL;
    CActionDamage *pActionDamage = NULL;

    for (lIndex = 0; lIndex < pActions->GetCount(); lIndex++) {
        pAction = pActions->GetAt(lIndex);
        cout << "\tAction by " << pAction->GetObject()->GetName() << " " << pAction->GetObject()->GetID() << ": " << pAction->GetName();
        if (pAction->GetType() == enACTIONTYPE_DAMAGE) {
            pActionDamage = dynamic_cast<CActionDamage *>(pAction);
            cout << " (damage: " << pActionDamage->GetDamage() << ")";
        }
        cout << endl;
    }
}

class CTestSoldierDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CSoldier::CSoldier (default constructor)");
        }

        bool Execute() {
            bool bResult = false;

            CSoldier *pSoldier = new CSoldier;
            bResult = CheckAgainstDefaultSoldierValues(pSoldier);
            delete pSoldier;
            pSoldier = NULL;

            return (bResult);
        }
};

class CTestSoldierFullConstructor : public ITest {
    public:
        string GetName() const {
            return ("CSoldier::CSoldier (full constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CSoldier *pSoldier = NULL;

            pSoldier = new CSoldier(enSOLDIERTYPE_CAVALIER, "Test", 0, 1, 2, 3, 4, 5, 6, 7, 8);
            bResult = (pSoldier->GetName() == "Test" &&
                       pSoldier->GetHealth() == 0 &&
                       pSoldier->GetMaximumHealth() == 1 &&
                       pSoldier->GetAttack() == 2 &&
                       pSoldier->GetMaximumAttack() == 3 &&
                       pSoldier->GetDefense() == 4 &&
                       pSoldier->GetMaximumDefense() == 5 &&
                       pSoldier->GetLevel() == 6 &&
                       pSoldier->GetExperience() == 7 &&
                       pSoldier->GetType() == enSOLDIERTYPE_CAVALIER &&
                       pSoldier->GetSpeed() == 8);
            delete pSoldier;
            pSoldier = NULL;

            return (bResult);
        }
};

class CTestSoldiersConstructor : public ITest {
    public:
        string GetName() const {
            return ("CSoldiers::CSoldiers (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CSoldiers *pSoldiers = NULL;

            pSoldiers = new CSoldiers;
            if (pSoldiers != NULL) {
                delete pSoldiers;
                pSoldiers = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestSoldiersAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CSoldiers::Add / CSoldiers::Remove");
        }

        bool Execute() {
            bool bResult = false;
            CSoldiers *pSoldiers = NULL;
            CSoldier *pSoldier = NULL;

            pSoldiers = new CSoldiers;
            pSoldier = new CSoldier;

            bResult = pSoldiers->Add(pSoldier);
            bResult &= (pSoldiers->GetCount() == 1);
            bResult &= (pSoldiers->Add(pSoldier) == false);
            bResult &= (pSoldiers->GetCount() == 1);
            pSoldier = NULL;

            bResult &= pSoldiers->Add(new CSoldier);
            bResult &= pSoldiers->Add(new CSoldier);
            bResult &= pSoldiers->Add(new CSoldier);
            bResult &= (pSoldiers->GetCount() == 4);

            pSoldier = new CSoldier;
            bResult &= (pSoldiers->Remove(pSoldier) == false);
            delete pSoldier;
            pSoldier = NULL;

            bResult &= (pSoldiers->GetCount() == 4);
            pSoldiers->Purge();
            bResult &= (pSoldiers->GetCount() == 0);
            delete pSoldiers;
            pSoldiers = NULL;

            return (bResult);
        }
};

class CTestSoldiersFind : public ITest {
    public:
        string GetName() const {
            return ("CSoldiers::Find");
        }

        bool Execute() {
            bool bResult = false;
            CSoldiers *pSoldiers = NULL;
            CSoldier *pSoldier = NULL;

            pSoldiers = new CSoldiers;
            pSoldiers->Add(new CSoldier);
            pSoldiers->Add(new CSoldier);
            pSoldiers->Add(new CSoldier);
            bResult = (pSoldiers->GetCount() == 3);

            pSoldier = new CSoldier;
            bResult &= (pSoldiers->Find(pSoldier->GetID()) == false);
            bResult &= (pSoldiers->Add(pSoldier));
            bResult &= (pSoldiers->Find(pSoldier->GetID()) != NULL);
            bResult &= (pSoldiers->GetCount() == 4);

            pSoldiers->Purge();
            delete pSoldiers;
            return (bResult);
        }
};

class CTestSoldiersGetAt : public ITest {
    public:
        string GetName() const {
            return ("CSoldiers::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CSoldiers *pSoldiers = NULL;
            CSoldier *pSoldier = NULL;

            pSoldiers = new CSoldiers;
            pSoldier = new CSoldier;
            pSoldiers->Add(pSoldier);
            bResult  = (pSoldiers->GetAt(0)->GetID() == pSoldier->GetID());
            bResult &= (pSoldiers->GetAt(1) == NULL);

            delete pSoldiers;
            delete pSoldier;
            return (bResult);
        }
};

class CTestSoldiersClear : public ITest {
    public:
        string GetName() const {
            return ("CSoldiers::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CSoldiers *pSoldiers = NULL;
            CSoldier *pSoldier = NULL;

            pSoldiers = new CSoldiers;
            pSoldier = new CSoldier;
            pSoldiers->Add(pSoldier);
            pSoldiers->Clear();
            bResult = (pSoldiers->GetCount() == 0);

            delete pSoldiers;
            delete pSoldier;
            return (bResult);
        }
};

class CTestObjectID : public ITest {
    public:
        string GetName() const {
            return ("CObject::GetID");
        }

        bool Execute() {
            CObject *pObject1 = NULL;
            CObject *pObject2 = NULL;
            bool bResult = false;

            pObject1 = new CSoldier;
            pObject2 = new CSoldier;
            bResult = ((pObject1->GetID() + 1) == pObject2->GetID());
            delete pObject1;
            delete pObject2;
            pObject1 = NULL;
            pObject2 = NULL;

            return (bResult);
        }
};

class CTestWeaponDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CWeapon::CWeapon (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CWeapon *pWeapon = NULL;

            pWeapon = new CWeapon;
            if (pWeapon != NULL) {
                delete pWeapon;
                pWeapon = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestWeaponFullConstructor : public ITest {
    public:
        string GetName() const {
            return ("CWeapon::CWeapon (full constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CWeapon *pWeapon = NULL;

            pWeapon = new CWeapon(10, 14);
            bResult = (pWeapon->GetToHitModifier() == 10) && (pWeapon->GetDamageModifier() == 14);
            delete pWeapon;

            pWeapon = new CWeapon(13, 15, enWEAPONTYPE_KNIFE);
            bResult &= ((pWeapon->GetToHitModifier() == 13) && (pWeapon->GetDamageModifier() == 15) && (pWeapon->GetType() == enWEAPONTYPE_KNIFE));
            delete pWeapon;

            return (bResult);
        }
};

class CTestWeaponSetGet : public ITest {
    public:
        string GetName() const {
            return ("CWeapon::Get / CWeapon::Set");
        }

        bool Execute() {
            bool bResult = false;
            CWeapon *pWeapon = NULL;

            pWeapon = new CWeapon();
            pWeapon->SetName("Test");
            bResult  = (pWeapon->GetName() == "Test");
            pWeapon->SetDamageModifier(10);
            bResult &= (pWeapon->GetDamageModifier() == 10);
            pWeapon->SetToHitModifier(12);
            bResult &= (pWeapon->GetToHitModifier() == 12);

            delete pWeapon;
            return (bResult);
        }
};

class CTestWeaponsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CWeapons::CWeapons (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CWeapons *pWeapons = NULL;

            pWeapons = new CWeapons;
            if (pWeapons != NULL) {
                delete pWeapons;
                pWeapons = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestWeaponsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CWeapons::Add / CWeapons::Remove / CWeapons::GetCount");
        }

        bool Execute() {
            bool bResult = false;
            CWeapons *pWeapons = NULL;
            CWeapon *pWeapon = NULL;

            pWeapons = new CWeapons;
            pWeapon = new CWeapon;

            bResult = pWeapons->Add(pWeapon);
            bResult &= (pWeapons->GetCount() == 1);
            bResult &= (pWeapons->Add(pWeapon) == false);
            bResult &= (pWeapons->GetCount() == 1);
            pWeapon = NULL;

            bResult &= pWeapons->Add(new CWeapon);
            bResult &= pWeapons->Add(new CWeapon);
            bResult &= pWeapons->Add(new CWeapon);
            bResult &= (pWeapons->GetCount() == 4);

            pWeapon = new CWeapon;
            bResult &= (pWeapons->Remove(pWeapon) == false);
            delete pWeapon;
            pWeapon = NULL;

            bResult &= (pWeapons->GetCount() == 4);
            pWeapons->Purge();
            bResult &= (pWeapons->GetCount() == 0);
            delete pWeapons;
            pWeapons = NULL;

            return (bResult);
        }
};

class CTestWeaponsFind : public ITest {
    public:
        string GetName() const {
            return ("CWeapons::Find");
        }

        bool Execute() {
            bool bResult = false;
            CWeapons *pWeapons = NULL;
            CWeapon *pWeapon = NULL;

            pWeapons = new CWeapons;
            pWeapons->Add(new CWeapon);
            pWeapons->Add(new CWeapon);
            pWeapons->Add(new CWeapon);
            bResult = (pWeapons->GetCount() == 3);

            pWeapon = new CWeapon;
            bResult &= (pWeapons->Find(pWeapon->GetID()) == false);
            bResult &= (pWeapons->Add(pWeapon));
            bResult &= (pWeapons->Find(pWeapon->GetID()) != NULL);
            bResult &= (pWeapons->GetCount() == 4);

            pWeapons->Purge();
            delete pWeapons;
            return (bResult);
        }
};

class CTestWeaponsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CWeapons::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CWeapons *pWeapons = NULL;
            CWeapon *pWeapon = NULL;

            pWeapons = new CWeapons;
            pWeapon = new CWeapon;
            pWeapons->Add(pWeapon);
            bResult  = (pWeapons->GetAt(0)->GetID() == pWeapon->GetID());
            bResult &= (pWeapons->GetAt(1) == NULL);

            delete pWeapons;
            delete pWeapon;
            return (bResult);
        }
};

class CTestWeaponsClear : public ITest {
    public:
        string GetName() const {
            return ("CWeapons::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CWeapons *pWeapons = NULL;
            CWeapon *pWeapon = NULL;

            pWeapons = new CWeapons;
            pWeapon = new CWeapon;
            pWeapons->Add(pWeapon);
            pWeapons->Clear();
            bResult = (pWeapons->GetCount() == 0);

            delete pWeapons;
            delete pWeapon;
            return (bResult);
        }
};

class CTestWeaponFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CWeaponFactory::CWeaponFactory");
        }

        bool Execute() {
            bool bResult = false;
            CWeaponFactory *pWeaponFactory = NULL;

            pWeaponFactory = new CWeaponFactory;
            if (pWeaponFactory != NULL) {
                delete pWeaponFactory;
                pWeaponFactory = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestWeaponFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CWeaponFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CWeaponFactory *pWeaponFactory = NULL;
            CWeapon *pWeapon = NULL;

            pWeaponFactory = new CWeaponFactory;
            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_NONE);
            bResult = (pWeapon == NULL);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_UNKNOWN);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_UNKNOWN);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_AXE);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_AXE);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_SWORD);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_SWORD);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_BOW);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_BOW);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_KNIFE);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_KNIFE);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_HALBERD);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_HALBERD);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_CLUB);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_CLUB);
            delete pWeapon;

            pWeapon = pWeaponFactory->Create(enWEAPONTYPE_MAGIC_WAND);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_MAGIC_WAND);
            delete pWeapon;

            delete pWeaponFactory;
            return (bResult);
        }
};

class CTestWeaponManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CWeaponManager::CWeaponManager");
        }

        bool Execute() {
            bool bResult = false;
            CWeaponManager *pWeaponManager = NULL;

            pWeaponManager = new CWeaponManager;
            if (pWeaponManager != NULL) {
                delete pWeaponManager;
                pWeaponManager = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestWeaponManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CWeaponManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CWeaponManager *pWeaponManager = NULL;
            CWeapon *pWeapon = NULL;

            pWeaponManager = new CWeaponManager;
            pWeapon = pWeaponManager->Create(enWEAPONTYPE_NONE);
            bResult = (pWeapon == NULL);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_UNKNOWN);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_UNKNOWN);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_AXE);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_AXE);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_SWORD);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_SWORD);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_BOW);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_BOW);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_KNIFE);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_KNIFE);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_HALBERD);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_HALBERD);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_CLUB);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_CLUB);

            pWeapon = pWeaponManager->Create(enWEAPONTYPE_MAGIC_WAND);
            bResult = (pWeapon->GetType() == enWEAPONTYPE_MAGIC_WAND);

            delete pWeaponManager;
            return (bResult);

        }
};

class CTestArmourDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CArmour::CArmour (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CArmour *pArmour = NULL;

            pArmour = new CArmour;
            if (pArmour != NULL) {
                bResult = (pArmour->GetDefenseModifier() == pArmour->GetDefaultDefenseModifier());
                bResult &= (pArmour->GetDodgeModifier() == pArmour->GetDefaultDodgeModifier());
                bResult &= (pArmour->GetType() == pArmour->GetDefaultType());
                delete pArmour;
                pArmour = NULL;
            }

            return (bResult);
        }
};

class CTestArmourFullConstructor : public ITest {
    public:
        string GetName() const {
            return ("CArmour::CArmour (full constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CArmour *pArmour = NULL;

            pArmour = new CArmour(1, 2);
            if (pArmour != NULL) {
                bResult = (pArmour->GetDodgeModifier() == 1);
                bResult &= (pArmour->GetDefenseModifier() == 2);
                bResult &= (pArmour->GetType() == enARMOURTYPE_UNKNOWN);

                delete pArmour;
                pArmour = NULL;
            }

            pArmour = new CArmour(1, 2, enARMOURTYPE_HELM);
            if (pArmour != NULL) {
                bResult = (pArmour->GetDodgeModifier() == 1);
                bResult &= (pArmour->GetDefenseModifier() == 2);
                bResult &= (pArmour->GetType() == enARMOURTYPE_HELM);

                delete pArmour;
                pArmour = NULL;
            }

            return (bResult);
        }
};

class CTestArmourSetGet : public ITest {
    public:
        string GetName() const {
            return ("CArmour::Get / CArmour::Set");
        }

        bool Execute() {
            bool bResult = false;
            CArmour *pArmour = NULL;

            pArmour = new CArmour();
            pArmour->SetName("Test1");
            bResult  = (pArmour->GetName() == "Test1");
            pArmour->SetDefenseModifier(14);
            bResult &= (pArmour->GetDefenseModifier() == 14);
            pArmour->SetDodgeModifier(16);
            bResult &= (pArmour->GetDodgeModifier() == 16);

            delete pArmour;
            return (bResult);
        }
};

class CTestArmoursConstructor : public ITest {
    public:
        string GetName() const {
            return ("CArmours::CArmours (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CArmours *pArmours = NULL;

            pArmours = new CArmours;
            if (pArmours != NULL) {
                delete pArmours;
                pArmours = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestArmoursAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CArmours::Add / CArmours::Remove / CArmours::GetCount");
        }

        bool Execute() {
            bool bResult = false;
            CArmours *pArmours = NULL;
            CArmour *pArmour = NULL;

            pArmours = new CArmours;
            pArmour = new CArmour;

            bResult = pArmours->Add(pArmour);
            bResult &= (pArmours->GetCount() == 1);
            bResult &= (pArmours->Add(pArmour) == false);
            bResult &= (pArmours->GetCount() == 1);
            pArmour = NULL;

            bResult &= pArmours->Add(new CArmour);
            bResult &= pArmours->Add(new CArmour);
            bResult &= pArmours->Add(new CArmour);
            bResult &= (pArmours->GetCount() == 4);

            pArmour = new CArmour;
            bResult &= (pArmours->Remove(pArmour) == false);
            delete pArmour;
            pArmour = NULL;

            bResult &= (pArmours->GetCount() == 4);
            pArmours->Purge();
            bResult &= (pArmours->GetCount() == 0);
            delete pArmours;
            pArmours = NULL;

            return (bResult);
        }
};

class CTestArmoursFind : public ITest {
    public:
        string GetName() const {
            return ("CArmours::Find");
        }

        bool Execute() {
            bool bResult = false;
            CArmours *pArmours = NULL;
            CArmour *pArmour = NULL;

            pArmours = new CArmours;
            pArmours->Add(new CArmour);
            pArmours->Add(new CArmour);
            pArmours->Add(new CArmour);
            bResult = (pArmours->GetCount() == 3);

            pArmour = new CArmour;
            bResult &= (pArmours->Find(pArmour->GetID()) == false);
            bResult &= (pArmours->Add(pArmour));
            bResult &= (pArmours->Find(pArmour->GetID()) != NULL);
            bResult &= (pArmours->GetCount() == 4);

            pArmours->Purge();
            delete pArmours;
            return (bResult);
        }
};

class CTestArmoursGetAt : public ITest {
    public:
        string GetName() const {
            return ("CArmours::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CArmours *pArmours = NULL;
            CArmour *pArmour = NULL;

            pArmours = new CArmours;
            pArmour = new CArmour;
            pArmours->Add(pArmour);
            bResult  = (pArmours->GetAt(0)->GetID() == pArmour->GetID());
            bResult &= (pArmours->GetAt(1) == NULL);

            delete pArmours;
            delete pArmour;
            return (bResult);
        }
};

class CTestArmoursClear : public ITest {
    public:
        string GetName() const {
            return ("CArmours::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CArmours *pArmours = NULL;
            CArmour *pArmour = NULL;

            pArmours = new CArmours;
            pArmour = new CArmour;
            pArmours->Add(pArmour);
            pArmours->Clear();
            bResult = (pArmours->GetCount() == 0);

            delete pArmours;
            delete pArmour;
            return (bResult);
        }
};

class CTestArmourFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CArmourFactory::CArmourFactory");
        }

        bool Execute() {
            bool bResult = false;
            CArmourFactory *pArmourFactory = NULL;

            pArmourFactory = new CArmourFactory;
            if (pArmourFactory != NULL) {
                delete pArmourFactory;
                pArmourFactory = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestArmourFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CArmourFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CArmourFactory *pArmourFactory = NULL;
            CArmour *pArmour = NULL;

            pArmourFactory = new CArmourFactory;
            pArmour = pArmourFactory->Create(enARMOURTYPE_NONE);
            bResult = (pArmour == NULL);

            pArmour = pArmourFactory->Create(enARMOURTYPE_UNKNOWN);
            bResult &= (pArmour->GetType() == enARMOURTYPE_UNKNOWN);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_HELM);
            bResult &= (pArmour->GetType() == enARMOURTYPE_HELM);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_MAIL);
            bResult &= (pArmour->GetType() == enARMOURTYPE_MAIL);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_BRACERS);
            bResult &= (pArmour->GetType() == enARMOURTYPE_BRACERS);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_GREAVES);
            bResult &= (pArmour->GetType() == enARMOURTYPE_GREAVES);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_BOOTS);
            bResult &= (pArmour->GetType() == enARMOURTYPE_BOOTS);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_SHIELD);
            bResult &= (pArmour->GetType() == enARMOURTYPE_SHIELD);
            delete pArmour;

            pArmour = pArmourFactory->Create(enARMOURTYPE_CLOAK);
            bResult &= (pArmour->GetType() == enARMOURTYPE_CLOAK);
            delete pArmour;

            delete pArmourFactory;
            return (bResult);
        }
};

class CTestArmourManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CArmourManager::CArmourManager");
        }

        bool Execute() {
            bool bResult = false;
            CArmourManager *pArmourManager = NULL;

            pArmourManager = new CArmourManager;
            if (pArmourManager != NULL) {
                delete pArmourManager;
                pArmourManager = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestArmourManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CArmourManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CArmourManager *pArmourManager = NULL;
            CArmour *pArmour = NULL;

            pArmourManager = new CArmourManager;
            pArmour = pArmourManager->Create(enARMOURTYPE_NONE);
            bResult = (pArmour == NULL);

            pArmour = pArmourManager->Create(enARMOURTYPE_UNKNOWN);
            bResult &= (pArmour->GetType() == enARMOURTYPE_UNKNOWN);

            pArmour = pArmourManager->Create(enARMOURTYPE_HELM);
            bResult &= (pArmour->GetType() == enARMOURTYPE_HELM);

            pArmour = pArmourManager->Create(enARMOURTYPE_MAIL);
            bResult &= (pArmour->GetType() == enARMOURTYPE_MAIL);

            pArmour = pArmourManager->Create(enARMOURTYPE_BRACERS);
            bResult &= (pArmour->GetType() == enARMOURTYPE_BRACERS);

            pArmour = pArmourManager->Create(enARMOURTYPE_GREAVES);
            bResult &= (pArmour->GetType() == enARMOURTYPE_GREAVES);

            pArmour = pArmourManager->Create(enARMOURTYPE_BOOTS);
            bResult &= (pArmour->GetType() == enARMOURTYPE_BOOTS);

            pArmour = pArmourManager->Create(enARMOURTYPE_SHIELD);
            bResult &= (pArmour->GetType() == enARMOURTYPE_SHIELD);

            pArmour = pArmourManager->Create(enARMOURTYPE_CLOAK);
            bResult &= (pArmour->GetType() == enARMOURTYPE_CLOAK);

            delete pArmourManager;
            return (bResult);
        }
};

class CTestSoldierFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CSoldierFactory::CSoldierFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CSoldierFactory *pSoldierFactory = NULL;

            pSoldierFactory = new CSoldierFactory;
            if (pSoldierFactory != NULL) {
                bResult = true;
                delete pSoldierFactory;
                pSoldierFactory = NULL;
            }

            return (bResult);
        }
};

class CTestSoldierFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CSoldierFactory::Create");
        }

        bool Execute() {
            CSoldierFactory *pSoldierFactory = NULL;
            CSoldier *pSoldier = NULL;
            bool bResult = true;

            pSoldierFactory = new CSoldierFactory;
            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_NONE);
            bResult = (pSoldier == NULL);

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_UNKNOWN);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_UNKNOWN);
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_FOOTMAN);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_ARCHER);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier)); 
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_PIKEMAN);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_CLERIC);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_MAGE);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_CAVALIER);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            pSoldier = pSoldierFactory->Create(enSOLDIERTYPE_MESSENGER);
            bResult &= (CheckAgainstDefaultSoldierValues(pSoldier));
            delete pSoldier;
            pSoldier = NULL;

            delete pSoldierFactory;
            pSoldierFactory = NULL;
            return (bResult);
        }
};

class CTestSoldierManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CSoldierManager::Create (all)");
        }

        bool Execute() {
            CSoldierManager *pSoldierManager = NULL;
            CSoldier *pSoldier = NULL;
            bool bResult = true;

            pSoldierManager = new CSoldierManager;
            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_NONE);
            bResult = (pSoldier == NULL);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_UNKNOWN);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_UNKNOWN);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_FOOTMAN);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_ARCHER);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_ARCHER);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_PIKEMAN);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_PIKEMAN);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_CLERIC);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_CLERIC);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_MAGE);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_MAGE);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_CAVALIER);
            bResult &= (pSoldier->GetType() == enSOLDIERTYPE_CAVALIER);
            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;

            delete pSoldierManager;
            pSoldierManager = NULL;
            return (bResult);
        }
};

class CTestSoldierManagerCreate : public ITest {
    public:
        string GetName() const {
            return ("CSoldierManager::Create");
        }

        bool Execute() {
            bool bResult = false;
            CSoldierManager *pSoldierManager = NULL;
            CSoldier *pSoldier = NULL;

            pSoldierManager = new CSoldierManager;
            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_CAVALIER, "Test2", 0, 1, 2, 3, 4, 5, 6, 7, 8);
            bResult = (pSoldier->GetName() == "Test2" &&
                       pSoldier->GetHealth() == 0 &&
                       pSoldier->GetMaximumHealth() == 1 &&
                       pSoldier->GetAttack() == 2 &&
                       pSoldier->GetMaximumAttack() == 3 &&
                       pSoldier->GetDefense() == 4 &&
                       pSoldier->GetMaximumDefense() == 5 &&
                       pSoldier->GetLevel() == 6 &&
                       pSoldier->GetExperience() == 7 &&
                       pSoldier->GetType() == enSOLDIERTYPE_CAVALIER &&
                       pSoldier->GetSpeed() == 8);

            pSoldierManager->Delete(pSoldier);
            pSoldier = NULL;
            delete pSoldierManager;
            pSoldierManager = NULL;

            return (bResult);
        }
};

class CTestSoldierServicesConstructor : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::CSoldierServices (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            if (pSoldierServices != NULL) {
                delete pSoldierServices;
                pSoldierServices = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestSoldierServicesExperience : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::ModifyExperience");
        }

        bool Execute() {
            CSoldierServices *pSoldierServices = NULL;
            CSoldier *pSoldier = NULL;
            bool bResult = false;

            pSoldierServices = new CSoldierServices;
            pSoldier = new CSoldier;
            pSoldier->SetExperience(0);
            pSoldier->SetLevel(1);
            pSoldierServices->ModifyExperience(pSoldier, 10);
            bResult = (pSoldier->GetExperience() == 10) && (pSoldier->GetLevel() == 1);
            pSoldierServices->ModifyExperience(pSoldier, 25500);
            bResult = (pSoldier->GetExperience() == 25510) && (pSoldier->GetLevel() == 51);

            delete pSoldierServices;
            pSoldierServices = NULL;
            delete pSoldier;
            pSoldier = NULL;
            return (bResult);
        }
};

class CTestSoldierServicesHeal : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::Heal");
        }

        bool Execute() {
            bool bResult = false;
            CSoldier *pSoldier = NULL;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            pSoldier = new CSoldier;
            pSoldier->SetMaximumHealth(20);
            pSoldier->SetHealth(1);
            pSoldierServices->Heal(pSoldier, 11);
            bResult = (pSoldier->GetHealth() == 12);

            pSoldierServices->Heal(pSoldier, 100);
            bResult = (pSoldier->GetHealth() == 20);

            pSoldierServices->Kill(pSoldier);
            pSoldierServices->Heal(pSoldier, 100);
            bResult = (pSoldier->GetHealth() == -1);

            delete pSoldier;
            pSoldier = NULL;
            delete pSoldierServices;
            pSoldierServices = NULL;
            return (bResult);
        }
};

class CTestSoldierServicesRevive : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::Revive");
        }

        bool Execute() {
            bool bResult = false;
            CSoldierServices *pSoldierServices = NULL;
            CSoldier *pSoldier = NULL;

            pSoldier = new CSoldier;
            pSoldier->SetMaximumHealth(10);
            pSoldier->SetHealth(-1);

            pSoldierServices = new CSoldierServices;
            bResult = pSoldierServices->Revive(pSoldier);
            bResult = ! pSoldierServices->Revive(pSoldier);
            delete pSoldier;
            pSoldier = NULL;
            delete pSoldierServices;
            pSoldierServices = NULL;

            return (bResult);
        }
};

class CTestSoldierServicesSelect : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::Select / CSoldierServices::Unselect");
        }

        bool Execute() {
            CSoldier *pSoldierExtra = NULL;
            bool bResult = false;
            CSoldier *pSoldier = NULL;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            pSoldier = new CSoldier;
            pSoldierExtra = new CSoldier;

            bResult = pSoldierServices->Select(pSoldier);
            bResult &= (pSoldierServices->GetSelectedSoldiers()->GetCount() == 1);
            bResult &= pSoldierServices->IsSelected(pSoldier);
            bResult &= (pSoldierServices->IsSelected(pSoldierExtra) == false);
            bResult &= (pSoldierServices->Unselect(pSoldierExtra) == false);
            bResult &= pSoldierServices->Unselect(pSoldier);
            bResult &= (pSoldierServices->GetSelectedSoldiers()->GetCount() == 0);
            bResult &= (pSoldierServices->IsSelected(pSoldier) == false);

            delete pSoldier;
            pSoldier = NULL;
            delete pSoldierExtra;
            pSoldierExtra = NULL;
            delete pSoldierServices;
            pSoldierServices = NULL;
            return (bResult);
        }
};

class CTestSoldierServicesEquipUnequipArmour : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::EquipArmour / CSoldierServices::UnequipArmour");
        }

        bool Execute() {
            CSoldier *pSoldier = NULL;
            CArmour *pArmour = NULL;
            CArmour *pArmourExtra = NULL;
            CSoldierServices *pSoldierServices = NULL;
            bool bResult = false;

            pSoldierServices = new CSoldierServices();
            pSoldier = new CSoldier;
            pArmour = new CArmourHelm();
            pArmour->SetDefenseModifier(10);
            pSoldier->SetDefense(5);
            pSoldierServices->EquipArmour(pSoldier, pArmour);

            bResult = (pSoldier->GetModifiedDefense() == 15);

            pArmourExtra = new CArmourHelm();
            pArmourExtra->SetDefenseModifier(10);
            pSoldierServices->EquipArmour(pSoldier, pArmourExtra);
            bResult &= (pSoldier->GetArmours()->GetCount() == 1);
            delete pArmourExtra;

            pArmourExtra = new CArmourBracers();
            pArmourExtra->SetDefenseModifier(15);
            pSoldierServices->EquipArmour(pSoldier, pArmourExtra);
            bResult &= (pSoldier->GetArmours()->GetCount() == 2);
            bResult &= (pSoldier->GetModifiedDefense() == 30);
            delete pArmourExtra;

            delete pSoldierServices;
            delete pSoldier;
            delete pArmour;
            return (bResult);
        }
};

class CTestSoldierServicesEquipUnequipWeapon : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::EquipWeapon / CSoldierServices::UnequipWeapon");
        }

        bool Execute() {
            CSoldier *pSoldier = NULL;
            CWeapon *pWeapon = NULL;
            CWeapon *pWeaponExtra = NULL;
            CSoldierServices *pSoldierServices = NULL;
            bool bResult = false;

            pSoldierServices = new CSoldierServices();
            pSoldier = new CSoldier;
            pWeapon = new CWeaponAxe();
            pWeapon->SetToHitModifier(10);
            pSoldier->SetAttack(5);
            pSoldierServices->EquipWeapon(pSoldier, pWeapon);

            bResult = (pSoldier->GetModifiedAttack() == 15);

            pWeaponExtra = new CWeaponAxe();
            pWeaponExtra->SetToHitModifier(10);
            pSoldierServices->EquipWeapon(pSoldier, pWeaponExtra);
            bResult &= (pSoldier->GetWeapons()->GetCount() == 1);
            bResult &= (pSoldier->GetModifiedAttack() == 15);
            delete pWeaponExtra;

            pWeaponExtra = new CWeaponSword();
            pWeaponExtra->SetToHitModifier(15);
            pSoldierServices->EquipWeapon(pSoldier, pWeaponExtra);
            bResult &= (pSoldier->GetWeapons()->GetCount() == 1);
            bResult &= (pSoldier->GetModifiedAttack() == 15);
            delete pWeaponExtra;

            delete pSoldierServices;
            delete pSoldier;
            delete pWeapon;
            return (bResult);
        }
};

class CTestSoldierServicesCanHeal : public ITest {
    public:
        string GetName() const {
            return ("CSoldierServices::CanHeal");
        }

        bool Execute() {
            bool bResult = false;
            CSoldierManager *pSoldierManager = NULL;
            CSoldier *pSoldier = NULL;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            pSoldierManager = new CSoldierManager;
            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN);
            bResult  = (pSoldierServices->CanHeal(pSoldier) == false);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_ARCHER);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == false);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_CAVALIER);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == false);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_PIKEMAN);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == false);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_CLERIC);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == true);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_MAGE);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == false);

            pSoldier = pSoldierManager->Create(enSOLDIERTYPE_MESSENGER);
            bResult &= (pSoldierServices->CanHeal(pSoldier) == false);

            delete pSoldierManager;
            delete pSoldierServices;
            return (bResult);
        }
};

class CTestBattalionsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CBattalions::CBattalions (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CBattalions *pBattalions = NULL;

            pBattalions = new CBattalions;
            if (pBattalions != NULL) {
                delete pBattalions;
                pBattalions = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestBattalionsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CBattalions::Add / CBattalions::Remove");
        }

        bool Execute() {
            bool bResult = false;
            CBattalions *pBattalions = NULL;
            CBattalion *pBattalion = NULL;

            pBattalions = new CBattalions;
            pBattalion = new CBattalion;

            bResult = pBattalions->Add(pBattalion);
            bResult &= (pBattalions->GetCount() == 1);
            bResult &= (pBattalions->Add(pBattalion) == false);
            bResult &= (pBattalions->GetCount() == 1);
            pBattalion = NULL;

            bResult &= pBattalions->Add(new CBattalion);
            bResult &= pBattalions->Add(new CBattalion);
            bResult &= pBattalions->Add(new CBattalion);
            bResult &= (pBattalions->GetCount() == 4);

            pBattalion = new CBattalion;
            bResult &= (pBattalions->Remove(pBattalion) == false);
            delete pBattalion;
            pBattalion = NULL;

            bResult &= (pBattalions->GetCount() == 4);
            pBattalions->Purge();
            bResult &= (pBattalions->GetCount() == 0);
            delete pBattalions;
            pBattalions = NULL;

            return (bResult);
        }
};

class CTestBattalionsFind : public ITest {
    public:
        string GetName() const {
            return ("CBattalions::Find");
        }

        bool Execute() {
            bool bResult = false;
            CBattalions *pBattalions = NULL;
            CBattalion *pBattalion = NULL;

            pBattalions = new CBattalions;
            pBattalions->Add(new CBattalion);
            pBattalions->Add(new CBattalion);
            pBattalions->Add(new CBattalion);
            bResult = (pBattalions->GetCount() == 3);

            pBattalion = new CBattalion;
            bResult &= (pBattalions->Find(pBattalion->GetID()) == false);
            bResult &= (pBattalions->Add(pBattalion));
            bResult &= (pBattalions->Find(pBattalion->GetID()) != NULL);
            bResult &= (pBattalions->GetCount() == 4);

            pBattalions->Purge();
            delete pBattalions;
            return (bResult);
        }
};

class CTestBattalionsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CBattalions::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CBattalions *pBattalions = NULL;
            CBattalion *pBattalion = NULL;

            pBattalions = new CBattalions;
            pBattalion = new CBattalion;
            pBattalions->Add(pBattalion);
            bResult  = (pBattalions->GetAt(0)->GetID() == pBattalion->GetID());
            bResult &= (pBattalions->GetAt(1) == NULL);

            delete pBattalions;
            delete pBattalion;
            return (bResult);
        }
};

class CTestBattalionsClear : public ITest {
    public:
        string GetName() const {
            return ("CBattalions::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CBattalions *pBattalions = NULL;
            CBattalion *pBattalion = NULL;

            pBattalions = new CBattalions;
            pBattalion = new CBattalion;
            pBattalions->Add(pBattalion);
            pBattalions->Clear();
            bResult = (pBattalions->GetCount() == 0);

            delete pBattalions;
            delete pBattalion;
            return (bResult);
        }
};

class CTestPositionServicesWithinRange : public ITest {
    public:
        string GetName() const {
            return ("CPositionServices::WithinRange()");
        }

        bool Execute() {
            bool bResult = false;
            CPosition *pPositionFootman = NULL;
            CPosition *pPositionArcher = NULL;
            CSoldier *pSoldierFootman = NULL;
            CSoldier *pSoldierArcher = NULL;
            CPositionManager *pPositionManager = NULL;
            CSoldierManager *pSoldierManager = NULL;
            CPositionServices *pPositionServices = NULL;

            pPositionManager = new CPositionManager;
            pSoldierManager = new CSoldierManager;
            pPositionServices = new CPositionServices;

            pPositionFootman = pPositionManager->Create(10, 10, -1, pSoldierFootman = pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN));
            pPositionArcher = pPositionManager->Create(12, 12, -1, pSoldierArcher = pSoldierManager->Create(enSOLDIERTYPE_ARCHER));
            bResult  = (pPositionServices->IsWithinRange(pPositionFootman, pPositionArcher, pSoldierFootman->GetRange()) == false);
            bResult &= (pPositionServices->IsWithinRange(pPositionArcher, pPositionFootman, pSoldierArcher->GetRange()) == true);

            delete pPositionManager;
            delete pSoldierManager;
            delete pPositionServices;

            return (bResult);
        }
};

class CTestBattalionConstructor : public ITest {
    public:
        string GetName() const {
            return ("CBattalion::CBattalion (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CBattalion *pBattalion = NULL;

            pBattalion = new CBattalion;
            if (pBattalion != NULL) {
                bResult = true;
                delete pBattalion;
                pBattalion = NULL;
            }

            return (bResult);
        }
};

class CTestBattalionAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CBattalion::Add / CBattalion::Remove / CBattalion::GetCount");
        }

        bool Execute() {
            bool bResult = false;
            CBattalion *pBattalion = NULL;
            CSoldier *pSoldier = NULL;

            pBattalion = new CBattalion;
            pSoldier = new CSoldier;
            bResult = pBattalion->GetCount() == 0;
            bResult &= (pBattalion->Remove(pSoldier) == false);
            bResult &= pBattalion->GetCount() == 0;
            bResult &= (pBattalion->Add(pSoldier) == true);
            bResult &= pBattalion->GetCount() == 1;
            bResult &= (pBattalion->Add(pSoldier) == false);
            bResult &= pBattalion->GetCount() == 1;
            bResult &= (pBattalion->Remove(pSoldier) == true);
            bResult &= pBattalion->GetCount() == 0;
            bResult &= (pBattalion->Remove(pSoldier) == false);
            bResult &= pBattalion->GetCount() == 0;

            delete pSoldier;
            pSoldier = NULL;
            delete pBattalion;
            pBattalion = NULL;

            return (bResult);
        }
};

class CTestBattalionAttackDefense : public ITest {
    public:
        string GetName() const {
            return ("CBattalion::GetAttack / CBattalion::GetDefense");
        }

        bool Execute() {
            CSoldier *pFootman = NULL;
            CSoldier *pArcher = NULL;
            bool bResult = false;
            CBattalion *pBattalion = NULL;
            CSoldierManager *pSoldierManager = NULL;

            pBattalion = new CBattalion;
            pSoldierManager = new CSoldierManager;

            pBattalion->Add(pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN));
            pBattalion->Add(pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN));
            pBattalion->Add(pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN));
            pFootman = pSoldierManager->Create(enSOLDIERTYPE_FOOTMAN);
            pBattalion->Add(pFootman);
            pArcher = pSoldierManager->Create(enSOLDIERTYPE_ARCHER);
            pBattalion->Add(pArcher);

            bResult = pBattalion->GetAttack() == (pFootman->GetDefaultAttack() * 4 + pArcher->GetDefaultAttack());
            bResult &= pBattalion->GetDefense() == (pFootman->GetDefaultDefense() * 4 + pArcher->GetDefaultDefense());

            delete pBattalion;
            pBattalion = NULL;
            delete pSoldierManager;
            pSoldierManager = NULL;
            return (bResult);
        }
};

class CTestCombatBattalionAgainstBattalion3 : public ITest {
    public:
        string GetName() const {
            return ("CCombatBattalionAgainstBattalion::Round (overwhelming defense)");
        }

        bool Execute() {
            bool bResult = false;
            CCombatBattalionAgainstBattalion *pCombat = NULL;
            CBattalion *pFirstBattalion = NULL;
            CBattalion *pSecondBattalion = NULL;

            pFirstBattalion = new CBattalion;
            pSecondBattalion = new CBattalion;

            pFirstBattalion->Add(new CSoldierCleric);
            pFirstBattalion->Add(new CSoldierCleric);
            pSecondBattalion->Add(new CSoldierCavalier);
            pSecondBattalion->Add(new CSoldierCavalier);
            pSecondBattalion->Add(new CSoldierCavalier);
            pSecondBattalion->Add(new CSoldierPikeman);
            pSecondBattalion->Add(new CSoldierPikeman);

            pCombat = new CCombatBattalionAgainstBattalion;
            pCombat->SetAttacker(pFirstBattalion);
            pCombat->SetDefender(pSecondBattalion);
            pCombat->Round();

            bResult = (pCombat->GetActions(false)->GetCount() == 51);
            if (m_bDump)
                DumpActions(pCombat->GetActions(false));

            pFirstBattalion->Purge();
            delete pFirstBattalion;
            pFirstBattalion = NULL;

            pSecondBattalion->Purge();
            delete pSecondBattalion;
            pSecondBattalion = NULL;

            delete pCombat;
            pCombat = NULL;

            return (bResult);
        }
};


class CTestCombatBattalionAgainstBattalion2 : public ITest {
    public:
        string GetName() const {
            return ("CCombatBattalionAgainstBattalion::Round (overwhelming attack)");
        }

        bool Execute() {
            bool bResult = false;
            CCombatBattalionAgainstBattalion *pCombat = NULL;
            CBattalion *pFirstBattalion = NULL;
            CBattalion *pSecondBattalion = NULL;

            pFirstBattalion = new CBattalion;
            pSecondBattalion = new CBattalion;

            pFirstBattalion->Add(new CSoldierCavalier);
            pFirstBattalion->Add(new CSoldierCavalier);
            pFirstBattalion->Add(new CSoldierCavalier);
            pFirstBattalion->Add(new CSoldierCavalier);
            pFirstBattalion->Add(new CSoldierPikeman);
            pSecondBattalion->Add(new CSoldierCleric);
            pSecondBattalion->Add(new CSoldierCleric);

            pCombat = new CCombatBattalionAgainstBattalion;
            pCombat->SetAttacker(pFirstBattalion);
            pCombat->SetDefender(pSecondBattalion);
            pCombat->Round();

            bResult = (pCombat->GetActions(false)->GetCount() == 32);
            if (m_bDump)
                DumpActions(pCombat->GetActions(false));

            pFirstBattalion->Purge();
            delete pFirstBattalion;
            pFirstBattalion = NULL;

            pSecondBattalion->Purge();
            delete pSecondBattalion;
            pSecondBattalion = NULL;

            delete pCombat;
            pCombat = NULL;

            return (bResult);
        }
};

class CTestCombatBattalionAgainstBattalion : public ITest {
    public:
        string GetName() const {
            return ("CCombatBattalionAgainstBattalion::Round (all survive)");
        }

        bool Execute() {
            bool bResult = false;
            CCombatBattalionAgainstBattalion *pCombat = NULL;
            CBattalion *pFirstBattalion = NULL;
            CBattalion *pSecondBattalion = NULL;

            pFirstBattalion = new CBattalion;
            pSecondBattalion = new CBattalion;

            pFirstBattalion->Add(new CSoldierArcher);
            pFirstBattalion->Add(new CSoldierArcher);
            pFirstBattalion->Add(new CSoldierArcher);
            pFirstBattalion->Add(new CSoldierPikeman);
            pFirstBattalion->Add(new CSoldierMage);
            pSecondBattalion->Add(new CSoldierCleric);
            pSecondBattalion->Add(new CSoldierCleric);

            pCombat = new CCombatBattalionAgainstBattalion;
            pCombat->SetAttacker(pFirstBattalion);
            pCombat->SetDefender(pSecondBattalion);
            pCombat->Round();

            bResult = (pCombat->GetActions(false)->GetCount() == 50);
            if (m_bDump)
                DumpActions(pCombat->GetActions(false));

            pFirstBattalion->Purge();
            delete pFirstBattalion;
            pFirstBattalion = NULL;

            pSecondBattalion->Purge();
            delete pSecondBattalion;
            pSecondBattalion = NULL;

            delete pCombat;
            pCombat = NULL;

            return (bResult);
        }
};

class CTestCombatSoldierAgainstBattalion : public ITest {
    public:
        string GetName() const {
            return ("CCombatSoldierAgainstBattalion::Round");
        }

        bool Execute() {
            bool bResult = true;
            CCombatSoldierAgainstBattalion *pCombat = NULL;
            CSoldier *pAttacker = NULL;
            CSoldier *pDefender = NULL;
            CBattalion *pBattalion = NULL;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            pAttacker = new CSoldierArcher;
            pBattalion = new CBattalion;
            pBattalion->Add(new CSoldierArcher);
            pBattalion->Add(new CSoldierCavalier);
            pBattalion->Add(new CSoldierMage);
            pBattalion->Add(new CSoldierPikeman);

            pCombat = new CCombatSoldierAgainstBattalion;
            pCombat->SetAttacker(pAttacker);
            pCombat->SetDefender(pBattalion);
            pCombat->Round();

            if (m_bDump)
                DumpActions(pCombat->GetActions());

            bResult &= (pCombat->GetActions()->GetCount() == 31);
            pDefender = pBattalion->GetAt(0);
            bResult &= (pDefender->GetHealth() == (pDefender->GetMaximumHealth() - (pSoldierServices->CalculateAttack(pAttacker, pDefender))));
            pDefender = pBattalion->GetAt(1);
            bResult &= (pDefender->GetHealth() == (pDefender->GetMaximumHealth() - (pSoldierServices->CalculateAttack(pAttacker, pDefender))));
            pDefender = pBattalion->GetAt(2);
            bResult &= (pDefender->GetHealth() == (pDefender->GetMaximumHealth() - (pSoldierServices->CalculateAttack(pAttacker, pDefender))));
            pDefender = pBattalion->GetAt(3);
            bResult &= (pDefender->GetHealth() == pDefender->GetMaximumHealth());

            delete pCombat;
            delete pAttacker;
            delete pSoldierServices;

            pBattalion->Purge();
            delete pBattalion;

            return (bResult);
        }
};

class CTestCombatBattalionAgainstSoldier : public ITest {
    public:
        string GetName() const {
            return ("CCombatBattalionAgainstSoldier::Round");
        }

        bool Execute() {
            bool bResult = true;
            CCombatBattalionAgainstSoldier *pCombat = NULL;
            CSoldier *pAttacker = NULL;
            CSoldier *pDefender = NULL;
            CBattalion *pBattalion = NULL;
            CSoldierServices *pSoldierServices = NULL;

            pSoldierServices = new CSoldierServices;
            pBattalion = new CBattalion;
            pBattalion->Add(new CSoldierArcher);
            pBattalion->Add(new CSoldierCavalier);
            pBattalion->Add(new CSoldierMage);
            pBattalion->Add(new CSoldierPikeman);
            pDefender = new CSoldierArcher;

            pCombat = new CCombatBattalionAgainstSoldier;
            pCombat->SetAttacker(pBattalion);
            pCombat->SetDefender(pDefender);
            pCombat->Round();

            if (m_bDump)
                DumpActions(pCombat->GetActions());

            bResult &= (pCombat->GetActions()->GetCount() == 26);
            pAttacker = pBattalion->GetAt(0);
            bResult &= (pAttacker->GetHealth() == (pAttacker->GetMaximumHealth() - (pSoldierServices->CalculateAttack(pDefender, pAttacker))));
            pAttacker = pBattalion->GetAt(1);
            bResult &= (pAttacker->GetHealth() == (pAttacker->GetMaximumHealth() - (pSoldierServices->CalculateAttack(pDefender, pAttacker))));
            pAttacker = pBattalion->GetAt(2);
            bResult &= (pAttacker->GetHealth() == pAttacker->GetMaximumHealth());
            pAttacker = pBattalion->GetAt(3);
            bResult &= (pAttacker->GetHealth() == pAttacker->GetMaximumHealth());

            delete pCombat;
            delete pDefender;
            delete pSoldierServices;

            pBattalion->Purge();
            delete pBattalion;

            return (bResult);
        }
};

class CTestCombatSoldierAgainstSoldier : public ITest {
    public:
        string GetName() const {
            return ("CCombatSoldierAgainstSoldier::Round");
        }

        bool Execute() {
            bool bResult = true;
            CCombatSoldierAgainstSoldier *pCombat = NULL;
            CSoldier *pAttacker = NULL;
            CSoldier *pDefender = NULL;

            pAttacker = new CSoldierArcher;
            pDefender = new CSoldierPikeman;

            pCombat = new CCombatSoldierAgainstSoldier;
            pCombat->SetAttacker(pAttacker);
            pCombat->SetDefender(pDefender);
            pCombat->Round();
            bResult &= (pCombat->GetActions()->GetCount() == 10);

            if (m_bDump)
                DumpActions(pCombat->GetActions());
            delete pCombat;

            bResult &= ((pDefender->GetDefaultHealth() - (((pAttacker->GetAttack() - pDefender->GetDefense()) < 1)? 1 : pAttacker->GetAttack() - pDefender->GetDefense() + 1)) == pDefender->GetHealth());
            bResult &= ((pAttacker->GetDefaultHealth() - (((pDefender->GetAttack() - pAttacker->GetDefense()) < 1)? 1 : pDefender->GetAttack() - pAttacker->GetDefense() + 1)) == pAttacker->GetHealth());

            delete pAttacker;
            delete pDefender;

            return (bResult);
        }
};

class CTestCombatsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CCombats::CCombats (default constructor)");
        }

        bool Execute() {
            bool bExecute = false;
            CCombats *pCombats = NULL;

            pCombats = new CCombats;
            if (pCombats != NULL) {
                delete pCombats;
                bExecute = true;
            }

            return (bExecute);
        }
};

class CTestCombatsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CCombats::Add / CCombats::Remove");
        }

        bool Execute() {
            bool bResult = false;
            CCombats *pCombats = NULL;
            CCombat *pCombat = NULL;

            pCombats = new CCombats;
            pCombat = new CCombatSimple;

            bResult = pCombats->Add(pCombat);
            bResult &= (pCombats->GetCount() == 1);
            bResult &= (pCombats->Add(pCombat) == false);
            bResult &= (pCombats->GetCount() == 1);

            bResult &= pCombats->Add(new CCombatSimple);
            bResult &= pCombats->Add(new CCombatSimple);
            bResult &= pCombats->Add(new CCombatSimple);
            bResult &= (pCombats->GetCount() == 4);

            pCombat = new CCombatSimple;
            bResult &= (pCombats->Remove(pCombat) == false);
            delete pCombat;

            bResult &= (pCombats->GetCount() == 4);
            pCombats->Purge();
            bResult &= (pCombats->GetCount() == 0);
            delete pCombats;
            return (bResult);
        }
};

class CTestCombatsFind : public ITest {
    public:
        string GetName() const {
            return ("CCombats::Find");
        }

        bool Execute() {
            bool bResult = false;
            CCombats *pCombats = NULL;
            CCombat *pCombat = NULL;

            pCombats = new CCombats;
            pCombats->Add(new CCombatSoldierAgainstSoldier);
            pCombats->Add(new CCombatBattalionAgainstBattalion);
            pCombats->Add(new CCombatSoldierAgainstBattalion);
            bResult = (pCombats->GetCount() == 3);

            pCombat = new CCombatBattalionAgainstSoldier;
            bResult &= (pCombats->Find(pCombat->GetID()) == false);
            bResult &= (pCombats->Add(pCombat));
            bResult &= (pCombats->Find(pCombat->GetID()) != NULL);
            bResult &= (pCombats->GetCount() == 4);

            pCombats->Purge();
            delete pCombats;
            return (bResult);
        }
};

class CTestCombatsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CCombats::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CCombats *pCombats = NULL;
            CCombat *pCombat = NULL;

            pCombats = new CCombats;
            pCombat = new CCombatSoldierAgainstSoldier;
            pCombats->Add(pCombat);
            bResult  = (pCombats->GetAt(0)->GetID() == pCombat->GetID());
            bResult &= (pCombats->GetAt(1) == NULL);

            delete pCombats;
            delete pCombat;
            return (bResult);
        }
};

class CTestCombatsClear : public ITest {
    public:
        string GetName() const {
            return ("CCombats::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CCombats *pCombats = NULL;
            CCombat *pCombat = NULL;

            pCombats = new CCombats;
            pCombat = new CCombatSoldierAgainstSoldier;
            pCombats->Add(pCombat);
            pCombats->Clear();
            bResult = (pCombats->GetCount() == 0);

            delete pCombats;
            delete pCombat;
            return (bResult);
        }
};

class CTestCombatFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CCombatFactory::CCombatFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CCombatFactory *pCombatFactory = NULL;

            pCombatFactory = new CCombatFactory;
            if (pCombatFactory != NULL) {
                bResult = true;
                delete pCombatFactory;
                pCombatFactory = NULL;
            }

            return (bResult);
        }
};

class CTestCombatFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CCombatFactory::Create");
        }

        bool Execute() {
            CCombatFactory *pCombatFactory = NULL;
            CCombat *pCombat = NULL;
            bool bResult = true;

            pCombatFactory = new CCombatFactory;
            pCombat = pCombatFactory->Create(enCOMBATTYPE_NONE);
            bResult = (pCombat == NULL);
            delete pCombat;

            pCombat = pCombatFactory->Create(enCOMBATTYPE_UNKNOWN);
            bResult &= (pCombat->GetType() == enCOMBATTYPE_UNKNOWN);
            delete pCombat;

            pCombat = pCombatFactory->Create(enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER);
            bResult &= (pCombat->GetType() == enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER);
            delete pCombat;

            pCombat = pCombatFactory->Create(enCOMBATTYPE_SOLDIER_AGAINST_BATTALION);
            bResult &= (pCombat->GetType() == enCOMBATTYPE_SOLDIER_AGAINST_BATTALION);
            delete pCombat;

            pCombat = pCombatFactory->Create(enCOMBATTYPE_BATTALION_AGAINST_SOLDIER);
            bResult &= (pCombat->GetType() == enCOMBATTYPE_BATTALION_AGAINST_SOLDIER);
            delete pCombat;

            pCombat = pCombatFactory->Create(enCOMBATTYPE_BATTALION_AGAINST_BATTALION);
            bResult &= (pCombat->GetType() == enCOMBATTYPE_BATTALION_AGAINST_BATTALION);
            delete pCombat;

            delete pCombatFactory;
            pCombatFactory = NULL;
            return (bResult);
        }
};

class CTestCombatManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CCombatManager::CCombatManager (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CCombatManager *pCombatManager = NULL;

            pCombatManager = new CCombatManager;
            bResult = (pCombatManager != NULL);
            delete pCombatManager;
            pCombatManager = NULL;

            return (bResult);
        }
};

class CTestCombatManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CCombatManager::Create");
        }

        bool Execute() {
            bool bResult = false;
            CCombatManager *pCombatManager = NULL;
            CCombat *pCombat = NULL;

            pCombatManager = new CCombatManager;
            pCombat = pCombatManager->Create();
            bResult = (pCombat != NULL);
            bResult &= pCombatManager->Delete(pCombat);

            pCombat = new CCombatSimple;
            bResult &= (pCombatManager->Delete(pCombat) == false);
            delete pCombat;

            pCombat = NULL;
            delete pCombatManager;
            pCombatManager = NULL;

            return (bResult);
        }
};

class CTestCombatSoldierAgainstSoldierToDeath : public ITest {
    public:
        string GetName() const {
            return ("CCombatSoldierAgainstSoldier::Round (to death)");
        }

        bool Execute() {
            CSoldierServices *pSoldierServices = NULL;
            bool bResult = true;
            CCombat *pCombat = NULL;
            CSoldier *pAttacker = NULL;
            CSoldier *pDefender = NULL;

            pAttacker = new CSoldierArcher;
            pDefender = new CSoldierPikeman;

            pCombat = new CCombatSoldierAgainstSoldier;
            pCombat->SetAttacker(pAttacker);
            pCombat->SetDefender(pDefender);
            pCombat->Round();

            bResult &= ((pDefender->GetDefaultHealth() - (((pAttacker->GetAttack() - pDefender->GetDefense()) < 1)? 1 : pAttacker->GetAttack() - pDefender->GetDefense() + 1)) == pDefender->GetHealth());
            bResult &= ((pAttacker->GetDefaultHealth() - (((pDefender->GetAttack() - pAttacker->GetDefense()) < 1)? 1 : pDefender->GetAttack() - pAttacker->GetDefense() + 1)) == pAttacker->GetHealth());

            pCombat->Round();
            bResult &= (pAttacker->GetHealth() == 3);
            pCombat->Round();
            bResult &= (pAttacker->GetHealth() == 1);
            bResult &= (pDefender->GetHealth() == 7);
            pCombat->Round();
            bResult &= (pAttacker->GetHealth() == -1);
            bResult &= (pDefender->GetHealth() == 6);
            pCombat->Round();
            bResult &= (pAttacker->GetHealth() == -1);
            bResult &= (pDefender->GetHealth() == 6);

            pSoldierServices = new CSoldierServices;
            pSoldierServices->Revive(pAttacker);
            delete pSoldierServices;

            pCombat->Round();
            bResult &= (pAttacker->GetHealth() == -1);
            bResult &= (pDefender->GetHealth() == 5);

            if (m_bDump)
                DumpActions(pCombat->GetActions(false));

            delete pCombat;
            delete pAttacker;
            delete pDefender;

            return (bResult);
        }
};

class CTestActionConstructor : public ITest {
    public:
        string GetName() const {
            return ("CAction::CAction (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CAction *pAction = NULL;

            pAction = new CAction;
            if (pAction != NULL) {
                bResult = true;
                delete pAction;
            }

            return (bResult);
        }
};

class CTestActionFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CActionFactory::CActionFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CActionFactory *pActionFactory = NULL;

            pActionFactory = new CActionFactory;
            if (pActionFactory != NULL) {
                bResult = true;
                delete pActionFactory;
            }

            return (bResult);
        }
};

class CTestActionFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CActionFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CAction *pAction = NULL;
            CActionFactory *pActionFactory = NULL;

            pActionFactory = new CActionFactory;

            pAction = pActionFactory->Create(enACTIONTYPE_NONE);
            bResult = (pAction == NULL);

            pAction = pActionFactory->Create(enACTIONTYPE_UNKNOWN);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_WAIT);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_HIGH_ATTACK);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_LOW_ATTACK);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_HIGH_PARRY);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_LOW_PARRY);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_HIGH_BLOCK);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_LOW_BLOCK);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_DAMAGE);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_HEAL);
            bResult &= (pAction != NULL);
            delete pAction;

            pAction = pActionFactory->Create(enACTIONTYPE_REVIVE);
            bResult &= (pAction != NULL);
            delete pAction;

            delete pActionFactory;
            return (bResult);
        }
};

class CTestActionManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CActionManager::CActionManager (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CActionManager *pActionManager = NULL;

            pActionManager = new CActionManager;
            if (pActionManager != NULL) {
                delete pActionManager;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestActionManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CActionManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CActionManager *pActionManager = NULL;
            CAction *pAction = NULL;

            pActionManager = new CActionManager;
            pAction = pActionManager->Create(enACTIONTYPE_NONE);
            bResult = (pAction == NULL);

            pAction = pActionManager->Create(enACTIONTYPE_UNKNOWN);
            bResult &= (pAction->GetType() == enACTIONTYPE_UNKNOWN);

            pAction = pActionManager->Create(enACTIONTYPE_WAIT);
            bResult &= (pAction->GetType() == enACTIONTYPE_WAIT);

            pAction = pActionManager->Create(enACTIONTYPE_HIGH_ATTACK);
            bResult &= (pAction->GetType() == enACTIONTYPE_HIGH_ATTACK);

            pAction = pActionManager->Create(enACTIONTYPE_LOW_ATTACK);
            bResult &= (pAction->GetType() == enACTIONTYPE_LOW_ATTACK);

            pAction = pActionManager->Create(enACTIONTYPE_HIGH_PARRY);
            bResult &= (pAction->GetType() == enACTIONTYPE_HIGH_PARRY);

            pAction = pActionManager->Create(enACTIONTYPE_LOW_PARRY);
            bResult &= (pAction->GetType() == enACTIONTYPE_LOW_PARRY);

            pAction = pActionManager->Create(enACTIONTYPE_HIGH_BLOCK);
            bResult &= (pAction->GetType() == enACTIONTYPE_HIGH_BLOCK);

            pAction = pActionManager->Create(enACTIONTYPE_LOW_BLOCK);
            bResult &= (pAction->GetType() == enACTIONTYPE_LOW_BLOCK);

            pAction = pActionManager->Create(enACTIONTYPE_DAMAGE);
            bResult &= (pAction->GetType() == enACTIONTYPE_DAMAGE);

            pAction = pActionManager->Create(enACTIONTYPE_HEAL);
            bResult &= (pAction->GetType() == enACTIONTYPE_HEAL);

            pAction = pActionManager->Create(enACTIONTYPE_REVIVE);
            bResult &= (pAction->GetType() == enACTIONTYPE_REVIVE);

            delete pActionManager;
            return (bResult);
        }
};

class CTestActionsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CActions::CActions (default constructor)");
        }

        bool Execute() {
            bool bExecute = false;
            CActions *pActions = NULL;

            pActions = new CActions;
            if (pActions != NULL) {
                delete pActions;
                bExecute = true;
            }

            return (bExecute);
        }
};

class CTestActionsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CActions::Add / CActions::Remove");
        }

        bool Execute() {
            bool bResult = false;
            CActions *pActions = NULL;
            CAction *pAction = NULL;

            pActions = new CActions;
            pAction = new CAction;

            bResult = pActions->Add(pAction);
            bResult &= (pActions->GetCount() == 1);
            bResult &= (pActions->Add(pAction) == false);
            bResult &= (pActions->GetCount() == 1);

            bResult &= pActions->Add(new CAction);
            bResult &= pActions->Add(new CAction);
            bResult &= pActions->Add(new CAction);
            bResult &= (pActions->GetCount() == 4);

            pAction = new CAction;
            bResult &= (pActions->Remove(pAction) == false);
            delete pAction;

            bResult &= (pActions->GetCount() == 4);
            pActions->Purge();
            bResult &= (pActions->GetCount() == 0);
            delete pActions;
            return (bResult);
        }
};

class CTestActionsFind : public ITest {
    public:
        string GetName() const {
            return ("CActions::Find");
        }

        bool Execute() {
            bool bResult = false;
            CActions *pActions = NULL;
            CAction *pAction = NULL;

            pActions = new CActions;
            pActions->Add(new CAction);
            pActions->Add(new CAction);
            pActions->Add(new CAction);
            bResult = (pActions->GetCount() == 3);

            pAction = new CAction;
            bResult &= (pActions->Find(pAction->GetID()) == false);
            bResult &= (pActions->Add(pAction));
            bResult &= (pActions->Find(pAction->GetID()) != NULL);
            bResult &= (pActions->GetCount() == 4);

            pActions->Purge();
            delete pActions;
            return (bResult);
        }
};

class CTestActionsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CActions::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CActions *pActions = NULL;
            CAction *pAction = NULL;

            pActions = new CActions;
            pAction = new CAction;
            pActions->Add(pAction);
            bResult  = (pActions->GetAt(0)->GetID() == pAction->GetID());
            bResult &= (pActions->GetAt(1) == NULL);

            delete pActions;
            delete pAction;
            return (bResult);
        }
};

class CTestActionsClear : public ITest {
    public:
        string GetName() const {
            return ("CActions::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CActions *pActions = NULL;
            CAction *pAction = NULL;

            pActions = new CActions;
            pAction = new CAction;
            pActions->Add(pAction);
            pActions->Clear();
            bResult = (pActions->GetCount() == 0);

            delete pActions;
            delete pAction;
            return (bResult);
        }
};

class CTestPositionDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CPosition::CPosition (default constructor)");
        }

        bool Execute() {
            bool bResult = false;

            CPosition *pPosition = new CPosition;
            bResult = CheckAgainstDefaultPositionValues(pPosition);
            delete pPosition;
            pPosition = NULL;

            return (bResult);
        }
};

class CTestPositionFullConstructor : public ITest {
    public:
        string GetName() const {
            return ("CPosition::CPosition (full constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CPosition *pPosition = NULL;

            pPosition = new CPosition(1, 2);
            bResult = (pPosition->GetPositionX() == 1 && pPosition->GetPositionY() == 2);
            delete pPosition;
            pPosition = new CPosition(1, 2, 3);
            bResult &= (pPosition->GetPositionX() == 1 && pPosition->GetPositionY() == 2 && pPosition->GetLevel() == 3);
            delete pPosition;

            return (bResult);
        }
};

class CTestPositionsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CPositions::CPositions (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CPositions *pPositions = NULL;

            pPositions = new CPositions;
            if (pPositions != NULL) {
                delete pPositions;
                pPositions = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestPositionsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CPositions::Add / CPositions::Remove");
        }

        bool Execute() {
            bool bResult = false;
            CPositions *pPositions = NULL;
            CPosition *pPosition = NULL;

            pPositions = new CPositions;
            pPosition = new CPosition;

            bResult = pPositions->Add(pPosition);
            bResult &= (pPositions->GetCount() == 1);
            bResult &= (pPositions->Add(pPosition) == false);
            bResult &= (pPositions->GetCount() == 1);
            pPosition = NULL;

            bResult &= pPositions->Add(new CPosition);
            bResult &= pPositions->Add(new CPosition);
            bResult &= pPositions->Add(new CPosition);
            bResult &= (pPositions->GetCount() == 4);

            pPosition = new CPosition;
            bResult &= (pPositions->Remove(pPosition) == false);
            delete pPosition;
            pPosition = NULL;

            bResult &= (pPositions->GetCount() == 4);
            pPositions->Purge();
            bResult &= (pPositions->GetCount() == 0);
            delete pPositions;
            pPositions = NULL;

            return (bResult);
        }
};

class CTestPositionsFind : public ITest {
    public:
        string GetName() const {
            return ("CPositions::Find");
        }

        bool Execute() {
            bool bResult = false;
            CPositions *pPositions = NULL;
            CPosition *pPosition = NULL;

            pPositions = new CPositions;
            pPositions->Add(new CPosition);
            pPositions->Add(new CPosition);
            pPositions->Add(new CPosition);
            bResult = (pPositions->GetCount() == 3);

            pPosition = new CPosition;
            bResult &= (pPositions->Find(pPosition->GetID()) == false);
            bResult &= (pPositions->Add(pPosition));
            bResult &= (pPositions->Find(pPosition->GetID()) != NULL);
            bResult &= (pPositions->GetCount() == 4);

            pPositions->Purge();
            delete pPositions;
            return (bResult);
        }
};

class CTestPositionsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CPositions::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CPositions *pPositions = NULL;
            CPosition *pPosition = NULL;

            pPositions = new CPositions;
            pPosition = new CPosition;
            pPositions->Add(pPosition);
            bResult  = (pPositions->GetAt(0)->GetID() == pPosition->GetID());
            bResult &= (pPositions->GetAt(1) == NULL);

            delete pPositions;
            delete pPosition;
            return (bResult);
        }
};

class CTestPositionsClear : public ITest {
    public:
        string GetName() const {
            return ("CPositions::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CPositions *pPositions = NULL;
            CPosition *pPosition = NULL;

            pPositions = new CPositions;
            pPosition = new CPosition;
            pPositions->Add(pPosition);
            pPositions->Clear();
            bResult = (pPositions->GetCount() == 0);

            delete pPositions;
            delete pPosition;
            return (bResult);
        }
};

class CTestPositionFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CPositionFactory::CPositionFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CPositionFactory *pPositionFactory = NULL;

            pPositionFactory = new CPositionFactory;
            if (pPositionFactory != NULL) {
                bResult = true;
                delete pPositionFactory;
            }

            return (bResult);
        }
};

class CTestPositionFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CPositionFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CPosition *pPosition = NULL;
            CPositionFactory *pPositionFactory = NULL;

            pPositionFactory = new CPositionFactory;

            pPosition = pPositionFactory->Create();
            bResult = (pPosition != NULL);
            bResult &= CheckAgainstDefaultPositionValues(pPosition);
            delete pPosition;
            pPosition = NULL;

            delete pPositionFactory;
            pPositionFactory = NULL;
            return (bResult);
        }
};

class CTestPositionManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CPositionManager::CPositionManager (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CPositionManager *pPositionManager = NULL;

            pPositionManager = new CPositionManager;
            if (pPositionManager != NULL) {
                delete pPositionManager;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestPositionManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CPositionManager::Create (all)");
        }

        bool Execute() {
            CSoldier *pSoldier = NULL;
            bool bResult = false;
            CPositionManager *pPositionManager = NULL;
            CPosition *pPosition = NULL;

            pPositionManager = new CPositionManager;
            pPosition = pPositionManager->Create();
            bResult = (CheckAgainstDefaultPositionValues(pPosition));
            pPositionManager->Delete(pPosition);

            pPosition = pPositionManager->Create(1);
            bResult &= (pPosition->GetPositionX() == 1);
            bResult &= (pPosition->GetPositionY() == pPosition->GetDefaultPositionY());
            bResult &= (pPosition->GetLevel() == pPosition->GetDefaultLevel());
            bResult &= (pPosition->GetObject() == NULL);
            pPositionManager->Delete(pPosition);

            pPosition = pPositionManager->Create(1, 2);
            bResult &= (pPosition->GetPositionX() == 1);
            bResult &= (pPosition->GetPositionY() == 2);
            bResult &= (pPosition->GetLevel() == pPosition->GetDefaultLevel());
            bResult &= (pPosition->GetObject() == NULL);
            pPositionManager->Delete(pPosition);

            pPosition = pPositionManager->Create(1, 2, 3);
            bResult &= (pPosition->GetPositionX() == 1);
            bResult &= (pPosition->GetPositionY() == 2);
            bResult &= (pPosition->GetLevel() == 3);
            bResult &= (pPosition->GetObject() == NULL);
            pPositionManager->Delete(pPosition);

            pSoldier = new CSoldier;
            pPosition = pPositionManager->Create(1, 2, 3, pSoldier);
            bResult &= (pPosition->GetPositionX() == 1);
            bResult &= (pPosition->GetPositionY() == 2);
            bResult &= (pPosition->GetLevel() == 3);
            bResult &= (pPosition->GetObject()->GetID() == pSoldier->GetID());
            delete pSoldier;
            pPositionManager->Delete(pPosition);

            delete pPositionManager;
            pPositionManager = NULL;
            return (bResult);
        }
};

class CTestMatrixDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMatrix::CMatrix (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CMatrix<int> *pMatrix = NULL;

            pMatrix = new CMatrix<int>;
            if (pMatrix != NULL) {
                bResult = ((pMatrix->GetWidth() == 0) && (pMatrix->GetHeight() == 0));
                delete pMatrix;
                pMatrix = NULL;
            }

            return (bResult);
        }
};

class CTestMatrixFullConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMatrix::CMatrix (full constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CMatrix<int> *pMatrix = NULL;

            pMatrix = new CMatrix<int>(10, 15);
            if (pMatrix != NULL) {
                bResult = ((pMatrix->GetHeight() == 15) && (pMatrix->GetWidth() == 10));
                delete pMatrix;
                pMatrix = NULL;
            }

            return (bResult);
        }
};

class CTestMatrixPointer : public ITest {
    public:
        string GetName() const {
            return ("CMatrix::Create (pointer)");
        }

        bool Execute() {
            bool bResult = false;
            CMatrix<int *> pMatrix(10, 10);

            pMatrix[2][2] = new int;
            *pMatrix[2][2] = 5;
            bResult = (*pMatrix[2][2] == 5);
            delete pMatrix[2][2];

            return (bResult);
        }
};

class CTestMatrixAssign : public ITest {
    public:
        string GetName() const {
            return ("CMatrix::operator[]");
        }

        bool Execute() {
            bool bResult = false;
            long lPositionX = 0;
            long lPositionY = 0;
            CMatrix<int> *pMatrix = NULL;

            //  0  1  2  3  4
            //  5  6  7  8  9
            // 10 11 12 13 14
            // 15 16 17 18 19
            pMatrix = new CMatrix<int>(5, 4);
            for (lPositionY = 0; lPositionY < pMatrix->GetHeight(); lPositionY++)
                for (lPositionX = 0; lPositionX < pMatrix->GetWidth(); lPositionX++)
                    (*pMatrix)[lPositionY][lPositionX] = lPositionY * pMatrix->GetWidth() + lPositionX;

            bResult = ((*pMatrix)[3][3] == 18) && ((*pMatrix)[2][2] == 12) && ((*pMatrix)[3][1] == 16);
            delete pMatrix;
            pMatrix = NULL;

            return (bResult);
        }
};

class CTestTerrainDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CTerrain::CTerrain (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CTerrain *pTerrain = NULL;

            pTerrain = new CTerrain;
            if (pTerrain != NULL) {
                delete pTerrain;
                pTerrain = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestTerrainFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CTerrainFactory::CTerrainFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CTerrainFactory *pTerrainFactory = NULL;

            pTerrainFactory = new CTerrainFactory;
            if (pTerrainFactory != NULL) {
                delete pTerrainFactory;
                pTerrainFactory = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestTerrainFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CTerrainFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CTerrainFactory *pTerrainFactory = NULL;
            CTerrain *pTerrain = NULL;

            pTerrainFactory = new CTerrainFactory;
            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_NONE);
            bResult = (pTerrain == NULL);

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_UNKNOWN);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_UNKNOWN);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_GRASS);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_GRASS);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_ROCK);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_ROCK);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_WATER);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_WATER);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_SAND);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_SAND);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_WOOD);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_WOOD);
            delete pTerrain;

            pTerrain = pTerrainFactory->Create(enTERRAINTYPE_PATH);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_PATH);
            delete pTerrain;

            delete pTerrainFactory;
            return (bResult);
        }
};

class CTestTerrainManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CTerrainManager::CTerrainManager");
        }

        bool Execute() {
            bool bResult = false;
            CTerrainManager *pTerrainManager = NULL;

            pTerrainManager = new CTerrainManager;
            if (pTerrainManager != NULL) {
                delete pTerrainManager;
                pTerrainManager = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestTerrainManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CTerrainManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CTerrainManager *pTerrainManager = NULL;
            CTerrain *pTerrain = NULL;

            pTerrainManager = new CTerrainManager;
            pTerrain = pTerrainManager->Create(enTERRAINTYPE_NONE);
            bResult = (pTerrain == NULL);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_UNKNOWN);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_UNKNOWN);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_GRASS);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_GRASS);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_ROCK);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_ROCK);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_WATER);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_WATER);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_SAND);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_SAND);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_WOOD);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_WOOD);

            pTerrain = pTerrainManager->Create(enTERRAINTYPE_PATH);
            bResult &= (pTerrain->GetType() == enTERRAINTYPE_PATH);

            delete pTerrainManager;
            return (bResult);
        }
};

class CTestMapDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMap::CMap (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CMap *pMap = NULL;

            pMap = new CMap;
            if (pMap != NULL) {
                delete pMap;
                pMap = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestMapCreate : public ITest {
    public:
        string GetName() const {
            return ("CMap::Create");
        }

        bool Execute() {
            bool bResult = false;
            CMap *pMap = NULL;

            pMap = new CMap;
            bResult = pMap->Create(10, 10);
            delete pMap;
            pMap = NULL;

            return (bResult);
        }
};

class CTestMapGetAt : public ITest {
    public:
        string GetName() const {
            return ("CMap::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CMap *pMap = NULL;

            pMap = new CMap;
            bResult = pMap->Create(10, 10);
            bResult &= (pMap->GetAt(2, 2) == NULL);
            (*pMap)[2][2] = new CTerrain;
            bResult &= (pMap->GetAt(2, 2)->GetType() == enTERRAINTYPE_UNKNOWN);
            delete (*pMap)[2][2];
            delete pMap;
            pMap = NULL;

            return (bResult);
        }
};

class CTestMapSetAt : public ITest {
    public:
        string GetName() const {
            return ("CMap::SetAt");
        }

        bool Execute() {
            bool bResult = false;
            CMap pMap(64, 64);
            long lPositionX = 0;
            long lPositionY = 0;

            pMap.SetAt(0, 0, new CTerrainWater);
            pMap.SetAt(9, 9, new CTerrainWater);
            pMap.SetAt(0, 9, new CTerrainWood);
            pMap.SetAt(9, 0, new CTerrainPath);
            for (lPositionY = 0; lPositionY < pMap.GetHeight(); lPositionY++)
                for (lPositionX = 0; lPositionX < pMap.GetWidth(); lPositionX++)
                    if (pMap.GetAt(lPositionX, lPositionY) == NULL)
                        pMap.SetAt(lPositionX, lPositionY, new CTerrain);

            if (m_bDump)
                DumpMap(&pMap);

            bResult = (pMap.GetAt(0, 0)->GetType() == enTERRAINTYPE_WATER);
            bResult &= (pMap.GetAt(9, 9)->GetType() == enTERRAINTYPE_WATER);
            bResult &= (pMap.GetAt(0, 9)->GetType() == enTERRAINTYPE_WOOD);
            bResult &= (pMap.GetAt(9, 0)->GetType() == enTERRAINTYPE_PATH);

            pMap.Purge();
            return (bResult);
        }
};

class CTestMapsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMaps::CMaps");
        }

        bool Execute() {
            bool bResult = false;
            CMaps *pMaps = NULL;

            pMaps = new CMaps;
            if (pMaps != NULL) {
                delete pMaps;
                pMaps = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestMapsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CMaps::Add / CMaps::Remove / CMaps::GetCount");
        }

        bool Execute() {
            bool bResult = false;
            CMaps *pMaps = NULL;
            CMap *pMap = NULL;

            pMaps = new CMaps;
            pMap = new CMap;
            bResult = pMaps->GetCount() == 0;
            bResult &= (pMaps->Remove(pMap) == false);
            bResult &= pMaps->GetCount() == 0;
            bResult &= (pMaps->Add(pMap) == true);
            bResult &= pMaps->GetCount() == 1;
            bResult &= (pMaps->Add(pMap) == false);
            bResult &= pMaps->GetCount() == 1;
            bResult &= (pMaps->Remove(pMap) == true);
            bResult &= pMaps->GetCount() == 0;
            bResult &= (pMaps->Remove(pMap) == false);
            bResult &= pMaps->GetCount() == 0;

            delete pMap;
            pMap = NULL;
            delete pMaps;

            return (bResult);
        }
};

class CTestMapsFind : public ITest {
    public:
        string GetName() const {
            return ("CMaps::Find");
        }

        bool Execute() {
            bool bResult = false;
            CMaps *pMaps = NULL;
            CMap *pMap = NULL;

            pMaps = new CMaps;
            pMaps->Add(new CMap);
            pMaps->Add(new CMap);
            pMaps->Add(new CMap);
            bResult = (pMaps->GetCount() == 3);

            pMap = new CMap;
            bResult &= (pMaps->Find(pMap->GetID()) == false);
            bResult &= (pMaps->Add(pMap));
            bResult &= (pMaps->Find(pMap->GetID()) != NULL);
            bResult &= (pMaps->GetCount() == 4);

            pMaps->Purge();
            delete pMaps;
            return (bResult);
        }
};

class CTestMapsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CMaps::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CMaps *pMaps = NULL;
            CMap *pMap = NULL;

            pMaps = new CMaps;
            pMap = new CMap;
            pMaps->Add(pMap);
            bResult  = (pMaps->GetAt(0)->GetID() == pMap->GetID());
            bResult &= (pMaps->GetAt(1) == NULL);

            delete pMaps;
            delete pMap;
            return (bResult);
        }
};

class CTestMapsClear : public ITest {
    public:
        string GetName() const {
            return ("CMaps::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CMaps *pMaps = NULL;
            CMap *pMap = NULL;

            pMaps = new CMaps;
            pMap = new CMap;
            pMaps->Add(pMap);
            pMaps->Clear();
            bResult = (pMaps->GetCount() == 0);

            delete pMaps;
            delete pMap;
            return (bResult);
        }
};

class CTestMapFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMapFactory::CMapFactory");
        }

        bool Execute() {
            bool bResult = false;
            CMapFactory *pMapFactory = NULL;

            pMapFactory = new CMapFactory;
            if (pMapFactory != NULL) {
                delete pMapFactory;
                pMapFactory = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestMapFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CMapFactory::Create");
        }

        bool Execute() {
            bool bResult = false;
            CMapFactory *pMapFactory = NULL;
            CMap *pMap = NULL;

            pMapFactory = new CMapFactory;
            pMap = pMapFactory->Create();
            delete pMapFactory;

            if (pMap != NULL) {
                delete pMap;
                pMap = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestMapManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CMapManager::CMapManager");
        }

        bool Execute() {
            bool bResult = false;
            CMapManager *pMapManager = NULL;

            pMapManager = new CMapManager;
            if (pMapManager != NULL) {
                delete pMapManager;
                pMapManager = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestMapManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CMapManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CMapManager *pMapManager = NULL;
            CMap *pMap = NULL;

            pMapManager = new CMapManager;
            pMap = pMapManager->Create(10, 10);
            bResult = (pMap != NULL);
            delete pMapManager;

            return (bResult);
        }
};

class CTestMapServicesAddRemovePosition : public ITest {
    public:
        string GetName() const {
            return ("CMapServices::AddPosition / CMapServices::RemovePosition");
        }

        bool Execute() {
            bool bResult = false;
            CMapServices *pMapServices = NULL;
            CMap *pMap = NULL;
            CPosition *pPosition = NULL;
            CSoldier *pSoldier = NULL;

            pSoldier = new CSoldier;
            pPosition = new CPosition;
            pPosition->SetObject(pSoldier);
            pMap = new CMap;
            bResult = (pMap->GetPositions()->GetCount() == 0);
            bResult &= pMapServices->AddPosition(pMap, pPosition);
            bResult &= (pMap->GetPositions()->GetCount() == 1);
            bResult &= pMapServices->RemovePosition(pMap, pPosition);
            bResult &= (pMap->GetPositions()->GetCount() == 0);
            bResult &= (pMapServices->RemovePosition(pMap, pPosition) == false);

            delete pSoldier;
            delete pPosition;
            delete pMap;
            return (bResult);
        }
};

class CTestMapServicesFindPosition : public ITest {
    public:
        string GetName() const {
            return ("CMapServices::FindPosition");
        }

        bool Execute() {
            bool bResult = false;
            CMapServices *pMapServices = NULL;
            CPosition *pPosition = NULL;
            CMap *pMap = NULL;

            pPosition = new CPosition;
            pPosition->SetPosition(10, 9);
            pMap = new CMap(10, 10);
            pMapServices = new CMapServices;
            pMapServices->AddPosition(pMap, pPosition);
            bResult = (pMapServices->FindPosition(pMap, pPosition->GetID()) != NULL);
            bResult &= (pMapServices->FindPosition(pMap, pPosition->GetID() + 1) == NULL);

            delete pMap;
            delete pPosition;
            delete pMapServices;

            return (bResult);
        }
};

class CTestMapServicesMoveEastWest : public ITest {
    public:
        string GetName() const {
            return ("CMapServices::MoveEast / CMapServices::MoveWest");
        }

        bool Execute() {
            bool bResult = false;
            CPosition *pPosition = NULL;
            CMapServices *pMapServices = NULL;
            CMap *pMap = NULL;

            pPosition = new CPosition(10, 10);
            pMapServices = new CMapServices;
            pMap = new CMap(100, 100);
            pMapServices->AddPosition(pMap, pPosition);
            bResult = pMapServices->MoveWest(pMap, pPosition);
            bResult &= (pPosition->GetPositionX() == 9 && pPosition->GetPositionY() == 10);
            bResult &= pMapServices->MoveEast(pMap, pPosition);
            bResult &= (pPosition->GetPositionX() == 10 && pPosition->GetPositionY() == 10);

            pPosition->SetPosition(99, 0);
            bResult &= (pMapServices->MoveEast(pMap, pPosition) == false);
            bResult &= (pPosition->GetPositionX() == 99);

            pPosition->SetPosition(0, 0);
            bResult &= (pMapServices->MoveWest(pMap, pPosition) == false);
            bResult &= (pPosition->GetPositionX() == 0);

            delete pMap;
            pMap = NULL;
            delete pMapServices;
            pMapServices = NULL;
            delete pPosition;
            pPosition = NULL;

            return (bResult);
        }
};

class CTestMapServicesMoveNorthSouth : public ITest {
    public:
        string GetName() const {
            return ("CMapServices::MoveNorth / CMapServices::MoveSouth");
        }

        bool Execute() {
            bool bResult = false;
            CPosition *pPosition = NULL;
            CMapServices *pMapServices = NULL;
            CMap *pMap = NULL;

            pPosition = new CPosition(10, 10);
            pMapServices = new CMapServices;
            pMap = new CMap(100, 100);
            pMapServices->AddPosition(pMap, pPosition);
            bResult = pMapServices->MoveNorth(pMap, pPosition);
            bResult &= (pPosition->GetPositionX() == 10 && pPosition->GetPositionY() == 9);
            bResult &= pMapServices->MoveSouth(pMap, pPosition);
            bResult &= (pPosition->GetPositionX() == 10 && pPosition->GetPositionY() == 10);

            pPosition->SetPosition(0, 0);
            bResult &= (pMapServices->MoveNorth(pMap, pPosition) == false);
            bResult &= (pPosition->GetPositionY() == 0);

            pPosition->SetPosition(0, 99);
            bResult &= (pMapServices->MoveSouth(pMap, pPosition) == false);
            bResult &= (pPosition->GetPositionY() == 99);

            delete pMap;
            pMap = NULL;
            delete pMapServices;
            pMapServices = NULL;
            delete pPosition;
            pPosition = NULL;

            return (bResult);
        }
};

class CTestShopDefaultConstructor : public ITest {
    public:
        string GetName() const {
            return ("CShop::CShop (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CShop *pShop = NULL;

            pShop = new CShop;
            if (pShop != NULL) {
                delete pShop;
                pShop = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestShopsConstructor : public ITest {
    public:
        string GetName() const {
            return ("CShops::CShops (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CShops *pShops = NULL;

            pShops = new CShops;
            if (pShops != NULL) {
                delete pShops;
                pShops = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestShopsAddRemove : public ITest {
    public:
        string GetName() const {
            return ("CShops::Add / CShops::Remove / CShops::GetCount");
        }

        bool Execute() {
            bool bResult = false;
            CShops *pShops = NULL;
            CShop *pShop = NULL;

            pShops = new CShops;
            pShop = new CShop;

            bResult = pShops->Add(pShop);
            bResult &= (pShops->GetCount() == 1);
            bResult &= (pShops->Add(pShop) == false);
            bResult &= (pShops->GetCount() == 1);
            pShop = NULL;

            bResult &= pShops->Add(new CShop);
            bResult &= pShops->Add(new CShop);
            bResult &= pShops->Add(new CShop);
            bResult &= (pShops->GetCount() == 4);

            pShop = new CShop;
            bResult &= (pShops->Remove(pShop) == false);
            delete pShop;
            pShop = NULL;

            bResult &= (pShops->GetCount() == 4);
            pShops->Purge();
            bResult &= (pShops->GetCount() == 0);
            delete pShops;
            pShops = NULL;

            return (bResult);
        }
};

class CTestShopsFind : public ITest {
    public:
        string GetName() const {
            return ("CShops::Find");
        }

        bool Execute() {
            bool bResult = false;
            CShops *pShops = NULL;
            CShop *pShop = NULL;

            pShops = new CShops;
            pShops->Add(new CShop);
            pShops->Add(new CShop);
            pShops->Add(new CShop);
            bResult = (pShops->GetCount() == 3);

            pShop = new CShop;
            bResult &= (pShops->Find(pShop->GetID()) == false);
            bResult &= (pShops->Add(pShop));
            bResult &= (pShops->Find(pShop->GetID()) != NULL);
            bResult &= (pShops->GetCount() == 4);

            pShops->Purge();
            delete pShops;
            return (bResult);
        }
};

class CTestShopsGetAt : public ITest {
    public:
        string GetName() const {
            return ("CShops::GetAt");
        }

        bool Execute() {
            bool bResult = false;
            CShops *pShops = NULL;
            CShop *pShop = NULL;

            pShops = new CShops;
            pShop = new CShop;
            pShops->Add(pShop);
            bResult  = (pShops->GetAt(0)->GetID() == pShop->GetID());
            bResult &= (pShops->GetAt(1) == NULL);

            delete pShops;
            delete pShop;
            return (bResult);
        }
};

class CTestShopsClear : public ITest {
    public:
        string GetName() const {
            return ("CShops::Clear");
        }

        bool Execute() {
            bool bResult = false;
            CShops *pShops = NULL;
            CShop *pShop = NULL;

            pShops = new CShops;
            pShop = new CShop;
            pShops->Add(pShop);
            pShops->Clear();
            bResult = (pShops->GetCount() == 0);

            delete pShops;
            delete pShop;
            return (bResult);
        }
};

class CTestShopFactoryConstructor : public ITest {
    public:
        string GetName() const {
            return ("CShopFactory::CShopFactory (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CShopFactory *pShopFactory = NULL;

            pShopFactory = new CShopFactory;
            if (pShopFactory != NULL) {
                delete pShopFactory;
                pShopFactory = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestShopFactoryCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CShopFactory::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CShopFactory *pShopFactory = NULL;
            CShop *pShop = NULL;

            pShopFactory = new CShopFactory;
            pShop = pShopFactory->Create();
            bResult = (pShop != NULL);

            delete pShopFactory;
            delete pShop;
            return (bResult);
        }
};

class CTestShopManagerConstructor : public ITest {
    public:
        string GetName() const {
            return ("CShopManager::CShopManager (default constructor)");
        }

        bool Execute() {
            bool bResult = false;
            CShopManager *pShopManager = NULL;

            pShopManager = new CShopManager;
            if (pShopManager != NULL) {
                delete pShopManager;
                pShopManager = NULL;
                bResult = true;
            }

            return (bResult);
        }
};

class CTestShopManagerCreateAll : public ITest {
    public:
        string GetName() const {
            return ("CShopManager::Create (all)");
        }

        bool Execute() {
            bool bResult = false;
            CShopManager *pShopManager = NULL;
            CShop *pShop = NULL;

            pShopManager = new CShopManager;
            pShop = pShopManager->Create();
            bResult = (pShop != NULL);
            delete pShopManager;

            return (bResult);
        }
};

int main(int argc, char **argv) {
    vector<ITest *> pTestVector;
    vector<ITest *>::iterator pIterator;
    ITest *pTest = NULL;

    if (argc > 1) {
        string szArgv(argv[1]);

        if (szArgv == "--dump")
            m_bDump = true;
    }

    pTestVector.push_back(new CTestObjectID);
    pTestVector.push_back(new CTestWeaponDefaultConstructor);
    pTestVector.push_back(new CTestWeaponFullConstructor);
    pTestVector.push_back(new CTestWeaponSetGet);
    pTestVector.push_back(new CTestWeaponsConstructor);
    pTestVector.push_back(new CTestWeaponsAddRemove);
    pTestVector.push_back(new CTestWeaponsFind);
    pTestVector.push_back(new CTestWeaponsGetAt);
    pTestVector.push_back(new CTestWeaponsClear);
    pTestVector.push_back(new CTestWeaponFactoryConstructor);
    pTestVector.push_back(new CTestWeaponFactoryCreateAll);
    pTestVector.push_back(new CTestWeaponManagerConstructor);
    pTestVector.push_back(new CTestWeaponManagerCreateAll);
    pTestVector.push_back(new CTestArmourDefaultConstructor);
    pTestVector.push_back(new CTestArmourFullConstructor);
    pTestVector.push_back(new CTestArmourSetGet);
    pTestVector.push_back(new CTestArmoursConstructor);
    pTestVector.push_back(new CTestArmoursAddRemove);
    pTestVector.push_back(new CTestArmoursFind);
    pTestVector.push_back(new CTestArmoursGetAt);
    pTestVector.push_back(new CTestArmoursClear);
    pTestVector.push_back(new CTestArmourFactoryConstructor);
    pTestVector.push_back(new CTestArmourFactoryCreateAll);
    pTestVector.push_back(new CTestArmourManagerConstructor);
    pTestVector.push_back(new CTestArmourManagerCreateAll);
    pTestVector.push_back(new CTestSoldierDefaultConstructor);
    pTestVector.push_back(new CTestSoldierFullConstructor);
    pTestVector.push_back(new CTestSoldiersConstructor);
    pTestVector.push_back(new CTestSoldiersAddRemove);
    pTestVector.push_back(new CTestSoldiersFind);
    pTestVector.push_back(new CTestSoldiersGetAt);
    pTestVector.push_back(new CTestSoldiersClear);
    pTestVector.push_back(new CTestSoldierFactoryConstructor);
    pTestVector.push_back(new CTestSoldierFactoryCreateAll);
    pTestVector.push_back(new CTestSoldierManagerCreate);
    pTestVector.push_back(new CTestSoldierManagerCreateAll);
    pTestVector.push_back(new CTestSoldierServicesConstructor);
    pTestVector.push_back(new CTestSoldierServicesExperience);
    pTestVector.push_back(new CTestSoldierServicesHeal);
    pTestVector.push_back(new CTestSoldierServicesRevive);
    pTestVector.push_back(new CTestSoldierServicesSelect);
    pTestVector.push_back(new CTestSoldierServicesEquipUnequipArmour);
    pTestVector.push_back(new CTestSoldierServicesEquipUnequipWeapon);
    pTestVector.push_back(new CTestSoldierServicesCanHeal);
    pTestVector.push_back(new CTestBattalionConstructor);
    pTestVector.push_back(new CTestBattalionAddRemove);
    pTestVector.push_back(new CTestBattalionAttackDefense);
    pTestVector.push_back(new CTestBattalionsConstructor);
    pTestVector.push_back(new CTestBattalionsAddRemove);
    pTestVector.push_back(new CTestBattalionsFind);
    pTestVector.push_back(new CTestBattalionsGetAt);
    pTestVector.push_back(new CTestBattalionsClear);
    pTestVector.push_back(new CTestCombatSoldierAgainstSoldier);
    pTestVector.push_back(new CTestCombatSoldierAgainstBattalion);
    pTestVector.push_back(new CTestCombatBattalionAgainstSoldier);
    pTestVector.push_back(new CTestCombatBattalionAgainstBattalion);
    pTestVector.push_back(new CTestCombatBattalionAgainstBattalion2);
    pTestVector.push_back(new CTestCombatBattalionAgainstBattalion3);
    pTestVector.push_back(new CTestCombatSoldierAgainstSoldierToDeath);
    pTestVector.push_back(new CTestCombatsConstructor);
    pTestVector.push_back(new CTestCombatsAddRemove);
    pTestVector.push_back(new CTestCombatsFind);
    pTestVector.push_back(new CTestCombatsGetAt);
    pTestVector.push_back(new CTestCombatsClear);
    pTestVector.push_back(new CTestCombatFactoryConstructor);
    pTestVector.push_back(new CTestCombatFactoryCreateAll);
    pTestVector.push_back(new CTestCombatManagerConstructor);
    pTestVector.push_back(new CTestCombatManagerCreateAll);
    pTestVector.push_back(new CTestActionConstructor);
    pTestVector.push_back(new CTestActionsConstructor);
    pTestVector.push_back(new CTestActionsAddRemove);
    pTestVector.push_back(new CTestActionsFind);
    pTestVector.push_back(new CTestActionsGetAt);
    pTestVector.push_back(new CTestActionsClear);
    pTestVector.push_back(new CTestActionFactoryConstructor);
    pTestVector.push_back(new CTestActionFactoryCreateAll);
    pTestVector.push_back(new CTestActionManagerConstructor);
    pTestVector.push_back(new CTestActionManagerCreateAll);
    pTestVector.push_back(new CTestPositionDefaultConstructor);
    pTestVector.push_back(new CTestPositionFullConstructor);
    pTestVector.push_back(new CTestPositionsConstructor);
    pTestVector.push_back(new CTestPositionsAddRemove);
    pTestVector.push_back(new CTestPositionsFind);
    pTestVector.push_back(new CTestPositionsGetAt);
    pTestVector.push_back(new CTestPositionsClear);
    pTestVector.push_back(new CTestPositionFactoryConstructor);
    pTestVector.push_back(new CTestPositionFactoryCreateAll);
    pTestVector.push_back(new CTestPositionManagerConstructor);
    pTestVector.push_back(new CTestPositionManagerCreateAll);
    pTestVector.push_back(new CTestPositionServicesWithinRange);
    pTestVector.push_back(new CTestMatrixDefaultConstructor);
    pTestVector.push_back(new CTestMatrixFullConstructor);
    pTestVector.push_back(new CTestMatrixPointer);
    pTestVector.push_back(new CTestMatrixAssign);
    pTestVector.push_back(new CTestTerrainDefaultConstructor);
    pTestVector.push_back(new CTestTerrainFactoryConstructor);
    pTestVector.push_back(new CTestTerrainFactoryCreateAll);
    pTestVector.push_back(new CTestTerrainManagerConstructor);
    pTestVector.push_back(new CTestTerrainManagerCreateAll);
    pTestVector.push_back(new CTestMapDefaultConstructor);
    pTestVector.push_back(new CTestMapCreate);
    pTestVector.push_back(new CTestMapGetAt);
    pTestVector.push_back(new CTestMapSetAt);
    pTestVector.push_back(new CTestMapsConstructor);
    pTestVector.push_back(new CTestMapsAddRemove);
    pTestVector.push_back(new CTestMapsFind);
    pTestVector.push_back(new CTestMapsGetAt);
    pTestVector.push_back(new CTestMapsClear);
    pTestVector.push_back(new CTestMapFactoryConstructor);
    pTestVector.push_back(new CTestMapFactoryCreateAll);
    pTestVector.push_back(new CTestMapManagerConstructor);
    pTestVector.push_back(new CTestMapManagerCreateAll);
    pTestVector.push_back(new CTestMapServicesAddRemovePosition);
    pTestVector.push_back(new CTestMapServicesFindPosition);
    pTestVector.push_back(new CTestMapServicesMoveEastWest);
    pTestVector.push_back(new CTestMapServicesMoveNorthSouth);
    pTestVector.push_back(new CTestShopDefaultConstructor);
    pTestVector.push_back(new CTestShopsConstructor);
    pTestVector.push_back(new CTestShopsAddRemove);
    pTestVector.push_back(new CTestShopsFind);
    pTestVector.push_back(new CTestShopsGetAt);
    pTestVector.push_back(new CTestShopsClear);
    pTestVector.push_back(new CTestShopFactoryConstructor);
    pTestVector.push_back(new CTestShopFactoryCreateAll);
    pTestVector.push_back(new CTestShopManagerConstructor);
    pTestVector.push_back(new CTestShopManagerCreateAll);

    for (pIterator = pTestVector.begin(); pIterator != pTestVector.end(); ++pIterator) {
        pTest = (*pIterator);

        cout << setw(3) << setiosflags(ios::right) << pTest->GetID() << " " << resetiosflags(ios::right);
        cout << setw(65)<< setiosflags(ios::left) << pTest->GetName() << ": " <<(pTest->Execute()? "\033[32m[true]\033[0m" : "\033[31m[false]\033[0m") << endl;
        delete pTest;
    }

    pTestVector.clear();
    return (0);
}

// vim:nowrap
