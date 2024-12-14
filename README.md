# ModbusTCPComm
This library provides some core functions for implementing Modbus TCP communication.
It is not a full implementation of Modbus TCP.

<!--
Other libraries are available for that purpose: see [ModbusTCPSlave](https://github.com/CMB27/ModbusTCPSlave) and [ModbusTCPMaster](https://github.com/CMB27/ModbusTCPMaster).
-->

<!--
## Compatibility
This library has been tested with the following boards and cores:

| Board Name                  | Core                                                                 | Works   |
| :-------------------------- | :------------------------------------------------------------------- | :-----: |
| Arduino Due                 | **Arduino SAM Boards (32-bits ARM Cortex-M3)** by Arduino `1.6.12`   | Yes     |
| Arduino Giga                | **Arduino Mbed OS GIGA Boards** by Arduino `4.1.5`                   | Yes     |
| Arduino Leonardo            | **Arduino AVR Boards** by Arduino `1.8.6`                            | Yes     |
| Arduino Make Your UNO       | **Arduino AVR Boards** by Arduino `1.8.6`                            | Yes     |
| Arduino Mega 2560           | **Arduino AVR Boards** by Arduino `1.8.6`                            | Yes     |
| Arduino Nano                | **Arduino AVR Boards** by Arduino `1.8.6`                            | Yes     |
| Arduino Nano 33 BLE         | **Arduino Mbed OS Nano Boards** by Arduino `4.1.5`                   | Yes     |
| Arduino Nano 33 IoT         | **Arduino SAMD Boards (32-bits ARM Cortex-M0+)** by Arduino `1.8.14` | Yes     |
| Arduino Nano ESP32          | **Arduino ESP32 Boards** by Arduino `2.0.13`                         | Yes     |
| Arduino Nano ESP32          | **esp32** by Espressif Systems `3.0.4`                               | Yes     |
| Arduino Nano Every          | **Arduino megaAVR Boards** by Arduino `1.8.8`                        | Yes     |
| Arduino Nano Matter         | **Silicon Labs** by Silicon Labs `2.1.0`                             | No [^1] |
| Arduino Nano RP2040 Connect | **Arduino Mbed OS Nano Boards** by Arduino `4.1.5`                   | No [^2] |
| Arduino Nano RP2040 Connect | **Raspberry Pi Pico/RP2040** by Earle F. Philhower, III `4.0.1`      | Yes     |
| Arduino UNO R3 SMD          | **Arduino AVR Boards** by Arduino `1.8.6`                            | Yes     |
| Arduino UNO R4 Minima       | **Arduino UNO R4 Boards** by Arduino `1.2.0`                         | Yes     |

[^1]: **Arduino Nano RP2040 Connect**  
This board has trouble receiving Modbus messages when using the **Arduino Mbed OS Nano Boards** core by Arduino.  
There seems to be some sort of timing issue.  
It can technically be made to work if you tell the library that it is operating at a lower baud rate than the serial port assigned to the library is actually operating at.
However, this would cause the library to operate with unknown timing tolerances, possibly well outside the Modbus specification.

[^2]: **Arduino Nano Matter**  
As of this writing (2024-09-07), `flush()` is not properly implemented with `Serial1` on this board.  
This library depends on `flush()` to know when to set the DE pin LOW after a message is sent.
-->


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


---

