#!/bin/sh

ALPINE_VERSION=3.11.3

CLANG_VERSION=9.0.0-r1
CMAKE_VERSION=3.15.5-r0
GCC_VERSION=9.2.0-r3

# Dockerhub username, so the images get pushed to your account
DOCKERHUB_USERNAME=thomascassimon

# Build clang container
cd clang || exit
docker build										\
	-t ${DOCKERHUB_USERNAME}/cmake-clang			\
	--build-arg ALPINE_VERSION=${ALPINE_VERSION}	\
	--build-arg CLANG_VERSION=${CLANG_VERSION}		\
	--build-arg CMAKE_VERSION=${CMAKE_VERSION}		\
	--build-arg GCC_VERSION=${GCC_VERSION}			\
	.

# Build gcc container
cd ../gcc || exit
docker build										\
	-t ${DOCKERHUB_USERNAME}/cmake-gcc				\
	--build-arg ALPINE_VERSION=${ALPINE_VERSION}	\
	--build-arg CLANG_VERSION=${CLANG_VERSION}		\
	--build-arg CMAKE_VERSION=${CMAKE_VERSION}		\
	--build-arg GCC_VERSION=${GCC_VERSION}			\
	.

# Build final images
cd ..
docker build												\
	-t ${DOCKERHUB_USERNAME}/p1385-clang					\
	--build-arg base_img=${DOCKERHUB_USERNAME}/cmake-clang	\
	.

docker build												\
	-t ${DOCKERHUB_USERNAME}/p1385-gcc						\
	--build-arg base_img=${DOCKERHUB_USERNAME}/cmake-gcc	\
	.