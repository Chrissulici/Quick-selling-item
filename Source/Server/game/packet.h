//search:
	HEADER_CG_ITEM_DROP2							= 20,

//add:
#ifdef ENABLE_SELL_ITEM
	HEADER_CG_ITEM_SELL								= 22,
#endif	

//search:
typedef struct command_item_move
{
	BYTE		header;
	TItemPos	Cell;
	TItemPos	CellTo;
	WORD		count;
} TPacketCGItemMove;

//add:
#ifdef ENABLE_SELL_ITEM
typedef struct command_item_sell
{
    BYTE        header;
    TItemPos    Cell;
	DWORD		gold;
} TPacketCGItemSell;
#endif