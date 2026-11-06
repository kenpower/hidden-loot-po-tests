// Story 6: As a player I want to know my average power level.
#include "po_helpers.h"

// "My power level" is the average of what I have EQUIPPED, not the whole vault.
TEST(Story6, OnlyEquippedItemsCount) {
    // Equipped: 1795 + 1785 + 1730 + 1830 = 7140, / 4 = 1785.
    // Copper Psalm and Rusted Promise sit unequipped in the vault.
    Vault v = vaultOf({"Quiet Engine", "Kestrel Oath", "Driftglass", "Bastion of Ash",
                       "Copper Psalm", "Rusted Promise"});
    equip(v, "Primary", "Quiet Engine");
    equip(v, "Secondary", "Kestrel Oath");
    equip(v, "Heavy", "Driftglass");
    equip(v, "Armour", "Bastion of Ash");
    EXPECT_EQ(averagePowerLevel(v), 1785);
}

// Equipped armour counts towards power level, not just weapons.
TEST(Story6, ArmourCounts) {
    // All four: 7140 / 4 = 1785. Weapons only would be 5310 / 3 = 1770.
    Vault v = vaultOf({"Quiet Engine", "Kestrel Oath", "Driftglass", "Bastion of Ash"});
    equip(v, "Primary", "Quiet Engine");
    equip(v, "Secondary", "Kestrel Oath");
    equip(v, "Heavy", "Driftglass");
    equip(v, "Armour", "Bastion of Ash");
    EXPECT_EQ(averagePowerLevel(v), 1785);
}

// An empty slot is skipped, not counted as power 0.
TEST(Story6, EmptySlotsAreSkipped) {
    // Heavy is empty: 1795 + 1785 + 1760 = 5340, / 3 = 1780 (not / 4 = 1335).
    Vault v = vaultOf({"Quiet Engine", "Kestrel Oath", "Eventide Lattice"});
    equip(v, "Primary", "Quiet Engine");
    equip(v, "Secondary", "Kestrel Oath");
    equip(v, "Armour", "Eventide Lattice");
    EXPECT_EQ(averagePowerLevel(v), 1780);
}

// Power level is rounded DOWN.
TEST(Story6, RoundsDown) {
    // 1795 + 1710 + 1780 + 1830 = 7115, / 4 = 1778.75 -> 1778 (not 1779).
    Vault v = vaultOf({"Quiet Engine", "Tin Sparrow", "Static Widow", "Bastion of Ash"});
    equip(v, "Primary", "Quiet Engine");
    equip(v, "Secondary", "Tin Sparrow");
    equip(v, "Heavy", "Static Widow");
    equip(v, "Armour", "Bastion of Ash");
    EXPECT_EQ(averagePowerLevel(v), 1778);
}
