FROM ubuntu:latest

RUN apt-get update

ADD --chown=root ./app/pwn300 /pwn300
ADD --chown=root ./app/flag.txt /flag.txt
ADD --chown=root ./app/slot_machine_banner.txt /slot_machine_banner.txt
#ADD --chown=root ./app/libc.so /lib/x86_64-linux-gnu/libc.so.6

WORKDIR /

ENTRYPOINT /pwn300

