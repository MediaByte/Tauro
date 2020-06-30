"use strict";
exports.__esModule = true;
var tauro_1 = require("../build/Release/tauro");
function main() {
    var settings = {
        rate: 2500,
        samples_per_channel: 1,
        low_channel: 0,
        high_channel: 7,
        serial: "01DCF261",
        input_mode: "DIFFERENTIAL",
        volts: 10
    };
    var device = new tauro_1.Tauro(settings);
    console.log(device);
}
main();
