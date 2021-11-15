FROM debian
WORKDIR /root
RUN apt update \
 && apt upgrade -y \
 && apt install -y curl \
 && curl -LO https://github.com/kaitai-io/kaitai_struct_compiler/releases/download/0.9/kaitai-struct-compiler_0.9_all.deb \
 && apt-get install -y ./kaitai-struct-compiler_0.9_all.deb
