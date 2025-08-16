#ifndef _BATRIUM_HTML_H
#define _BATRIUM_HTML_H

#include "../datalayer/datalayer.h"
#include "../datalayer/datalayer_extended.h"
#include "src/devboard/webserver/BatteryHtmlRenderer.h"

class BatriumHtmlRenderer : public BatteryHtmlRenderer {
 public:
  //BatriumHtmlRenderer(DATALAYER_INFO_Batrium* dl) : datalayer_batrium(dl) {}

  String get_status_html() {
    String content;

content += "<h4>Hardware_Version: " + String(datalayer_extended.batriumBMS.Hardware_Version) + "</h4>";
content += "<h4>Firmware_Version: " + String(datalayer_extended.batriumBMS.Firmware_Version) + "</h4>";
content += "<h4>Device_Serial_NO: " + String(datalayer_extended.batriumBMS.Device_Serial_NO) + "</h4>";
content += "<h4>Min cell voltage: " + String(datalayer_extended.batriumBMS.min_cell_voltage) + "</h4>";
content += "<h4>Max cell voltage: " + String(datalayer_extended.batriumBMS.max_cell_voltage) + "</h4>";
content += "<h4>Avg cell voltage: " + String(datalayer_extended.batriumBMS.avg_cell_voltage) + "</h4>";
content += "<h4>Min cell voltage number: " + String(datalayer_extended.batriumBMS.min_voltage_cell_no) + "</h4>";
content += "<h4>Max cell voltage number: " + String(datalayer_extended.batriumBMS.max_voltage_cell_no) + "</h4>";
content += "<h4>Min cell temperature: " + String(datalayer_extended.batriumBMS.min_cell_temperature) + "</h4>";
content += "<h4>Max cell temperature: " + String(datalayer_extended.batriumBMS.max_cell_temperature) + "</h4>";
content += "<h4>Avg cell temperature: " + String(datalayer_extended.batriumBMS.avg_cell_temperature) + "</h4>";
content += "<h4>Min cell temperature number: " + String(datalayer_extended.batriumBMS.min_temp_cell_no) + "</h4>";
content += "<h4>Max cell temperature number: " + String(datalayer_extended.batriumBMS.max_temp_cell_no) + "</h4>";
content += "<h4>Number in bypass: " + String(datalayer_extended.batriumBMS.number_in_bypass) + "</h4>";
content +=
    "<h4>Number in initial_bypass: " + String(datalayer_extended.batriumBMS.number_in_initial_bypass) + "</h4>";
content += "<h4>Number in final_bypass: " + String(datalayer_extended.batriumBMS.number_in_final_bypass) + "</h4>";
content += "<h4>Shunt voltage: " + String(datalayer_extended.batriumBMS.shunt_voltage) + "</h4>";
content += "<h4>Shunt amperes: " + String(datalayer_extended.batriumBMS.shunt_amperes) + "</h4>";
content += "<h4>Shunt power: " + String(datalayer_extended.batriumBMS.shunt_power) + "</h4>";
content += "<h4>SOC: " + String(datalayer_extended.batriumBMS.state_of_charge) + "</h4>";
content += "<h4>SOH: " + String(datalayer_extended.batriumBMS.state_of_health) + "</h4>";
content += "<h4>Remaining Ah: " + String(datalayer_extended.batriumBMS.remaining_ah) + "</h4>";
content += "<h4>Nominal capacity Ah: " + String(datalayer_extended.batriumBMS.nominal_capacity_ah) + "</h4>";
content += "<h4>Charge target voltage: " + String(datalayer_extended.batriumBMS.charge_target_voltage) + "</h4>";
content += "<h4>Charge target amp: " + String(datalayer_extended.batriumBMS.charge_target_amp) + "</h4>";
content +=
        "<h4>Discharge target voltage: " + String(datalayer_extended.batriumBMS.discharge_target_voltage) + "</h4>";
content += "<h4>Discharge target amp: " + String(datalayer_extended.batriumBMS.discharge_target_amp) + "</h4>";
content += "<h4>Critical control flags: " + String(datalayer_extended.batriumBMS.critical_control_flags) + "</h4>";
content += "<h4>Charge control flags: " + String(datalayer_extended.batriumBMS.charge_control_flags) + "</h4>";
content +=
    "<h4>Discharge control flags: " + String(datalayer_extended.batriumBMS.discharge_control_flags) + "</h4>";
content += "<h4>Heat control flags: " + String(datalayer_extended.batriumBMS.heat_control_flags) + "</h4>";
content += "<h4>Cool control flags: " + String(datalayer_extended.batriumBMS.cool_control_flags) + "</h4>";
content += "<h4>Cell balancing flags: " + String(datalayer_extended.batriumBMS.cell_balancing_flags) + "</h4>";
return content;
  }

 //private:
  //DATALAYER_INFO_Batrium* datalayer_batrium;
};

#endif
