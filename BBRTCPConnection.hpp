#include <climits>

class BBRTCPConnection
{
public:
    BBRTCPConnection(int init_cwnd);
    int sendData();
    int onPacketLoss();
    int onRTTUpdate(int new_rtt, int new_btlbw);

    int getCwnd();

private:
    int cwnd;
    int minRTT;
    int btlbw;
    int inflight;
};
