FROM ubuntu

# C'est de la merde, I use arch btw
WORKDIR push_swap

RUN apt update && apt -y install gcc make bash vim

COPY . .

RUN ["/bin/bash"]