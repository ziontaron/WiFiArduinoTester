String pagina;

String paginafin = "</body>"
"</html>";


void LoadWebPage()
{
//-----------CODIGO HTML PAGINA DE CONFIGURACION---------------
String _webHeader = "<!DOCTYPE html>"
"<html>"
"<head>"
"<title>WIFI ARDUINO CYCLE COUNTER</title>"
"<br>"
"<title>CONTROL PANEL</title>"
"<meta charset='UTF-8'>"
"</head>"
"<body>"

"<h1>WIFI ARDUINO CYCLE COUNTER</h1>"
"<br>"
"<h2>CONTROL PANEL</h2>"
"</form>"
"<form action='guardar_conf' method='get'>";
String _webSSID="SSID: <input class='input1' name='ssid' type='text' value='"+ssid+"'><br>";
String _webPASS="PASSWORD: <input class='input1' name='pass' type='password' value='"+password+"'><br>";
String _webDEV="DEVICE NAME: <input class='input1' name='dev_name' type='text' value='"+Device+"'><br>";
String _webOP="OP NAME: <input class='input1' name='op_name' type='text' value='"+OP+"'><br>";
String _webPPC="PARTS PER CYCLE: <input class='input1' name='pp_cycle' type='text' value='"+PartsProd+"'><br>";

String _webButtons="<input class='boton' type='submit' value='SAVE'/><br><br>"
"</form>"
"<a href='exit'><button class='boton'>CLOSE</button></a><br><br>"
"<a href='escanear'><button class='boton'>SCAN</button></a><br><br>";

pagina=_webHeader+_webSSID+_webPASS+_webDEV+_webOP+_webPPC+_webButtons;
//Serial.println(pagina);

}
