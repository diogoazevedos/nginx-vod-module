#!/bin/sh

set -eo nounset # Treat unset variables as an error

BASE_URL=https://nginx.org/download
VERSION=`curl -sL $BASE_URL |
   grep -oP 'href="nginx-\K[0-9]+\.[0-9]+\.[0-9]+' |
   sort -t. -rn -k1,1 -k2,2 -k3,3 | head -1`

mkdir -p /tmp/nginx /tmp/nginx-vod-module
curl -s $BASE_URL/nginx-$VERSION.tar.gz | tar -xz --strip-components 1 -C /tmp/nginx
cp -r . /tmp/nginx-vod-module

cd /tmp/nginx

./configure \
        --prefix=/etc/nginx \
        --sbin-path=/sbin/nginx \
        --conf-path=/etc/nginx/nginx.conf \
        --error-log-path=/var/log/log/nginx/error.log \
        --http-log-path=/var/log/log/nginx/access.log \
        --pid-path=/var/log/run/nginx.pid \
        --lock-path=/var/log/run/nginx.lock \
        --http-client-body-temp-path=/var/log/cache/nginx/client_temp \
        --http-proxy-temp-path=/var/log/cache/nginx/proxy_temp \
        --http-fastcgi-temp-path=/var/log/cache/nginx/fastcgi_temp \
        --http-uwsgi-temp-path=/var/log/cache/nginx/uwsgi_temp \
        --http-scgi-temp-path=/var/log/cache/nginx/scgi_temp \
        --with-http_ssl_module \
        --with-http_realip_module \
        --with-http_addition_module \
        --with-http_sub_module \
        --with-http_dav_module \
        --with-http_flv_module \
        --with-http_mp4_module \
        --with-http_gunzip_module \
        --with-http_gzip_static_module \
        --with-http_random_index_module \
        --with-http_secure_link_module \
        --with-http_stub_status_module \
        --with-http_auth_request_module \
        --with-mail \
        --with-mail_ssl_module \
        --with-file-aio \
        --with-debug \
        --with-threads \
	--with-cc-opt="-O3 -mpopcnt" \
        $*

make -j $(nproc)
