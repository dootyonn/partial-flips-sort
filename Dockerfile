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
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build . --config Release
RUN cmake --install . 

ENTRYPOINT [ "/usr/local/bin/quizsort" ]