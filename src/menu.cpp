#include "Menu.hpp"
#include "PersonelLoadList.hpp"
#include "BookManager.hpp"
#include "LoadStack.hpp"
#include "ReturnedStack.hpp"
#include "RequestQueue.hpp"
#include "BookTree.hpp"
#include "HashTable.hpp"
#include <iostream>

void showMainMenu(BookManager &bookManager, UserManager &userManager, LoadStack &loadStack, ReturnedStack &returnedStack, PersonelLoadList &personelLoadList, RequestQueue &requestQueue, HashTable &hashTable)
{

    int choice;

    while (true)
    {
        cout << "\n=====Ana Menu =====" << endl;
        cout << "1.Personel Girisi" << endl;
        cout << "2.Kullanici Girisi" << endl;
        cout << "3.Cikis" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            personelMenu(bookManager, loadStack, personelLoadList, requestQueue, hashTable);
            break;
        case 2:
            userMenu(userManager, bookManager, loadStack, returnedStack, personelLoadList, requestQueue, hashTable);
            break;
        case 3:
            cout << "Programdan Cikiliyor..." << endl;
            return;
        default:
            cout << "Gecersiz secim.Tekrar deneyiniz" << endl;
        }
    }
}

void personelMenu(BookManager &bookManager, LoadStack &loadStack, PersonelLoadList &personelLoadList, RequestQueue &requestQueue, HashTable &hashTable)
{
    int choice;

    while (true)
    {
        cout << "\n--- Personel Menusu ---" << endl;
        cout << "1.Kitap Ekle" << endl;
        cout << "2.Ismine gore kitabi duzenle" << endl;
        cout << "3.ID'Ye gore Kitap Sil" << endl;
        cout << "4.Zaman Damgasi Ile Listele" << endl;
        cout << "5.ID'ye Gore Kitap Ara" << endl;
        cout << "6.Kitap Sayisini Goster" << endl;
        cout << "7.Sayfa Sayisina Gore Sirala" << endl;
        cout << "8.En eski 5 kitabi listele" << endl;
        cout << "9.Hasar Notu Ekle " << endl;
        cout << "10.Hasarli Kitaplari Listele" << endl;
        cout << "11.Odunc Alinan Kitaplari Listele" << endl;
        cout << "12.Iade Edilen Kitaplari Listele" << endl;
        cout << "13.Erisilebilir Kitaplari Listele" << endl;
        cout << "14. Kitap Talebi Karsila" << endl;
        cout << "15. Odunc Alinan Kitaplari Agaca Aktar" << endl;
        cout << "16. Odunc Alma Suresine Gore Filtrele (30 Gun Alti/Ustu)" << endl;
        cout << "17. Basim Yilina Gore Filtrele (1950 Oncesi/Sonrasi)" << endl;
        cout << "18. 1950 Oncesi ve 30 Gunden Uzun Sureli Kitaplar" << endl;
        cout << "19. Kitabi Puanla(personel)" << endl;
        cout << "20.4 ve Uzeri puanli kitaplari listele" << endl;
        cout << "21.Ana Menuye Don" << endl;
        cout << "seciminiz" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookManager.addBook();
            break;
        case 2:
        {
            // bookManager.editByBookName(...);
            string title;
            cout << "Duzenlenecek kitabin basligini giriniz: ";
            cin.ignore();
            getline(cin, title);
            bookManager.editBookByName(title);
            break;
        }
        case 3:
        {
            // bookManager.deleteBookById(...);

            int id;
            cout << "Silinecek kitap ID: ";
            cin >> id;
            bookManager.deleteBookById(id);
            break;
        }
        case 4:
            bookManager.listBooksWithTimestamps();
            break;
        case 5:
        {
            // bookManager.findBookById();
            int id;
            cout << "Aranacak Kitap ID: ";
            cin >> id;

            PersonelBook *found = bookManager.findBookById(id);

            if (found != nullptr)
            {
                cout << "Kitap Bulundu: " << endl;
                cout << "ID: " << found->getId() << endl;
                cout << "Baslik: " << found->getTitle() << endl;
                cout << "Yazar: " << found->getAuthor() << endl;
                cout << "Basim Yili: " << found->getYear() << endl;
                cout << "Sayfa sayisi: " << found->getPages() << endl;

                time_t added = found->getAddedTime();
                cout << "Eklenme zamani : " << ctime(&added);
            }
            else
            {
                cout << " Kitap bulunamadi " << endl;
            }
            break;
        }
        case 6:
            cout << "Toplam kitap sayisi: " << bookManager.getBookCount() << endl;

            break;
        case 7:
            bookManager.sortBooksByPageCount();
            cout << "Kitaplar sayfa sayisina gore siralandi." << endl;
            break;
        case 8:
            bookManager.listOldestFiveBooks();
            break;
        case 9:
        {
            // bookManager.addDamagedNoteToBook(...);
            int id;
            cout << "Hasar Notu eklenecek kitap ID";
            cin >> id;
            bookManager.addDamageNoteToBook(id);
            break;
        }
        case 10:
            bookManager.listDamagedBooks();
            break;
        case 11: // Ödünç alınan kitapları listele
            personelLoadList.listLoans();
            break;
        case 12: // İade edilen kitapları listele
            personelLoadList.listReturns();
            break;
        case 13: // Erişilebilir kitapları listele
            personelLoadList.listAvailableBooks(bookManager, loadStack);
            break;
        case 14:
            handleRequest(requestQueue, bookManager);
            break;
        case 15:
            static BookTree tree; // ağacı burada static tanımlarsak kalıcı olur (menü içinde)
            transferFromStackToTree(loadStack, tree, bookManager);
            break;
        case 16:
        {
            int secim;
            cout << "1 - 30 Gun Altindaki Kitaplar\n2 - 30 Gun Ustundeki Kitaplar\nSecim: ";
            cin >> secim;
            if (secim == 1)
                tree.filterByBorrowTime(30, false);
            else if (secim == 2)
                tree.filterByBorrowTime(30, true);
            else
                cout << "Gecersiz secim.\n";
            break;
        }
        case 17:
        {
            int secim;
            cout << "1 - 1950 Oncesi Kitaplar\n2 - 1950 Sonrasi Kitaplar\nSecim: ";
            cin >> secim;
            if (secim == 1)
                tree.inorderByYear(tree.getRoot(), 1950, false);
            else if (secim == 2)
                tree.inorderByYear(tree.getRoot(), 1950, true);
            else
                cout << "Gecersiz secim.\n";
            break;
        }
        case 18:
        {
            tree.filter1950And30Days();
            break;
        }
        case 19:
        {
            int id, rating;
            cout << "Puan verilecek kitap ID: ";
            cin >> id;
            cout << "Puan (1-5): ";
            cin >> rating;
            if (rating < 1 || rating > 5)
            {
                cout << "Gecersiz puan! (1-5 arasi olmali)\n";
                break;
            }
            PersonelBook *book = bookManager.findBookById(id);
            if (book != nullptr)
            {
                hashTable.insert(book->getId(), book->getTitle(), book->getCategory());
                hashTable.rateBook(book->getId(), rating);
            }
            else
            {
                cout << "Kitap bulunamadi.\n";
            }
            break;
        }
        case 20:
        {
            hashTable.listHighRatedBooks();
            break;
        }
        case 21:
            cout << "Ana menuye donuluyor..." << endl;
            return;
        default:
            cout << "Gecersiz Secenek.Tekrar deneyiniz" << endl;
        }
    }
}

