#ifndef _ENTITIE_ITEM_INC
#define _ENTITIE_ITEM_INC

#include <GWCA\GameContainers\Array.h>

namespace GW {

    using wchar = wchar_t;
    using ItemID = DWORD;

    struct Bag;
    struct Item;

    using ItemArray = Array<Item*>;

    struct Bag { // total: 0x24/36
        /* +h0000 */ DWORD h0000;
        /* +h0004 */ DWORD index;
        /* +h0008 */ DWORD BagId;
        /* +h000C */ DWORD ContainerItem;
        /* +h0010 */ DWORD ItemsCount;
        /* +h0014 */ Bag *BagArray;
        /* +h0018 */ ItemArray Items;
    };

    struct ItemModifier {
        DWORD mod;

        DWORD identifier() { return (mod & 0x3FF00000) >> 20; }
        DWORD arg1() { return (mod & 0x0001FF00) >> 8; }
        DWORD arg2() { return (mod & 0x000000FE); }
        DWORD arg3() { return (mod & 0x0003FFFF); }
        DWORD arg4() { return (mod & 0x00040000) >> 17; }
        DWORD arg5() { return (mod & 0x0001FFFE); }
        DWORD arg6() { return (mod & 0x00000001); }
    };

    struct Item { // total: 0x50/80
        /* +h0000 */ DWORD ItemId;
        /* +h0004 */ DWORD AgentId;
        /* +h0008 */ BYTE h0008[4];
        /* +h000C */ Bag *Bag;
        /* +h0010 */ ItemModifier *ModStruct; // Pointer to an array of mods.
        /* +h0014 */ DWORD ModStructSize; // Size of this array.
        /* +h0018 */ wchar *Customized;
        /* +h001C */ DWORD ModelFileID;
        /* +h0020 */ BYTE Type;
        /* +h0021 */ BYTE h0021;
        /* +h0022 */ WORD ExtraId;
        /* +h0024 */ WORD Value;
        /* +h0026 */ BYTE h0026[4];
        /* +h002A */ WORD Interaction;
        /* +h002C */ DWORD ModelId;
        /* +h0030 */ wchar *InfoString;
        /* +h0034 */ wchar *NameString;
        /* +h0038 */ wchar *CompleteName; // with color, quantity, etc.
        /* +h003C */ BYTE h003C[15];
        /* +h004B */ BYTE Quantity;
        /* +h004C */ BYTE Equipped;
        /* +h004D */ BYTE Profession;
        /* +h004E */ BYTE Slot;
    };

    struct Inventory { // total: 0x84/124
        union {
        /* +h0000 */ Bag *Bags[31];
            struct {
        /* +h0000 */ Bag *UnusedBag;
        /* +h0004 */ Bag *Backpack;
        /* +h0008 */ Bag *BeltPouch;
        /* +h000C */ Bag *Bag1;
        /* +h0010 */ Bag *Bag2;
        /* +h0014 */ Bag *EquipmentPack;
        /* +h0018 */ Bag *MaterialStorage;
        /* +h001C */ Bag *UnclaimedItems;
        /* +h0020 */ Bag *Storage1;
        /* +h0024 */ Bag *Storage2;
        /* +h0028 */ Bag *Storage3;
        /* +h002C */ Bag *Storage4;
        /* +h0030 */ Bag *Storage5;
        /* +h0034 */ Bag *Storage6;
        /* +h0038 */ Bag *Storage7;
        /* +h003C */ Bag *Storage8;
        /* +h0040 */ Bag *Storage9;
        /* +h0044 */ Bag *EquippedItems;
            };
        };

        /* +h007C */ DWORD GoldCharacter;
        /* +h0080 */ DWORD GoldStorage;
    };

    using MerchItemArray = Array<ItemID>;
}

#endif // _ENTITIE_ITEM_INC
