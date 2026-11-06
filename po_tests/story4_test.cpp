// Story 4: As a player I want to know how many Exotics I own.
#include "po_helpers.h"

// Count copies, not items: 3 copies of an Exotic is 3 Exotics.
TEST(Story4, EveryCopyCounts) {
    // Starfall Covenant: Exotic, 3 copies.
    Vault v = vaultOf({"Starfall Covenant", "Quiet Engine"});
    EXPECT_EQ(countExotics(v), 3);
}

// Exotic armour counts, not just weapons.
TEST(Story4, ExoticArmourCounts) {
    // Crown of Cinders: Exotic armour.
    Vault v = vaultOf({"Crown of Cinders", "Cobalt Absolution"});
    EXPECT_EQ(countExotics(v), 2);
}

// Locked Exotics still count.
TEST(Story4, LockedExoticsCount) {
    // Lantern of Mercy: locked Exotic.
    Vault v = vaultOf({"Lantern of Mercy", "Cobalt Absolution"});
    EXPECT_EQ(countExotics(v), 2);
}

// Only Exotic rarity counts. Legendary is not "Exotic or close enough".
TEST(Story4, LegendaryIsNotExotic) {
    Vault v = vaultOf({"Hollow Requiem", "Cobalt Absolution"});
    EXPECT_EQ(countExotics(v), 1);
}
