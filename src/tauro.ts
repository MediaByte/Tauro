import * as DaqDevice from '../build/Release/mccdaq';

function main() {
    const serial_number : string = 'L823763672';
    const configuration = {
        high_channel: 16,
        low_channel: 1,
        rate: 5000,
        samples_per_channel: 1
    };
    const Daq: DaqDevice = new DaqDevice(serial_number);

    Daq.initialize(configuration);

    Daq.on('event', handle_event);
}

function handle_event(sensor_name: string, data: object) {
    console.log(sensor_name);
    console.log(data);
}

main();