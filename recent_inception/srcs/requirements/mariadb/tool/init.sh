#!/bin/bash

set -eu 


#tail -f
sudo service mariadb start
mysqld -uroot

mysql -e "CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;"
mysql -e "CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PWD';"
mysql -e "GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%';"
mysql -e "FLUSH PRIVILEGES;"

#echo "Database setup completed."

#sudo service mariadb stop

exec "$@"