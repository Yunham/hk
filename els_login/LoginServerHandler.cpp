#include "LoginServerHandler.hpp"
#include "LoginHandler.hpp"
#include <iostream>

namespace els {

	namespace LoginServerHandler {

		void handlePacket(PacketReader pr, Connection* c) {

/*			for (int i = 0; i < pr.getLength(); i++) {
				std::printf("%x ", static_cast<int>(pr.getPacket()[i]));
			}
			std::printf("\n");*/
			
			pr.skipBytes(32);
			unsigned short header = pr.readShort();
			pr.readInt(); // �ƾڥ]����
			pr.readByte(); // �ƾڥ]�O�_���Y boolean

//			std::printf("RECV: 0x%x\n", header);

			switch (header) {
				case 0x26B: // user_login
					LoginHandler::userLogin(pr, c);
					break;
				case 0x29:
					LoginHandler::channelListReq(c);
					break;
				case 0x22E:
					LoginHandler::terminateConnection(c);
					break;

				case 0x4F4:
					LoginHandler::serverListReq(c);
					break;

			}

		}

	}
}