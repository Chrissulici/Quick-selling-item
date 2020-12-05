//search:
		bool			DropItem(TItemPos Cell,  WORD bCount = 0);

//add:
#ifdef ENABLE_SELL_ITEM
		bool            SellItem(TItemPos Cell);
#endif