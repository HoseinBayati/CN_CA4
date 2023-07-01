#include "RenoTCPConnection.hpp"
#include "NewRenoTCPConnection.hpp"
#include "BBRTCPConnection.hpp"

#include <iostream>
#include <chrono>

#define TOTAL_INFO_SIZE 1000000

#include <iostream>

double calculatePacketLossProbability(int cwnd, int cwndThreshold)
{
    double baseLossProbability = 0.01; // Base loss probability (e.g., 1%)

    double lossProbability;

    if (cwnd <= cwndThreshold)
    {
        lossProbability = baseLossProbability * (cwnd / static_cast<double>(cwndThreshold));
    }
    else
    {
        lossProbability = baseLossProbability;
    }

    return lossProbability;
}

void testReno(int init_cwnd, int init_ssthresh)
{
    RenoTCPConnection connection(init_cwnd, init_ssthresh);

    int info_sent = 0;

    while (info_sent < TOTAL_INFO_SIZE)
    {
        double fail_prob = calculatePacketLossProbability(connection.getCwnd(), connection.getSsthresh());
        double random = (double)rand() / RAND_MAX;

        connection.sendData();

        if (random > fail_prob)
        {
            info_sent += connection.getCwnd();
            int old_rtt = connection.getRtt();
            int new_rtt = old_rtt < 50 ? old_rtt + 10 : random > 0.8 ? old_rtt + 10
                                                                     : old_rtt - 10;
            connection.onRTTUpdate(new_rtt);
        }
        else
        {
            connection.onPacketLoss();
        }
    }
}

void testNewReno(int init_cwnd, int init_ssthresh)
{
    NewRenoTCPConnection connection(init_cwnd, init_ssthresh);

    int info_sent = 0;

    while (info_sent < TOTAL_INFO_SIZE)
    {
        double fail_prob = calculatePacketLossProbability(connection.getCwnd(), connection.getSsthresh());
        double random = (double)rand() / RAND_MAX;

        connection.sendData();

        if (random > fail_prob)
        {
            info_sent += connection.getCwnd();
            int old_rtt = connection.getRtt();
            int new_rtt = old_rtt < 50 ? old_rtt + 10 : random > 0.8 ? old_rtt + 10
                                                                     : old_rtt - 10;
            connection.onRTTUpdate(new_rtt);
        }
        else
        {
            connection.onPacketLoss();
        }
    }
}

void testBBR(int init_cwnd, int init_ssthresh, int inflight, int btlbw)
{
    BBRTCPConnection connection(init_cwnd, inflight, btlbw);

    int info_sent = 0;

    while (info_sent < TOTAL_INFO_SIZE)
    {
        double fail_prob = calculatePacketLossProbability(connection.getCwnd(), connection.getSsthresh());
        double random = (double)rand() / RAND_MAX;
        int random2 = rand() % 5;

        connection.sendData(random2);

        if (random > fail_prob)
        {
            info_sent += connection.getCwnd();
            int old_rtt = connection.getRtt();
            int new_rtt = old_rtt < 50 ? old_rtt + 10 : random > 0.8 ? old_rtt + 10
                                                                     : old_rtt - 10;
            connection.onRTTUpdate(new_rtt, random2);
        }
        else
        {
            connection.onPacketLoss();
        }
    }
}

int main()
{
    srand(time(0));

    std::chrono::steady_clock::time_point start_time, end_time;
    double time_taken;

    double base_cwnd = 5, base_ssthresh = 2, base_inflight = 10, base_btlbw = 10;

    int init_cwnd = base_cwnd;
    int init_ssthresh = base_ssthresh;
    int init_inflight = base_inflight;
    int init_btlbw = base_btlbw;

    for (int i = 1; i < 10; i++)
    {
        std::cout << std::endl
                  << std::endl
                  << std::endl
                  << "========================================================"
                  << std::endl
                  << "init_cwnd  = " << init_cwnd << std::endl
                  << "init_ssthresh  = " << init_ssthresh << std::endl
                  << "inflight = " << init_inflight << std::endl
                  << "btlbw = " << init_btlbw << std::endl

                  << std::endl;

        start_time = std::chrono::steady_clock::now();
        testReno(init_cwnd, init_ssthresh);
        end_time = std::chrono::steady_clock::now();
        time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        std::cout << "Reno: Time taken = " << time_taken << " ms" << std::endl;

        // Test New Reno
        start_time = std::chrono::steady_clock::now();
        testNewReno(init_cwnd, init_ssthresh);
        end_time = std::chrono::steady_clock::now();
        time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        std::cout << "New Reno: Time taken = " << time_taken << " ms" << std::endl;

        // Test BBR
        start_time = std::chrono::steady_clock::now();
        testBBR(init_cwnd, init_ssthresh, init_inflight, init_btlbw);
        end_time = std::chrono::steady_clock::now();
        time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() / 1000.0;
        std::cout << "BBR: Time taken = " << time_taken << " ms" << std::endl;

        init_cwnd *= 2;
        init_ssthresh *= 2;
        init_inflight *= 2;
        init_btlbw *= 2;
    }

    return 0;
}
