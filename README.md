# PRIMER PARCIAL SPD

## Integrante
- Victoria Rodriguez Rosas  


## Proyecto: Montecargas.


## Descripción
Mi proyecto es un montecargas que al presionar el boton subir/ bajar muestra en el display y en la consola en que piso se encuentra.
Con el botón de pausa es posible detener el movimiento en cualquier momento.

## Función principal
Se inicializan dos variables, una marcará los pisos y la otra servirá para determinar el encendido del sistema. La función principal primero  verifica que la imclinacion y la luz sea optima para arrancar con el montecargas. Si es optima apaga la luz azul y llama a comprobar_arranque, esta recibe por referencia a encendido y espera a que el usuario prenda el sistema utilizando el botón de parar, luego cambia el valor de encendido a True.

~~~ C 
int piso = 0;
bool encendido = false;

void loop()
{
    encender_montacargas(encendido);
  
  val = analogRead(SENSOR);
  estado = digitalRead(INCLINACION);
  
  if(estado == LOW && val == LOW)
  {
    digitalWrite(LED_AZUL, HIGH);
    Serial.print("El ascensor se encuentra inclinado y con poca luz\n");
    contadorGrados++;
      myServo.write(contadorGrados);
      delay(100);
      if(contadorGrados == 180)
      {
        myServo.write(0);
        contadorGrados = 0;
        delay(50);
      }
  }
  else
  {
    digitalWrite(LED_AZUL, LOW);
    if (encendido == true)
    {
        prender_apagar_leds(false);
        encender_display(piso);
        funcionamiento_botones(piso);
    }
  }
}

~~~

## :robot: Link al proyecto
- https://www.tinkercad.com/things/gC6PgN6CTWS-primer-parcial-victoria-rodriguez-rosas-div-d/editel?sharecode=_MoNC0ohOUPbWP8EJzYU6ACP50PHgazaJj4FKZ5ykYI
