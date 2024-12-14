#include "ModbusTCPComm.h"

ModbusTCPCommError ModbusTCPCommClass::readAdu(Client& client, ModbusADU& adu) {
  adu.setTcpLen(0);
  if (!client.available()) return MODBUS_TCP_COMM_UNAVAILABLE;
  uint16_t len = 0;
  while (client.available()) {
    adu.tcp[len] = client.read();
    len++;
  }
  if (adu.getProtocolId() != 0) {
    adu.setTcpLen(0);
    return MODBUS_TCP_COMM_PROTOCOL_ERROR;
  }
  if (len != adu.getTcpLen()) {
    adu.setTcpLen(0);
    return MODBUS_TCP_COMM_LENGTH_ERROR;
  }
  return MODBUS_TCP_COMM_SUCCESS;
}

void ModbusTCPCommClass::writeAdu(Client& client, ModbusADU& adu) {
  client.write(adu.tcp, adu.getTcpLen());
  client.flush();
}