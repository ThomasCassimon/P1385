#!/bin/sh

# Dockerhub username, so the images get pushed to your account
DOCKERHUB_USERNAME=thomascassimon

# Build clang container
cd clang || exit
docker build -t ${DOCKERHUB_USERNAME}/cmake-clang .

# Build gcc container
cd ../gcc || exit
docker build -t ${DOCKERHUB_USERNAME}/cmake-gcc .

# Build final images
cd ..
docker build -t ${DOCKERHUB_USERNAME}/p1385-clang --build-arg base_img=${DOCKERHUB_USERNAME}/cmake-clang .
docker build -t ${DOCKERHUB_USERNAME}/p1385-gcc --build-arg base_img=${DOCKERHUB_USERNAME}/cmake-gcc .