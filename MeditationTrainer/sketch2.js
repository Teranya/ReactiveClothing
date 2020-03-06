var serial; // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem14301'; // fill in your serial port name here
var inData; // for incoming serial data
var outByte = 0; // for outgoing data
var sensor1;

function setup() {
    createCanvas(500, 500);
    serial = new p5.SerialPort(); // make a new instance of the serialport library
    serial.on();
    // serial.on('data', serialEvent); // callback for when new data arrives
    serial.on('error', serialError); // callback for errors
    serial.open(portName); // open a serial port


    // get a list of all ports
    serial.on('list', gotList);

    serial.on('data', gotData);

    // If code throws error  
    serial.on('error', gotError);

    // When our serial port is opened and ready for read/write
    serial.on('open', gotOpen);
    serial.on('close', gotClose);

}

function gotList(thelist) {
    print("List of Serial Ports:");
    // theList is an array of their names
    for (let i = 0; i < thelist.length; i++) {
        // Display in the console
        print(i + " " + thelist[i]);
    }
}

function gotOpen() {
    print("Serial Port is Open");
}

function gotClose() {
    print("Serial Port is Closed");
    latestData = "Serial Port is Closed";
}

// Log error in console if something crops up
function gotError(theerror) {
    print(theerror);
}


function gotData() {
    //    create a string that reads the entire line of sensor data from Arduino
    var inString = serial.readLine();
    // split the incoming data at every comma 
    if (inString.length > 0) {
        var splitString = split(inString, ',');
        // connecting the varous splits into different variables
        sensor1 = Number(splitString[0]);


    }


}

function gotRawData(thedata) {
    print("gotRawData" + thedata);
}


function draw() {

    clear();

    textSize(32);
    fill(0, 102, 153);
    text("meditation trainer", 10, 100);

    fill(0);
    textSize(20);
    text("Press H to switch to pulse tracking", 10, 220);
    text("Press L to switch to meditation trainer", 10, 260);
    text("Current BPM: " + (sensor1), 10, 300);

    noStroke();
    //    fill(255, 0, 0);
    //    rect(220, 200, 55, 30);
    //    fill(255, 153, 204);
    //    rect(220, 240, 55, 30);


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
