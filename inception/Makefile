VOLUME = ./srcs/gkwon
COMPOSE = ./srcs/docker-compose.yml

all:
	@mkdir -p $(VOLUME)/data/mariadb
	@mkdir -p $(VOLUME)/data/wordpress
	docker-compose -f $(COMPOSE) up --build -d

logs:
	docker-compose -f $(COMPOSE) logs


.PHONY:	up
up:
	docker-compose -f $(COMPOSE) up

.PHONY:	down
down:
	docker-compose -f $(COMPOSE) down

.PHONY: clean
clean: down
	docker system prune -f --all # Remove all unused images not just dangling ones

.PHONY: fclean
fclean: clean
	@rm -rf $(VOLUME)
	docker-compose -f $(COMPOSE) down --rmi all
	docker volume rm $$(docker volume ls -f dangling=true -q)

.PHONY: re
re: fclean all
.PHONY: all re clean fclean