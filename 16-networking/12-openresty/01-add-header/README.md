# Add Header

We will add header and pass this request further. This will work as proxy server.

`access_by_lua_block` directive is used to execute Lua code during the access phase of the request-response cycle, before the response headers are sent. This allows you to perform various types of access control, logging, and other operations before the response is generated.
