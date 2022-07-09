# IMPLEMENTACIÓN PRODUCTOR CONSUMIDOR 
El presente proyecto es el resultado de la implementación de Productor - Monitor - Consumidor. Todo usando el lenguaje de programación c++

## Table of Contents

* [Monitor](#Monitor)
* [Productor](#Productor)
* [Consumidor](#Consumidor)
* [Cconclusiones](#CONCLUSIONES)

## Monitor
Monitor es una clase en la que nosotros colocaremos las funciones que realizan cada uno de las partes, en este caso Productor y consumidor:

* Producir: Para que el productor produza los recursos, utilizamos rand para que se tenga un letra aleatoria la cuál próximamenta será añadida al buffer.
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
* Consumir: Para que consuma el recurso producido por el productor.
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

Hay que conciderar que para que no haya un problema con los hilos se colocó un flag para así ir controlando los hilos, **otra alternativa es usar semaphore**. Es por eso que las funciones anteriormente detalladas se utiliza **flag.lock()** para parar los hilos.
```
flag.lock();
```
Así como utilizar el **flag.unlock()** para seguir corriendo los hilos.
```
flag.unlock();
```


## Productor
El productor tendrá los siguientes atributos:
* Monitor: El monitor en el cuál se realizará la funcion de producir. 
* Thread: Para la reación del hilo.
* Nombre: Para identificar cada hilo.
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
