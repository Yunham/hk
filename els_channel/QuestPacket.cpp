#include "MessagePacket.hpp"
#include "Time.hpp"

namespace els {

	namespace QuestPacket {

		PacketBuilder OpenNPCAck(int npcid) {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(npcid)
				.finishPacket(0xEA);

			return pb;

		}

		PacketBuilder QuestAcceptAck() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0xDE);

			return pb;

		}

		PacketBuilder QuestAccept(int npcid, int questid) {
			int 不知道什麼的數量 = 0/*1*/;
			PacketBuilder pb;
			pb
				.writeInt(questid)
				.writeLong(Time::timestamp_now())

				.writeInt(不知道什麼的數量)

/*				.writeInt(questid)
				.writeByte(1)
				.writebool(true)*/

				.finishPacket(0xDF);

			return pb;

		}
	}
}