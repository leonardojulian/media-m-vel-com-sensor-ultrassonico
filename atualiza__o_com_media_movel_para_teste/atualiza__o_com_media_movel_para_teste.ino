#include <Ultrasonic.h> //Biblioteca para funcionamento do sensor ultrassônico
#include <Sim800l.h>    //Biblioteca para funcionamento do modulo GSM responsável por enviar mensagem
#include <SoftwareSerial.h>
Sim800l Sim800l;
#define N 3 

Ultrasonic ultrassom(6,7);//(trig, echo) // pinos de saida do arduino arduino para leitura do sensor ultrassônico
 long distancia;
SoftwareSerial BT(9, 8); //10 RX, 11 TX. // pinos de leitura transmissão de dados para o modulo bluetooth

char* texto = "ATENCAO! RISCO DE ENTUPIMENTO NO CHUTE DO TRAILER DA EP 313K-03"; // texto que aparecera no corpo do SMS enviado
//Numeros cadastrados para recebimento de mensagem
//char* numero1 = "+5598999746275"; //NATALIA
//char* numero2 = "+5598988181900";//ROTA
//char* numero3 = "+5598988733299";//HEDERSON
char* numero4 = "+5598988966984";//LEONARDO
char* numero5 = "+5598988194346";//ZÉ ROBERTO
//char* numero6 = "+5598987268559";//JOAO

void setup()
  
{
  
   Serial.begin(9600); 
  Serial.begin(9600);
  Sim800l.begin(); // inicializa a biblioteca
  Serial.println("Trabalho desenvolvido pela equipe Anjos da Noite");
  int filtrado;
  int vals[N];
}


void loop()
{
   int filtrado;
   int vals[N];
   int value =  distancia;
   for(int i = N - 1; i > 0; i-- ){
            vals[i] = vals[i-1]; 
        }
        vals[0] = value;

        long sum = 0;
        for (int i = 0; i < N; i++){
            sum = sum + vals[i];
        }
        
        filtrado = sum / N;
        Serial.print(value);
        Serial.print('\t');
        Serial.println(filtrado);

        delay(100);
        
  distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia e
   Serial.print(distancia); //imprime o valor da variável distancia
  
   delay(3000);

Serial.println(filtrado);//mostrar valor filtrado

/*if (distancia < 68){
  BT.println(" CHUTE AFUNILANDO ");
  
  }*/
  
if (filtrado > 50){
  Serial.println(" CHUTE OPERACIONAL"); 
  }

  
  if (filtrado < 50)
  
  {
        
   /*Serial.println("Sensor acionado! Enviando SMS...");
    Sim800l.sendSms(numero1, texto);
    Serial.println("SMS1 Enviado...");
    while (distancia > 25)*/
      
    /*Serial.println("Sensor acionado! Enviando SMS3...");
    Sim800l.sendSms(numero3, texto);
   Serial.println("SMS3 Enviado...");
    while (distancia > 25)*/
    
    Serial.println("ATENÇÃO! RISCO DE ENTUPIMENTO. Sensor acionado! Enviando S M S 4...");
    Sim800l.sendSms(numero4, texto);
    Serial.println("SMS4 Enviado...");
    while (distancia > 25)
    
    Serial.println("Sensor acionado! Enviando S M S 5...");
    Sim800l.sendSms(numero5, texto);
    Serial.println("SMS5 Enviado...");
    while (distancia > 25)
    
    /*Serial.println("Sensor acionado! Enviando SMS6...");
    Sim800l.sendSms(numero6, texto);
    Serial.println("SMS6 Enviado  ...");*/
   
    {
     
    }
    Serial.println("Aguardando nova leitura");
   delay(420000);
   }
  
}
