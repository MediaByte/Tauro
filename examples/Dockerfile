FROM node:lts

WORKDIR /usr/src/tauro

COPY ./ ./

RUN apt-get update && apt-get install -y \ 
    gcc \
    g++ \
    make \
    libusb-1.0-0-dev

RUN wget -N https://github.com/mccdaq/uldaq/releases/download/v1.2.0/libuldaq-1.2.0.tar.bz2 && tar -xvjf libuldaq-1.2.0.tar.bz2 && cd libuldaq-1.2.0 && ./configure && make && make install

RUN npm install -g typescript
RUN npm install -g node-gyp
RUN npm install

CMD ["/bin/bash"]