#include "Menu.hpp"
#include "BookManager.hpp"
#include "UserManager.hpp"
#include "PersonelLoadList.hpp"
#include "ReturnedStack.hpp"
#include "LoadStack.hpp"
#include "RequestQueue.hpp"
#include "HashTable.hpp"

#include <iostream>

using namespace std;
int main()
{

    BookManager bookManager;
    UserManager userManager;
    LoadStack loadStack;
    ReturnedStack returnedStack;
    PersonelLoadList personelLoadList;
    RequestQueue requestQueue;
    HashTable hashTable;

    bookManager.initializeDemoBooks();


        //30 gun mevzusu icin test verilerimiz hazirlaidm
    time_t now = time(0);
    time_t g30Once = now - (31 * 24 * 60 * 60);
    time_t g15Once = now - (15 * 24 * 60 * 60);

    loadStack.push(1001, "Sefiller", g30Once);
    loadStack.push(1002, "Suc ve Ceza", now);
    loadStack.push(1003, "Kurk Mantolu Madonna", g15Once);
    loadStack.push(1004, "1984", now);
    loadStack.push(1005, "Simyaci", g30Once);
    loadStack.push(1006, "Tutunamayanlar", g15Once);

    showMainMenu(bookManager, userManager, loadStack, returnedStack, personelLoadList, requestQueue,hashTable);

    return 0;
}