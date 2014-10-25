#include<Bridge.h>
#include<YunServer.h>
#include<YunClient.h>
YunServer server;
int activo=0;

//typedef struct{
//  double x;
//  double y;
//  double z;
//  
//}Cords;

void setup() {
  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
    pinMode(13,OUTPUT);
 
}

void loop() {
 
  YunClient client=server.accept();

  if(client){
    process(client);
    client.stop();
  }else{
    Serial.println("Error");
  }
  delay(50);
}

void process(YunClient client){
   String command = client.readString();
    client.println("Status: 200");
    client.println("Content-type: application/json");
    client.println(); 
    //Cords d;
   // d=getWifiCoords();
    client.print("{\"Respuesta\":\"[\"");
    //client.print(d.x);
    client.print(1.23);
    client.print("\";\"");
    client.print(2.23);
    client.print("\";\"");
    client.print(0.23);
    client.print("\"]");
    client.print("\"}");
     if(activo==0){
     digitalWrite(13, HIGH);
     activo=1;
     }else{
      digitalWrite(13,LOW);
      activo=0;
     }
    
}
//Cords getWifiCoords(){
//  Cords coordenadas;
//  //Provisional: hacer programa python
//  randomSeed(millis());
//  double d = random(255);
//  coordenadas.x=d;
//  coordenadas.y=d;
//  coordenadas.z=d;
//  return coordenadas;
//}
