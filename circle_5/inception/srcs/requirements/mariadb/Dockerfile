FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/setup_mariadb.sh /tmp/mariadb_setup.sh

ENTRYPOINT ["sh", "/tmp/mariadb_setup.sh"]

EXPOSE 3306