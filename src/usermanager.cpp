#include "UserManager.hpp"
#include <iostream>
#include "PersonelBook.hpp"
#include "BookManager.hpp"
using namespace std;

UserManager::UserManager()
{
    head = nullptr;
}

void UserManager::createCollection()
{
    if (head != nullptr)
    {
        cout << "Zaten bir koleksiyon olusturulmus" << endl;
        return;
    }

    // else ilk kitabı ekleyip lsiteye head ile baglatiyoz kendine
    int id;
    cout << "Koleksiyonun ilk kitabi icin ID giriniz";
    cin >> id;

    head = new UserBook(id);
    head->setNext(head);
    head->setPrev(head); // head = head->prev;

    cout << "Koleksiyon basariyla olustruldu" << endl;
}

void UserManager::addToCollection(int bookId)
{
    if (head == nullptr)
    {
        cout << "Once koleksiyon olusturmalisiniz" << endl;
        return;
    }
    // normal aslinda ekleeme islemi yapicaz suanda.

    UserBook *newBook = new UserBook(bookId);

    UserBook *temp = head;
    while (temp->getNext() != head) // BU DONGU YERİNE DIREKT OLARAK UserBook* last = head->getprev(); headin previ son dugum zaten;
    {
        temp = temp->getNext();
    }
    newBook->setNext(head);
    newBook->setPrev(temp);
    temp->setNext(newBook);
    head->setPrev(newBook);

    cout << "Kitap başariyla koleksiyona eklendi" << endl;
}

void UserManager::setBookAsRead(int bookId)
{

    if (head == nullptr)
    {
        cout << "Koleksiyon olusturmaniz gerekiyor" << endl;
        return;
    }

    UserBook *temp = head;
    bool firstCheck = true;
    while (temp != nullptr && (temp != head || firstCheck)) // ik dugumu kontrol ediyoruz.iceriye girebilmesi icin firscheck yaptim
    {
        firstCheck = false;
        if (temp->getId() == bookId)
        {
            temp->setRead(true);
            cout << "Kitap okundu olarak kaydedildi";
            return;
        }
        temp = temp->getNext();
    }
    cout << "Bu ID'ye sahip bir kitap bulunamadi!" << endl;
}

void UserManager::setBookAsUnRead(int bookId)
{
    if (head == nullptr)
    {
        cout << "Koleksiyon olusturmaniz gerekiyor" << endl;
        return;
    }
    UserBook *temp = head;
    bool firstCheck = true;
    while (temp != nullptr && (temp != head || firstCheck))
    {
        firstCheck = false;
        if (temp->getId() == bookId)
        {
            temp->setRead(false);
            cout << "Kitap okundu olarak kaydedildi";
            return;
        }
        temp = temp->getNext();
    }
    cout << "Bu ID'ye sahip bir kitap bulunamadi";
}

void UserManager::removeBookFromCollection(int bookId)
{

    if (head == nullptr)
    {
        cout << "Once koleksiyon olusturmaniz gerekiyor" << endl;
        return;
    }

    UserBook *temp = head; // temp aslinda silinecek olan burada
    bool firstCheck = true;
    while (temp != nullptr && (temp != head || firstCheck))
    {
        firstCheck = false;

        if (temp->getId() == bookId)
        {
            if (temp->getNext() == temp) // sadece 1 eleman var
            {
                delete temp;
                head = nullptr;
            }
            else
            {
                temp->getPrev()->setNext(temp->getNext());
                // silinecek olanın önceki dugumunu , silinecek olanin bir önceki dugumunun,nextini , silinecek olan dugumun bir sonraki dugumuna isaret ettirdik.
                temp->getNext()->setPrev(temp->getPrev());
                // sillinecke olan tempin bir sonraki dugumunun, prev işaretçisini,temp(silinecekin)bir önceki dugumunu isaret ettiretek temple baglantilairni kiriyoruz.

                // eğer temp,yani silinen dugum head isei yeni head artik head->getNext()olur.

                if (temp == head)
                {
                    head = temp->getNext();
                }

                delete temp;
            }
            cout << "Kitap koleksiyondan basariyla silindi" << endl;
            return;
        }
        temp = temp->getNext();
    }

    cout << "Bu ID'ye sahip kitap bulunamadi" << endl;
}
// bu fonksiyonu aslinda şey de yaparsin, dugumGetir fonksiyonu ile aranacak kitab bulur donderisin.o kitabın oncesini , sonrasını onceki ve sonraki diye bi işaretçiye kaydedersim
//  sonra mesela direkt while dongusu iceriisnde eşitlemeleri yaparsin yukaridaki gibi karisik olmaz.

