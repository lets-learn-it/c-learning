# Hello World

```sh
# running hello world
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf

# stop
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf -s stop

# restart
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf -s reload
```
