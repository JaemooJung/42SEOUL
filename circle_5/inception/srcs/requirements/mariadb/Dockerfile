FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y mariadb-server

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./conf/wp_setup.sql ./
COPY ./tools/setup_mariadb.sh /tmp/mariadb_setup.sh

ENTRYPOINT ["sh", "/tmp/mariadb_setup.sh"]

EXPOSE 3306