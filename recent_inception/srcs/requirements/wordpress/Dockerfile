FROM debian:11

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
RUN mkdir -p /run/php
ENTRYPOINT ["/entrypoint.sh"]
CMD ["php-fpm7.4", "-F"]