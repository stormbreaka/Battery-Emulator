#include "advanced_battery_html.h"
#include <Arduino.h>
#include <vector>
#include "../../battery/BATTERIES.h"
#include "../../datalayer/datalayer.h"
#include "../../datalayer/datalayer_extended.h"

// Available generic battery commands that are taken into use based on what the selected battery supports.
std::vector<BatteryCommand> battery_commands = {
    {"clearIsolation", "Clear isolation fault", "clear any active isolation fault?",
     [](Battery* b) { return b && b->supports_clear_isolation(); },
     [](Battery* b) {
       b->clear_isolation();
     }},
    {"chademoRestart", "Restart", "restart the V2X session?",
     [](Battery* b) { return b && b->supports_chademo_restart(); },
     [](Battery* b) {
       b->chademo_restart();
     }},
    {"chademoStop", "Stop", "stop V2X?", [](Battery* b) { return b && b->supports_chademo_restart(); },
     [](Battery* b) {
       b->chademo_restart();
     }},
    {"resetBMS", "BMS reset", "reset the BMS?", [](Battery* b) { return b && b->supports_reset_BMS(); },
     [](Battery* b) {
       b->reset_BMS();
     }},
    {"resetCrash", "Unlock crashed BMS",
     "reset crash data? Note this will unlock your BMS and enable contactor closing and SOC calculation.",
     [](Battery* b) { return b && b->supports_reset_crash(); },
     [](Battery* b) {
       b->reset_crash();
     }},
    {"resetNVROL", "Perform NVROL reset",
     "trigger an NVROL reset? Battery will be unavailable for 30 seconds while this is active!",
     [](Battery* b) { return b && b->supports_reset_NVROL(); },
     [](Battery* b) {
       b->reset_NVROL();
     }},
    {"resetContactor", "Perform contactor reset", "reset contactors?",
     [](Battery* b) { return b && b->supports_contactor_reset(); },
     [](Battery* b) {
       b->reset_contactor();
     }},
    {"resetDTC", "Erase DTC", "erase DTCs?", [](Battery* b) { return b && b->supports_reset_DTC(); },
     [](Battery* b) {
       b->reset_DTC();
     }},
    {"readDTC", "Read DTC (result must be checked in CANlog)", nullptr,
     [](Battery* b) { return b && b->supports_read_DTC(); },
     [](Battery* b) {
       b->read_DTC();
     }},
    {"resetBECM", "Restart BECM module", "restart BECM??", [](Battery* b) { return b && b->supports_reset_DTC(); },
     [](Battery* b) {
       b->reset_DTC();
     }},
    {"contactorClose", "Close Contactors", "a contactor close request?",
     [](Battery* b) { return b && b->supports_contactor_close(); },
     [](Battery* b) {
       b->request_close_contactors();
     }},
    {"contactorOpen", "Open Contactors", "a contactor open request?",
     [](Battery* b) { return b && b->supports_contactor_close(); },
     [](Battery* b) {
       b->request_open_contactors();
     }},
    {"resetSOH", "Reset degradation data", "reset degradation data?",
     [](Battery* b) { return b && b->supports_reset_SOH(); },
     [](Battery* b) {
       b->reset_SOH();
     }},
    {"setFactoryMode", "Set Factory Mode", "set factory mode and disable isolation measurement?",
     [](Battery* b) { return b && b->supports_factory_mode_method(); },
     [](Battery* b) {
       b->set_factory_mode();
     }},
    {"toggleSOC", "Toggle SOC method",
     "toggle SOC method? This will toggle between ESTIMATED and MEASURED SOC methods.",
     [](Battery* b) { return b && b->supports_toggle_SOC_method(); },
     [](Battery* b) {
       b->toggle_SOC_method();
     }},
};

String advanced_battery_processor(const String& var) {
  if (var == "X") {
    String content = "";
    //Page format
    content += "<style>";
    content += "body { background-color: black; color: white; }";
    content +=
        "button { background-color: #505E67; color: white; border: none; padding: 10px 20px; margin-bottom: 20px; "
        "cursor: pointer; border-radius: 10px; }";
    content += "button:hover { background-color: #3A4A52; }";
    content += "h4 { margin: 0.6em 0; line-height: 1.2; }";
    content += "</style>";
    content += "<button onclick='goToMainPage()'>Back to main page</button>";

    // Start a new block with a specific background color
    content += "<div style='background-color: #303E47; padding: 10px; margin-bottom: 10px;border-radius: 50px'>";
    /*#ifdef BATRIUM_BMS
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
    #endif  //BATRIUM_BMS*/
    // Render buttons dynamically based on what commands the battery supports.
    auto render_command_buttons = [&content](Battery* batt, int ix) {
      for (const auto& cmd : battery_commands) {
        if (cmd.condition(batt)) {
          // Button for user action
          content += "<button onclick='ask" + String(cmd.identifier) + "(" + String(ix) + ")'>" + String(cmd.title) +
                     "</button>";

          // Script that calls the backend to perform the command
          content += "<script>";
          content += "function ask" + String(cmd.identifier) + "(batteryNum) { ";

          if (cmd.prompt) {
            content += "if (window.confirm('Are you sure you want to " + String(cmd.prompt) + "'))";
          }

          content += "{" + String(cmd.identifier) + "(batteryNum); } }";
          content += "function " + String(cmd.identifier) + "(batteryNum) {";
          content += "  var xhr = new XMLHttpRequest();";
          content += "  xhr.open('PUT', '/" + String(cmd.identifier) + "', true);";
          // Send index of the battery as PUT content
          content += "  xhr.send(batteryNum);";
          content += "}";
          content += "</script>";
        }
      }
    };

    if (battery) {
      content += battery->get_status_renderer().get_status_html();
      render_command_buttons(battery, 0);
    }

    if (battery2) {
      content += "<h4>Values from battery 2</h4>";
      content += battery2->get_status_renderer().get_status_html();
      render_command_buttons(battery2, 1);
    }

    content += "</div>";

    content += "<script>";
    content += "function exportLog() { window.location.href = '/export_log'; }";
    content += "function goToMainPage() { window.location.href = '/'; }";
    content += "</script>";

    return content;
  }
  return String();
}
