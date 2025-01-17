FROM ubuntu:24.04

WORKDIR /app

RUN apt-get update && apt-get install -y \
  g++ \
  ninja-build \
  cmake \
  gdb \
  libgtest-dev

COPY * .

RUN mkdir build
WORKDIR /app/build
RUN cmake .. && make

CMD [ "ls", "/app" ]