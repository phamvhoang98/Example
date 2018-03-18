#include<iostream>
#include<fstream>
#define n 100

using namespace std;

struct priorityQueue{
	int last;
	int a[n];
};
struct priorityQueue pQueue;

void Insert(int value){
	int temp;
	if(pQueue.last > n - 1){
		cout << "Priority Queue is overflow" << endl;
		return;
	}
	else{
		pQueue.last++;
		pQueue.a[pQueue.last] = value;
		int i = pQueue.last;
		while(i > 1 && pQueue.a[i] < pQueue.a[i/2]){
			int t = pQueue.a[i];
			pQueue.a[i] = pQueue.a[i/2];
			pQueue.a[i/2] = t;
			i = i/2;
		}
	}
}
void priQueue(char* filename){
	fstream file;
	file.open(filename);
	int value;
	while(file >> value){
		Insert(value);
	}
	file.close();
}
int deleteMin(){
	if(pQueue.last == 0){
		cout << " Priority Queue is Empty!" << endl;
		return 0;
	}
	else {
		int Min = pQueue.a[1];
		pQueue.a[1] = pQueue.a[pQueue.last];
		pQueue.last --;
		int found = 0;
		int i = 1, j ;
		while(i <= pQueue.last/2 && found == 0){
			if(pQueue.a[2*i] < pQueue.a[2*i + 1])
				j = 2*i;
			else j = 2*i + 1;
			if(pQueue.a[i] > pQueue.a[j]){
				int temp = pQueue.a[i];
				pQueue.a[i] = pQueue.a[j];
				pQueue.a[j] = temp;
				i = j;
			}
			else found = 1;
		}
		return Min;
	}
}
void printQueue(){
	if(pQueue.last == 0) {
		cout << "Priority Queue is empty!" << endl;
		return;
	}
	for(int i = 1; i <= pQueue.last; i ++){
		cout << pQueue.a[i] << " ";
	}
	cout << endl;
}
int main(){
    char a[] = "priorityQueue.txt" ;
	priQueue(a);
	cout << "Priority queue : ";
	printQueue();
	int value = 18 ;
	cout << "Priority queue sau khi them " << value <<" la : ";
	Insert(value);
	printQueue();
	cout << "Priority queue sau khi xoa min : ";
	deleteMin();
	printQueue();
	return 0;
}
