#ifndef BATRIUM_BMS_H
#define BATRIUM_BMS_H
#include <Arduino.h>
//#include "../include.h"
#include "BATRIUM-HTML.h"
#include "CanBattery.h"

#ifdef BATRIUM_BMS
#define SELECTED_BATTERY_CLASS BatriumBms
#endif

class BatriumBms : public CanBattery {
 public:
  //BatriumBms() : CanBattery(true) {}
  virtual void setup(void);
  virtual void handle_incoming_can_frame(CAN_frame rx_frame);
  virtual void update_values();
  virtual void transmit_can(unsigned long currentMillis);

  static constexpr const char* Name = "DIY battery with Batrium BMS";

  BatteryHtmlRenderer& get_status_renderer() { return renderer; }
 private:
  BatriumHtmlRenderer renderer;
  /* Change the following to suit your battery */
  /* Tweak these according to your battery build and Batrium settings */

  static const int NUMBER_OF_CELLS = 80;
  static const int MAX_PACK_VOLTAGE_DV = 2880;  //5000 = 500.0V
  static const int MIN_PACK_VOLTAGE_DV = 2160;
  static const int MAX_CELL_VOLTAGE_MV = 3600;  //Battery is put into emergency stop if one cell goes over this value
  static const int MIN_CELL_VOLTAGE_MV = 2700;  //Battery is put into emergency stop if one cell goes below this value
  static const int MAX_CELL_DEVIATION_MV = 200;

uint16_t Hardware_Version = 0;
uint16_t Firmware_Version = 0;
uint32_t Device_Serial_NO = 0;
uint16_t min_cell_voltage = 3700;
uint16_t max_cell_voltage = 3700;
uint16_t avg_cell_voltage = 0;
uint8_t min_voltage_cell_no = 0;
uint8_t max_voltage_cell_no = 0;
uint8_t min_cell_temperature = 0;
uint8_t max_cell_temperature = 0;
uint8_t avg_cell_temperature = 0;
uint8_t min_temp_cell_no = 0;
uint8_t max_temp_cell_no = 0;
uint8_t number_in_bypass = 0;
uint8_t number_in_initial_bypass = 0;
uint8_t number_in_final_bypass = 0;
int16_t shunt_voltage = MIN_PACK_VOLTAGE_DV + 1;
int16_t shunt_amperes = 0;
int16_t shunt_power = 0;
int16_t state_of_charge = 0;
uint16_t state_of_health = 9900;
uint16_t remaining_ah = 0;
uint16_t nominal_capacity_ah = 0;
uint16_t charge_target_voltage = 0;
uint16_t charge_target_amp = 0;
uint16_t discharge_target_voltage = 0;
uint16_t discharge_target_amp = 0;
uint8_t critical_control_flags = 0;
uint8_t charge_control_flags = 0;
uint8_t discharge_control_flags = 0;
uint8_t heat_control_flags = 0;
uint8_t cool_control_flags = 0;
uint8_t cell_balancing_flags = 0;

};

#endif
