#include "Config.hpp"
#include <string>

namespace els {

	namespace Config {

		std::string version = "N_20100405_A";

		// Database

		std::string sqlhost = "127.0.0.1";
		std::string sqluser = "root";
		std::string sqlpass = "";
		std::string sqldb = "els";

		//Net

		short loginport = 9400;
		std::string serverName = "Server 1";
		std::string serverIP = "127.0.0.1";

		//Channels

		int channels = 1;
//		std::string channelName[1] = { "Channel 1" };
		std::wstring channelName[1] = { L"���y1" };
		std::string channelIP[1] = { "127.0.0.1" };
	}
}