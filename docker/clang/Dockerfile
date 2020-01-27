ARG ALPINE_VERSION

FROM alpine:$ALPINE_VERSION

ARG CLANG_VERSION
ARG CMAKE_VERSION
ARG GCC_VERSION

RUN apk update	&&				\
	apk add						\
		musl-dev				\
		binutils=2.33.1-r0		\
		cmake=$CMAKE_VERSION	\
		make					\
		gcc=$GCC_VERSION		\
		g++=$GCC_VERSION		\
		clang=$CLANG_VERSION