FROM ubuntu:latest

RUN apt-get update && apt-get install -y python-pip python-dev
RUN pip install Flask

ADD --chown=root ./app/main.py /main.py
ADD --chown=root ./app/flag.txt /flag.txt
ADD --chown=root ./app/templates /templates

WORKDIR /

ENTRYPOINT [ "python" ]

CMD [ "main.py" ]

