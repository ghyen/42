FROM debian:buster

COPY ./tools/entrypoint.sh /entrypoint.sh
COPY ./conf/nginx.conf /etc/nginx/
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]