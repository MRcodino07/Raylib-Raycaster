# Raylib Raycaster

Questo é un progetto realizzato dagli studenti Freddi Marco e Wang Cristiano in occasione del Capolavoro
scolastico dell'anno 2024.


https://github.com/MRcodino07/Raylib-Raycaster/assets/58667917/ec69611e-504b-4512-8974-6c275bd83205

## In che cosa consiste?

Il presente é un motore grafico che si basa sulla tecnica del Raycasting per simulare un ambiente tridimensionale,
ispirata a videogiochi dei primi anni '90 come Wolfenstein 3D.
Il tutto é stato realizzato con il framework grafico [Raylib](https://github.com/raysan5/raylib).

## Come funziona?

Supponendo che tutti i muri all'interno del nostro mondo di gioco siano tutti della **stessa altezza**, per calcolare come visualizzarli a schermo é sufficiente tracciare un raggio con come origine il punto di vista del giocatore parallelo al pavimento. 

Una volta che questo raggio colliderá con un muro, in base alla sua lunghezza, verrá tracciata sullo schermo una **linea verticale**: maggiore é la lunghezza, minore sará la lunghezza della linea tracciata a schermo e piú scuro sará il colore utilizzato per visualizzarla. 

Se questo processo viene effettuato con un numero sufficiente di raggi (in questo progetto ne vengono tracciati 100), e i loro angoli vengono impostati in modo tale da attraversare i muri posizionati in fronte al giocatore, si potrá avere una rappresentazione convincente del mondo attorno a lui.

Rappresentazione semplificata con 5 raggi:

![Screenshot 2024-05-05 161026](https://github.com/MRcodino07/Raylib-Raycaster/assets/58667917/cfec9ea2-d30a-474b-901f-e344526df1b6)


## Perché questo progetto?

Il progetto da noi realizzato migliora le seguenti competenze stabilite dalla piattaforma Unica:
- **Competenza multilinguistica**, dati i numerosi siti in lingua inglese che abbiamo dovuto visitare per studiare il funzionamento di un motore grafico di questo tipo
- **Competenza matematica e competenza in scienze, tecnologie e ingegneria**, per via della forte necessitá di nozioni matematiche per completare il progetto
- **Competenza digitale**
- **Competenza personale, sociale e capacità di imparare a imparare**
- **Competenza imprenditoriale**, dato che é stata necessaria un'organizzazione ordinata del progetto per poterlo realizzare in modo piú agevole

# Utilizzo

## Come compilare il progetto

É consigliato scaricare il progetto utilizzando [Git](https://git-scm.com/) per scaricare correttamente anche le dipendenze. 

Una volta scaricato git, sará sufficiente scrivere da linea di comando: 

`git clone https://github.com/MRcodino07/Raylib-Raycaster.git`

Il progetto é gestito utilizzando il build system [CMake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html), e quindi dovrebbe essere compilabile dalla maggior parte delle piattaforme (le uniche testate da noi sono Arch Linux e Windows) 

Unica incompatibilitá confermata é presente se su linux si utilizza il server grafico Wayland, nel quale non é supportata la funzione `DisableMouse()` di Raylib (sará sufficiente rimuovere la chiamata alla suddetta funzione da main.cpp per far funzionare correttamente il progetto)

## Comandi

Per girarsi a sinistra o a destra é sufficiente muovere il **mouse**, invece per camminare si utilizzano i tasti **WASD**.
I comandi possono essere modificati dal file res/config/player.config:
1. Inserire come primo carattere il pulsante a cui si vuole associare un'azione
2. Aggiungere due numeri che indicano in che direzione il tasto prima specificato muoverá il giocatore (il primo numero indica il movimento in avanti e il secondo il movimento verso destra)

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
