// Story 3: As a player I want to scrap my junk.
#include "po_helpers.h"

// Junk means Common rarity. Not "Rare", not "low power".
TEST(Story3, OnlyCommonItemsAreJunk) {
    // Copper Psalm is Rare and has the lowest power in the vault.
    Vault v = vaultOf({"Bent Halo", "Copper Psalm"});
    scrapJunk(v);
    EXPECT_EQ(quantityOf(v, "Copper Psalm"), 1);
}

// Locked items are never scrapped, even Common ones.
TEST(Story3, LockedItemsAreNeverScrapped) {
    // Rusted Promise is a locked Common.
    Vault v = vaultOf({"Rusted Promise", "Bent Halo"});
    scrapJunk(v);
    EXPECT_EQ(quantityOf(v, "Rusted Promise"), 1);
}

// Equipped items are never scrapped, even Common ones.
TEST(Story3, EquippedItemsAreNeverScrapped) {
    // Tin Sparrow is a Common, equipped as the Secondary.
    Vault v = vaultOf({"Tin Sparrow", "Bent Halo"});
    equip(v, "Secondary", "Tin Sparrow");
    scrapJunk(v);
    EXPECT_EQ(quantityOf(v, "Tin Sparrow"), 1);
}

// Every copy of a junk item is scrapped, and each copy pays out.
TEST(Story3, EveryCopyIsScrapped) {
    // Dull Thorn: Common, 2 copies x 5 scrap.
    Vault v = vaultOf({"Dull Thorn"});
    EXPECT_EQ(scrapJunk(v), 10);
}

// Scrapped items leave the vault completely (no entry left with quantity 0).
TEST(Story3, ScrappedItemsLeaveTheVault) {
    Vault v = vaultOf({"Quiet Engine", "Bent Halo"});
    scrapJunk(v);
    EXPECT_EQ(indexOf(v, "Bent Halo"), -1);
}
