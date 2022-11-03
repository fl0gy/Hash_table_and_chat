#include "Chat.h"
#include <iostream>
#include <string>

int main()
{
	Chat chat;

	chat.reg("Ravkat", "egfcewtk");
	chat.reg("Alina", "iyfhtj,j");
	chat.reg("Kirill", "vtyenjce");
	chat.reg("Natali", "t[fdbgfy");
	chat.reg("Fedor", "egfcewtk");
	chat.reg("Pavel", "ybrfrjq");
	chat.reg("Alex", "djnhfp");
	chat.reg("Dima", "gjnjvexnj");

	chat.showData();

	chat.DeleteUserLogin("Ravkat", "egfcewtk");

	chat.showData();

	return 0;
}