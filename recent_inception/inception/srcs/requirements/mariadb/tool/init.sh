#!/bin/bash

set -eu
#sudo chown -R 999:999 ./data/mariadb

mysqld --datadir=/var/lib/mysql

#until mysqladmin ping -h localhost -u root -p"$MARIADB_ROOT_PWD" --silent; do
#  echo "Waiting for MySQL to start..."
#  sleep 1
#done

#tail -f
#sudo service mariadb start
#mysqld -uroot


mysql -u root -p"$MARIADB_ROOT_PWD" -e "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;"
mysql -u root -p"$MARIADB_ROOT_PWD" -e "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';"
mysql -u root -p"$MARIADB_ROOT_PWD" -e "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%';"
mysql -u root -p"$MARIADB_ROOT_PWD" -e "FLUSH PRIVILEGES;"

#echo "Database setup completed."

#sudo service mariadb stop

exec "$@"