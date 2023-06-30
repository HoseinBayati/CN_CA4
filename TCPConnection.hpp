class TCPConnection
{
public:
    TCPConnection(int cwnd, int ssthresh);
    int sendData();
    int onPacketLoss();
    int onRTTUpdate(int i);

    int getCwnd();
    int getSsthresh();

private:
    int cwnd;
    int ssthresh;
    int rtt;
};