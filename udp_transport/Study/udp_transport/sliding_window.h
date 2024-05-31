#pragma once

#include <vector>

#include "buffer.h"

namespace safe_udp{
    class SlidingWindow{
        public:
        SlidingWindow();
        ~SlidingWindow();

        int AddToBuffer(const SlidWInBUffer &buffer);

        std::vector<SlidWinBuffer> s_w_buffer_;

        int last_packet_sent;
        int last_acked_packet_;
        // 第一个未确认的数据包的指针
        int send_base_;
        int dup_ack_;

    };
}