FROM debian:11

RUN apt-get -y update && apt-get -y upgrade && apt-get -y install \
	nginx \
	openssl \
	vim

COPY ./tools/entrypoint.sh /entrypoint.sh
COPY ./conf/nginx.conf /etc/nginx	
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]