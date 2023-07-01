#include <climits>
#include <algorithm>

class BBRTCPConnection
{
public:
    BBRTCPConnection(int init_cwnd);
    int sendData(int bytes_in_flight);
    int onPacketLoss();
    int onRTTUpdate(int new_rtt, int new_btlbw);

    int getCwnd();
    int getSsthresh();
    int getRtt();

private:
    int cwnd;
    int ssthresh;
    int rtt;
    int minRTT;
    int btlbw;
    int inflight;
};

