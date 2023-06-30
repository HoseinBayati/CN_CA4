#include "TCPConnection.hpp"

#include <iostream>
#include <chrono>
#include <thread>

TCPConnection::TCPConnection(int init_cwnd, int init_ssthresh)
{
    cwnd = init_cwnd;
    ssthresh = init_ssthresh;
    rtt = 0;
    inSlowStart = true;
    inFastRecovery = false;
}

int TCPConnection::sendData()
{
    std::cout << std::endl
              << std::endl;

    if (inSlowStart)
    {
        std::cout << "Slow Start phase: Sending data using cwnd = " << cwnd << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(rtt));

        cwnd *= 2;

        if (cwnd >= ssthresh)
        {
            inSlowStart = false;
            std::cout << "Transitioning to Congestion Avoidance phase" << std::endl;
        }
    }
    else if (inFastRecovery)
    {
        std::cout << "Fast Recovery phase: Sending data using cwnd = " << cwnd << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(rtt));

        cwnd++;
    }
    else
    {
        std::cout << "Congestion Avoidance phase: Sending data using cwnd = " << cwnd << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(rtt));

        cwnd++;
    }

    return 0;
}

int TCPConnection::onPacketLoss()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "Packet loss detected. Entering Fast Recovery mode." << std::endl;

    ssthresh = cwnd / 2;
    cwnd = ssthresh + 3;

    std::cout << "Fast Recovery phase: Sending data using cwnd = " << cwnd << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(rtt));
    cwnd++;

    inFastRecovery = true;
    inSlowStart = false;

    return 0;
}

int TCPConnection::onRTTUpdate(int new_rtt)
{
    rtt = new_rtt;

    if (inFastRecovery)
    {
        cwnd = ssthresh;
        inFastRecovery = false;
        std::cout << "Transitioning to Congestion Avoidance phase" << std::endl;
    }
    else if (inSlowStart)
    {
        cwnd *= 2;

        if (cwnd >= ssthresh)
        {
            inSlowStart = false;
            std::cout << "Transitioning to Congestion Avoidance phase" << std::endl;
        }
    }
    else
    {
        cwnd++;
    }

    return 0;
}

int TCPConnection::getCwnd()
{
    return cwnd;
}

int TCPConnection::getSsthresh()
{
    return ssthresh;
}