void userMenu(UserManager &userManager, BookManager &bookManager, LoadStack &loadStack, ReturnedStack &returnedStack, PersonelLoadList &personelLoadList, RequestQueue &requestQueue, HashTable &hashTable)
{
    int choice;

    while (true)
    {
        cout << "\n--- KULLANICI MENÜSÜ ---" << endl;
        cout << "1. ID ye Gore Kitaba Yorum Yap" << endl;
        cout << "2. ID ye Gore Yorumlari Listele" << endl;
        cout << "3. Koleksiyon Olustur" << endl;
        cout << "4. Koleksiyona Kitap Ekle" << endl;
        cout << "5. Kitaplari Okundu/Okunmadi Olarak Guncelle" << endl;
        cout << "6. Koleksiyondan Kitap Sil" << endl;
        cout << "7. Koleksiyonu Yazdir" << endl;
        cout << "8. Odunc Kitap Al\n";
        cout << "9. Oduunc Alinan Kitaplari Listele\n";
        cout << "10. Oduunc Alinan (son) Kitabi Iade Et\n"; // stackin mantigi bu
        cout << "11. Iade Edilen Kitaplari Listele\n";
        cout << "12.Talep Menusunu goruntule\n";
        cout << "13. Agac Tabanli Kitap Raporlarini Goruntule\n";
        cout << "14. Kategoriye göre benzer kitap oner" << endl;
        cout << "15. Kitaplari Puanla ve Listele\n";
        cout << "16. Ana Menuye Don" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int bookId;
            string comment;
            cout << "Yorum eklemek istediginiz kitap ID giriniz" << endl;
            cin >> bookId;

            userManager.addComment(bookId, bookManager);
            break;
        }
        case 2:
        {
            int id;
            cout << "Yorumlarini gormek istediginiz kitabin ID'si: ";
            cin >> id;
            userManager.listComment(id, bookManager);
            break;
        }

        case 3:
            userManager.createCollection();
            break;
        case 4:
        {
            int id;
            cout << "Koleksiyona eklemek istediğiniz kitabin ID'si: ";
            cin >> id;
            userManager.addToCollection(id);
            break;
        }
        case 5:
        {
            // userManager.setBookAsRead(...) veya setBookAsUnread(...);
            int id;
            cout << "Durumunu degistireceginiz kitabin ID'sini giriniz: ";
            cin >> id;

            int choice;
            cout << "1 - Okundu olarak isaretle" << endl;
            cout << "2 - Okunmadi olarak isaretle" << endl;
            cout << "Seciminiz: ";
            cin >> choice;

            if (choice == 1)
                userManager.setBookAsRead(id);
            else if (choice == 2)
                userManager.setBookAsUnRead(id);
            else
                cout << "Gecersiz secim!" << endl;

            break;
        }
        case 6:
        {
            int id;
            cout << "Koleksiyondan silmek istediğiniz kitabin ID'si: ";
            cin >> id;
            userManager.removeBookFromCollection(id);
            break;
        }
        case 7:
            userManager.printCollection(bookManager);
            break;
        case 8: //*odunc kitap al;
        {
            int bookId;
            cout << "Odunc almak istediginiz kitap ID'si: ";
            cin >> bookId;
            PersonelBook *book = bookManager.findBookById(bookId);
            if (book != nullptr)
            {
                time_t borrowTime = time(0);
                loadStack.push(book->getId(), book->getTitle());
                personelLoadList.addLoan(book->getId(), book->getTitle(), borrowTime);
                
                hashTable.insert(book->getId(), book->getTitle(), book->getCategory());

                
                cout << "Kitap odunc alindi.\n";
            }
            else
            {
                cout << "Bu ID'ye sahip kitap bulunamadi.\n";
            }
            break;
        }
        case 9: // **Ödünç alınan kitapları listele**
            loadStack.display();
            break;
        case 10: //*odunc alınan kitabı iade et;
        {
            if (!loadStack.isEmpty())
            {
                StackNode *returnedBook = loadStack.pop();
                if (returnedBook != nullptr)
                {
                    time_t returnTime = time(0);
                    returnedStack.push(returnedBook->bookId, returnedBook->bookTitle, returnedBook->borrowTime, returnTime);
                    personelLoadList.addReturn(returnedBook->bookId, returnedBook->bookTitle, returnedBook->borrowTime, returnTime);
                    cout << "Kitap iade edildi ve iade listesine eklendi." << endl;
                    delete returnedBook;
                }
            }
            else
            {
                cout << "Iade edilecek kitap bulunamadi!" << endl;
            }
            break;
        }
        case 11: // **İade edilen kitapları listele**
            returnedStack.display();
            break;
        case 12:
            requestMenu(requestQueue, bookManager);
            break;
        case 13:
            userTreeMenu(loadStack, bookManager);
            break;
        case 14:
        {
            string category;
            cout << "Hangi kategoriye gore kitap onerisi istiyorsunuz? ";
            cin.ignore();
            getline(cin, category);
            hashTable.recommendByCategory(category);
            break;
        }
        case 15:
        {
            int id, rating;
            cout << "Puan verilecek kitap ID: ";
            cin >> id;
            cout << "Puan (1-5): ";
            cin >> rating;
            if (rating < 1 || rating > 5)
            {
                cout << "Gecersiz puan! (1-5 arasi olmali)\n";
                break;
            }
            PersonelBook *book = bookManager.findBookById(id);
            if (book != nullptr)
            {
                hashTable.insert(book->getId(), book->getTitle(), book->getCategory());
                hashTable.rateBook(book->getId(), rating);
                hashTable.listRatedBooks(); // İstersen listelemeyi ayrı bir menüde yapabiliriz.
            }
            else
            {
                cout << "Kitap bulunamadi.\n";
            }
            break;
        }
        case 16:
            cout << "Ana menuye donuluyor..." << endl;
            return;
        default:
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    }
}

