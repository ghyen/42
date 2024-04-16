sleep 10

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

mkdir -p /run/php

cd /var/www/html

wp core install --allow-root --path=/var/www/html \
								--url=$DOMAIN_NAME \
								--title=Inception \
								--admin_user=$ADMIN_NAME \
								--admin_password=$ADMIN_PWD \
								--admin_email=$ADMIN_EMAIL

wp user create \
							$USER_NAME $USER_EMAIL \
							--allow-root --path=/var/www/html \
							--role=author \
							--user_pass=$USER_PWD

sleep 5
exec  php-fpm7.4 -F