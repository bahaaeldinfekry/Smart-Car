/*
 * BlueTooth.h
 *
 * Created: 10-Sep-19 10:18:55 AM
 *  Author: al ghazaly
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "IncludeAll.h"

void Bluetooth_Init(void);
void Bluetooth_transmit_byte(UINT8 data_byte);
UINT8 Bluetooth_receive_byte(void);
void Bluetooth_transmit_string(UINT8 *transmit_string);
void Bluetooth_receive_string(UINT8 *receive_string );
UINT8 Bluetooth_at_command_mode_test(void);
UINT8 Bluetooth_get_version(void);
UINT8 Bluetooth_pin_change(UINT8 *new_pin);
UINT8 Bluetooth_device_name_change(UINT8 *device_name);


#endif /* BLUETOOTH_H_ */