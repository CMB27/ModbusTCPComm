#ifndef ModbusTCPComm_h
#define ModbusTCPComm_h

#include "Arduino.h"
#include "Client.h"
#include "ModbusADU.h"

enum ModbusTCPCommError : uint8_t {
  MODBUS_TCP_COMM_SUCCESS = 0,
  MODBUS_TCP_COMM_UNAVAILABLE = 1,
  MODBUS_TCP_COMM_PROTOCOL_ERROR = 2,
  MODBUS_TCP_COMM_LENGTH_ERROR = 3
};


class ModbusTCPCommClass {
  public:
    ModbusTCPCommError readAdu(Client& client, ModbusADU& adu);
    void writeAdu(Client& client, ModbusADU& adu);

};

extern ModbusTCPCommClass ModbusTCPComm;

#endif
