#include "constants.hpp"

class NewRenoTCPConnection
{
public:
    NewRenoTCPConnection(int init_cwnd, int init_ssthresh);
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
    bool inFastRecovery;
    int duplicateAckCount;
};
