FROM    debian:bullseye

EXPOSE  3306

RUN     apt-get update && \
        apt-get upgrade && \
        apt-get -y install mariadb-server mariadb-client && \
        mkdir -p /var/run/mysqld && \
        chown mysql:mysql /var/run/mysqld

COPY    ./conf/my.cnf /etc/mysql/
COPY    ./tools/entrypoint.sh /

RUN     chmod +x /entrypoint.sh

ENTRYPOINT sh /entrypoint.sh