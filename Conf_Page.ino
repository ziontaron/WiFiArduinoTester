
//-----------CODIGO HTML PAGINA DE CONFIGURACION---------------
String pagina = "<!DOCTYPE html>"
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
"<form action='guardar_conf' method='get'>"
"SSID:"
"<input class='input1' name='ssid' type='text' value='@ssid'><br>"
"PASSWORD:"
"<input class='input1' name='pass' type='password' value='@pass'><br>"

"DEVICE NAME:"
"<input class='input1' name='dev_name' type='text' value='@dev_name'><br>"

"OP NAME:"
"<input class='input1' name='op_name' type='text' value='@op_name'><br>"

"PARTS PER CYCLE:"
"<input class='input1' name='pp_cycle' type='text' value='@partcycle'><br>"

"<input class='boton' type='submit' value='SAVE'/><br><br>"
"</form>"
"<a href='exit'><button class='boton'>CLOSE</button></a><br><br>"
"<a href='escanear'><button class='boton'>SCAN</button></a><br><br>";

String paginafin = "</body>"
"</html>";
