FROM debian:bullseye

RUN apt-get -y update && \
	apt-get -y upgrade && \
	apt-get -y install nginx openssl vim

COPY ./tools/entrypoint.sh /entrypoint.sh
COPY ./conf/default /etc/nginx/sites-available/default
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]