void requestMenu(RequestQueue &requestQueue, BookManager &bookManager)
{
    int choice;
    while (true)
    {
        cout << "\n--- Kitap Talep Menusu ---" << endl;
        cout << "1. Kitap Talep Et (Normal)" << endl;
        cout << "2. Kitap Talep Et (Akademik)" << endl;
        cout << "3. Tum Talepleri Listele" << endl;
        cout << "4. Ana Menuye Don" << endl;
        cout << "Seciminiz: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Talep edilen kitap kutuphanede mevcut olmak zorunda degildir.\n ID'yi kendiniz belirleyiniz." << endl;
            int id, pages, year;
            string title, name, author;
            string publisher, language, category;

            cout << "Kitap ID: ";
            cin >> id;
            cin.ignore();
            cout << "Kitap Adi: ";
            getline(cin, title);
            cout << "Yazar Adi: ";
            getline(cin, author);
            cout << "Basim Yili: ";
            cin >> year;
            cout << "Sayfa Sayisi: ";
            cin >> pages;
            cin.ignore();
            cout << "Talep Eden (Isim): ";
            getline(cin, name);
            cout << "Yayinevi: (Yerli / Yabanci)";
            getline(cin, publisher);
            cout << "Dil: (Ingilizce / Turkce)";
            getline(cin, language);
            cout << "Kategori: ";
            getline(cin, category);

            if (bookManager.findBookById(id) != nullptr)
            {
                cout << "Bu kitap zaten kutuphanede mevcut!" << endl;
                continue;
            }

            requestQueue.enqueue(id, title, name, author, year, pages, publisher, language, 0, category);
            cout << "Bu kitap kutuphanede bulunamadi veTalebiniz basariyla eklendi.(normal)" << endl;
        }
        else if (choice == 2)
        {
            int id, pages, year;
            string title, name, author;
            string publisher, language, category;

            cout << "Kitap ID: ";
            cin >> id;
            cin.ignore();
            cout << "Kitap Adi: ";
            getline(cin, title);
            cout << "Yazar Adi: ";
            getline(cin, author);
            cout << "Basim Yili: ";
            cin >> year;
            cout << "Sayfa Sayisi: ";
            cin >> pages;
            cin.ignore();
            cout << "Talep Eden (Akademik): ";
            getline(cin, name);
            cout << "Yayinevi: (Yerli / Yabanci )";
            getline(cin, publisher);
            cout << "Dil: (Turkce / Ingilizce)";
            getline(cin, language);
            cout << "Kategori: ";
            getline(cin, category);

            if (bookManager.findBookById(id) != nullptr)
            {
                cout << "Bu kitap zaten kutuphanede mevcut!" << endl;
                continue;
            }
            else

                requestQueue.academicEnqueue(id, title, name, author, year, pages, publisher, language, category);
            cout << "Bu kitap kutuphanede bulunamadi. Ve Akademik talebiniz basariyla eklendi." << endl;
        }
        else if (choice == 3)
        {
            requestQueue.displayQueue();
        }
        else if (choice == 4)
        {
            cout << "Ana menuye donuluyor..." << endl;
            return;
        }
        else
        {
            cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    }
}

