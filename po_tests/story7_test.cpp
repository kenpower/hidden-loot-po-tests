// Story 7: As a player I want to check if my loadout is complete.
#include "po_helpers.h"

// Every slot filled with an item from the vault is complete.
TEST(Story7, FullLoadoutIsComplete) {
    Vault v = makeSeedVault();
    equip(v, "Heavy", "Hollow Requiem");
    EXPECT_TRUE(isLoadoutComplete(v));
}

// One empty weapon slot makes the loadout incomplete.
TEST(Story7, EmptySlotMeansIncomplete) {
    Vault v = makeSeedVault();  // the seed Heavy slot is empty
    EXPECT_FALSE(isLoadoutComplete(v));
}

// The armour slot is part of the loadout too.
TEST(Story7, ArmourSlotMustBeFilled) {
    Vault v = makeSeedVault();
    equip(v, "Heavy", "Hollow Requiem");
    equip(v, "Armour", "");
    EXPECT_FALSE(isLoadoutComplete(v));
}

// A slot naming an item that is no longer in the vault (e.g. it was scrapped)
// is not really filled.
TEST(Story7, EquippedItemMustStillBeInTheVault) {
    Vault v = makeSeedVault();
    equip(v, "Heavy", "Hollow Requiem");
    removeItem(v, "Hollow Requiem");
    EXPECT_FALSE(isLoadoutComplete(v));
}
