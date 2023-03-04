# RPC

- Remote Procedure Call
- 

## Serialization & De-serialization

- **Serialization** is mechanism to transform program's internal data structure into a form that could be sent to remote machine over the network
- **De-serialization** is a mechanism to transform the serialized data and convert or reconstruct the internal data structure.
- Data serialization & deserialization helps in making data exchange between processes running on heterogeneous machines independent of underlying OS, compilers, programming language, hardware etc.

## Why we need data serialization & deserialization

Due to varying below points of 2 machines
- Hardware architecture: 32 bit/ 64 bit
- Software version / different compiler: size of int (32/64 bit)
- Endianness: little/big endian

**Solution**:
- Sending machine needs to encode data in standard pre defined format (serialization)
- Receiving machine should decode data as per same standard format (deserialization)
- Eg. machines will use 32 bit int. 64 bit machines also encode integer in 32 bit.

## References

[[00] https://www.udemy.com/course/linuxrpc/](https://www.udemy.com/course/linuxrpc/)