void handleRequest(RequestQueue &requestQueue, BookManager &bookManager)
{
    if (requestQueue.isEmpty())
    {
        cout << "Karsilanacak talep bulunmamaktadir." << endl;
        return;
    }

    RequestNode *talep = requestQueue.peekFront(); // en oncelikli talebi al

    cout << "\n--- Talep Karsilaniyor ---" << endl;
    cout << "ID: " << talep->requestId << endl;
    cout << "Baslik: " << talep->bookTitle << endl;
    cout << "Yazar: " << talep->author << endl;
    cout << "Basim Yili: " << talep->year << endl;
    cout << "Sayfa Sayisi: " << talep->pages << endl;

    // bookManager'a kitap olarak ekle
    time_t now = time(0);
    PersonelBook *newBook = new PersonelBook(
        talep->requestId, talep->bookTitle, talep->author,
        talep->year, talep->pages, now, talep->publisher, talep->language, talep->category);

    // Listeye ekleme  (sona)
    if (bookManager.getHead() == nullptr)
    {
        bookManager.setHead(newBook);
    }
    else
    {
        PersonelBook *temp = bookManager.getHead();
        while (temp->getNext() != nullptr)
            temp = temp->getNext();
        temp->setNext(newBook);
    }

    cout << "Talep edilen kitap kutuphaneye eklendi." << endl;

    requestQueue.dequeue(); // talepten cikart
}

