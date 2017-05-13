FROM ubuntu:16.04

RUN apt update -y; apt install -y build-essential git man
RUN git config --global user.email ulefebvr@student.42.fr
RUN git config --global user.name ulefebvr
RUN mkdir /workspace

WORKDIR /workspace
