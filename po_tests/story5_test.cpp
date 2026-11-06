// Story 5: As a player I want to see all my Void weapons.
#include "po_helpers.h"

using Names = std::vector<std::string>;

// Void armour is not a weapon.
TEST(Story5, VoidArmourIsNotAWeapon) {
    // Veil of Nothing: Void armour.
    Vault v = vaultOf({"Veil of Nothing", "Hush Protocol"});
    EXPECT_EQ(voidWeapons(v), Names({"Hush Protocol"}));
}

// Swords are weapons, even though they have no fire rate.
TEST(Story5, SwordsAreWeapons) {
    // Ninth Veil: Void sword.
    Vault v = vaultOf({"Ninth Veil", "Hush Protocol"});
    EXPECT_EQ(sorted(voidWeapons(v)), sorted({"Ninth Veil", "Hush Protocol"}));
}

// Each weapon is listed once, however many copies there are.
TEST(Story5, EachWeaponListedOnce) {
    // Null Choir: Void, 2 copies.
    Vault v = vaultOf({"Null Choir"});
    EXPECT_EQ(voidWeapons(v), Names({"Null Choir"}));
}

// Locked weapons are still shown.
TEST(Story5, LockedWeaponsAreShown) {
    // Grave Orchid: locked Void sword.
    Vault v = vaultOf({"Grave Orchid", "Hush Protocol"});
    EXPECT_EQ(sorted(voidWeapons(v)), sorted({"Grave Orchid", "Hush Protocol"}));
}
