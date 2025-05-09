#ifndef UserManager_hpp
#define UserManager_hpp

#include "UserBook.hpp"
#include "BookManager.hpp"
#include "PersonelBook.hpp"
#include <string>
class UserManager
{
private:
    UserBook *head;

public:
    UserManager();

    void createCollection();
    void addToCollection(int bookId);
    void setBookAsRead(int bookId);
    void setBookAsUnRead(int bookId);
    void removeBookFromCollection(int bookId);
    void printCollection(BookManager& bookManager);
    void addComment(int bookId,BookManager& bookManager);
    void listComment(int bookId,BookManager& bookManager);// sadece koleksiyondaki olsaydıd bookmanager eklemezdik

    




};





#endif