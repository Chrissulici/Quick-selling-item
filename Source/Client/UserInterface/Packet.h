//search:
	HEADER_CG_ITEM_DROP2                        = 20,

//add:
#ifdef ENABLE_SELL_ITEM
	HEADER_CG_ITEM_SELL							= 22,
#endif

//search:
typedef struct command_item_move
{
	BYTE 		header;
	TItemPos 	pos;
	TItemPos 	change_pos;
	WORD 		num;
} TPacketCGItemMove;

//add:
#ifdef ENABLE_SELL_ITEM
typedef struct command_item_sell
{
    BYTE        header;
    TItemPos    pos;
	DWORD		gold;
} TPacketCGItemSell;
#endif