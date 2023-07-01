#include "constants.hpp"

class RenoTCPConnection
{
public:
    RenoTCPConnection(int init_cwnd, int init_ssthresh);
    void sendData();
    void onPacketLoss();
    void onRTTUpdate(int new_rtt);

    int getCwnd();
    int getSsthresh();
    int getRtt();

private:
    int cwnd;
    int ssthresh;
    int rtt;
    int mode;
};
