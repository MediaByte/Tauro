declare enum Status {
    ERROR,
    READY,
    RUNNING
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
    
    public status : Status;
    public on(event : string, cb : (event: string, buffer: object) => void) : void;
    public listen(): void;

    constructor(settings : Config);

    private options: Config;

}