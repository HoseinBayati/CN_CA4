#include "NewRenoTCPConnection.hpp"
#include <iostream>

NewRenoTCPConnection::NewRenoTCPConnection(int init_cwnd, int init_ssthresh)
{
    cwnd = init_cwnd;
    ssthresh = init_ssthresh;
    rtt = 0;
    inFastRecovery = false;
    duplicateAckCount = 0;
}

void NewRenoTCPConnection::sendData()
{
    if (inFastRecovery)
    {
        std::cout << "Retransmitting lost packet" << std::endl;

        for (int i = 0; i < cwnd; ++i)
        {
            std::cout << "Sending packet " << i << std::endl;
        }
    }
    else if (cwnd < ssthresh)
    {
        for (int i = 0; i < cwnd; ++i)
        {
            std::cout << "Sending packet " << i << std::endl;
        }
        cwnd *= 2;
    }
    else
    {
        for (int i = 0; i < cwnd; ++i)
        {
            std::cout << "Sending packet " << i << std::endl;
        }
        cwnd += 1;
    }
}

void NewRenoTCPConnection::onPacketLoss()
{
    if (inFastRecovery)
    {
        cwnd = ssthresh;
        inFastRecovery = false;
    }
    else
    {
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