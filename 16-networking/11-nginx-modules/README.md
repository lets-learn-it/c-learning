# Nginx Modules

## Nginx Contexts

- `main`: directives apply to everything
- `server`: directives apply to particular host/port
- `upstream`: refers to set of backend servers
- `location`: directives apply to only matching web locations i.e. `/`, `/images`

>**Notes**: 
>- `location` context inherits from surrounding `server` context, & `server` context inherits from `main` context. <br>
>- `upstream` context neither inherits nor imparts its properties. It has its own special directives.

## Installing Module

`--add-module=<path>` will be used to build module into nginx


```sh
# get source
git clone --depth 1 -b release-1.22.1 git@github.com:nginx/nginx.git

# install dependencies
apt install build-essential libpcre3 libpcre3-dev zlib1g zlib1g-dev libssl-dev

./auto/configure --sbin-path=/usr/bin/nginx --conf-path=/etc/nginx/nginx.conf --error-log-path=/var/log/nginx/error.log --http-log-path=/var/log/nginx/access.log --with-pcre --pid-path=/var/run/nginx.pid --with-openssl=/usr/local/src/openssl/ --with-http_ssl_module --add-module=/home/parikshit/github/c-learning/01-hello-world

make

make install

# start nginx
nginx

# restart nginx
nginx -s reload
```

## References

[[01] https://www.evanmiller.org/nginx-modules-guide.html](https://www.evanmiller.org/nginx-modules-guide.html)

[[02] https://www.evanmiller.org/nginx-modules-guide-advanced.html](https://www.evanmiller.org/nginx-modules-guide-advanced.html)

[[03] https://openresty.org/download/agentzh-nginx-tutorials-en.html](https://openresty.org/download/agentzh-nginx-tutorials-en.html)

[[04] https://github.com/mcjffld/nginx-dev-examples](https://github.com/mcjffld/nginx-dev-examples)
