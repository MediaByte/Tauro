declare enum Status {
    ERROR,
    READY,
    RUNNING
}

interface Config {
    samplesPerSecond: number,
    sampleRate: number,
    high_channel: number,
    low_channel: number
}

export class Daq {
    
    public status : Status;
    public initialize(options: Config) : Status;
    public on(event : string, cb : (event: string, buffer: object) => void) : void;
    public listen(): void

    constructor(serial : string);

    private options: Config;

}

