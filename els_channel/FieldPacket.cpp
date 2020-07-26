#include "FieldPacket.hpp"
#include "MapDataProvider.hpp"
#include "Config.hpp"
#include "World.hpp"

namespace els {

	namespace FieldPacket {

		PacketBuilder playerList(Player* player) { // 0x372

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(player->getMap())

				.writeInt(1)
				.writeShort(0)
				.writeInt(1)
				.writeByte(0)
				.writeShort(7)
				.writeByte(0)
				.writeShort(7)
				.writeByte(0)
				.writeInt(8)
				.writeInt(0)
				.writeByte(0)
				.writeInt(6)
				.writeByte(1)
				.writeShort(0)
				.writeInt(4)

				// number of players
				.writeByte((int) World::getMap(player->getMap())->getPlayers()->size())
				.writeElsString(Config::serverIP)
				.writeShort(9101) // server port o.o
				.writeShort(0)
				.writeByte(0)
				.writeInt(-1)
				.writeLong(0)
				.writeLong(1)
				.writeLong(0)
				.writeByte(0)
				.writeInt(player->getMap())
				.writeInt(0)
				.writeInt(0)
				.writeByte(0x0C) // ???
				.writeShort(5)
				.writeShort(1) // ???
				.writeShort(0); // ???

			// INCOMPLETE


			return pb;
		}

		PacketBuilder CashShopInfo() {
			int �D��ƶq = 0;
			PacketBuilder pb;
			pb
				.writebool(true)
				.writeInt(�D��ƶq)

/*				for
				CInPacket::Decode4((int)a1, (_DWORD *)a2)
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 4))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 8))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 9))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 10))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 11))
				&& CInPacket::DecodeStr(a1, a2 + 12)
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 40))
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 41))
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 45))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 49))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 50))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 51))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 52))
				&& CInPacket::DecodeStr*/

				.finishPacket(0x26E);

			return pb;
		}

		PacketBuilder CashShopUnk() {
			int �D��ƶq = 0;
			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(�D��ƶq)

/*				for
				CInPacket::Decode4((int)a1, a2)
				&& CInPacket::DecodeStr(a1, (int)(a2 + 1))

				CInPacket::Decode4((int)a1, (_DWORD *)a2)
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 4))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 8))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 9))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 10))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 11))
				&& CInPacket::DecodeStr(a1, a2 + 12)
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 40))
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 41))
				&& CInPacket::Decode4((int)a1, (_DWORD *)(a2 + 45))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 49))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 50))
				&& CInPacket::DecodeBoolean((int)a1, (bool *)(a2 + 51))
				&& (unsigned __int8)CInPacket::Decode1((int)a1, (void *)(a2 + 52))
				&& CInPacket::DecodeStr
				CInPacket::Decode4->CInPacket::Decode4
				&& (unsigned __int8)CInPacket::Decode1_((int)a1, (char *)a2 + 129)
				&& CInPacket::DecodeStr(a1, (int)a2 + 130)
				&& CInPacket::DecodeStr(a1, (int)a2 + 158)
				&& CInPacket::Decode8((int)a1, (_DWORD *)((char *)a2 + 186));*/

			.finishPacket(0x270);

			return pb;
		}

		PacketBuilder SquareInfo() {
			int �ө�����y�ƶq = 1/*2*/;
			PacketBuilder pb;
			pb
				.writeInt(0)

				.writeInt(1) // �{�b����
				.writeInt(1) // �̤j����

				.writeInt(�ө�����y�ƶq)

				.writeByte(4/*5*/) // �ө���a��ID 4=�x���Ϊ�
				.writeLong(1) // �W�DID
				.writeElsWString(L"�ө��� 1")
				.writeByte(5) // �̤j�H��
				.writeByte(1) // �{�b�H��
				.writeElsWString(L"")
				.writeInt(1/*0*/)

/*				.writeByte(2)
				.writeLong(2)
				.writeElsWString(L"�ө��� 2")
				.writeByte(5)
				.writeByte(1)
				.writeElsWString(L"")
				.writeInt(0)*/

				.finishPacket(0x3E);

			return pb;
		}

		PacketBuilder SquareEnter(Player* player) {
			int ����ƶq = 1;
			PacketBuilder pb;
			pb
				.writeInt(0)

				.writeByte(4/*5*/) // �ө���a��ID 4=�x���Ϊ�
				.writeLong(1) // �W�DID
				.writeElsWString(L"�ө��� 1")
				.writeByte(5) // �̤j�H��
				.writeByte(1) // �{�b�H��
				.writeElsWString(L"")
				.writeInt(1/*0*/)

				.writeInt(����ƶq)

				.writeLong(player->getAccountID())
				.writeLong(player->getPlayerID())
				.writeElsWString(player->getName())
				.writeElsString(player->getIP())
				.writeShort(8134)

				.writeByte(player->getLevel())
				.writeByte(0/*1*/)
				.writeByte(0/*1*/)
				.writebool(false)
				.writeByte(1)
				.writeByte(1)

				.writeElsWString(L"�D�b������")

				.writeInt(player->getInv()->getQuantity(9));
			    for (auto equip : *player->getInv()->getInventory()) {
				    if (equip.second.isEquipped()) {
					pb
						.writeLong(equip.second.getUniqueID())
						.writeInt(equip.second.getItemID())
						.writeByte(9)
						.writeByte(equip.second.getPosition())
						.writeByte(0)
						// �ݩ�
						.writeByte(0)
						.writeByte(0)
						.writeByte(0)
						;
			     	}
			    }

			pb
				.writeShort(1/*0*/)
				.writeElsWString(L"")

				.finishPacket(0x49);

			return pb;
		}

		PacketBuilder OpenPersonalShopAck(int playerid) {
			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeLong(playerid)

				.finishPacket(0x1AA);
			return pb;
		}


	}
}