FROM alpine:3.11.3

RUN apk update	&&		\
	apk add				\
		musl-dev		\
		clang=9.0.1-r3	\
		lld=9.0.1-r1	&&\
		export LD=ld.lld