// Story 1: As a player I want to see my most powerful weapon.
#include "po_helpers.h"

using Names = std::vector<std::string>;

// "Powerful" means power level: not damage, not damage x fire rate.
TEST(Story1, PowerMeansPowerLevelNotDamage) {
    // Quiet Engine: power 1795, damage 42. Thunder Lullaby: power 1750, damage 95.
    Vault v = vaultOf({"Thunder Lullaby", "Quiet Engine"});
    EXPECT_EQ(mostPowerfulWeapon(v), Names({"Quiet Engine"}));
}

// Armour is not a weapon, even when it has the highest power.
TEST(Story1, ArmourIsNotAWeapon) {
    // Bastion of Ash is armour with power 1830.
    Vault v = vaultOf({"Bastion of Ash", "Quiet Engine"});
    EXPECT_EQ(mostPowerfulWeapon(v), Names({"Quiet Engine"}));
}

// If weapons tie on power, show all of them (order does not matter).
TEST(Story1, TiedWeaponsAreAllShown) {
    // Hollow Requiem and Ember Litany are both power 1820.
    Vault v = vaultOf({"Quiet Engine", "Hollow Requiem", "Ember Litany"});
    EXPECT_EQ(sorted(mostPowerfulWeapon(v)), sorted({"Hollow Requiem", "Ember Litany"}));
}

// Rarity does not decide power: a Legendary can be weaker than an Epic.
TEST(Story1, RarityDoesNotDecidePower) {
    // Gilded Mourning: Legendary, 1702. Quiet Engine: Epic, 1795.
    Vault v = vaultOf({"Gilded Mourning", "Quiet Engine"});
    EXPECT_EQ(mostPowerfulWeapon(v), Names({"Quiet Engine"}));
}

// A sword is a weapon, even though it has no fire rate.
TEST(Story1, SwordsAreWeaponsToo) {
    // Ninth Veil: sword, power 1810, fire rate 0.
    Vault v = vaultOf({"Quiet Engine", "Ninth Veil"});
    EXPECT_EQ(mostPowerfulWeapon(v), Names({"Ninth Veil"}));
}
