#include "PVPRoom.hpp"
#include "Config.hpp"
#include "Converter.hpp"
#include <cassert>
#include <iostream>

namespace els {

	PVPRoom::PVPRoom(int id) : m_id(id) { }

	int PVPRoom::getID() {
		return m_id;
	}

	int PVPRoom::getMaxPlayer() {
		return m_maxplayer;
	}

	int PVPRoom::getPlayerSize() {
		return (int) m_players.size();
	}

	int PVPRoom::getType() {
		return m_type;
	}

	int PVPRoom::getKill() {
		return m_kill;
	}

	int PVPRoom::getMapId() {
		return m_mapid;
	}

	std::wstring PVPRoom::getRoomName() {
		return m_roomname;
	}

	std::wstring PVPRoom::getPassword() {
		return m_password;
	}

	bool PVPRoom::getOpen() {
		return m_open;
	}

	bool PVPRoom::getProp() {
		return m_prop;
	}

	float PVPRoom::getSecond() {
		return m_second;
	}

	Player PVPRoom::getLeader() {
		return m_leader;
	}

	std::map<int, Player*>* PVPRoom::getPlayers() {
		return &m_players;
	}

	void PVPRoom::addPlayer(Player* player) {
//		std::cout << "PVPRoom addplayer ID: " << std::dec << m_id << std::endl;
//		std::cout << player->getName() << std::endl;
		m_players.insert(std::make_pair(player->getPlayerID(), player));
	}

	void PVPRoom::removePlayer(int id) {
		if (m_players.find(id) != m_players.end())
			m_players.erase(id);
	}

	void PVPRoom::setMaxPlayer(int value) {
		m_maxplayer = value;
	}

	void PVPRoom::setType(int value) {
		m_type = value;
	}

	void PVPRoom::setKill(int value) {
		m_kill = value;
	}

	void PVPRoom::setMapId(int value) {
		m_mapid = value;
	}

	void PVPRoom::setRoomName(std::wstring name) {
		m_roomname = name;
	}

	void PVPRoom::setPassword(std::wstring password) {
		m_password = password;
	}

	void PVPRoom::setOpen(bool b) {
		m_open = b;
	}

	void PVPRoom::setProp(bool b) {
		m_prop = b;
	}

	void PVPRoom::setSecond(float s) {
		m_second = s;
	}

	void PVPRoom::setLeader(Player p) {
		m_leader = p;
	}

	void PVPRoom::writeRoomInfoData(PacketBuilder& pb) {
		pb
			.writeByte(1/*0*/) // PVP_CHANNEL_CLASS ?
			.writeLong(getID())
			.writeInt(0) // PVP�W�DID?
			.writeElsWString(getRoomName())
			.writeByte(3/*0*/) // ROOM_STATE | INIT = 1 CLOSED = 2 WAIT = 3 LOADING = 4 PLAY = 5
			.writebool(getOpen())
			.writebool(true/*false*/)
			.writeElsWString(getPassword())
			.writeByte(getMaxPlayer())
			.writeByte((int) m_players.size())
			.writeElsString(Config::serverIP)
			.writeShort(9101)
			.writeByte(getType()) // NULL = -1 TEAM = 0 TEAM_DEATH = -1 �ͦs��(SURVIVIAL) = 2
			.writebool(getProp())
			.writeInt(0/*-1*/)
			.writeByte(getKill())
			.writebool(true)
			.writeFloat(getSecond())
			.writeShort(0/*-1*/)
			.writeShort(getMapId()) // WORLD_ID
			.writeByte(0)
			.writeInt(0) // dungeonID
			.writeByte(0) // dungeon = 1
			.writeByte(0)
			.writeLong(0)
			;
	}

	void PVPRoom::writeRoomPlayersData(PacketBuilder& pb) {
		pb.writeInt(/*1*/8);

		auto *players = getPlayers();
		for (auto p : *players) {
			p.second->writeData(pb);
		}

/*		for (int i = 0; i < 8; i++) {
			bool empty = true;
			for (auto p : *players) {
				if (p.second->getIndex() == i) {
					empty = false;
					break;
				}
			}
			if (empty) {
				writeEmptyPlayerData(pb, i, 1);
				empty = false;
			}
		}*/

		for (int i = (0 + (int) m_players.size()); i < 8; i++) {
			writeEmptyPlayerData(pb, i, 1);
		}

		pb.writeInt(0);

		pb.writeElsString(""/*getLeader().getIP()*/);
	}

	void PVPRoom::writeEmptyPlayerData(PacketBuilder& pb, int index, int state) {
		pb
			.writeByte(index) // ����index
			.writeByte(state) // ���⪬�A 1 = �}���L�H���J�� 2 = ������L�H���J�� 3 = ���ݤ� 4 = Ū���� 5 = �C����
			.writebool(false) // �ХD
			.writebool(false) // �ǳ�
			.writebool(false) // true = ���b�����L�ʧ@
			.writebool(false) // true = ���b�����L�ʧ@
			.writeInt(0) // 0 = ���� 1 = �Ŷ�

			.writeLong(0) // 2 �n�����O�b��ID
			.writeLong(0)
			.writeByte(0)
			.writebool(false)
			.writeByte(0)
			.writeLong(0)
			.writeInt(0) // 17113 ���O����id
			.writeByte(0)
			.writeInt(0)
			.writeElsWString(L"")
			.writeElsString("") // ����IP
			.writeShort(-1/*0*/) // port
			.writeByte(0)

			.writeInt(0)
			.writeInt(0)
			.writeInt(0)
			.writeInt(0)
			.writeInt(0)

			;

		pb.writeInt(0); // equipped equips

		// �ޯ�ֱ���
		for (int i = 0; i < 8; i++) {
			pb.writeShort(0);
			pb.writeByte(0);
		}

		pb
			.writeElsString("")
			.writeByte(0);

		pb.writeInt(0); // number of skills

		pb
			.writeInt(0);

		pb
			.writeInt(0);

		pb
			.writeInt(0) // ����{�b�h�ҭ�
			.writeInt(0) // �h�ҭȤW��
			.writebool(false)
			.writebool(false)
			.writeInt(0)
			.writebool(false)
			.writebool(false)
			.writeInt(0)
			.writeShort(0)
			.writeElsString("")
			.writeInt(0)
			.writeByte(0);
	}
}