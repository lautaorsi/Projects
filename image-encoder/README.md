# image-encoder

## Requisitios

Para este proyecto necesitamos únicamente la dependencia externa `opencv2`, biblioteca estandar de C++ y un sistema unix/linux/macOS.

## Modo de uso

Tenemos dos ejecutables distintos (`encoder` y `decoder`) que utilizaremos en conjunto con un archivo de texto para codificar y una imagen para decodificar. <br>
El ejecutable en sí va a pedirte el nombre del archivo sobre el que trabajará, no es necesario pasar como argumento de ejecución el path.

Ejemplo:

- Encriptado: 

        $ ./encoder
        $ Ingresa nombre de archivo: aText.txt
        $ Ingresa nombre de archivo encriptado: imagenEncriptada
        $ Archivo encriptado con éxito!

- Desencriptado:

        $ ./decoder
        $ Ingresa nombre de imagen a decodificar: imagenEncriptada.png
        $ [CONTENIDO DE ARCHIVO]



## Especificación tecnica

Es importante notar que para esta primera versión tenemos ciertas limitaciones en cuanto a los tamaños de archivo, predefiní un tamaño de 640x640 pixeles para la imagen y una relación 1:1 caracter-pixel (notese entonces que el limite de caracteres a codificar es de 640x640). <br>
<br>
Por otro lado la codificación en si es simplemente una traduccion del valor ascii a intensidad en la escala de grises, luego para "ofuscar" un poco mas el mensaje trasponemos la matriz.

## Futuras versiones

Logicamente el encriptado que se hace es basicamente nulo, se podrían utilizar funciones criptograficas mas avanzadas junto a operaciones matriciales para generar imagenes menos directas al texto. Por otro lado tambien se podría ampliar el tamaño de imagen o incluso hacerlo dinamico en relación a la longitud del texto, requeriría armar la imagen luego de una primera lectura del archivo pero no es nada muy complicado.


