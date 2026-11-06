// Story 2: As a player I want to see what my vault is worth.
#include "po_helpers.h"

// Worth is scrap value, and every copy of an item counts.
TEST(Story2, EveryCopyCounts) {
    // Starfall Covenant: 3 copies x 80 scrap.
    Vault v = vaultOf({"Starfall Covenant"});
    EXPECT_EQ(vaultWorth(v), 240);
}

// Locked items are still worth something.
TEST(Story2, LockedItemsStillCount) {
    // Rusted Promise (locked) 5 + Quiet Engine 25.
    Vault v = vaultOf({"Rusted Promise", "Quiet Engine"});
    EXPECT_EQ(vaultWorth(v), 30);
}

// Armour counts, not just weapons.
TEST(Story2, ArmourCounts) {
    // Bastion of Ash 40 + Quiet Engine 25.
    Vault v = vaultOf({"Bastion of Ash", "Quiet Engine"});
    EXPECT_EQ(vaultWorth(v), 65);
}

// The scrap the player already has is part of what the vault is worth.
TEST(Story2, ScrapYouAlreadyHaveCounts) {
    Vault v = vaultOf({"Quiet Engine"});
    v.scrap = 1000;
    EXPECT_EQ(vaultWorth(v), 1025);
}
