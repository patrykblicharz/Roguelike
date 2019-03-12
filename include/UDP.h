#ifndef UDP_H
#define UDP_H
#include <iostream>
#include <cstring>
#include <string>
#include <SFML/Network.hpp>


class UDP
{
public:
    UDP();
    ~UDP();
    struct peer
    {
        peer(sf::IpAddress _address, unsigned short _port): address(_address), port(_port) {};
        sf::IpAddress address;
        unsigned short port;
    };
    void send(sf::UdpSocket &socket, std::vector<peer> &list);
    void receive(sf::UdpSocket &socket, int peers);
    int run(int localPort, int peersNumber);


protected:

private:
};

#endif // UDP_H
