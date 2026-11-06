#pragma once
// Helpers for the Product Owner's acceptance tests.
// Each test builds a small vault out of real seed items, so that it checks
// exactly one decision the Product Owner made.
#include <algorithm>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "stories.h"
#include "vault.h"

// A copy of one item from the seed vault, looked up by its exact name.
inline Item seedItem(const std::string& name) {
    Vault seed = makeSeedVault();
    for (const Item& item : seed.items) {
        if (item.name == name) return item;
    }
    ADD_FAILURE() << "Seed data changed: no item called \"" << name << "\"";
    return Item{};
}

// A vault holding only the named seed items, no scrap and four empty slots.
inline Vault vaultOf(const std::vector<std::string>& names) {
    Vault v;
    for (const std::string& name : names) v.items.push_back(seedItem(name));
    v.scrap = 0;
    v.loadout = {{"Primary", ""}, {"Secondary", ""}, {"Heavy", ""}, {"Armour", ""}};
    return v;
}

inline void equip(Vault& v, const std::string& slot, const std::string& itemName) {
    for (LoadoutSlot& s : v.loadout) {
        if (s.slotName == slot) { s.itemName = itemName; return; }
    }
    ADD_FAILURE() << "No loadout slot called \"" << slot << "\"";
}

inline void removeItem(Vault& v, const std::string& name) {
    for (size_t i = 0; i < v.items.size(); i++) {
        if (v.items[i].name == name) { v.items.erase(v.items.begin() + i); return; }
    }
}

// Position of the named item in the vault, or -1.
inline int indexOf(const Vault& v, const std::string& name) {
    for (int i = 0; i < (int)v.items.size(); i++) {
        if (v.items[i].name == name) return i;
    }
    return -1;
}

// Quantity of the named item still in the vault (0 if it is gone).
inline int quantityOf(const Vault& v, const std::string& name) {
    int i = indexOf(v, name);
    return i < 0 ? 0 : v.items[i].quantity;
}

inline std::vector<std::string> sorted(std::vector<std::string> names) {
    std::sort(names.begin(), names.end());
    return names;
}
