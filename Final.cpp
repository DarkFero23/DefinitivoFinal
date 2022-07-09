#include<iostream>
#include<thread>
#include<mutex>
#include <queue>

using namespace std;


#define NUM_HILOS 10

queue<char>Colitas;
const char alfabeto[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int cont=0;
mutex flag;

class Monitor {
	public:
	void producir(int productor){
		flag.lock();	
		int random;
		random = rand() % 26;
		char producido=alfabeto[random];
		Colitas.push(producido);
		cout<<"Productor ->"<<productor<<"<- produció: "<<producido<<endl;
		flag.unlock();		
	}
	
	void consumir(int consumidor){
	    flag.lock();	
		int random;
		random = rand() % 26;
		char consumido=alfabeto[random];
		Colitas.pop();
		cout<<"Consumidor ->"<<consumidor<<"<- consumió: "<<consumido<<endl;
		flag.unlock();	
	}
};

class Productor {
	private:
		Monitor* monitor;
		thread t;
		int usuario;
		void run_thread(){			
			for (int i=1; true; i++) {
			    monitor->producir(usuario);		
			}
		}
			
	public:
		Productor(Monitor* mon, int id){
			usuario = id;
			monitor = mon;
			t = thread(&Productor::run_thread, this);
		}
		void join_thread(){
			t.join();	
		}
		
};

class Consumidor {
	private:
		Monitor* monitor;
		thread t;
		int id;
		void run_thread(){			
			for (int i=1; true; i++) {
			    monitor->consumir(id);		
			}
		}
			
	public:
		Consumidor(Monitor* mon, int idd){
			id = idd;
			monitor = mon;
			t = thread(&Consumidor::run_thread, this);
		}
		void join_thread(){
			t.join();	
		}
		
};


int main() {

	Productor* productor[NUM_HILOS];
	Consumidor* consumidor[NUM_HILOS];
	Monitor* mo;
	
	int i;
	for(i=0; i<NUM_HILOS; i++) {
		productor[i] = new Productor(mo, i);
		consumidor[i] = new Consumidor(mo, i);
	}
	
	for(i=0; i<NUM_HILOS; i++) {
		productor[i]->join_thread();	
	    consumidor[i]->join_thread();	
	}

	return 0;
}