#include <iostream>
#include <cstdlib>
#include <string>
#include <glog/logging.h>

#include "udp_server_study.h"

using namespace std;
int main(int argc, char *argv[])
{
    int sfd = 0;
    int port_num;
    int recv_window;
    char *message_recv;
    google::InitGoogleLogging(argv[0]);
    FLAGS_logtostderr = true;
    FLAGS_minloglevel = google::GLOG_INFO;


    if(argv[1] != NULL) {
        port_num = atoi(argv[1]);
    }

    if(argv[2] != NULL) {
        recv_window = atoi(argv[2]);
    }

    safe_udp::UDPServer *udp_server = new safe_udp::Udpserver();
    udp_server->rwnd_ = recv_window;
    sfd = udp_server _> StartServer(port_num);

}



