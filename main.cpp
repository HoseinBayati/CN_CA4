#include "TCPConnection.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    TCPConnection tcpConnection1(10, 5);
    TCPConnection tcpConnection2(5, 2);

    tcpConnection1.sendData();
    tcpConnection1.onRTTUpdate(50);

    tcpConnection2.sendData();
    tcpConnection2.onRTTUpdate(100);

    tcpConnection1.onPacketLoss();
    tcpConnection2.onPacketLoss();

    cout << "TCPConnection1: cwnd = " << tcpConnection1.getCwnd() << ", ssthresh = " << tcpConnection1.getSsthresh() << endl;
    cout << "TCPConnection1: cwnd = " << tcpConnection1.getCwnd() << ", ssthresh = " << tcpConnection1.getSsthresh() << endl;
}