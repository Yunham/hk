#include "PacketBuilder.hpp"
#include "Connection.hpp"

#pragma once

namespace els {

	namespace PartyPacket {

		PacketBuilder PartyCreateAck(long unk1, std::wstring ����W��, int dungeonid, int ����, int unk2, int �̤j�H��, bool ���},
			int unk3, bool �����D, int unk4, int unk5, Player* chr);

		PacketBuilder PartyDungeonEnterAck();
		PacketBuilder PartyDungeonEnterData(int dungeonid, Player* player);

	}


}