void UserManager::printCollection(BookManager &bookManager)
{
    // bookmanageri referans alacak şekilde ekledim cunku baslik bilgileri vs ana veri tabanimizda.
    // referans ile de aslinda gerçek nesne üzerinde işlem yapiyoruz.
    if (head == nullptr)
    {
        cout << "Koleksiyon boş..." << endl;
        return;
    }
    UserBook *temp = head;
    bool firstCheck = true;
    int count = 1;
    while (temp != nullptr && (temp != head || firstCheck))
    {
        firstCheck = false;
        cout << "Kitap " << count++ << ":" << endl;
        cout << "ID" << temp->getId() << endl;

        PersonelBook *foundBook = bookManager.findBookById(temp->getId());
        if (foundBook != nullptr)
        {
            cout << "Baslik: " << foundBook->getTitle() << endl;
        }
        else
        {
            cout << "Baslik: (Bulunamadi)" << endl;
        }
        cout << "Durum: " << (temp->isRead() ? "Okundu " : "Okunmadi ") << endl;
        cout << "----------------------" << endl;

        temp = temp->getNext();
    }
}

void UserManager::addComment(int bookId, BookManager &bookManager)
{
    // if (head == nullptr)
    // {
    //     cout << "Yorum yapilabilecek kitap yok,koleksiyon bos." << endl;
    //     return;
    // }

    // UserBook *temp = head;
    // bool firstCheck = true;

    // while (temp != nullptr && (temp != head || firstCheck))
    // {
    //     firstCheck = false;

    //     if (temp->getId() == bookId)
    //     {
    //         string comment;
    //         cout << "Yorumunuzu giriniz: ";
    //         cin.ignore();
    //         getline(cin, comment);

    //         temp->setComment(comment);
    //         cout << "Yorum basariyla eklendi!" << endl;
    //         return;
    //     }
    //     temp = temp->getNext();
    // }
    // cout << "Bu ID'ye sahip bir kitap bulunamadi!" << endl;

    // yorum satirli kisim, koleksiyondaki kitaplarina yorum yapabilmesi.

    PersonelBook *book = bookManager.findBookById(bookId);
    if (book == nullptr)
    {
        cout << "Bu ID'ye sahip bir kitap bulunamadi!" << endl;
        return;
    }

    string comment;
    cout << "Yorumunuzu giriniz: ";
    cin.ignore();
    getline(cin, comment);

    book->setComment(comment);
    cout << "Yorum basariyla eklendi!" << endl;
}

void UserManager::listComment(int bookId,BookManager& bookManager)
{
    // if (head == nullptr)
    // {
    //     cout << "Liste bos" << endl;
    //     return;
    // }

    // UserBook *temp = head;
    // bool firstCheck = true;
    // while (temp != nullptr && (temp != head || firstCheck))
    // {
    //     firstCheck = false;
    //     if (temp->getId() == bookId)
    //     {
    //         if (temp->getComment() != "")
    //         {
    //             cout << temp->getId() << "ID'li kitaba yapilan yorum: " << temp->getComment() << endl;
    //         }
    //         else
    //         {
    //             cout << "Bu kitaba yorum yapilmamis. " << endl;
    //         }
    //         return;
    //     }
    //     temp = temp->getNext();
    // }
    // cout << "Koleksiyonunuzda Bu ID'ye sahip kitap bulunamadi!" << endl;

    // yorum satirli kisim, koleksiyondaki kitaplarina yorum yapabilmesi.

    PersonelBook *book = bookManager.findBookById(bookId);
    if (book == nullptr)
    {
        cout << "Bu ID'ye sahip bir kitap bulunamadi!" << endl;
        return;
    }

    if (book->getComment() != "")
    {
        cout << bookId << " ID'li kitaba yapilan yorum: " << book->getComment() << endl;
    }
    else
    {
        cout << "Bu kitaba yorum yapilmamis." << endl;
    }
}