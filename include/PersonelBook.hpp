#ifndef PersonelBook_hpp
#define PersonelBook_hpp
using namespace std;

#include <string>

// bu sınıf tek yonlu bagli listede her bir kitabı temsil edecek
//  personel bu nesneler ekleyecek,silecek, düzenleyecek.
// kullanıcılar da bu nesneler üzerinden kitap bilgilerini okuyacak , yorumlarını kendi tarafında sağlayacak

// kitap oluştururken id,title,author,year,pages gibi bilgiler constructor ile verilecek.
// damageNote boş başlasın
// addedTime o anki zaman
// get,set metotlarını yazacahız.

// personelbook sınıfı tek yonlu lsitenin dugumlerini tutup,
// bookmanager ise bu düğümlerin lsitesini tutar.

// şimdi aynısını userbook için usermanagerı yapıcaz.

class PersonelBook
{
private:
    int id;
    string title;
    string author;
    int year;
    int pages;
    string damageNote;
    string publisher;
    string language;
    time_t addedTime;
    PersonelBook *next;

    string comment;

    string category;

public:
    PersonelBook(int id, string title, string author, int year, int pages, time_t addedTime,string publisher, string language,string category);

    // getterslari yapalim.encapsulation icin gerekli bence sonucta private tanimladik
    int getId();
    string getTitle();
    string getAuthor();
    int getYear();
    int getPages();
    time_t getAddedTime();
    string getDamageNote();
    PersonelBook *getNext();

    string getPublisher() const;
    string getLanguage() const;

    string getCategory() const;

    // setterslari yapali bakalim
    void setDamageNote(string note);
    void setNext(PersonelBook *nextBook);
    void setTitle(string title);
    void setAuthor(string author);
    void setYear(int year);
    void setPages(int pages);
    void setId(int id);
    void setAddedTime(time_t addedTime);
    void setPublisher(const string &publisher);
    void setLanguage(const string &language);
    void setCategory(const string &category);

    void setComment(const string &c) { comment = c; }
    string getComment() const { return comment; }
};

#endif