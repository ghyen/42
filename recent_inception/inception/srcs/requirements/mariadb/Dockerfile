FROM debian:11

WORKDIR /app

RUN apt-get update -y && \
    apt-get install -y mariadb-server sudo && \
    apt-get upgrade -y

RUN mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql && \
    chmod -R 750 /var/lib/mysql

COPY ./tool/init.sh .
# COPY ./conf/mariadb.cnf /etc/mysql/mariadb.cnf
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/.

EXPOSE 3306

RUN chmod +x ./init.sh
RUN chmod +x /etc/mysql/mariadb.cnf

ENTRYPOINT ["./init.sh"]