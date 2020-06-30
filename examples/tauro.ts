import { Tauro } from '../build/Release/tauro';

function main() {

    const settings = {
        rate: 2500,
        samples_per_channel: 1,
        low_channel: 0,
        high_channel: 7,
        serial: "01DCF261",
        input_mode: "DIFFERENTIAL",
        volts: 10,
    };

    const device : Tauro = new Tauro(settings);

    console.log(device);
}

main();