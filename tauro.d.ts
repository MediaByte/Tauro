declare enum Status {
    ERROR = 0,
    READY = 1,
    RUNNING = 2,
    CONFIGURE = 3
}

interface Config {
    rate: number;
    samples_per_channel: number;
    low_channel: number;
    high_channel: number;
    serial: string;
    input_mode: string;
    volts: number;
}

export class Tauro {
    
    public listen(): void;
    public getStatus(): Status;

    constructor(rate: string, samples_per_channel: string, low_channel: string, high_channel: string, serial: string, input_mode: string, volts: string);


}