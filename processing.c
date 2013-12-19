import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
int a,b;
int x,y;

void setup() 
{
  size(400, 400);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if(myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
    if(val == 255) {
      x = myPort.read();
      y = myPort.read();
      if( y>=3 && y<=8) {
        y = 10-y;
      }
      print(x);
      print(' ');
      println(y);
    }  
  }
  
  for(a=0; a<=8; a++) {
     for(b=0; b<=8; b++){
       if(a==x && b==y) {
         fill(0);
       } else {
         fill(255);
       }
       
       ellipse(a*50+25, b*50+25, 20, 20);
     }
  }
  
  
}
