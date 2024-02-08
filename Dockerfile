FROM ubuntu:22.04

RUN apt-get update && apt-get install -y make
RUN apt-get install -y gcc binutils-for-build


RUN mkdir /ft_nm
COPY . /ft_nm

CMD ["cd ft_nm/; make"]

# docker build -t ft_nm .
# docker run -it ft_nm /bin/bash