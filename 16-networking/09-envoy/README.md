# Envoy

## Introduction

- Envoy is an L3/L4 network proxy. A pluggable filter chain mechanism allows filters to be written to perform different TCP/UDP proxy tasks.
- Envoy suppports an additional HTTP L7 filter layer. HTTP filters can be plugged into HTTP connection management subsystem that perform different tasks such as buffering, rate limiting, routing/forwarding etc.

### Terminology

- **Host**: Client/Server
- **Downstream**: host connects to envoy, sends requests & receives response (Client)
- **Upstream**: host receives connections & requests from envoy (Server)
- **Listener**: named network location (eg. port, unix domain socket etc) that can be connected to by downstream clients. envoy exposes this.
- **Cluster**: group of logically similar upstream hosts that envoy connects to.
- **Endpoint**: part of cluster. can be IP, dns etc
- **Filters**: piece of code, hooks in envoy & manipulate request/response.

## Listeners

- envoy supports any number of TCP/UDP listeners.

```sh
docker run --rm -it -v $(pwd)/00_simple_tcp.yaml:/00_simple_tcp.yaml --network host envoyproxy/envoy:tools-dev -c /00_simple_tcp.yaml -l debug
```

## References

[[00] Envoy Documentation - envoyproxy.io](https://www.envoyproxy.io/docs/envoy/latest/)

[[01] Envoy Exampls - github.com](https://github.com/envoyproxy/envoy/tree/main/examples)

