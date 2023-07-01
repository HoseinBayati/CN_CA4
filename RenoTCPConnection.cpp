#include "RenoTCPConnection.hpp"

#include <iostream>
#include <chrono>
#include <thread>

RenoTCPConnection::RenoTCPConnection(int init_cwnd, int init_ssthresh)
{
    cwnd = init_cwnd;
    ssthresh = init_ssthresh;
    rtt = 100;
}

void RenoTCPConnection::sendData()
{
    if (cwnd < ssthresh)
    {
        cwnd *= 2;
    }
    else
    {
        cwnd += 1;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));
}

void RenoTCPConnection::onPacketLoss()
{
    ssthresh = cwnd / 2;
    cwnd = 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));
}

void RenoTCPConnection::onRTTUpdate(int new_rtt)
{
    rtt = new_rtt;
}

int RenoTCPConnection::getCwnd()
{
    return cwnd;
}

int RenoTCPConnection::getSsthresh()
{
    return ssthresh;
}

int RenoTCPConnection::getRtt()
{
    return rtt;
}