#include <iostream>
using namespace std;

// D�k�man bilgileri i�inde kullan�lacak d�k�man sahibi bilgileri i�in veri tipi tan�m�
struct Person {
	string firstName;
	string lastName;
	string userName;
	string eMailAddress;
	int birthYear;
};

// D�k�man bilgileri i�inde kullan�lacak olu�turulma tarihi i�in veri tipi tan�m�
struct Date {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

// D�k�man bilgileri i�in veri tipi tan�m�
struct Document {
	string name;
	double size;
	int pageNumber;
	struct Person owner;
	struct Date creationDate;	
};

// CircularList d���mleri i�in veri tipi tan�m�
struct Node {
	struct Document document;
	int priority;
	struct Node* next;
};

// Kuyruk veri yap�s�nda kullan�lacak dairesel liste veri tipi tan�m�
struct CircularList {
	struct Node* cursor;	// cursor dairesel ba�l� listede sondaki elemana i�aret eden pointerd�r.
	
	CircularList();	// constructor 
	~CircularList();	// destructor
	
	bool isEmpty() const;	// Liste bo� mu de�il mi kontrol eder bo�sa true de�ilse false d�ner.
	struct Document frontElement() const;	// listenin �n taraf�ndaki eleman� d�nd�r�r fakat listeden silmez o y�zden fonksiyon const.
	struct Document backElement() const;	// listenin arka taraf�ndaki eleman� d�nd�r�r fakat listeden silmez o y�zden fonksiyon const.
	void addElement(struct Document& document, int priority);	// listeye parametre olarak verilen eleman� priority (�ncelik) de�erine g�re uygun s�raya ekler.
	void removeFront();	// listenin �n�ndeki eleman� siler.
};

CircularList::CircularList() {
	cursor = NULL;	// ba�ta listeyi bo� oldu�u i�in cursor NULL'a setlenir.
}

CircularList::~CircularList() {
	while (!isEmpty())	// destructor fonksiyonu de�i�kenin i�i bitti�inde bellekteki d���mlerini siler.
		removeFront();	
}

bool CircularList::isEmpty() const {
	return (cursor == NULL);	// liste bo� mu de�il mi cursor NULL ise bo�tur.
}

struct Document CircularList::frontElement() const {
	return (cursor->next->document);	// listenin �n�ndeki eleman� d�nd�r. cursor dairesel ba�l� listede son elemana i�aret eder.
};

struct Document CircularList::backElement() const {
	return (cursor->document);	// listenin arkas�ndaki eleman� d�nd�r yani cursor�n i�aret etti�i ��nk� cursor dairesel ba�l� listede son elemana i�aret eder.
};

void CircularList::addElement(struct Document& document, int priority) {
	struct Node* newNode = new Node;	// Dairesel listenin arkas�na eklenecek yeni Node i�in bellekte alan olu�turup de�erlerini setledim.
	newNode->document = document;
	newNode->priority = priority;
	newNode->next = NULL;
	
	if (cursor == NULL) {	// liste bo� ise direk ekle
		newNode->next = newNode;
		cursor = newNode;
	}
	
	else {	// de�il ise �ncelik de�erine bakarak uygun bir s�raya ekle
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
		
		// newNode u back ile front aras�na ekle
		
		back->next = newNode;
		newNode->next = front;
	}
	
}

void CircularList::removeFront() {
	
	if (cursor->next == cursor) {	// sadece tek eleman varsa direk cursor�n i�aret etti�ini sil
		delete cursor;
		cursor = NULL;
	}
	
	else {	// cursor� ilerletip cursor�n nextini yani en ba�taki eleman� sil
		struct Node* temp = cursor->next;
		cursor->next = cursor->next->next;
		delete temp;
	}
}

// Kuyruk i�in veri tipi tan�m�
struct PriorityQueue {
	struct CircularList list;
	int size;
	int maximumCapacity;
	
	PriorityQueue(int maxCapacity);
	
	bool isFull() const;	// liste dolu mu dolu ise true de�ilse false
	bool isEmpty() const;	// liste bo� mu bo� ise true de�ilse false
	void changeCapacity(int newCapacity); // kapasiteyi de�i�tiren fonksiyon
	int getDocumentNumber() const;	// kuyrukta mevcut olan d�k�man say�s�n� d�nd�r�r
	bool addDocument(struct Document& document, int priority);	// kuyru�a belge ekleyen fonksiyon
	struct Document getFirstDocument() const;	// kuyruktaki ilk d�k�man� d�nd�r�r
	
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
	
	cout << "D�k�man yazd�r�l�yor..." << endl;
}


int main(int argc, char** argv) {
	return 0;
	
	
	
}
