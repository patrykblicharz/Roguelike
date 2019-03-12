#include "UDP.h"

UDP::UDP()
{
    //ctor
}

UDP::~UDP()
{
    //dtor
}

void UDP::send(sf::UdpSocket &socket, std::vector<peer> &list)
{
    std::string s;
    std::cout << "Please type a message to send: ";
    std::getline(std::cin, s);
    char buffer[256];
    std::memset(buffer, 0, 256);
    std::memcpy(buffer, s.c_str(), s.size());
    for (peer p : list)
    {
        if (socket.send(buffer, sizeof(buffer), p.address, p.port) !=
                sf::Socket::Done)
        {
            std::cerr << "Problems sending" << std::endl;
        }
    }
}

void UDP::receive(sf::UdpSocket &socket, int peers)
{
    char data[100];
    std::memset(data, 0, 100);
    std::size_t received;
    sf::IpAddress recipient;
    unsigned short remote_port;
    int i = 0;
    while (i < peers)
    {
        if (socket.receive(data, 100, received, recipient, remote_port) != sf::Socket::Done)
        {
            std::cerr << "Error receiving" << std::endl;
        }
        std::cout << "Received: \"" << std::string(data) << "\" from " <<
                  recipient << " on " << remote_port << std::endl;
        i++;
    }
}

int UDP::run(int localPort, int peersNumber)
{
    sf::UdpSocket socket;

    unsigned short local_port = localPort;
    int peers = peersNumber;
    if (socket.bind(local_port) != sf::Socket::Done)
    {
        std::cerr << "Problems binding socket" << std::endl;
    }
    std::vector<peer> list;
    for (int i = 0; i < peers; i++)
    {
        std::string a;
        unsigned short port;
        std::cout << "Please type address: ";
        std::cin >> a;
        std::cout << "Please type port: ";
        std::cin >> port;
        list.push_back(peer(sf::IpAddress(a), port));
    }

    while(1)
    {
        send(socket, list);
        receive(socket, peers);
    }
    return 0;
}
