#include <Colorduino.h>
typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} ColorRGB;

/********************************************************
Name: ColorFill
Function: Fill the frame with a color
Parameter:R: the value of RED.   Range:RED 0~255
          G: the value of GREEN. Range:RED 0~255
          B: the value of BLUE.  Range:RED 0~255
********************************************************/
void ColorFill(unsigned char R,unsigned char G,unsigned char B)
{
  PixelRGB *p = Colorduino.GetPixel(0,0);
  for (unsigned char y=0;y<ColorduinoScreenWidth;y++) {
    for(unsigned char x=0;x<ColorduinoScreenHeight;x++) {
      p->r = R;
      p->g = G;
      p->b = B;
      p++;
    }
  }
  
  Colorduino.FlipPage();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   Colorduino.Init();

  unsigned char whiteBalVal[3] = {36,63,63}; // for LEDSEE 6x6cm round matrix
  Colorduino.SetWhiteBal(whiteBalVal);



for (int i =0; i < ColorduinoScreenWidth; i++)
{
  for(int j = 0; j < ColorduinoScreenHeight;j++)
  {
    checkRedInRGBColorInPixel(i,j);
    checkGreenInRGBColorInPixel(i,j);
    checkBlueInRGBColorInPixel(i,j);
   }
  
}


  delay(1000);
  ColorFill(0,0,0);

  
/*
   delay(2000);
  ColorFill(0,0,255);
  Colorduino.FlipPage();
  */

  Serial.println("FIN");
    
}

void checkColorInRGBMatrixInPixel(int pixelX, int pixelY, char color)
{
   int red,green,blue = 0; 
   PixelRGB *pixel = Colorduino.GetPixel(pixelX,pixelY);
   red = pixel->r;
   green = pixel->g;
   blue = pixel->b;
    
   for (int i = 0; i < 256;i++)
  {
    Colorduino.SetPixel(pixelX, pixelY, red, green, blue);
    Colorduino.FlipPage();
    delay(1);

    if(color =='r'){red++;}
    if(color=='g'){green++;}
    if(color=='b'){blue++;}
 
   } 
/*
  Serial.println("Salgo de checkColorInRGBMatrixInPixel, color=");
  Serial.print(color);
  Serial.print(" coordenadas x,y pixel: ");
  Serial.print(pixelX);
  Serial.print(",");
  Serial.print(pixelY);
  Serial.println(" ");
  Serial.println("valores rgb = ");
  Serial.print(pixel->r);
  Serial.print(",");
  Serial.print(pixel->g);
  Serial.print(",");
  Serial.print(pixel->b);
  Serial.println(" "); 
  */

 }
void checkRedInRGBColorInPixel( int pixelX, int pixelY)
{
  checkColorInRGBMatrixInPixel( pixelX,  pixelY,  'r');

}
 void checkGreenInRGBColorInPixel(  int pixelX, int pixelY)
{
  checkColorInRGBMatrixInPixel( pixelX,  pixelY, 'g') ;
 
 }

  void checkBlueInRGBColorInPixel( int pixelX, int pixelY)
{
  checkColorInRGBMatrixInPixel( pixelX,  pixelY,'b');
 }

void loop() {
  // put your main code here, to run repeatedly:

}

