FROM ubuntu

RUN apt update && apt -y install gcc make bash

COPY . push_swap

RUN ["/bin/bash"]