#pragma once
#include <string>
#include <netinet/in.h>
#include <fstream>
#include <memory>
#include <iostream>

#include "data_segment_study.h"
#include "packet_statistics_study.h"
#include "sliding_window_study.h"

namespace safe_udp{
    class UdpServer{

        public:
            UdpServer();
            ~UdpServer();

            int rwnd_;
            int cwnd_;
            int ssthresh_;
            int start_byte_;
            bool is_slow_start_;
            bool is_cong_avd_;
            bool is_fast_recovery_;

            char *GetRequest(int client_sockfd);
            bool OpenFIle(const std::string &file_name);
            void StartFileTransfer();
            void SendError();
            int StartServer(int port);
            
        private:
            std::unique_ptr<> sliding_window_;
    };
}