FROM ubuntu:20.04 AS parser_base
ARG DEBIAN_FRONTEND=noninteractive

# Linux packages
RUN rm -rf /var/lib/apt/lists/* && \
        apt-get -y update
		
RUN apt-get install -y --no-install-recommends \
        build-essential \
        gdbserver \
        && \
    apt-get -y autoremove && \
    apt-get -y clean
