//search:
PyObject* netSendItemDropPacketNew(PyObject* poSelf, PyObject* poArgs)
{
	[...]
}

//add:
#ifdef ENABLE_SELL_ITEM
PyObject* netSendItemSellPacket(PyObject* poSelf, PyObject* poArgs)
{
	TItemPos Cell;
	
	switch (PyTuple_Size(poArgs))
	{
		case 1:
			if (!PyTuple_GetInteger(poArgs, 0, &Cell.cell))
				return Py_BuildException();
			break;
		case 2:
			if (!PyTuple_GetByte(poArgs, 0, &Cell.window_type))
				return Py_BuildException();
			if (!PyTuple_GetInteger(poArgs, 1, &Cell.cell))
				return Py_BuildException();
			break;
		default:
			return Py_BuildException();
	}


	CPythonNetworkStream& rkNetStream=CPythonNetworkStream::Instance();
	rkNetStream.SendItemSellPacket(Cell, 0);
	return Py_BuildNone();
}
#endif

//search:
		{ "SendItemDropPacketNew",				netSendItemDropPacketNew,				METH_VARARGS },

//add:
#ifdef ENABLE_SELL_ITEM
		{ "SendItemSellPacket",					netSendItemSellPacket,					METH_VARARGS },
#endif

