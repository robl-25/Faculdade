/***************************************\ 
**     
ROBOCORE ARDUINO KIT INICIANTE      **
*                                       * 
**        Display 7 Segmentos 1        ** 
\***************************************/
const int A = 12; // Primeiramente setamos os 7 pinos
const int B = 11; 
const int C = 10; 
const int D = 9; 
const int E = 8;  
const int F = 6; 
const int G = 7;
const int BotaoMais = 4;
const int BotaoMenos = 3;
int contador = 0;
int mais = 0, menos = 0;

void setup(){ 
    pinMode(A, OUTPUT); // seta todos as portas que estão os leds do displa y como saída
    pinMode(B, OUTPUT); 
    pinMode(C, OUTPUT); 
    pinMode(D, OUTPUT); 
    pinMode(E, OUTPUT); 
    pinMode(F, OUTPUT); 
    pinMode(G, OUTPUT);
    pinMode(BotaoMais, INPUT);
    pinMode(BotaoMenos, INPUT);
} 

void loop(){
    mais = digitalRead(BotaoMais);
    menos = digitalRead(BotaoMenos);

    if(mais == 1){
        contador++;
        if(contador > 9){
          contador = 0;
        }
    }
    if(menos == 1){
        contador--;
        if(contador < 0){
          contador = 0;
        }
    }

    if(contador == 0){
        digitalWrite(A, HIGH); //acende os leds que representam o número 0
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, LOW); 
        delay (250); //aguarda 1 segundo para mostrar próximo número
    }

    else if(contador == 1){
        digitalWrite(A, LOW); //acende os leds que representam o número 1
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }

    else if(contador == 2){
        digitalWrite(A, HIGH); //acende os leds que representam o número 2
        digitalWrite(B, HIGH); 
        digitalWrite(C, LOW); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, LOW); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }

    else if(contador == 3){
        digitalWrite(A, HIGH); //acende os leds que representam o número 3
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 4){
        digitalWrite(A, LOW); //acende os leds que representam o número 4
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 5){
        digitalWrite(A, HIGH); //acende os leds que representam o número 5
        digitalWrite(B, LOW); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, LOW); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 6){
        digitalWrite(A, LOW); //acende os leds que representam o número 6
        digitalWrite(B, LOW); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 7){
        digitalWrite(A, HIGH); //acende os leds que representam o número 7
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, LOW); 
        digitalWrite(G, LOW); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 8){
        digitalWrite(A, HIGH); //acende os leds que representam o número 8
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, HIGH); 
        digitalWrite(E, HIGH); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
    
    else if(contador == 9){
        digitalWrite(A, HIGH); //acende os leds que representam o número 9
        digitalWrite(B, HIGH); 
        digitalWrite(C, HIGH); 
        digitalWrite(D, LOW); 
        digitalWrite(E, LOW); 
        digitalWrite(F, HIGH); 
        digitalWrite(G, HIGH); 
        delay(250); //aguarda 1 segundo para mostrar próximo número
    }
} 
