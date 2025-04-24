FROM alpine:3.21.3 AS build

RUN apk --no-cache add \
		build-base \
		linux-headers \
		zlib-dev \
		pcre2-dev \
		ffmpeg-dev \
		fdk-aac-dev \
		openssl-dev \
	&& mkdir /nginx \
	&& wget -qO- https://nginx.org/download/nginx-1.27.5.tar.gz | tar -xz --strip-components 1 -C /nginx

COPY . /nginx-vod-module

WORKDIR /nginx

RUN /nginx-vod-module/scripts/build_basic.sh \
		--without-http_charset_module \
		--without-http_ssi_module \
		--without-http_userid_module \
		--without-http_auth_basic_module \
		--without-http_mirror_module \
		--without-http_autoindex_module \
		--without-http_geo_module \
		--without-http_map_module \
		--without-http_split_clients_module \
		--without-http_referer_module \
		--without-http_fastcgi_module \
		--without-http_uwsgi_module \
		--without-http_scgi_module \
		--without-http_grpc_module \
		--without-http_memcached_module \
		--without-http_limit_conn_module \
		--without-http_limit_req_module \
		--without-http_empty_gif_module \
		--without-http_browser_module \
		--without-http_upstream_hash_module \
		--without-http_upstream_ip_hash_module \
		--without-http_upstream_random_module \
		--with-debug \
		--with-http_stub_status_module \
		--add-module=/nginx-vod-module \
		--with-cc-opt='-O0' \
	&& make -j $(nproc) \
	&& make install

FROM alpine:3.21.3

LABEL maintainer="Diogo Azevedo <diogoazevedos@gmail.com>"

RUN apk --no-cache add \
		zlib \
		pcre2 \
		ffmpeg \
		fdk-aac \
		openssl \
		ca-certificates \
	&& mkdir /var/spool/nginx

COPY --from=build /opt/nginx /opt/nginx
COPY sample/nginx.conf sample/cache.conf sample/proxy.conf /opt/nginx/conf/
COPY static/* /opt/nginx/html/

EXPOSE 80

ENTRYPOINT ["/opt/nginx/sbin/nginx"]

CMD ["-g", "daemon off;"]
