var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem14201'; // fill in your serial port name here
var inData; // for incoming serial data
var outByte = 0; // for outgoing data

function setup() {
    createCanvas(500, 500);
    serial = new p5.SerialPort(); // make a new instance of the serialport library
    serial.on();
    // serial.on('data', serialEvent); // callback for when new data arrives
    serial.on('error', serialError); // callback for errors
    serial.open(portName); // open a serial port
}

function draw() {

    clear();

    textSize(32);
    fill(0, 102, 153);
    text("praesidio v. 1", 10, 100);

    fill(0);
    textSize(20);
    text("Press H to set lights to", 10, 220);
    text("Press L to set lights to", 10, 260);


    noStroke();
    fill(255, 0, 0);
    rect(220, 200, 55, 30);
    fill(255, 153, 204);
    rect(220, 240, 55, 30);


}

// function serialEvent() {
// var inByte = serial.read();   // read a byte from the serial port:
// inData = inByte;   // store it in a global variable:
// }

function keyPressed() {
    if (key === 'h' || key === 'l') { // if the user presses H or L
        serial.write(key); // send it out the serial port
        print(key);

    }

}

// function mouseDragged() {
//  outByte = int(map(mouseY, 0, height, 0, 255));  // map the mouseY to a range from 0 to 255:
//  serial.write(outByte);  // send it out the serial port:
// }

function serialError(err) {
    print('Something went wrong with the serial port. ' + err);
}
