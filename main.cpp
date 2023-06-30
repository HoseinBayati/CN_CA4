#include "RenoTCPConnection.hpp"
#include "NewRenoTCPConnection.hpp"
#include "BBRTCPConnection.hpp"

#include <iostream>

void testReno()
{
    RenoTCPConnection tcpConnection1(10, 5);
    RenoTCPConnection tcpConnection2(5, 2);

    tcpConnection1.sendData();
    tcpConnection1.onRTTUpdate(50);

    tcpConnection2.sendData();
    tcpConnection2.onRTTUpdate(100);

    tcpConnection1.onPacketLoss();
    tcpConnection2.onPacketLoss();

    std::cout << std::endl
              << std::endl;

    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
}

void testNewReno()
{

    RenoTCPConnection tcpConnection1(10, 5);
    RenoTCPConnection tcpConnection2(5, 2);

    tcpConnection1.sendData();
    tcpConnection1.onRTTUpdate(50);

    tcpConnection2.sendData();
    tcpConnection2.onRTTUpdate(100);

    tcpConnection1.onPacketLoss();
    tcpConnection2.onPacketLoss();

    std::cout << std::endl
              << std::endl;

    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
}
void testBBR()
{

    RenoTCPConnection tcpConnection1(10, 5);
    RenoTCPConnection tcpConnection2(5, 2);

    tcpConnection1.sendData();
    tcpConnection1.onRTTUpdate(50);

    tcpConnection2.sendData();
    tcpConnection2.onRTTUpdate(100);

    tcpConnection1.onPacketLoss();
    tcpConnection2.onPacketLoss();

    std::cout << std::endl
              << std::endl;

    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
}

int main()
{
    RenoTCPConnection tcpConnection1(10, 5);
    RenoTCPConnection tcpConnection2(5, 2);

    tcpConnection1.sendData();
    tcpConnection1.onRTTUpdate(50);

    tcpConnection2.sendData();
    tcpConnection2.onRTTUpdate(100);

    tcpConnection1.onPacketLoss();
    tcpConnection2.onPacketLoss();

    std::cout << std::endl
              << std::endl;

    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
    std::cout << "TCPConnection1: cwnd = " <<
        tcpConnection1.getCwnd() << ", ssthresh = " <<
        tcpConnection1.getSsthresh() << std::endl;
}