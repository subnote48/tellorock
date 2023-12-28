#include "SocketTello.h"


SocketTello::SocketTello(boost::asio::io_context& io_context, boost::asio::ip::udp::socket& socket,
		boost::asio::ip::udp::endpoint const& listen_endpoint,
		boost::asio::ip::udp::endpoint const& connect_endpoint)
		: ip(listen_endpoint.address().to_string()), port(listen_endpoint.port()), io_context(io_context),
		  socket(socket), listen_endpoint(listen_endpoint), connect_endpoint(connect_endpoint)
{
	socket.bind(listen_endpoint);
}


int SocketTello::send_command(const std::string& command)
{
	boost::system::error_code err;
	socket.send_to(boost::asio::buffer(command), connect_endpoint, 0, err);

	if (err)
	{
		spdlog::error("Error sending command: {}", err.message());
		spdlog::error("Address: {}", listen_endpoint.address().to_string());

		return -1;
	}
	else
	{
		spdlog::info("Command sent!");
	}

	return 0;
}

void SocketTello::ReceiveThread()
{
	for (char receivedData[1024]; isListening_;)
	{
		try
		{
			boost::system::error_code error;
			size_t len = socket.receive_from(boost::asio::buffer(receivedData), listen_endpoint, 0, error);

			if (error && error != boost::asio::error::message_size)
			{
				throw boost::system::system_error(error);
			}

			receivedData[len] = '\0';

			spdlog::info("Received UDP data: {}", receivedData);
		}
		catch (std::exception const& e)
		{
			std::cerr << "Error receiving UDP data: " << e.what() << std::endl;
		}
	}
}

void SocketTello::StartListening()
{
	std::thread udpThread(&SocketTello::ReceiveThread, this);
	udpThread.detach(); // Detach the thread so it runs independently
}

void SocketTello::StopListening()
{
	isListening_ = false;
}


void SocketTello::takeoff()
{
	this->send_command("takeoff");
}

void SocketTello::land()
{
	this->send_command("land");
}

void SocketTello::emergency()
{
	this->send_command("emergency");
}

void SocketTello::up(int x)
{
	this->send_command("up " + std::to_string(x));
}

void SocketTello::down(int x)
{
	this->send_command("down " + std::to_string(x));
}

void SocketTello::left(int x)
{
	this->send_command("left " + std::to_string(x));
}

void SocketTello::right(int x)
{
	this->send_command("right " + std::to_string(x));
}

void SocketTello::forward(int x)
{
	this->send_command("forward " + std::to_string(x));
}

void SocketTello::back(int x)
{
	this->send_command("back " + std::to_string(x));
}

void SocketTello::cw(int x)
{
	this->send_command("cw " + std::to_string(x));
}

void SocketTello::ccw(int x)
{
	this->send_command("ccw " + std::to_string(x));
}

void SocketTello::flip(std::string direction)
{
	this->send_command("flip " + direction);
}

void SocketTello::go(int x, int y, int z, int speed)
{
	this->send_command(
			"go " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " +
			std::to_string(speed));
}

void SocketTello::stop()
{
	this->send_command("stop");
}

void SocketTello::curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed)
{
	this->send_command(
			"curve " + std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1) + " " +
			std::to_string(x2) +
			" " + std::to_string(y2) + " " + std::to_string(z2) + " " + std::to_string(speed));
}

void SocketTello::setSpeed(int x)
{
	this->send_command("speed " + std::to_string(x));
}

void SocketTello::initConnection()
{
	this->send_command("command");
}


bool SocketTello::isConnected() const
{
	return this->connected;
}

std::string SocketTello::getSN() const
{
	return this->sn;
}

std::string SocketTello::getSpeed() const
{
	return this->speed;
}

std::string SocketTello::getBattery() const
{
	return this->battery;
}

std::string SocketTello::getTime() const
{
	return this->time;
}

std::string SocketTello::getWifi() const
{
	return this->wifi;
}
