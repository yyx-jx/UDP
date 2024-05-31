

class UdpServer{
    public:
        char *GetRequest(int client_sockfd);
        bool OpenFIle(const std::string &file_name);

}