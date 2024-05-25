

FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get clean && \
    apt-get autoclean
#依赖文件
RUN apt update && \
    apt install -y \
    vim \
    htop \
    apt-utils \
    curl \
    cmake \
    net-tools \
    gdb  gcc g++ \
    libgoogle-glog-dev
#跳转工作目录
WORKDIR /work
 

