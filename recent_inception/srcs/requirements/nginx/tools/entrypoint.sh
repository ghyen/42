#!/bin/bash
echo start setting nginx

openssl	req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout /etc/ssl/private/server_pkey.pem \
		-out /etc/ssl/certs/server.crt \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=./CN=gkwon.42.fr/emailAddress=gkwon@student.42seoul.kr"
#yes | cp var/www/html/default /etc/nginx/sites-available/default

echo finish setting nginx
exec "$@"