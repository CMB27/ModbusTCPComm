# ModbusTCPComm
This library provides some core functions for implementing Modbus TCP communication.
It is not a full implementation of Modbus TCP.

> [!NOTE]
> At present this library should be considered to be in Beta.
> It may contain bugs and documentation may be incomplete.
> If you encounter issues, please report them [here](https://github.com/CMB27/ModbusTCPComm/issues).
> This will help me know what to focus on in improving and developing this library.
>
> Thanks,
>
> C. M. Bulliner

## Methods


<details><summary id="readadu"><strong>readAdu()</strong></summary>
  <blockquote>

### Description
Reads data to a `ModbusADU` object from a `Client`.

### Syntax
- `ModbusTCPComm.readAdu(client, adu)`

### Parameters
- `client`: a `Client` object.
- `adu`: a `ModbusADU` object.

### Returns
Error code. Data type: `ModbusTCPCommError` or `uint8_t`.
- `0`: Success
- `1`: No data avialable
- `2`: Protocol error
- `3`: Length error

### Example
```C++
ModbusADU adu;
uint8_t error = ModbusTCPComm.readAdu(client, adu);
```

  </blockquote>
</details>



<details><summary id="writeadu"><strong>writeAdu()</strong></summary>
  <blockquote>

### Description
Writes data from a `ModbusADU` object to a `Client`.

### Syntax
- `rtuComm.writeAdu(client, adu)`

### Parameters
- `client`: a `Client` object.
- `adu`: a `ModbusADU` object.

### Returns
Nothing

### Example
```C++
ModbusADU adu;
adu.setUnitId(1);
adu.setFunctionCode(1);
adu.setDataRegister(0, 0);
adu.setDataRegister(2, 2);
adu.setDataLen(4);
bool success = rtuComm.writeAdu(client, adu);
```

  </blockquote>
</details>
