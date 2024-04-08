FROM	debian:11

WORKDIR /app

RUN		apt-get update -y && \
		apt-get upgrade -y && \
		apt-get install -y mariadb-server sudo

COPY	./tool/init.sh .
COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

RUN chmod +x ./init.sh
RUN chmod +x /etc/mysql/mariadb.conf.d/50-server.cnf
#CMD ["tail", "-f"]
ENTRYPOINT ["./init.sh"]
CMD ["mysqld"]