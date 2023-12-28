//
//
//

#ifndef TELLOROCK_SOCKETTELLO_H
#define TELLOROCK_SOCKETTELLO_H

#include "../AppInit/AppInit.h"

class SocketTello
{
private:
	std::string ip;
	int port;
	bool connected;
	char buffer[1024];
	std::string sn;
	std::string speed;
	std::string battery;
	std::string time;
	std::string wifi;
	boost::asio::io_context& io_context;
	boost::asio::ip::udp::socket& socket;
	boost::asio::ip::udp::endpoint listen_endpoint;
	boost::asio::ip::udp::endpoint connect_endpoint;
	std::atomic_bool isListening_{true};
	std::thread udpThread;
public:
	SocketTello(boost::asio::io_context& io_context, boost::asio::ip::udp::socket& socket, const boost::asio::ip::udp::endpoint&
	      listen_endpoint, const boost::asio::ip::udp::endpoint& connect_endpoint);
	void ReceiveThread();
	void StartListening();
	void StopListening();
	void initConnection();
	void refreshData();
	bool isConnected() const;
	int send_command(const std::string& command);
	void takeoff();
	void land();
	void emergency();
	void up(int x);
	void down(int x);
	void left(int x);
	void right(int x);
	void forward(int x);
	void back(int x);
	void cw(int x);
	void ccw(int x);
	void flip(std::string direction);
	void go(int x, int y, int z, int speed);
	void stop();
	void curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed);
	void setSpeed(int x);
	std::string getSN() const;
	std::string getSpeed() const;
	std::string getBattery() const;
	std::string getTime() const;
	std::string getWifi() const;
};

#endif //TELLOROCK_SOCKETTELLO_H