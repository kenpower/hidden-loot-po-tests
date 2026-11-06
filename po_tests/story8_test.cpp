// Story 8: As a player I want to find a weapon by name.
#include "po_helpers.h"

// Anything that is not a valid position in the vault counts as "not found" here;
// the exact not-found value is checked separately in NotFoundGivesMinusOne.
static bool notFound(const Vault& v, int result) {
    return result < 0 || result >= (int)v.items.size();
}

// Upper/lower case does not matter.
TEST(Story8, CaseDoesNotMatter) {
    Vault v = makeSeedVault();
    EXPECT_EQ(findWeapon(v, "hollow requiem"), indexOf(v, "Hollow Requiem"));
}

// The whole name must match: part of a name finds nothing.
TEST(Story8, PartOfANameFindsNothing) {
    Vault v = makeSeedVault();
    EXPECT_TRUE(notFound(v, findWeapon(v, "Requiem")));
}

// An exact match wins, even when a longer name containing it comes first.
TEST(Story8, ExactNameNotALongerOne) {
    Vault v = makeSeedVault();  // "Static Widow Mk II" is before "Static Widow"
    EXPECT_EQ(findWeapon(v, "Static Widow"), indexOf(v, "Static Widow"));
}

// Armour is not a weapon, so it is never found.
TEST(Story8, ArmourIsNotFound) {
    Vault v = makeSeedVault();
    EXPECT_TRUE(notFound(v, findWeapon(v, "Bastion of Ash")));
}

// When nothing matches, the answer is -1.
TEST(Story8, NotFoundGivesMinusOne) {
    Vault v = makeSeedVault();
    EXPECT_EQ(findWeapon(v, "Golden Banana"), -1);
}
