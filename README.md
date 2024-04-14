# Raylib Raycaster

Questo é un progetto realizzato dagli studenti Freddi Marco e Wang Cristiano in occasione del Capolavoro
scolastico dell'anno 2024.


https://github.com/MRcodino07/Raylib-Raycaster/assets/58667917/ec69611e-504b-4512-8974-6c275bd83205


## In che cosa consiste?

Il presente é un motore grafico che si basa sulla tecnica del Raycasting per simulare un ambiente tridimensionale,
ispirata a videogiochi dei primi anni '90 come Wolfenstein 3D.
Il tutto é stato realizzato con il framework grafico [Raylib](https://github.com/raysan5/raylib).

# Utilizzo

## Come compilare il progetto

Il progetto é gestito utilizzando il build system CMake, il cui utilizzo é illustrato [qui](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

## Comandi

Per girarsi a sinistra o a destra é sufficiente muovere il **mouse**, invece per camminare si utilizzano i tasti **WASD**.

## Modificare la mappa

Nella cartella `res/maps` é presente un file base.map, nel quale é contenuta la mappa che verrá visualizzata a schermo. Per modificarne il layout sará sufficiente modificare i dati al suo interno nel seguente modo:

1. I due numeri in cima sono rispettivamente la grandezza della mappa in orizzontale e in verticale (`XSize` e `YSize`)
2. A seguire, é necessario inserire `XSize * YSize` valori booleani (`0` o `1`). Tutti gli `1` inseriti sono considerati muri.
3. É inoltre necessario inserire dei muri su tutto il perimetro della mappa per evitare errori durante l'esecuzione

ESEMPIO:

`4 4`  
`1 1 1 1`  
`1 0 0 1`  
`1 0 0 1`  
`1 1 1 1`
