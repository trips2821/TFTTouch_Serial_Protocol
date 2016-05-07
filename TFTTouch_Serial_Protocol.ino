#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup()
{
  Serial.begin(115200);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  
  tft.setTextSize(3);
  tft.setTextColor(GREEN);
}

void loop()
{
  if(Serial.available())
  {
    int i = 0;
    String s = "";
    
    tft.fillScreen(BLACK);
    while(Serial.available())
    {
      char c = Serial.read();
      
      if(c == '\\')
      {
        tft.println(s);
        s = "";
        //mydisp.setPrintPos(0, ++i);
        continue;
      }
      s = s + c;
    }
    tft.println(s);
    Serial.write("OK");
  }
  tft.setCursor(0,0);
}
/*void setup() {
    mydisp.begin();

    mydisp.disableCursor(); //disable cursor, enable cursore use: enableCursor();
    mydisp.drawStr(4, 0, "Demo now"); //display string at: x=4, y=0

    //Test print function
    mydisp.setPrintPos(0, 1);
    mydisp.print(a); // display a char array
    resetpos();
    mydisp.print("display a char:");
    mydisp.print(b); //display a char
    resetpos();
    mydisp.print("int as DEC:");
    mydisp.print(c); //display 3456 in Dec
    resetpos();
    mydisp.print("as HEX:");
    mydisp.print(c, HEX); //display 3456 in Hex
    resetpos();
    mydisp.print("as OCT:");
    mydisp.print(c, OCT); //display 3456 in Oct
    resetpos();
    mydisp.print("BIN:");
    mydisp.print(c, BIN); //display 3456 in Bin
    resetpos();
    mydisp.print(d); //display String object
    resetpos();
    mydisp.print("float pi=");
    mydisp.print(pi); //display float of PI
    resetpos();
    mydisp.print("Pi6=");
    mydisp.print(pi, 6); //display PI in 6 Accuracy
    resetpos();
    mydisp.print("Pi*3=");
    mydisp.print(pi * 3, 6); //display PI time 3 in 6 Accuracy
    resetpos();
    mydisp.print("lg5=");
    mydisp.print(log(5), 8); //display log(5) in 8 Accuracy
    resetpos();
    mydisp.clearScreen();
    mydisp.enableCursor(); //enable cursor
}*/
