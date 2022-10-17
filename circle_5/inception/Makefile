NAME = inception

UNAME	:= $(shell uname -s)

ifeq ($(UNAME),Darwin)	#macOS
	DB_PATH		:= /Users/jaemoojung/Desktop/42/42SEOUL/circle_5/inception/data
	HOST_LINK	:= 
else					#Linux
	DB_PATH		:= /home/jaemjung/data
	HOST_LINK	:= "127.0.0.1	jaemjung.42.fr" > /etc/hosts
endif
# TODO: make 시 호스트 파일에 도메인 링크 안 되어있으면 추가하기

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	mkdir -p $(DB_PATH)/mariadb/
	mkdir -p $(DB_PATH)/wordpress/
	docker-compose -f ./srcs/docker-compose.yml up --build -d 

clean:
	docker-compose -f ./srcs/docker-compose.yml down --rmi "all" --volumes

fclean: clean
	rm -rf $(DB_PATH)

re: fclean all