#include "GameItemFactory.h" 
#include "GameItem.h"
#include "../Configuration.h"
#include "../Constants.h"
#include <iostream>

GameItemFactory::GameItemFactory(){}

GameItem GameItemFactory::getBareHands(){
    Configuration& config = Configuration::getInstance();
    GameItem bareHands = getItem("bare_hands", HANDS_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    int shieldSlot = config.getValue("inv_shield_slot");
    bareHands.addValidSlot(weaponSlot);
    bareHands.addValidSlot(shieldSlot);
    return bareHands;
}

GameItem GameItemFactory::getNoArmor(){
    Configuration& config = Configuration::getInstance();
    GameItem noArmor = getItem("no_armor", NO_ARMOR_ID);
    int armorSlot = config.getValue("inv_armor_slot");
    noArmor.addValidSlot(armorSlot);
    return noArmor;
}

GameItem GameItemFactory::getItem(std::string name, int id){
    Configuration& config = Configuration::getInstance();
    int damageMin = config.getValue("damage_min_" + name);
    int damageMax = config.getValue("damage_max_" + name);
    int defenseMin = config.getValue("defense_min_" + name);
    int defenseMax = config.getValue("defense_max_" + name);
    int range = config.getValue("range_" + name);
    int manaNeeded = config.getValue("mana_req_" + name);
    return std::move(GameItem(name, id, damageMin, damageMax, 
                    defenseMin, defenseMax, range, manaNeeded));
}

GameItem GameItemFactory::getSword(){
    Configuration& config = Configuration::getInstance();
    GameItem sword = getItem("sword", SWORD_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    sword.addValidSlot(weaponSlot);
    return sword;
}

GameItem GameItemFactory::getHammer(){
    Configuration& config = Configuration::getInstance();
    GameItem hammer = getItem("hammer", HAMMER_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    hammer.addValidSlot(weaponSlot);
    return hammer;
}

GameItem GameItemFactory::getAxe(){
    Configuration& config = Configuration::getInstance();
    GameItem axe = getItem("axe", AXE_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    axe.addValidSlot(weaponSlot);
    return axe;
}

GameItem GameItemFactory::getIceStaff(){
    Configuration& config = Configuration::getInstance();
    GameItem iceStaff = getItem("ice_staff", ICE_STAFF_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    iceStaff.addValidSlot(weaponSlot);
    return iceStaff;
}

GameItem GameItemFactory::getElficFlute(){
    Configuration& config = Configuration::getInstance();
    GameItem elficFlute = getItem("ice_staff", ELFIC_FLUTE_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    elficFlute.addValidSlot(weaponSlot);
    return elficFlute;
}

GameItem GameItemFactory::getKnotStaff(){
    Configuration& config = Configuration::getInstance();
    GameItem knotStaff = getItem("knot_staff", KNOT_STAFF_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    knotStaff.addValidSlot(weaponSlot);
    return knotStaff;
}

GameItem GameItemFactory::getCrimpStaff(){
    Configuration& config = Configuration::getInstance();
    GameItem crimpStaff = getItem("crimp_staff", CRIMP_STAFF_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    crimpStaff.addValidSlot(weaponSlot);
    return crimpStaff;
}

GameItem GameItemFactory::getSimpleBow(){
    Configuration& config = Configuration::getInstance();
    GameItem simpleBow = getItem("simple_bow", SIMPLE_BOW_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    simpleBow.addValidSlot(weaponSlot);
    return simpleBow;
}

GameItem GameItemFactory::getCompoundBow(){
    Configuration& config = Configuration::getInstance();
    GameItem compoundBow = getItem("compound_bow", COMPOUND_BOW_ID);
    int weaponSlot = config.getValue("inv_weapon_slot");
    compoundBow.addValidSlot(weaponSlot);
    return compoundBow;
}

GameItem GameItemFactory::getLeatherArmor(){
    Configuration& config = Configuration::getInstance();
    GameItem leatherArmor = getItem("leather_armor", LEATHER_ARMOR_ID);
    int armorSlot = config.getValue("inv_armor_slot");
    leatherArmor.addValidSlot(armorSlot);
    return leatherArmor;
}

GameItem GameItemFactory::getPlateArmor(){
    Configuration& config = Configuration::getInstance();
    GameItem plateArmor = getItem("plate_armor", PLATE_ARMOR_ID);
    int armorSlot = config.getValue("inv_armor_slot");
    plateArmor.addValidSlot(armorSlot);
    return plateArmor;
}

GameItem GameItemFactory::getBlueTunic(){
    Configuration& config = Configuration::getInstance();
    GameItem blueTunic = getItem("blue_tunic", BLUE_TUNIC_ID);
    int armorSlot = config.getValue("inv_armor_slot");
    blueTunic.addValidSlot(armorSlot);
    return blueTunic;
}

GameItem GameItemFactory::getHood(){
    Configuration& config = Configuration::getInstance();
    GameItem hood = getItem("hood", HOOD_ID);
    int helmetSlot = config.getValue("inv_helmet_slot");
    hood.addValidSlot(helmetSlot);
    return hood;
}

GameItem GameItemFactory::getIronHelmet(){
    Configuration& config = Configuration::getInstance();
    GameItem helmet = getItem("iron_helmet", IRON_HELMET_ID);
    int helmetSlot = config.getValue("inv_helmet_slot");
    helmet.addValidSlot(helmetSlot);
    return helmet;
}

GameItem GameItemFactory::getTurtleShield(){
    Configuration& config = Configuration::getInstance();
    GameItem turtleShield = getItem("turtle_shield", TURTLE_SHIELD_ID);
    int shieldSlot = config.getValue("inv_shield_slot");
    turtleShield.addValidSlot(shieldSlot);
    return turtleShield;
}

GameItem GameItemFactory::getIronShield(){
    Configuration& config = Configuration::getInstance();
    GameItem ironShield = getItem("iron_shield", IRON_SHIELD_ID);
    int shieldSlot = config.getValue("inv_shield_slot");
    ironShield.addValidSlot(shieldSlot);
    return ironShield;
}

GameItem GameItemFactory::getMagicHat(){
    Configuration& config = Configuration::getInstance();
    GameItem magicHat = getItem("magic_hat", MAGIC_HAT_ID);
    int helmetSlot = config.getValue("inv_helmet_slot");
    magicHat.addValidSlot(helmetSlot);
    return magicHat;
}

GameItem GameItemFactory::getItem(int id){
    switch(id){
        case HANDS_ID:
            return getBareHands();
        case NO_ARMOR_ID:
            return getNoArmor();
        case SWORD_ID:
            return getSword();
        case AXE_ID:
            return getAxe();
        case HAMMER_ID:
            return getHammer();
        case ICE_STAFF_ID:
            return getIceStaff();
        case ELFIC_FLUTE_ID:
            return getElficFlute();
        case KNOT_STAFF_ID:
            return getKnotStaff();
        case CRIMP_STAFF_ID:
            return getCrimpStaff();
        case SIMPLE_BOW_ID:
            return getSimpleBow();
        case COMPOUND_BOW_ID:
            return getCompoundBow();
        case LEATHER_ARMOR_ID:
            return getLeatherArmor();
        case PLATE_ARMOR_ID:
            return getPlateArmor();
        case BLUE_TUNIC_ID:
            return getBlueTunic();
        case HOOD_ID:
            return getHood();
        case IRON_HELMET_ID:
            return getIronHelmet();
        case TURTLE_SHIELD_ID:
            return getTurtleShield();
        case IRON_SHIELD_ID:
            return getIronShield();
        case MAGIC_HAT_ID:
            return getMagicHat();
    }

    std::cout << "Warning: item not implemented!" << std::endl;
    return std::move(GameItem());
}
