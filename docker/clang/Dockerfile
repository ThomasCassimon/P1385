FROM alpine:3.11.3

RUN apk update	&&		\
	apk add				\
		musl-dev		\
		cmake=3.15.5-r0	\
		clang=9.0.0-r1	\
		lld=9.0.0-r0	&&\
		export LD=ld.lld