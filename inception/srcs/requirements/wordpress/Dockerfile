FROM debian:11

EXPOSE 9000

RUN apt-get update && \
    apt-get upgrade && \
    apt-get -y install php7.4 php-fpm wget php7.4-mysql curl

RUN mkdir -p /var/www /var/www/html
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz && mv /wordpress/* /var/www/html/
RUN chown -R www-data:www-data /var/www/html
RUN rm -r /wordpress latest.tar.gz

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./conf/wp-config.php /var/www/html/
COPY ./tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

ENTRYPOINT [ "sh", "/entrypoint.sh" ]