#include <TinyGPSPlus.h>
#include <SunPosition.h>
#include <UnixTime.h>
#include <Servo.h>

static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
UnixTime stamp(0);
UnixTime localT(8);
Servo sb, sw, sf;

float lat;
float lon;
uint32_t unix;
int gmt = 8;
bool move;

//.................................................... Convert datetime to unixtime ........................................................

uint32_t convertUX()
{
  uint32_t ux;
  
  uint16_t Year = gps.date.year();
  uint8_t Month = gps.date.month();
  uint8_t Day = gps.date.day();
  uint8_t Hr = gps.time.hour();
  uint8_t Min = gps.time.minute();
  uint8_t Sec = gps.time.second();
  
  stamp.setDateTime(Year, Month, Day, Hr, Min, Sec);
  return ux = stamp.getUnix();
}

void displayLocaltime(uint32_t epox)
{
  localT.getDateTime(epox);
  
  //Serial.print(F("  Date/Time (UTC + 08:00): "));
  if (gps.date.isValid())
  {
    Serial.print(localT.day);
    Serial.print(F("/"));
    Serial.print(localT.month);
    Serial.print(F("/"));
    Serial.print(localT.year);

    Serial2.print(localT.day);
    Serial2.print(F("/"));
    Serial2.print(localT.month);
    Serial2.print(F("/"));
    Serial2.print(localT.year);
  }
  else
  {
    Serial.print(F("INVALID"));
    Serial2.print(F("INVALID"));
  }

  Serial.print(F(" , "));
  Serial2.print(F(" , "));
  if (gps.time.isValid())
  {
    if (localT.hour < 10) { Serial.print(F("0")); Serial.print(F("0")); }
    Serial.print(localT.hour);
    Serial.print(F(":"));
    Serial2.print(localT.hour);
    Serial2.print(F(":"));

    if (localT.minute < 10) { Serial.print(F("0")); Serial2.print(F("0")); }
    Serial.print(localT.minute);
    Serial.print(F(":"));
    Serial2.print(localT.minute);
    Serial2.print(F(":"));
    
    if (localT.second < 10) { Serial.print(F("0")); Serial2.print(F("0")); }
    Serial.print(localT.second);
    Serial2.print(localT.second);
  }
  else
  {
    Serial.print(F("INVALID"));
    Serial2.print(F("INVALID"));
  }
  //Serial.println();
  Serial.print(F(" , "));
  Serial2.print(F(" , "));   
}

//....................................................... Display GPS info .........................................................

void displayInfo()
{
  //Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 4);
    Serial.print(F(" , "));
    Serial.print(gps.location.lng(), 4);

    Serial2.print(gps.location.lat(), 4);
    Serial2.print(F(" , "));
    Serial2.print(gps.location.lng(), 4);
  }
  else
  {
    Serial.print(F("INVALID , INVALID"));
    Serial2.print(F("INVALID , INVALID"));
  }

  //Serial.print(F("  Date/Time (UTC): "));
  Serial.print(F(" , "));
  if (gps.date.isValid())
  {
    Serial.print(gps.date.day());
    Serial.print(F("/"));
    Serial.print(gps.date.month());
    Serial.print(F("/"));
    Serial.print(gps.date.year());

    Serial2.print(gps.date.day());
    Serial2.print(F("/"));
    Serial2.print(gps.date.month());
    Serial2.print(F("/"));
    Serial2.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
    Serial2.print(F("INVALID"));
  }

  Serial.print(F(" , "));
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) { Serial.print(F("0")); Serial2.print(F("0")); }
    Serial.print(gps.time.hour());
    Serial.print(F(":"));
    Serial2.print(gps.time.hour());
    Serial2.print(F(":"));

    if (gps.time.minute() < 10) { Serial.print(F("0")); Serial2.print(F("0")); }
    Serial.print(gps.time.minute());
    Serial.print(F(":"));
    Serial2.print(gps.time.minute());
    Serial2.print(F(":"));

    if (gps.time.second() < 10) { Serial.print(F("0")); Serial2.print(F("0")); }
    Serial.print(gps.time.second());
    Serial2.print(gps.time.second());
  }
  else
  {
    Serial.print(F("INVALID"));
    Serial2.print(F("INVALID"));
  }
  Serial.print(F(" , "));
  Serial2.print(F(" , "));
}

//............................................... Drive servo motors to the desired angle ............................................

