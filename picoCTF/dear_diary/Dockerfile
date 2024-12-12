# Use the official Kali Linux base image
FROM kalilinux/kali-rolling

# Set the maintainer label
LABEL maintainer="your_email@example.com"

# Update and install necessary packages, including Sleuth Kit and other useful forensics tools
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    sleuthkit \
    fdisk \
    mount \
    gpart \
    qemu-utils \
    # forensic-tools \
    vim \
    git \
    sudo \
    curl \
    wget \
    net-tools \
    nmap \
    ssh \
    && apt-get clean

# Set a working directory
WORKDIR /root

# Expose ports for SSH (optional)
EXPOSE 22

# Make sure the container runs as root for full access to tools
USER root

# Start an interactive shell by default
CMD ["/bin/bash"]
