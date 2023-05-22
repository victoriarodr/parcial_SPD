# PRIMER PARCIAL SPD

## Integrante
- Victoria Rodriguez Rosas  


## Proyecto: Montecargas.


## Descripción
Mi proyecto es un montecargas que al presionar el boton subir/ bajar muestra en el display y en la consola en que piso se encuentra.
Con el botón de pausa es posible detener el movimiento en cualquier momento.

## Función principal
Se inicializan dos variables, una marcará los pisos y la otra servirá para determinar el encendido del sistema. La función principal primero llama a comprobar_arranque, esta recibe por referencia a encendido y espera a que el usuario prenda el sistema utilizando el botón de parar, luego cambia el valor de encendido a True.

~~~ C 
int piso = 0;
bool encendido = false;

void loop()
{
    comprobar_arranque(encendido);
    if (encendido == true)
    {
        actualizar_led(false);
        display(piso);
        subir_bajar(piso);
    }
}
~~~

## :robot: Link al proyecto
- https://www.tinkercad.com/things/gC6PgN6CTWS-primer-parcial-victoria-rodriguez-rosas-div-d/editel?sharecode=_MoNC0ohOUPbWP8EJzYU6ACP50PHgazaJj4FKZ5ykYI
