ARG ALPINE_VERSION

FROM alpine:$ALPINE_VERSION

ARG CMAKE_VERSION
ARG GCC_VERSION

RUN apk update					&&\
	apk add						\
		cmake=$CMAKE_VERSION	\
		make					\
		gcc=$GCC_VERSION		\
		g++=$GCC_VERSION		\
