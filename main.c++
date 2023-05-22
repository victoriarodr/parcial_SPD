/*
Proyecto montecargas Victoria Rodriguez Rosas DIV D
*/

#define A 8
#define B 7
#define C A1
#define D A2
#define E A3
#define F 6
#define G 5
#define LED_ROJO 13
#define LED_VERDE 12
#define BOTON_SUBIR 4
#define BOTON_PAUSAR 3
#define BOTON_BAJAR 2

void apagar_display();
void encender_display(int numero);
void encender_montacargas(bool &encendido);
void prender_apagar_leds(bool estado);
void funcionamiento_montacargas(int piso);
void pausa_emergencia(bool emergencia);
void funcionamiento_botones(int &piso);

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(LED_ROJO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(BOTON_SUBIR, INPUT_PULLUP);
    pinMode(BOTON_PAUSAR, INPUT_PULLUP);
    pinMode(BOTON_BAJAR, INPUT_PULLUP);
    Serial.begin(9600);
}

int piso = 0;
bool encendido = false;

void loop()
{
    encender_montacargas(encendido);
    if (encendido == true)
    {
        prender_apagar_leds(false);
        encender_display(piso);
        funcionamiento_botones(piso);
    }
}


//FUNCIONES
//Apaga el display 7 segmentos
void apagar_display()
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

//Muestra en el display el numero solicitado
void encender_display(int numero)
{
    switch (numero)
    {
    case 0:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        break;
    case 1:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
    case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 4:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 5:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 6:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
    case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 9:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    }
}

//Comprueba que el usuario encienda el sistema y cambia el valor de encendido
void encender_montacargas(bool &encendido)
{
    if (encendido == false)
    {
        while (digitalRead(BOTON_PAUSAR) != 0)
        {
            delay(100);
        }
        encendido = true;
    }
}

//Cambia el estado de los leds según el booleano recibido por parámetro
void prender_apagar_leds(bool estado)
{
    if (estado == true)
    {
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, HIGH);
    }
    else
    {
        digitalWrite(LED_ROJO, HIGH);
        digitalWrite(LED_VERDE, LOW);
    }
}

//Actualiza los leds para mostrar que está en movimiento
//En for espera los tres segundos que tarda en subir/bajar
//Mientras comprueba que no se toque el botón para hacer una parada de emergencia
//Una vez terminado se llama a display_off y se imprime por consola el piso
void funcionamiento_montacargas(int piso)
{
    prender_apagar_leds(true);
    for (int i = 0; i < 3000; i++)
    {
        if (digitalRead(BOTON_PAUSAR) == 0)
        {
            pausa_emergencia(true);
        }
        delay(1);
    }
    apagar_display();
    Serial.print("Usted está en el piso: ");
    Serial.println(piso);
    delay(100);
}

//Actualiza los leds para mostrar que se paró 
/*Entra en un bucle esperando que el usuario vuelva a apretar el botón PAUSA
    para poder actualizar de nuevo los leds y salir del bucle*/
//Una vez terminado vuelve a la función montacargas a esperar lo que resta de los tres segundos.
void pausa_emergencia(bool emergencia)
{
    prender_apagar_leds(false);
    delay(200);
    while (emergencia == true)
    {
        if (digitalRead(BOTON_PAUSAR) == 0)
        {
            emergencia = false;
            prender_apagar_leds(true);
            delay(200);
        }
        delay(200);
    }
}

//Recibe el piso por parametro y determina si se presiono subir o bajar
//Sube un piso en el caso de subir y se lo pasa a montacarga
//Baja un piso en el caso de bajar y se lo pasa a montacarga
void funcionamiento_botones(int &piso)
{
    if (digitalRead(BOTON_SUBIR) == 0)
    {
        if (piso < 9)
        {
            piso++;
            funcionamiento_montacargas(piso);
        }
    }
    else if (digitalRead(BOTON_BAJAR) == 0)
    {
        if (piso > 0)
        {
            piso--;
            funcionamiento_montacargas(piso);
        }
    }
}