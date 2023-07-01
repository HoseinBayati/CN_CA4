#include "NewRenoTCPConnection.hpp"

#include <chrono>
#include <thread>

NewRenoTCPConnection::NewRenoTCPConnection(int init_cwnd, int init_ssthresh)
    : cwnd(init_cwnd), ssthresh(init_ssthresh), rtt(100), inFastRecovery(false), duplicateAckCount(0)
{
}

void NewRenoTCPConnection::sendData()
{
    if (!inFastRecovery)
    {
        cwnd++;
        if (cwnd >= ssthresh)
        {
            inFastRecovery = false;
        }
    }
    else
    {
        cwnd += 1;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));

    bool ackReceived = true;

    if (ackReceived)
    {
        if (!inFastRecovery)
        {
            duplicateAckCount = 0;
            cwnd += 1;
        }
        else
        {
            duplicateAckCount++;
            if (duplicateAckCount == 3)
            {
                onPacketLoss();
            }
        }
    }
}

void NewRenoTCPConnection::onPacketLoss()
{
    inFastRecovery = true;
    ssthresh = cwnd / 2;
    cwnd = ssthresh + 3;
    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));
}

void NewRenoTCPConnection::onRTTUpdate(int new_rtt)
{
    if (rtt == 0)
    {
        rtt = new_rtt;
    }
    else
    {
        const double alpha = 0.125;
        rtt = alpha * new_rtt + (1 - alpha) * rtt;
    }
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
