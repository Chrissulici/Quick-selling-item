//search:
		bool SendItemPickUpPacket(DWORD vid);

//add:
#ifdef ENABLE_SELL_ITEM
		bool SendItemSellPacket(TItemPos pos, DWORD elk);
#endif

