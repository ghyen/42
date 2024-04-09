VOLUME = ./gkwon/data
COMPOSE = ./srcs/docker-compose.yml

all: 
	@mkdir -p $(VOLUME)
	@mkdir -p $(VOLUME)/mariadb
	@mkdir -p $(VOLUME)/wordpress
	docker-compose -f $(COMPOSE) up --build

clean:
	docker-compose -f $(COMPOSE) down


fclean:
	docker-compose -f $(COMPOSE) down --volumes --rmi all
	docker system prune -f -a
	#docker volume rm $$(docker volume ls -q) -f
	@rm -rf ./gkwon

re:
	@make fclean
	make all

.PHONY: all re clean fclean