void driveServos(Servo srv, int intl)
{
  int srv_pos = srv.read();

  if (srv_pos != intl)
  {
    if (srv_pos > intl)
    {
      for (srv_pos; srv_pos >= intl; srv_pos -= 1)
      {
        srv.write(srv_pos);
        delay(30);
      }
    }
    else
    {
      for (srv_pos; srv_pos <= intl; srv_pos += 1)
      {
        srv.write(srv_pos);
        delay(30);
      } 
    }
  }
}

//.................................................... Display servo position info .........................................................

void displayServo()
{
  //Serial.print(F("Servo Position: "));
  //Serial.print(F("Base S: "));
  Serial.print(sb.read());
  Serial.print(F(" , "));
  Serial.print(sw.read());
  Serial.print(F(" , "));
  Serial.print(sf.read());
  Serial.print(F(" , "));

  Serial2.print(sb.read());
  Serial2.print(F(" , "));
  Serial2.print(sw.read());
  Serial2.print(F(" , "));
  Serial2.print(sf.read());
  Serial2.print(F(" , "));
}

//
  //
    //                                                                                                   
      //                                                                                              
        //..................................................... Main Code to Execute ........................................................
      //                                                                                            
    //                                                                                               
  //
//

void setup()
{
  Serial.begin(115200);
  Serial1.begin(GPSBaud);
  Serial2.begin(9600);
  sf.attach(10);
  sw.attach(11);
  sb.attach(12);

  driveServos(sf, 180);
  driveServos(sw, 0);
  driveServos(sb, 0);

  //delay(120000);
}

void loop()
{
  while (Serial1.available() > 0)
  {
    if (gps.encode(Serial1.read()))
    {
      lat = gps.location.lat();
      lon = gps.location.lng();
      unix = convertUX();
      SunPosition sun(lat, lon, unix, gmt);
      sun.compute(lat, lon, unix, gmt);
//......................................................... Display GPS Info ............................................................
      displayInfo();
//........................................................ Display Local Time ...........................................................
      displayLocaltime(unix);
//.......................................... Verify if solar panels should be open or close ..........................................

      if (gps.location.isValid() || gps.date.isValid() || gps.time.isValid())
      {
        if(gps.time.hour() >= 0)
        {
          if(gps.time.hour() >= 11)
          {
            move = false;
            driveServos(sf , 180);
          }
          else
          {
            move = true;
            driveServos(sf , 90);
          }
        }
        else
        {
          move = false;
        }

//..................................................... Track the sun ..............................................................

        int posb = sb.read();
        int posw = sw.read();
        int azm = (int) (sun.angle180() + 0.5);
        int alt = (int) (sun.altitude() + 0.5);

        if (move == true)
        {
          if (posb != sun.angle180())
          {
            driveServos(sb , azm);
          }

          if (posw != (sun.altitude() + 41))
          {
            driveServos(sw , (alt + 41));
          }
        }
        else
        {
          driveServos(sb, 0);
          driveServos(sw, 0);
        }

//..................................................... Display Sun Position Info........................................................

        //Serial.print(F("Sun Position: "));
        //Serial.print(F("Azm: "));
        Serial.print(sun.azimuth());
        Serial.print(F(" , "));
        Serial.print(sun.zenith());
        Serial.print(F(" , "));
        Serial.print(sun.azimuthMin());
        Serial.print(F(" , "));
        Serial.print(sun.azimuthMax());  
        Serial.print(F(" , "));
        Serial.print(sun.altitude());
        Serial.print(F(" , "));
        Serial.print(unix);
        Serial.print(" , ");
        Serial.print(sun.angle180());

        Serial2.print(sun.azimuth());
        Serial2.print(F(" , "));
        Serial2.print(sun.zenith());
        Serial2.print(F(" , "));
        Serial2.print(sun.azimuthMin());
        Serial2.print(F(" , "));
        Serial2.print(sun.azimuthMax());  
        Serial2.print(F(" , "));
        Serial2.print(sun.altitude());
        Serial2.print(F(" , "));
        Serial2.print(unix);
        Serial2.print(" , ");
        Serial2.print(sun.angle180());
      }
      else
      {
        Serial.print(F("INVALID"));
        Serial2.print(F("INVALID"));
      }
      Serial.print(" , ");
      Serial2.print(" , ");       
//.......................................... Display Servo Info and delay by 3 secs ...............................................
      displayServo();
      Serial.println();
      Serial2.println();
      delay(3000);
    }
  }
}




