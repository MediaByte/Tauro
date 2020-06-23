import { Daq } from '../build/Release/mccdaq';

function main() {
    const serial_number : string = 'L823763672';

    const settings = {
        high_channel: 16,
        low_channel: 1,
        sampleRate: 5000,
        samplesPerSecond: 1
    };

    const device : Daq = new Daq(serial_number);

    device.initialize(settings);

    device.listen();

    device.on('event', handle_event);
}

function handle_event(sensor_name : string, data : object) {
    console.log(sensor_name);
    console.log(data);
}

main();