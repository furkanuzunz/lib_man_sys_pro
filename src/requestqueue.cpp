#include "RequestQueue.hpp"

// first in first out yapıda kuyrugumuz.
// akademik olanlar oncelikli oldugu icin iki farklı fonksiyon olucak.

RequestQueue::RequestQueue()
{

    // aslinda bunu ilk ve son olarak da düşünebiliriz,hatta öyle yapsam daha iyi olurdu gibi.

    // şöyle düşünebilirisn gene de
    // front(ön) → İlk eleman
    //     Kuyruktan ilk çıkarılacak(dequeue edilecek) elemandır.
    //     Yani FIFO(First In First Out) mantığında en önce giren.

    //     back (arka) → Son eleman
    // Kuyruğa son eklenen (enqueue edilen) elemandır.

    // Yani en arkadaki kişi gibi düşün, sıranın sonunda bekler.

    this->front = nullptr;
    this->back = nullptr;
}

// normal talep ekliyoruz,öncelgiimiz sifir suanda.
void RequestQueue::enqueue(int id, string title, string requester, string author, int year, int pages,string publisher,string language, int priority,string category)
{

    RequestNode *newNode = new RequestNode(id, title, requester, author, year, pages, priority,publisher,language,category);

    if (isEmpty())
    {
        front = back = newNode; // boşsa kuyruk naptık hem arka hem önü yeni eklenene bagladik.
    }

    else
    {
        back->next = newNode; // şöyle düşün, son elemanın nextini newnnode yaptin, ve sonra da son elemanı newNode yaptin
        back = newNode;       // yani sondan eklemis olduk, son eleman newnode oldu.şekil çiz daha iyi oturur.
    }
}

void RequestQueue::academicEnqueue(int id, string title, string requester, string author, int year, int pages,string publisher,string language,string category)
{
    RequestNode *newNode = new RequestNode(id, title, requester, author, year, pages, 1,publisher,language,category);

    if (isEmpty())
    {
        front = back = newNode;
        return;
    }
    // eğer ilk düğüm normal düğümse , öncelikli olanı başa ekle.
    if (front->priority == 0)
    {
        newNode->next = front; // üstteki mantik 38.satirdaki
        front = newNode;
        return;
    }

    // Eğer öncelikli başka akademik varsa araya yerleştirilir.
    //  kuyrugun icinde dogru konumu bulup eklememiz lazim
    RequestNode *temp = front;
 

    while (temp != nullptr && temp->next->priority == 1)
    {
      
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    //newNode, temp'in sonrasına bağlanıyor.

    //Bu, akademik düğüm grubunun sonuna eklemek anlamına geliyor.


    // eğer sone eklendiyse backi de guncellemeliyiz
    if(newNode->next == nullptr)
    {
        back = newNode;
    }

}

//kuyruktan cikarma , personel bookmanagera talebi eklediginde yani
void RequestQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "Kuyruk bos, cikartilacak talep yok."<<endl;
        return;
    }
    // kuyruk = FIFOOO UNUTMA.!
    RequestNode *temp = front;
    front = front->next;

    // tek eleman varsa , back de guncellenmeli
    if(front == nullptr)
        back = nullptr;
    
    cout << "Talep cikarili: ID=" << temp->requestId << ",Kitap: "<<temp->bookTitle << endl;
    delete temp;
}

// kuyrugu gösterelim
void RequestQueue::displayQueue() const {
    if (isEmpty()) {
        cout << "Kuyruk bos." << endl;
        return;
    }
    RequestNode *temp = front;
    cout << "--- Kitap Talep Kuyrugu ---" << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->requestId
             << " | Kitap: " << temp->bookTitle
             << " | Talep Eden: " << temp->requestName
             << " | Yazar: " << temp->author
             << " | Basim Yili: " << temp->year
             << " | Sayfa Sayisi: " << temp->pages
             << " | Oncelik: " << (temp->priority == 1 ? "Akademik" : "Normal") << endl;
        temp = temp->next;
    }
    cout << "----------------------------" << endl;
}


// Boş mu kontrolü
bool RequestQueue::isEmpty() const
{
    return front == nullptr;
}

RequestNode* RequestQueue::peekFront() const
{   
    if (isEmpty()) {
        cout << "Kuyruk bos. Goruntulenecek talep yok." << endl;
        return nullptr;
    }
    return front;
}