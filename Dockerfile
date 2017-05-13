FROM ubuntu:14.04

RUN apt update -y; apt install -y build-essential git
RUN mkdir /workspace

WORKDIR /workspace
