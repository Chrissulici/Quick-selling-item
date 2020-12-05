//search:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", 0);
#endif

//add:
#ifdef ENABLE_SELL_ITEM
	PyModule_AddIntConstant(poModule, "ENABLE_SELL_ITEM", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SELL_ITEM", 0);
#endif

