void CommandDefinition(String CMD)
{
  /////////////////////////////////////////////////////////////////////////////
  if (CMD == "CFG_PRINT" || CMD == "CFG_PRINT\n")
  {
    Serial.println();
    Serial.println("CAPSONIC CYCLE COUNTER");
    Serial.println("ACTIVE CONFIGURATION PRINT");
    Serial.println();
    Serial.println("DEVICE MAC: " + MAC);
    Serial.println("DEVICE NAME: " + Device);
    Serial.println("OP NAME: " + OP);
    Serial.println("PARTS PER CYCLE: " + PartsProd);
    if (_HeartBeatEN)
    {
      Serial.println("HEART BEAT: ENABLE");
    } else
    {
      Serial.println("HEART BEAT: DISABLE");
    }

    Serial.println("HEART BEAT RATE IN SEC: " + HartBeat);
    Serial.println();
    //Serial.print("IP ADDRES: ");
    //Serial.println(Ethernet.localIP());

    Serial.print("SSID: "); Serial.println(ssid);
    Serial.print("SSID PASS: "); Serial.println(password);
    Serial.print("IP ADDRESS: "); Serial.println(WiFi.localIP());
    Serial.println();
    Serial.println("END CONFIGURATION PRINT");
    Serial.println();
    return;
  }
  ////////////////////////////////////////////////////////////////
  if (CMD == "CFGMODE_STAT" || CMD == "CFGMODE_STAT\n")
  {
    String s = "";
    if (CfgMode)
      s = "CFGMODE: ON";
    else
      s = "CFGMODE: OFF";
    Serial.println(s);
    return;
  }
  ///////////////////////////////////////////////////////////////
  if (CMD == "CFGMODE_ON" || CMD == "CFGMODE_ON\n")
  {
    CfgMode = true;
    Serial.println("CFGMODE_ON OK");
  }
  /////////////////////////////////////////////////////////////
  if (CMD == "CFGMODE_OFF" || CMD == "CFGMODE_OFF\n")
  {
    CfgMode = false;
    Serial.println("CFGMODE_OFF OK");
    return;
  }
  //////////////////////////////////////////////////////////////
  if (CMD == "DEV_NAME" || CMD == "DEV_NAME\n")
  {
    Serial.println("DEV_NAME: " + Device);
    return;
  }
  ////////////////////////////////////////////////////////////////
  if (CMD == "DEV_NAME_EDIT" || CMD == "DEV_NAME_EDIT\n")
  {
    if (CfgMode)
    {
      ChgDevName = true;
      Serial.println("DEV_NAME_EDIT OK");
    }
    else
    {
      Serial.println("DEV_NAME_EDIT ERROR");
    }
    return;
  }
  //////////////////////////////////////////////////////////////////
  if (ChgDevName)
  {
    if (CMD != "" && CMD != "\n")
    {
      Device = CMD;
      Serial.println("NEW DEVICE NAME: " + CMD + " OK");
    }
    else
    {
      Serial.println("NEW DEVICE NAME: " + CMD + " ERROR");
    }
    ChgDevName = false;
    return;
  }
  ////////////////////////////////////////////////////////////
  if (CMD == "OP_NAME" || CMD == "OP_NAME\n")
  {
    Serial.println("DEV_NAME: " + OP);
    return;
  }
  if (CMD == "OP_NAME_EDIT" || CMD == "OP_NAME_EDIT\n")
  {
    if (CfgMode)
    {
      ChgOPName = true;
      Serial.println("OP_NAME_EDIT OK");
    }
    else
    {
      Serial.println("OP_NAME_EDIT ERROR");
    }
    return;
  }
  /////////////////////////////////////////////////////////////////////
  if (ChgOPName)
  {
    if (CMD != "" && CMD != "\n")
    {
      OP = CMD;
      Serial.println("NEW OP: " + CMD + " OK");
    }
    else
    {
      Serial.println("NEW OP: " + CMD + " ERROR");
    }
    ChgOPName = false;
    return;
  }
  ////////////////////////////////////////////////////////////////
  if (CMD == "PART_PCYCLE" || CMD == "PART_PCYCLE\n")
  {
    Serial.println("PARTS PER CYCLE: " + PartsProd);
    return;
  }
  //////////////////////////////////////////////////////////////
  if (CMD == "PART_PCYCLE_EDIT" || CMD == "PART_PCYCLE_EDIT\n")
  {
    if (CfgMode)
    {
      PartsPCycle = true;
      Serial.println("PART_PCYCLE_EDIT OK");
    }
    else
    {
      Serial.println("PART_PCYCLE_EDIT ERROR");
    }
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (PartsPCycle)
  {
    if (CMD != "" && CMD != "\n")
    {
      PartsProd = CMD;
      Serial.println("OK");
    }
    else
    {
      Serial.println("ERROR");
    }
    PartsPCycle = false;
    return;
  }
  //////////////////////////////////////////////////////////////////////
  if (CMD == "SAVE_CFG" || CMD == "SAVE_CFG\n")
  { if (CfgMode)
    {
      CFG_SAVE();
      Serial.println("SAVE_CFG OK");
    }
    else
    {
      Serial.println("SAVE_CFG ERROR");
    }
  }
  //////////////////////////////////////////////////////////////////////
  if (CMD == "READ_CFG" || CMD == "READ_CFG\n")
  {
    CFG_LOAD();
    Serial.println("READ_CFG OK");
  }

  //////////WIFI COMMANDS/////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////
  if (CMD == "SSID" || CMD == "SSID\n")
  {
    Serial.println("SSID: " + ssid);
    return;
  }
  //////////////////////////////////////////////////////////////
  if (CMD == "SSID_EDIT" || CMD == "SSID_EDIT\n")
  {
    if (CfgMode)
    {
      _SSID = true;
      Serial.println("SSID_EDIT OK");
    }
    else
    {
      Serial.println("SSID_EDIT ERROR");
    }
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (_SSID)
  {
    if (CMD != "" && CMD != "\n")
    {
      ssid = CMD;
      Serial.println("NEW SSID: " + ssid + " OK");
    }
    else
    {
      Serial.println("NEW SSID: " + ssid + " ERROR");
    }
    _SSID = false;
    return;
  }
  ////////////////////////////////////////////////////////////////
  if (CMD == "SSID_PASS" || CMD == "SSID_PASS\n")
  {
    Serial.println("SSID_PASS: " + password);
    return;
  }
  //////////////////////////////////////////////////////////////
  if (CMD == "SSID_PASS_EDIT" || CMD == "SSID_PASS_EDIT\n")
  {
    if (CfgMode)
    {
      _PASS = true;
      Serial.println("SSID_PASS_EDIT OK");
    }
    else
    {
      Serial.println("SSID_PASS_EDIT ERROR");
    }
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (_PASS)
  {
    if (CMD != "" && CMD != "\n")
    {
      password = CMD;
      Serial.println("NEW SSID_PASS: " + password + " OK");
    }
    else
    {
      Serial.println("NEW SSID_PASS: " + password + " ERROR");
    }
    _PASS = false;
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (CMD == "HEART_BEAT_ON" || CMD == "HEART_BEAT_ON\n")
  {
    if (CfgMode)
    {
      _HeartBeatEN = true;
      NetCheckTimer.attach(HartBeat.toInt(), NetworkCheck);
      Serial.println("HEART_BEAT_ON OK");
    }
    else
    {
      Serial.println("HEART_BEAT_ON ERROR");
    }
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (CMD == "HEART_BEAT_OFF" || CMD == "HEART_BEAT_OFF\n")
  {
    if (CfgMode)
    {
      _HeartBeatEN = false;
      NetCheckTimer.detach();
      Serial.println("HEART_BEAT_OFF OK");
    }
    else
    {
      Serial.println("HEART_BEAT_OFF ERROR");
    }
    return;
  }
  ///////////////////////////////////////////////////////////////////
  if (CMD == "HEART_BEAT_RATE_EDIT" || CMD == "HEART_BEAT_RATE_EDIT\n")
  {
    if (CfgMode)
    {
      _HeartBeat = true;
      Serial.println("HEART_BEAT_RATE_EDIT OK");
    }
    else
    {
      Serial.println("HEART_BEAT_RATE_EDIT ERROR");
    }
    return;
  }
  //////////////////////////////////////////////////////////////////////
  if (_HeartBeat)
  {
    if (CMD != "" && CMD != "\n")
    {
      HartBeat = CMD;
      Serial.println("NEW HEART_BEAT_RATE: " + HartBeat + " OK");
      NetCheckTimer.detach();
      NetCheckTimer.attach(HartBeat.toInt(), NetworkCheck);
    }
    else
    {
      Serial.println("NEW HEART_BEAT_RATE: " + HartBeat + " ERROR");
    }
    _HeartBeat = false;
    return;
  }
}
