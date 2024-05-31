#include "data_segment_study.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>


namespace safe_udp{
    DataSegment::DataSegment() {
        ack_number_ = -1;
        seq_number_ = -1;
        data_length_ = -1;
    }

    //序列化
    char *DataSegment::SerializeToCHarArray() {
        if(final_packet_ != NULL) {
            memset(final_packet_, 0, MAX_PACKET_SIZE);
        }
        else {
            //重新定义final_packet_
            reinterpret_cast<char *>(calloc(MAX_PACKET_SIZE, sizeof(char)));
            if(final_packet_ == nullptr) {
                return nullptr;
            }
        }

        memcpy(final_packet_, &seq_number_, sizeof(seq_number_) );
        memcpy(final_packet_ + 4, &ack_number_, sizeof(ack_number_) );
        memcpy(final_packet_ + 8, &ack_flag_, 1);
        memcpy(final_packet_ + 9, &fin_flag_, 1);
        memcmp(final_packet_ + 10, &data_length_, sizeof(data_length_) );
        memcmp(final_packet_ + 12, data_, data_length_);
        return final_packet_;
    }

    void DataSegment::DeserializeToDataSegment(unsigned char *data_segment, int length)
    {
        seq_number_ = convert_to_uint32(data_segment, 0);
        ack_number_ = convert_to_uint32(data_segment, 4);
        ack_flag_ = convert_to_bool(data_segment, 8); //为什么flag是由data_segment得来的呢？
        fin_flag_ = convert_to_bool(data_segment, 9);
        data_length_ = convert_to_uint16(data_segment, 10);

        data_ = reinterpret_cast<char *>(calloc(length + 1, sizeof(char)));
        if(data_ == nullptr) {
            return ;
        }
        memcpy(data_, data_segment + HEADER_LENGTH, length);
        *(data + length) = '\0';
    }
}