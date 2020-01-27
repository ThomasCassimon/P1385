#!/bin/sh

# Dockerhub username, so the images get pushed to your account
DOCKERHUB_USERNAME=thomascassimon

docker push ${DOCKERHUB_USERNAME}/p1385-clang
docker push ${DOCKERHUB_USERNAME}/p1385-gcc