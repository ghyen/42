FROM debian:11

WORKDIR /etc/mysql
RUN apt-get -y update
RUN	apt-get -y upgrade
RUN	apt-get -y install \
	mariadb-server

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
CMD ["mysqld"]
ENTRYPOINT ["/entrypoint.sh"]
