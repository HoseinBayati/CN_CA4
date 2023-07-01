#include "NewRenoTCPConnection.hpp"

#include <chrono>
#include <thread>
NewRenoTCPConnection::NewRenoTCPConnection(int init_cwnd, int init_ssthresh)
    : cwnd(init_cwnd), ssthresh(init_ssthresh), rtt(0),
      inFastRecovery(false), duplicateAckCount(0)
{
}

void NewRenoTCPConnection::sendData()
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

void NewRenoTCPConnection::onPacketLoss()
{
    if (inFastRecovery)
    {
        // Fast Recovery Algorithm
        cwnd = ssthresh;
        inFastRecovery = false;
    }
    else
    {
        // Regular Packet Loss Handling
        ssthresh = cwnd / 2;
        cwnd = 1;
    }
}

void NewRenoTCPConnection::onRTTUpdate(int new_rtt)
{
    rtt = new_rtt;
}

int NewRenoTCPConnection::getCwnd()
{
    return cwnd;
}

int NewRenoTCPConnection::getSsthresh()
{
    return ssthresh;
}

int NewRenoTCPConnection::getRtt()
{
    return rtt;
}