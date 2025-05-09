#ifndef BookManager_hpp
#define BookManager_hpp
#include <string>
using namespace std;
#include "PersonelBook.hpp"

//book nesnelerini barındırıan tek yonlu baglı listeyi yönetecek ve personelin yaptıgı islemleri gerceklesitricek.
//liste başını burada tutalım

//kitaplarımızı yöneteceğimiz bir bağlı liste sınıfı bu. hani normalde hem düğüm hem balgılsite yapıyorduk o bu.
//düğüm sınıfımız ise aslında book.hpp olan, her kitap için bir düğüm oluşturucaz.


class BookManager
{

private:
    PersonelBook *head;

    
public:
    BookManager();
    void addBook();
    void editBookByName(string targetTitle);
    void deleteBookById(int targetId);
    void listBooksWithTimestamps();
    PersonelBook *findBookById(int targetId);
    int getBookCount();
    void sortBooksByPageCount();
    void listOldestFiveBooks();
    void addDamageNoteToBook(int targetId);
    void listDamagedBooks();

    void swapBookData(PersonelBook* i, PersonelBook* j);
    void initializeDemoBooks();

    PersonelBook* getHead() const;
    void setHead(PersonelBook *newHead);

    void addBookByData(int id, string title, string author, int year, int pages, time_t addedTime, string publisher, string language,string category);





};



#endif