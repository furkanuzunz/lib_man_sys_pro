#ifndef UserBook_hpp
#define UserBook_hpp

#include "BookManager.hpp"
#include  "PersonelBook.hpp"

//bu sınıfta kullanıcı sadece bir koleksiyonunu temsil edebilecek
//yorum yapmma,yorumları listeleme,1 koleksiyon oluşturma,kendi kitap koleksiyonuna kitap eklemesi,
// okundu okunmadı ataması ,koleksiyonuna eklediği kitaı silmesi ıd ye göre,koleksiyonundaki kitapları ayzdrıma
//buradaki kaynak ana veritabanı değildir o personelbook.hpp de ki ana veritabanıdır.


class UserBook
{
private:
    int id;
    bool read;
    string comment;
    UserBook *next;
    UserBook *prev;
public:
    UserBook(int id);

    // getters ve setterslar
    int getId();
    bool isRead();
    void setRead(bool r);
    string getComment();
    void setComment(string c);

    UserBook *getNext();
    void setNext(UserBook *n);
    UserBook *getPrev();
    void setPrev(UserBook *p);

};

#endif