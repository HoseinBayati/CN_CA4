#include "NewRenoTCPConnection.hpp"

#include <iostream>
#include <chrono>
#include <thread>

NewRenoTCPConnection::NewRenoTCPConnection(int init_cwnd, int init_ssthresh)
{
    cwnd = init_cwnd;
    ssthresh = init_ssthresh;
    rtt = 0;
    fastRecoveryMode = false;
    duplicateAcks = 0;
}

int NewRenoTCPConnection::sendData()
{
    int transmission_rate = cwnd;

    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));

    return transmission_rate;
}

int NewRenoTCPConnection::onPacketLoss()
{
    if (fastRecoveryMode)
    {
        cwnd = ssthresh / 2;
    }
    else
    {
        cwnd = 1;
        ssthresh = cwnd;
    }

    fastRecoveryMode = true;
    duplicateAcks = 0;

    return cwnd;
}

int NewRenoTCPConnection::onRTTUpdate(int new_rtt)
{
    rtt = new_rtt;

    if (fastRecoveryMode)
    {
        cwnd = ssthresh + duplicateAcks;
        fastRecoveryMode = false;
        duplicateAcks = 0;
    }
    else
    {
        if (cwnd < ssthresh)
        {
            cwnd *= 2;
        }
        else
        {
            cwnd += 1;
        }
    }

    return cwnd;
}

int NewRenoTCPConnection::getCwnd()
{
    return cwnd;
}

int NewRenoTCPConnection::getSsthresh()
{
    return ssthresh;
}
