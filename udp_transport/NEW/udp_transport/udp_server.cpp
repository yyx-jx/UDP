
namespace sfae_udp{

    void UdpServer::calculate_rtt_and_time(struct timeval start_time, struct timeval end_time)
    {
        if(start_time.tv_sec == 0 && start_time.tv_usec == 0){
            return ;
        }
    }
    
}