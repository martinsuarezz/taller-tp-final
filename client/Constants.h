enum directions{UP, RIGHT, DOWN, LEFT};

enum mobTypes{ZOMBIE, SPIDER, SKELETON, GOBLIN};

enum itemsIds{NULL_ITEM_ID, HANDS_ID, NO_HELMET_ID, NO_ARMOR_ID, 
            SWORD_ID, AXE_ID, HAMMER_ID, ICE_STAFF_ID, ELFIC_FLUTE_ID,
            KNOT_STAFF_ID, CRIMP_STAFF_ID, SIMPLE_BOW_ID, COMPOUND_BOW_ID,
            LEATHER_ARMOR_ID, PLATE_ARMOR_ID, BLUE_TUNIC_ID, HOOD_ID,
            IRON_HELMET_ID, TURTLE_SHIELD_ID, IRON_SHIELD_ID, MAGIC_HAT_ID};

enum weaponTypes{MELEE_FIRST = 4, MELEE_LAST = 6, STAFF_FIRST = 7, STAFF_LAST = 10,
                BOW_FIRST = 11, BOW_LAST = 12};

#define MICROS_IN_SECOND 1000000