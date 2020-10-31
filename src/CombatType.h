#ifndef _COMBATTYPE_H_INCLUDED
#define _COMBATTYPE_H_INCLUDED

typedef enum enCombatType {
    enCOMBATTYPE_NONE = 0,
    enCOMBATTYPE_UNKNOWN = 1,
    enCOMBATTYPE_SOLDIER_AGAINST_SOLDIER = 2,
    enCOMBATTYPE_SOLDIER_AGAINST_BATTALION = 3,
    enCOMBATTYPE_BATTALION_AGAINST_SOLDIER = 4,
    enCOMBATTYPE_BATTALION_AGAINST_BATTALION = 5
} enCombatType;

#endif // _COMBATTYPE_H_INCLUDED
