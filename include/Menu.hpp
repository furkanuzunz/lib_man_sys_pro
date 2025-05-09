#ifndef Menu_hpp
#define Menu_hpp

#include "BookManager.hpp"
#include "UserManager.hpp"
#include "LoadStack.hpp"
#include "ReturnedStack.hpp"
#include "PersonelLoadList.hpp"
#include "RequestQueue.hpp"
#include "BookTree.hpp"
#include "HashTable.hpp"


void showMainMenu(BookManager &bookManager, UserManager &userManager, LoadStack &loadStack, ReturnedStack &returnedStack,PersonelLoadList &personelLoadList,RequestQueue &requestQueue,HashTable& hashTable);

void personelMenu(BookManager &bookManager, LoadStack &loadStack, PersonelLoadList &personelLoadList,RequestQueue& requestQueue,HashTable& hashTable);

void userMenu(UserManager &userManager, BookManager &bookManager, LoadStack &loadStack, ReturnedStack &returnedStack,PersonelLoadList &personelLoadList,RequestQueue &requestQueue,HashTable& hashTable);//bookmanagerdan kitapları alıp usermanager ile yöneticek

void requestMenu(RequestQueue &requestQueue,BookManager& bookManager);

void handleRequest(RequestQueue &requestQueue, BookManager &bookManager);

void transferFromStackToTree(LoadStack &stack, BookTree &tree, BookManager &bookManager);

void userTreeMenu(LoadStack& loadStack, BookManager& bookManager);

#endif