void transferFromStackToTree(LoadStack &stack, BookTree &tree, BookManager &bookManager)
{
    StackNode *current = stack.getTop();

    while (current != nullptr)
    {
        PersonelBook *book = bookManager.findBookById(current->bookId);

        if (book != nullptr)
        {
            BookTreeNode *newNode = new BookTreeNode(
                book->getId(),
                book->getTitle(),
                book->getAuthor(),
                book->getYear(),
                book->getPages(),
                current->borrowTime, // Stack'ten
                book->getPublisher(),
                book->getLanguage(),
                book->getCategory());

            tree.insert(newNode);
        }
        current = current->getNext();
    }

    cout << "Stack'teki kitaplar eksiksiz bir sekilde agaca aktarildi.\n";
}

void userTreeMenu(LoadStack &loadStack, BookManager &bookManager)
{
    BookTree tree;
    transferFromStackToTree(loadStack, tree, bookManager); // stack → tree aktarımı

    int secim;
    while (true)
    {
        cout << "\n--- KULLANICI AĞAÇ RAPOR MENÜSÜ ---" << endl;
        cout << "1. Yayınevine Göre Filtrele (Yerli/Yabanci)" << endl;
        cout << "2. Diline Göre Filtrele (Turkce/Ingilizce)" << endl;
        cout << "3. Sayfa Sayisina Göre Filtrele (1000 Altı/Üstü)" << endl;
        cout << "4. Ana Menüye Dön" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1)
        {
            string publisher;
            cout << "Yayinevi giriniz (Yerli / Yabanci): ";
            cin.ignore();
            getline(cin, publisher);
            tree.filterByPublisher(publisher);
        }
        else if (secim == 2)
        {
            string language;
            cout << "Dil giriniz (Turkce / Ingilizce): ";
            cin.ignore();
            getline(cin, language);
            tree.filterByLanguage(language);
        }
        else if (secim == 3)
        {
            int secenek;
            cout << "1 - 1000 Altı\n2 - 1000 Üstü\nSeciminiz: ";
            cin >> secenek;
            if (secenek == 1)
                tree.filterByPageCount(1000, false);
            else if (secenek == 2)
                tree.filterByPageCount(1000, true);
            else
                cout << "Gecersiz secim." << endl;
        }
        else if (secim == 4)
        {
            cout << "Ana menüye dönülüyor..." << endl;
            return;
        }
        else
        {
            cout << "Geçersiz seçim!" << endl;
        }
    }
}
