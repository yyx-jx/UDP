#pragma one

#include <cstdint>
#include <cstdlib>

namespace safe_udp{
    //constexpr 为C++新特性，修饰常量，提高程序性能
    constexpr int MAX_PACKET_SIZE = 1472;
    constexpr int MAX_DATA_SIZE = 1460;
    constexpr int HEADER_LENGTH = 12;

    class DataSegment {
        public:
        //构造函数 和 析构函数
            DataSegment();
            ~DataSegment() {
                if(final_packet_ != nullptr){
                    free(final_packer_);
                }
            }

        //safe_udp的头文件
        int seq_number_;
        int ack_number_;
        bool ack_flag_;
        bool fin_flag_;
        uint16_t length_;
    }
}

