#include "RenoTCPConnection.hpp"
#include "NewRenoTCPConnection.hpp"
#include "BBRTCPConnection.hpp"

#include <iostream>
#include <bits/stdc++.h>

#define TOTAL_PACKETS_COUNT 100000
using namespace std;

void testReno()
{
    RenoTCPConnection conec1(10, 5);

    int packets_count = 0;

    while (packets_count < TOTAL_PACKETS_COUNT)
    {
        double ten = 10;
        double fail_prob = ten - ten / pow(conec1.getCwnd(), 1 / 2);

        srand((unsigned)time(NULL));
        int random = rand() % 10;

        conec1.sendData();

        if (random > fail_prob)
        {
            packets_count++;
            // int old_rtt = conec1.getRtt();
            // int new_rtt = random > 5 ? old_rtt > 100 ? old_rtt - 100 : old_rtt + 100 : old_rtt + 100;
            // conec1.onRTTUpdate(new_rtt);
        }
        else
        {
            conec1.onPacketLoss();
        }
    }
}

void testNewReno()
{
    NewRenoTCPConnection conec1(10, 5);

    int packets_count = 0;

    while (packets_count < TOTAL_PACKETS_COUNT)
    {
        double ten = 10;
        double fail_prob = ten - ten / pow(conec1.getCwnd(), 1 / 2);

        srand((unsigned)time(NULL));
        int random = rand() % 10;

        conec1.sendData();

        if (random > fail_prob)
        {
            packets_count++;
            // int old_rtt = conec1.getRtt();
            // int new_rtt = random > 5 ? old_rtt > 100 ? old_rtt - 100 : old_rtt + 100 : old_rtt + 100;
            // conec1.onRTTUpdate(new_rtt);
        }
        else
        {
            conec1.onPacketLoss();
        }
    }
}

void testBBR()
{

    BBRTCPConnection conec1(10);

    int packets_count = 0;

    while (packets_count < TOTAL_PACKETS_COUNT)
    {
        double ten = 10;
        double fail_prob = ten - ten / pow(conec1.getCwnd(), 1 / 2);

        srand((unsigned)time(NULL));
        int random = rand() % 10;
        int random2 = rand() % 10;

        conec1.sendData(random2);

        if (random > fail_prob)
        {
            packets_count++;
            // int old_rtt = conec1.getRtt();
            // int new_rtt = random > 5 ? old_rtt > 100 ? old_rtt - 100 : old_rtt + 100 : old_rtt + 100;
            // conec1.onRTTUpdate(new_rtt, random2 % 5);
        }
        else
        {
            conec1.onPacketLoss();
        }
    }
}

int main()
{
    NewRenoTCPConnection conec2(10, 2);
    RenoTCPConnection conec1(10, 2);
    BBRTCPConnection conec3(10);

    conec1.sendData();
    conec1.onRTTUpdate(50);

    conec2.sendData();
    conec2.onRTTUpdate(100);

    conec3.sendData(5);
    conec3.onRTTUpdate(75, 100);

    conec1.onPacketLoss();
    conec2.onPacketLoss();
    conec3.onPacketLoss();

    cout << endl
         << endl;

    cout << "Reno : cwnd = " << conec1.getCwnd()
         << ", ssthresh = " << conec1.getSsthresh() << endl;

    cout << "New Reno : cwnd = " << conec2.getCwnd()
         << ", ssthresh = " << conec2.getSsthresh() << endl;

    cout << "BBR : cwnd = " << conec3.getCwnd()
         << ", ssthresh = " << conec3.getSsthresh() << endl;

    cout << endl
         << endl;

    time_t start1, end1, start2, end2, start3, end3;

    time(&start1);
    testReno();
    time(&end1);
    double time_taken1 = double(end1 - start1);

    cout << "Reno : time taken = " << fixed << time_taken1 << setprecision(5) << endl;

    time(&start2);
    testNewReno();
    time(&end2);
    double time_taken2 = double(end2 - start2);

    cout << "New Reno : time taken = " << fixed << time_taken2 << setprecision(5) << endl;

    time(&start3);
    testBBR();
    time(&end3);
    double time_taken3 = double(end3 - start3);

    cout << "BBR : time taken = " << fixed << time_taken3 << setprecision(5) << endl;
}