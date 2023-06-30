#include "BBRTCPConnection.hpp"

BBRTCPConnection::BBRTCPConnection(int init_cwnd)
    : cwnd(init_cwnd), ssthresh(INT_MAX), rtt(0), minRTT(INT_MAX), btlbw(0), inflight(0)
{
}

int BBRTCPConnection::sendData(int bytes_in_flight)
{
    int bbr_cwnd = std::min(cwnd, bytes_in_flight + std::max(inflight, btlbw));

    inflight += bbr_cwnd;

    return bbr_cwnd;
}

int BBRTCPConnection::onPacketLoss()
{
    ssthresh = std::max(cwnd / 2, 4);
    cwnd = ssthresh;
    inflight = 0;

    return cwnd;
}

int BBRTCPConnection::onRTTUpdate(int new_rtt, int new_btlbw)
{

    minRTT = std::min(minRTT, new_rtt);
    btlbw = std::max(btlbw, new_btlbw);

    if (new_rtt > minRTT * 1.25)
    {
        cwnd += 1;
    }
    else
    {
        cwnd += cwnd / 4;
    }

    return cwnd;
}

int BBRTCPConnection::getCwnd()
{
    return cwnd;
}

int BBRTCPConnection::getSsthresh()
{
    return ssthresh;
}
