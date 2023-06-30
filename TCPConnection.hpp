class TCPConnection
{
public:
    TCPConnection(int init_cwnd, int init_ssthresh);
    int sendData();
    int onPacketLoss();
    int onRTTUpdate(int new_rtt);

    int getCwnd();
    int getSsthresh();

private:
    int cwnd;
    int ssthresh;
    int rtt;
    bool inSlowStart;
    bool inFastRecovery;
};
