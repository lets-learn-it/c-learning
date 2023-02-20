FROM bitnami/openresty:1.21.4-1-debian-11-r89

USER root

# RUN apt update && apt install libcurl4-openssl-dev luarocks -y

COPY libs/* /usr/local/share/lua/5.1/resty/

USER 1001

COPY conf/nginx.conf /opt/bitnami/openresty/nginx/conf/nginx.conf