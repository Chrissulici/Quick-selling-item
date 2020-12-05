//search:
	Set(HEADER_CG_STATE_CHECKER, 			sizeof(BYTE), 							"ServerStateCheck"	);

//add:
#ifdef ENABLE_SELL_ITEM
	Set(HEADER_CG_ITEM_SELL, 				sizeof(TPacketCGItemSell), 				"ItemSell",		true	);
#endif

