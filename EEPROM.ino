
int ADDR_Device = 0;
int ADDR_OP = 100;
int ADDR_ssid = 200;
int ADDR_password = 300;
int ADDR_PartsProd = 400;

void CFG_SAVE()
{ 
//  EEPROM_SAVE(Device+'\0',ADDR_Device);
//  delay(100);
//  EEPROM_SAVE(OP+'\0',ADDR_OP);
//  delay(100);
//  EEPROM_SAVE(ssid+'\0',ADDR_ssid);
//  delay(100);
//  EEPROM_SAVE(password+'\0',ADDR_password);
//  delay(100);
//  EEPROM_SAVE(PartsProd+'\0',ADDR_PartsProd);
//  delay(100);


  EEPROM_SAVE(Device,ADDR_Device);
  delay(100);
  EEPROM_SAVE(OP,ADDR_OP);
  delay(100);
  EEPROM_SAVE(ssid,ADDR_ssid);
  delay(100);
  EEPROM_SAVE(password,ADDR_password);
  delay(100);
  EEPROM_SAVE(PartsProd,ADDR_PartsProd);
  delay(100);
  
  EEPROM.commit();
  
  Serial.println("EEPROM SAVED");
}

void CFG_LOAD()
{
  Device=EEPROM_READ(ADDR_Device);
  delay(100);
  OP=EEPROM_READ(ADDR_OP);
  delay(100);
  ssid=EEPROM_READ(ADDR_ssid);
  delay(100);
  password=EEPROM_READ(ADDR_password);
  delay(100);
  PartsProd=EEPROM_READ(ADDR_PartsProd);
  delay(100);
}

String EEPROM_READ(int ADDR)
{
    byte b_read;
    String s_read;
    for(int i=ADDR;i<ADDR+50;i++)
    {
      b_read=EEPROM.read(i);
      if(b_read!=255)
      {
        s_read+=(char)b_read;
        }
      }
      delay(100);
      return s_read;
}

void EEPROM_SAVE(String x,int ADDR)
{
  //Serial.println("EEPROM_SAVE "+x);
  int s_size = x.length();
  char inchar[50];
  x.toCharArray(inchar,s_size+1);
  for(int i=0; i<s_size; i++)
  {
    EEPROM.write(ADDR+i, inchar[i]);
//    Serial.print("addr - ");
//    Serial.print(ADDR+i);
//    Serial.print(" = ");
//    Serial.println(inchar[i]);
  }
  for(int i=s_size; i<50; i++)
  {
    EEPROM.write(ADDR+i, 255);
  }
  EEPROM.commit();
}
