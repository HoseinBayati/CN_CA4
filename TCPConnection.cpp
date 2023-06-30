#include "TCPConnection.hpp"

TCPConnection::TCPConnection(int init_cwnd, int init_ssthresh) {

    cwnd = init_cwnd;
    ssthresh = init_ssthresh;
    rtt = 0;
}

int TCPConnection::sendData(){

    return 0;
}


int TCPConnection::onPacketLoss(){


    return 0;
}


int TCPConnection::onRTTUpdate(int rtt_in){

    return 0;
}