#!/bin/sh

./configure \
	--prefix=/opt/nginx --pid-path=/var/run/nginx.pid --lock-path=/var/run/nginx.lock \
	--error-log-path=/dev/stderr \
	--http-log-path=/dev/stdout \
	--with-threads \
	--with-file-aio \
	--http-client-body-temp-path=/var/spool/nginx/client_body \
	--http-proxy-temp-path=/var/spool/nginx/proxy \
	--http-fastcgi-temp-path=/var/spool/nginx/fastcgi \
	--http-uwsgi-temp-path=/var/spool/nginx/uwsgi \
	--http-scgi-temp-path=/var/spool/nginx/scgi \
	--with-http_ssl_module \
	"$@"

make -j $(nproc)
