FROM debian:buster

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get -y install \
	mariadb-client \
	wget \
	curl \
	tar \
	php7.3-fpm \
	php-cli \
	php-mysql \
	vim \
	sudo

COPY	./tools/setup_wordpress.sh /tmp/
COPY	./conf/wp-config.php /tmp/

RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar xzvf latest.tar.gz

ENTRYPOINT ["sh", "/tmp/setup_wordpress.sh"]

EXPOSE	9000
