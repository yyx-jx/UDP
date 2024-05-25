FROM ubuntu:20.04

run apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    && rm -f /var/lib/apt/lists



