#!/bin/bash

set -eu 

sudo service mariadb start

tail -f

mysql -e "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;"
mysql -e "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';"
mysql -e "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

echo "Database setup completed."

sudo service mariadb stop

exec "$@"