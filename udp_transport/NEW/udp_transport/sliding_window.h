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
        //最新的收到但还未确认的序列号
        int last_acked_packet_;
        // 成功发送且已经确认的数据包中最新的序列号
        int send_base_;
        int dup_ack_;

    };
}