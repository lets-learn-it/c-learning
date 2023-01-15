# nginx introduction

## Installation

```sh
# get source
git clone --depth 1 -b release-1.22.1 git@github.com:nginx/nginx.git

# install dependencies
apt install build-essential libpcre3 libpcre3-dev zlib1g zlib1g-dev libssl-dev

./auto/configure --sbin-path=/usr/bin/nginx --conf-path=/etc/nginx/nginx.conf --error-log-path=/var/log/nginx/error.log --http-log-path=/var/log/nginx/access.log --with-pcre --pid-path=/var/run/nginx.pid --with-openssl=/usr/local/src/openssl/ --with-http_ssl_module

make

make install

# start nginx
nginx

# restart nginx
nginx -s reload
```

## References

[[00] https://www.udemy.com/course/nginx-fundamentals/](https://www.udemy.com/course/nginx-fundamentals/)