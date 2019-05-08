void CommandDefinition(String CMD)
{
/////////////////////////////////////////////////////////////////////////////
  if(CMD=="CFG_PRINT" || CMD=="CFG_PRINT\n")
  {  
     Serial.println();
     Serial.println("CAPSONIC CYCLE COUNTER");
     Serial.println("ACTIVE CONFIGURATION PRINT");
     Serial.println();
     Serial.println("DEVICE NAME: "+Device);
     Serial.println("OP NAME: "+OP);
     Serial.println("PARTS PER CYCLE: "+PartsProd);
     //Serial.print("IP ADDRES: ");
     //Serial.println(Ethernet.localIP());
     Serial.print("SSII PASS: "); Serial.println(password);
     Serial.print("IP ADDRESS: "); Serial.println(WiFi.localIP());
     Serial.println();
     Serial.println("END CONFIGURATION PRINT");
     Serial.println();
     return;
  }
////////////////////////////////////////////////////////////////
  if(CMD=="CFGMODE_STAT" || CMD=="CFGMODE_STAT\n")
  {
    String s="";
     if(CfgMode)
        s="CFGMODE: ON";
     else
        s="CFGMODE: OFF";    
     Serial.println(s);
     return;
  }
///////////////////////////////////////////////////////////////
  if(CMD=="CFGMODE_ON" || CMD=="CFGMODE_ON\n")
  {
    CfgMode=true;    
    Serial.println("OK");
  }
/////////////////////////////////////////////////////////////    
  if(CMD=="CFGMODE_OFF" || CMD=="CFGMODE_OFF\n")
  {
    CfgMode=false;   
    Serial.println("OK");
     return;
  }
//////////////////////////////////////////////////////////////  
  if(CMD=="DEV_NAME" || CMD=="DEV_NAME\n")
  {  
    Serial.println("DEV_NAME: "+Device);
     return;
  }
////////////////////////////////////////////////////////////////
  if(CMD=="DEV_NAME_EDIT" || CMD=="DEV_NAME_EDIT\n")
  {
    if(CfgMode)
    {
      ChgDevName=true;   
      Serial.println("OK");
    }
    else
    {
      Serial.println("ERROR");
    }
     return;
  }
//////////////////////////////////////////////////////////////////
  if(ChgDevName)
  {
    if(CMD!="" && CMD!="\n")
    {
      Device=CMD;   
      Serial.println("OK"); 
    }       
    else
    {
      Serial.println("ERROR"); 
    }
      ChgDevName=false;
     return;
  }
////////////////////////////////////////////////////////////  
  if(CMD=="OP_NAME" || CMD=="OP_NAME\n")
  {  
    Serial.println("DEV_NAME: "+OP);
     return;
  }
  if(CMD=="OP_NAME_EDIT" || CMD=="OP_NAME_EDIT\n")
  {
    if(CfgMode)
    {
      ChgOPName=true;   
      Serial.println("OK");
    }
    else
    {
      Serial.println("ERROR");
    }
     return;
  }
/////////////////////////////////////////////////////////////////////
  if(ChgOPName)
  {
    if(CMD!="" && CMD!="\n")
    {
      OP=CMD;       
      Serial.println("OK");  
    }  
    else
    {
      Serial.println("ERROR"); 
    }
      ChgOPName=false;
     return;
  }
////////////////////////////////////////////////////////////////
  if(CMD=="PART_PCYCLE" || CMD=="PART_PCYCLE\n")
  {  
    Serial.println("PARTS PER CYCLE: " + PartsProd);
     return;
  }
//////////////////////////////////////////////////////////////
  if(CMD=="PART_PCYCLE_EDIT" || CMD=="PART_PCYCLE_EDIT\n")
  {
    if(CfgMode)
    {
      PartsPCycle=true;   
      Serial.println("OK");
    }
    else
    {
      Serial.println("ERROR");
    }
     return;
  }
///////////////////////////////////////////////////////////////////
  if(PartsPCycle)
  {
    if(CMD!="" && CMD!="\n")
    {
      PartsProd=CMD;       
      Serial.println("OK");  
    }  
    else
    {
      Serial.println("ERROR"); 
    }
      PartsPCycle=false;
     return;
  }
//////////////////////////////////////////////////////////////////////
}
