#!/bin/bash

if [ -z "$NGINX_SOURCE_DIR" ]; then
	echo "NGINX_SOURCE_DIR not set"
	exit 1
fi

if [ -z "$NGINX_VOD_MODULE_SOURCE_DIR" ]; then
	echo "NGINX_VOD_MODULE_SOURCE_DIR not set"
	exit 1
fi

cc -Wall -g -obitset_test -DNGX_HAVE_LIB_AV_CODEC=0 \
	$NGINX_VOD_MODULE_SOURCE_DIR/vod/common.c \
	$NGINX_VOD_MODULE_SOURCE_DIR/test/bitset/main.c \
	-I $NGINX_SOURCE_DIR/src/core \
	-I $NGINX_SOURCE_DIR/src/event \
	-I $NGINX_SOURCE_DIR/src/event/modules \
	-I $NGINX_SOURCE_DIR/src/os/unix \
	-I $NGINX_SOURCE_DIR/objs \
	-I $NGINX_VOD_MODULE_SOURCE_DIR
