FROM	debian:11

WORKDIR /app

RUN		apt-get update -y && \
		apt-get install -y mariadb-server sudo && \
		apt-get upgrade -y

COPY	./tool/init.sh .
COPY	./conf/mariadb.cnf /etc/mysql/mariadb.cnf

EXPOSE 3306

RUN chmod +x ./init.sh
RUN chmod +x /etc/mysql/mariadb.cnf
#CMD ["tail", "-f"]
ENTRYPOINT ["./init.sh"]
