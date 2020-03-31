#include <iostream>
using namespace std;

// Döküman bilgileri içinde kullanýlacak döküman sahibi bilgileri için veri tipi tanýmý
struct Person {
	string firstName;
	string lastName;
	string userName;
	string eMailAddress;
	int birthYear;
};

// Döküman bilgileri içinde kullanýlacak oluþturulma tarihi için veri tipi tanýmý
struct Date {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

// Döküman bilgileri için veri tipi tanýmý
struct Document {
	string name;
	double size;
	int pageNumber;
	struct Person owner;
	struct Date creationDate;	
};

// CircularList düðümleri için veri tipi tanýmý
struct Node {
	struct Document document;
	int priority;
	struct Node* next;
};

// Kuyruk veri yapýsýnda kullanýlacak dairesel liste veri tipi tanýmý
struct CircularList {
	struct Node* cursor;	// cursor dairesel baðlý listede sondaki elemana iþaret eden pointerdýr.
	
	CircularList();	// constructor 
	~CircularList();	// destructor
	
	bool isEmpty() const;	// Liste boþ mu deðil mi kontrol eder boþsa true deðilse false döner.
	struct Document frontElement() const;	// listenin ön tarafýndaki elemaný döndürür fakat listeden silmez o yüzden fonksiyon const.
	struct Document backElement() const;	// listenin arka tarafýndaki elemaný döndürür fakat listeden silmez o yüzden fonksiyon const.
	void addElement(struct Document& document, int priority);	// listeye parametre olarak verilen elemaný priority (öncelik) deðerine göre uygun sýraya ekler.
	void removeFront();	// listenin önündeki elemaný siler.
};

CircularList::CircularList() {
	cursor = NULL;	// baþta listeyi boþ olduðu için cursor NULL'a setlenir.
}

CircularList::~CircularList() {
	while (!isEmpty())	// destructor fonksiyonu deðiþkenin iþi bittiðinde bellekteki düðümlerini siler.
		removeFront();	
}

bool CircularList::isEmpty() const {
	return (cursor == NULL);	// liste boþ mu deðil mi cursor NULL ise boþtur.
}

struct Document CircularList::frontElement() const {
	return (cursor->next->document);	// listenin önündeki elemaný döndür. cursor dairesel baðlý listede son elemana iþaret eder.
};

struct Document CircularList::backElement() const {
	return (cursor->document);	// listenin arkasýndaki elemaný döndür yani cursorýn iþaret ettiði çünkü cursor dairesel baðlý listede son elemana iþaret eder.
};

void CircularList::addElement(struct Document& document, int priority) {
	struct Node* newNode = new Node;	// Dairesel listenin arkasýna eklenecek yeni Node için bellekte alan oluþturup deðerlerini setledim.
	newNode->document = document;
	newNode->priority = priority;
	newNode->next = NULL;
	
	if (cursor == NULL) {	// liste boþ ise direk ekle
		newNode->next = newNode;
		cursor = newNode;
	}
	
	else {	// deðil ise öncelik deðerine bakarak uygun bir sýraya ekle
		struct Node* front = cursor->next;
		struct Node* back = cursor;
		
		while (newNode->priority > front->priority) {
			back = front;
			front = front->next;
			
			if (back == cursor) {
				cursor->next = newNode;
				newNode->next = front;
				cursor = cursor->next;
				return;	
			}
			
		}
		
		// newNode u back ile front arasýna ekle
		
		back->next = newNode;
		newNode->next = front;
	}
	
}

void CircularList::removeFront() {
	
	if (cursor->next == cursor) {	// sadece tek eleman varsa direk cursorýn iþaret ettiðini sil
		delete cursor;
		cursor = NULL;
	}
	
	else {	// cursorý ilerletip cursorýn nextini yani en baþtaki elemaný sil
		struct Node* temp = cursor->next;
		cursor->next = cursor->next->next;
		delete temp;
	}
}

// Kuyruk için veri tipi tanýmý
struct PriorityQueue {
	struct CircularList list;
	int size;
	int maximumCapacity;
	
	PriorityQueue(int maxCapacity);
	
	bool isFull() const;	// liste dolu mu dolu ise true deðilse false
	bool isEmpty() const;	// liste boþ mu boþ ise true deðilse false
	void changeCapacity(int newCapacity); // kapasiteyi deðiþtiren fonksiyon
	int getDocumentNumber() const;	// kuyrukta mevcut olan döküman sayýsýný döndürür
	bool addDocument(struct Document& document, int priority);	// kuyruða belge ekleyen fonksiyon
	struct Document getFirstDocument() const;	// kuyruktaki ilk dökümaný döndürür
	
};


PriorityQueue::PriorityQueue(int maxCapacity) {
	maximumCapacity = maxCapacity;
	size = 0;
}

bool PriorityQueue::isFull() const {
	return (size == maximumCapacity);
}

bool PriorityQueue::isEmpty() const {
	return (size == 0);
}

void PriorityQueue::changeCapacity(int newCapacity) {
	if (newCapacity > maximumCapacity)
		maximumCapacity = newCapacity;
}


int PriorityQueue::getDocumentNumber() const {
	return size;
}

struct Document PriorityQueue::getFirstDocument() const {
	return list.frontElement();
};

bool PriorityQueue::addDocument(struct Document& document, int priority) {
	if (size == maximumCapacity)
		return false;
	else {
		list.addElement(document, priority);
		return true;
	}
}

struct Printer {
	struct PriorityQueue queue;
	int printerSpeed;
	
	Printer(int capacity, int speed);
	
	bool isPrinterFull() const;
	bool isPrinterEmpty() const;
	int getDocumentNumber() const;
	bool addDocument(struct Document& document, int priority);
	void printDocument();
};

Printer::Printer(int capacity, int speed) : queue(capacity) {
	printerSpeed = speed;
}

bool Printer::isPrinterFull() const {
	return queue.isFull();
}

bool Printer::isPrinterEmpty() const {
	return queue.isEmpty();
}

int Printer::getDocumentNumber() const {
	return queue.getDocumentNumber();
}

bool Printer::addDocument(struct Document& document, int priority) {
	if(queue.addDocument(document, priority))
		return true;
	else
		return false;	
}

void Printer::printDocument() {
	struct Document d = queue.getFirstDocument();
	
	cout << "Döküman yazdýrýlýyor..." << endl;
}


int main(int argc, char** argv) {
	return 0;
	
	
	
}
