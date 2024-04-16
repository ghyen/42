#!/bin/bash
chown mysql:mysql /var/run/
mysql_install_db --user=root

echo "CREATE DATABASE IF NOT EXISTS ${WORDPRESS_DB_NAME};
FLUSH PRIVILEGES;
USE ${WORDPRESS_DB_NAME};
CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PWD}';
GRANT ALL PRIVILEGES ON * TO '${MARIADB_USER}'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PWD}';" > sql

mysqld -uroot --bootstrap < sql
mysqld -uroot