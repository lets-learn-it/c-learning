# Hello World

```sh
# running hello world
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf

# stop
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf -s stop

# restart
/usr/local/openresty/nginx/sbin/nginx -p `pwd`/ -c conf/nginx.conf -s reload
```

`content_by_lua_block` directive is used to execute Lua code during the content generation phase of the request-response cycle, after the response headers have been sent. This allows you to generate the response body dynamically, based on the request and other factors.

