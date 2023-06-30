#include "BBRTCPConnection.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

BBRTCPConnection::BBRTCPConnection(int init_cwnd)
{
    cwnd = init_cwnd;
    minRTT = INT_MAX;
    btlbw = 0;
    inflight = 0;
}

int BBRTCPConnection::sendData()
{
    int transmission_rate = std::min(cwnd, inflight);

    std::this_thread::sleep_for(std::chrono::milliseconds(minRTT));

    inflight -= transmission_rate;

    return transmission_rate;
}

int BBRTCPConnection::onPacketLoss()
{
    cwnd /= 2;

    minRTT = INT_MAX;
    btlbw = 0;

    return cwnd;
}

int BBRTCPConnection::onRTTUpdate(int new_rtt, int new_btlbw)
{
    minRTT = std::min(minRTT, new_rtt);

    btlbw = std::max(btlbw, new_btlbw);

    double pacing_gain = static_cast<double>(cwnd) / btlbw;

    double cwnd_gain = 1 + ((2 * pacing_gain) * (static_cast<double>(minRTT) / new_rtt));

    cwnd *= cwnd_gain;

    return cwnd;
}

int BBRTCPConnection::getCwnd()
{
    return cwnd;
}
