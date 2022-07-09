## Introduccion
Este proyecto es sobre el ejemploe de Productor, Consumidor y Monitor , el cual se ejecutara en C++ , y tendra un link en GitHub.

## Tablita de contenidos

* [Monitor](#Monitor)
* [Productor](#Productor)
* [Consumidor](#Consumidor)
* [Conclusiones](#CONCLUSIONES)

## Monitor
Esta clase nos indicara que es lo que hace el productor y el consumidor , nos especificara exactamente todo eso.

* Producir: Para esto se agrega un random que hara que coma una letra aleatoria y sera agregada al buffer.
```
void producir(int productor){
    flag.lock();	
    int aleatorio;
    aleatorio = rand() % 26;
    char producido=letras[aleatorio];
    buffer.push(producido);
    cout<<"El productor "<<productor<<" Está produciendo: "<<producido<<endl;
    flag.unlock();		
}
```
* Consumir: Esto lo que se va a consumir.
```
void consumir(int consumidor){
    flag.lock();	
    int aleatorio;
    aleatorio = rand() % 26;
    char consumido=letras[aleatorio];
    buffer.pop();
    cout<<"El consumidor "<<consumidor<<"Está consumiendo:"<<consumido<<endl;
    flag.unlock();		
}
```

Para no tener ningun problema con los hilos hay que colocar un flag para que se vayan controlando los hilos,Es por eso que las funciones anteriormente detalladas se utiliza **flag.lock()** para parar los hilos. 
```


## Productor
El productor tendrá los siguientes atributos:
* Monitor: El monitor en el cuál se realizará la funcion de producir. 
* Thread: Con esto se crea hilos.
* Nombre: Identifcar el nombre hilo.
* Función para correr el hilo.
```
void join_thread(){
    hilo.join();	
}
```



## Consumidor
El consumidor tendrá los siguientes atributos:
* Monitor: El monitor en el cuál se realizará la funcion de producir. 
* Thread: Para la reación del hilo.
* Nombre: Para identificar cada hilo.
* Función para correr el hilo.
```
void join_thread(){
    hilo.join();	
}
```

# CONCLUSIONES
En conclusion este trabajo fue algo forzoso de hacer ya que no me acordaba de nada de Threads y sobre como funciona todo en especial , la verdad fue un trabajo que hizo doler la cabeza.