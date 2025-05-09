#include "BookManager.hpp"
#include <iostream>
#include <ctime> // time() fonksiyonu için

using namespace std;

BookManager::BookManager()
{
    head = nullptr; // başta liste boş oluyor.
}

void BookManager::addBook()
{
    int id, year, pages;
    string title, author, publisher, language, category; // şuan damagenote eklemiyoruz zaten yeni eklenen kitap yenidir.

    cout << "Kitap ID";
    cin >> id;
    cout << "Kitap Adi";
    cin.ignore(); // bosluk karakterlerini temizliyoruz.
    getline(cin, title);
    cout << "Yazar Adi: ";
    getline(cin, author);
    cout << "Basim Yili: ";
    cin >> year;
    cout << "Sayfa Sayisi: ";
    cin >> pages;
    cin.ignore(); // tekrar string alacagimiz icin
    cout << "Yayinevi: (Yerli / Yabanci) ";
    getline(cin, publisher);
    cout << "Dil: (Turkce / Ingilizce) ";
    getline(cin, language);

    cout << "Kategori: ";
    getline(cin, category);

    // Yayinevi kontrolü
    if (publisher == "Yerlı")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Yerli' atandi.\n";
        publisher = "Yerli";
    }
    else if (publisher == "Yabancı")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Yabanci' atandi.\n";
        publisher = "Yabanci";
    }

    // // Dil kontrolü
    if (language == "Türkçe")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Turkce' atandi.\n";
        language = "Turkce";
    }
    else if (language == "İngilizce")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Ingilizce' atandi.\n";
        language = "Ingilizce";
    }

    // zaman damgasını alalım
    time_t now = time(0);

    // şimdi biz personelbooku zaten personel kısmı için olusturduk tek yonlu, dugumumuz personelbookta.
    // oradan dugumlerimizi olusturucaz.

    PersonelBook *newBook = new PersonelBook(id, title, author, year, pages, now, publisher, language, category);

    // liste boşsa yeni ekliyoruz direkt
    if (head == 0)
    {
        head = newBook;
    }
    else
    {
        // değilse de listeye yeni ekleyeceğiz ya, lsitenin sonuna gelelim bir.
        PersonelBook *temp = head;         // gecici bir dugum olusturuyoruzki bası kaybetmeyelim.
        while (temp->getNext() != nullptr) // get metodlarını aslında bu yüzden kullandım bence daha güzel bir şey,hem de modüler.
        {
            temp = temp->getNext();
        }
        temp->setNext(newBook); // aslinda burada şunu yaptık:
        // nexti sonraki gibi düşün,ben hep sonraki ile yaaprdim.
        // temp->next = newBook; şeklinde,tabi biz private yaptık nexti ve onun için de setNext yaptık
        // bu yaptıgımız kapsüllememizi boşa çıkartır.
    }
    cout << "Kitap basariyla eklendi!" << endl;
    // system("pause");
}

void BookManager::initializeDemoBooks()
{

    time_t now1 = time(0);
    time_t now2 = time(0) + 1;
    time_t now3 = time(0) + 2; // saatleri ayni olmasin istedimi.
    time_t now4 = time(0) + 3;
    time_t now5 = time(0) + 4;
    time_t now6 = time(0) + 5;

    PersonelBook *book1 = new PersonelBook(1001, "Sefiller", "Victor Hugo", 1862, 1200, now1, "Yabanci", "Ingilizce", "Roman");
    PersonelBook *book2 = new PersonelBook(1002, "Suc ve Ceza", "Dostoyevski", 1866, 680, now2, "Yabanci", "Ingilizce", "Roman");
    PersonelBook *book3 = new PersonelBook(1003, "Kurk Mantolu Madonna", "Sabahattin Ali", 1943, 160, now3, "Yerli", "Turkce", "Roman");
    PersonelBook *book4 = new PersonelBook(1004, "1984", "George Orwell", 1949, 328, now4, "Yabanci", "Ingilizce", "Roman");
    PersonelBook *book5 = new PersonelBook(1005, "Simyaci", "Paulo Coelho", 1988, 192, now5, "Yabanci", "Ingilizce", "Roman");
    PersonelBook *book6 = new PersonelBook(1006, "Tutunamayanlar", "Oğuz Atay", 1971, 724, now6, "Yerli", "Turkce", "Roman");

    // bu dugumleri birbirine baglayalim simdi.liste olsunlar demi :)
    book1->setNext(book2);
    book2->setNext(book3);
    book3->setNext(book4);
    book4->setNext(book5);
    book5->setNext(book6);
    book6->setNext(nullptr);

    if (head == nullptr)
    {
        head = book1;
    }
    // biz önce addbook ile kitap ekledik diyelim 2 tane, peşinden book1,book2,book3 direkt eklenmiş mi olucak ?
    // eğer hiç kitap eklemezsek de direkt head =book1 olcak 3 ü birden eklecnek
    else
    {
        PersonelBook *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(book1); // son dugumun nextine yeni kitaplari bagladik.
    }
}

void BookManager::listBooksWithTimestamps()
{
    if (head == nullptr)
    {
        cout << "Liste Bos.Gosterilecek kitap yok!" << endl;
        return;
    }

    PersonelBook *temp = head;
    int count = 1;
    while (temp != nullptr) // bu sefer son dugume ulasabilmek değil,son dugumde dahil hepsine ulasmak istiyoruz.
    {
        cout << "\nKitap: " << count++ << endl;
        cout << "ID: " << temp->getId() << endl;
        cout << "Baslik: " << temp->getTitle() << endl;
        cout << "Yazar: " << temp->getAuthor() << endl;
        cout << "Basim Yili: " << temp->getYear() << endl;
        cout << "Sayfa Sayisi: " << temp->getPages() << endl;
        cout << "Kategori: " << temp->getCategory() << endl;
        cout << "Yayinevi: " << temp->getPublisher() << endl;
        cout << "Dil: " << temp->getLanguage() << endl;
        // zaman damgasini okunabilir yapalim
        time_t added = temp->getAddedTime();
        cout << "Ekleme zamani: " << ctime(&added); // cunku ctime pointerla adres ister.

        temp = temp->getNext();
    }
}

PersonelBook *BookManager::findBookById(int targetId)
{
    if (head == nullptr)
    {
        cout << "liste bos" << endl;
        return nullptr;
    }
    PersonelBook *temp = head;
    while (temp != nullptr)
    {
        if (temp->getId() == targetId)
        {
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

int BookManager::getBookCount()
{
    if (head == nullptr)
    {
        cout << " hiç kitap yok." << endl;
        return 0;
    }
    int count = 0;

    PersonelBook *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->getNext();
    }

    return count;
}

void BookManager::addDamageNoteToBook(int id)
{
    // personel hasar tespiti yaptıgı kitabın idsini girerek o kitap için bir hasar
    // notu string eklesin.bu damagenote kısmına eklensin.setdamagenote()metodu ile bunu atayalım

    // id yi bulalim hangi kitapa hasar kaydi yapcaz.

    PersonelBook *book = findBookById(id);

    // bulunduysa notumuzu alalm

    if (book != nullptr)
    {
        string note;
        cout << "Hasar notunu giriniz" << endl;
        cin.ignore();       // onceki cinden kalan newline ı temizleyecek bu
        getline(cin, note); // notu tam olarak alir
        book->setDamageNote(note);
        cout << "Hasar notu basariyla eklendi." << endl;
    }
    else
        cout << "kitap bulunamadi" << endl;
}

void BookManager::listDamagedBooks()
{
    if (head == nullptr)
    {
        cout << "Kitap listesi bos" << endl;
        return;
    }
    PersonelBook *temp = head;
    int found = 0;
    while (temp != nullptr)
    {
        if (temp->getDamageNote() != "")
        {
            cout << "\n--- Hasarli Kitap ---" << endl;
            cout << "ID: " << temp->getId() << endl;
            cout << "Baslik: " << temp->getTitle() << endl;
            cout << "Yazar: " << temp->getAuthor() << endl;
            cout << "Basim Yili: " << temp->getYear() << endl;
            cout << "Sayfa Sayisi: " << temp->getPages() << endl;
            cout << "Hasar Notu: " << temp->getDamageNote() << endl;
            found++;
        }
        temp = temp->getNext();
    }
    if (found == 0)
    {
        cout << "Hasarli kitap bulunamadi";
    }
}

void BookManager::editBookByName(string targetTitle)
{
    int found = 0;

    if (head == nullptr)
    {
        cout << "Liste bos.kitap yok" << endl;
        return;
    }

    PersonelBook *temp = head;
    while (temp != nullptr)
    {
        if (temp->getTitle() == targetTitle)
        {
            string newTitle, newAuthor, newPublisher, newLanguage, newCategory;
            int newYear, newPages;
            cout << "yeni baslik: ";
            cin.ignore();
            getline(cin, newTitle);

            cout << "Yeni yazar adi";
            getline(cin, newAuthor);

            cout << "Yeni basim yili";
            cin >> newYear;

            cout << "Yeni sayfa sayisi";
            cin >> newPages;

            cout << "Yeni yayinevi (Yerli/Yabanci): ";
            getline(cin, newPublisher);

            cout << "Yeni dil (Türkçe/İngilizce): ";
            getline(cin, newLanguage);

            cout << "Yeni kategori: ";
            getline(cin, newCategory);

            // Kontroller
            if (newPublisher != "Yerli" && newPublisher != "Yabanci")
                newPublisher = "Yabanci";

            if (newLanguage != "Türkçe" && newLanguage != "İngilizce")
                newLanguage = "Türkçe";
            // bunları guncelleyelim

            temp->setTitle(newTitle);
            temp->setAuthor(newAuthor);
            temp->setYear(newYear);
            temp->setPages(newPages);
            temp->setPublisher(newPublisher);
            temp->setLanguage(newLanguage);
            temp->setCategory(newCategory);

            cout << "Kitap bilgileri basariyla guncellendi" << endl;
            return;
        }
        temp = temp->getNext();
    }
    cout << "Kitap bulunamadi";
}

void BookManager::deleteBookById(int targetId)
{
    if (head == nullptr)
    {
        cout << "Liste bos kitap yok";
        return;
    }
    // burada isler söyle , biz silinecek dugumu bulacagız once, ama silinecek dugumun oncekindeki dugumun nextini
    //  silinecek dugumun sonrasına baglamamaiz lazim.
    // yani kisaca öönceki dugumun nexti , silinecej dugumun sonrakini gostermeli.
    // temp şuan aradıgımız dugum. temp->getNext() bir sınraki dugum
    // bir de o zaman onceki kullanalim, onceki->next = temp->next diyeceğiz.
    // onu da zaten onceki->setNext(temp->getNext()); yani tempin(silinecek olanin)nextini onceki dugumun nextine ayarla demek bu.

    if (head->getId() == targetId)
    {
        PersonelBook *toDelete = head;
        head = head->getNext(); // basi bir ileri kaydirdik;
        delete toDelete;
        cout << "Kitap basariyla silindi ( bastaki kitap)";
        return;
    }

    // yukaridaki yorum satirlarinda acikladigimi söyle yapariz
    PersonelBook *onceki = head;
    PersonelBook *temp = head->getNext(); // bu da hemen sonraki oldu zaten.biz diyelim
    // birer birer aslinda peşpeşe ilerlemiş olcaklar.
    // onceki suan başta,temp ise baş+1 de.dongu içerisinde baş temp olucak(yani baş + 1),temp ise temp->getNext() ile bir sonraki olmus olcak.
    // böyle böyle silicez.
    while (temp != nullptr)
    {
        if (temp->getId() == targetId)
        {
            onceki->setNext(temp->getNext()); // baglantiyi kurmus olduk silinenin oncesi ve sonrasi ile arasindkani
            delete temp;
            cout << "Kitap basariyla silindi";
            return;
        }
        onceki = temp;
        temp = temp->getNext();
    }

    cout << "Kitap bulunamadi,silinemedi" << endl;
}

void BookManager::swapBookData(PersonelBook *i, PersonelBook *j)
{
    // pointerlarımızı takasa etmeyeceğiz tabi bu listede veri tutarsızlıgını olusturur.
    // bilgileri takas edicez.
    // burayı şey gibi düşün
    // int temp = i;
    // int i = j;
    // int j = temp;

    int tempId = i->getId();
    string tempTitle = i->getTitle();
    string tempAuthor = i->getAuthor();
    int tempYear = i->getYear();
    int tempPages = i->getPages();
    time_t tempAddedTime = i->getAddedTime();
    string tempDamageNote = i->getDamageNote();
    string tempPublisher = i->getPublisher();
    string tempLanguage = i->getLanguage();
    string tempCategory = i->getCategory();

    // i ye j yi kopyaaldık
    i->setId(j->getId());
    i->setTitle(j->getTitle());
    i->setAuthor(j->getAuthor());
    i->setYear(j->getYear());
    i->setPages(j->getPages());
    i->setAddedTime(j->getAddedTime());
    i->setDamageNote(j->getDamageNote());
    i->setPublisher(j->getPublisher());
    i->setLanguage(j->getLanguage());
    i->setCategory(j->getCategory());

    // j ye tempi kopyalicaz yani i nin bilgileirni aslinda

    j->setId(tempId);
    j->setTitle(tempTitle);
    j->setAuthor(tempAuthor);
    j->setYear(tempYear);
    j->setPages(tempPages);
    j->setAddedTime(tempAddedTime);
    j->setDamageNote(tempDamageNote);
    j->setPublisher(tempPublisher);
    j->setLanguage(tempLanguage);
    j->setCategory(tempCategory);
}
void BookManager::sortBooksByPageCount()
{

    if (head == nullptr)
    {
        cout << "Liste bos,siralanacak kitap yok." << endl;
        return;
    }
    // bubble sort ile sıralayalım.
    PersonelBook *i = head;
    // PersonelBook *j = i->getNext(); // j, i den sonraki dugum fark ediliyor zaten.
    while (i != nullptr)
    {
        PersonelBook *j = i->getNext(); // j, i den sonraki dugum fark ediliyor zaten.
        // her seferinde bir sonrakini karşılaştırmak için dongu içerisine aldik.
        while (j != nullptr)
        {
            if (i->getPages() > j->getPages())
            {
                swapBookData(i, j);
            }
            j = j->getNext();
        }
        i = i->getNext();
    }
}

void BookManager::listOldestFiveBooks()
{
    if (head == nullptr)
    {
        cout << "Liste bos,kitap yok.Siralanamiyor" << endl;
    }

    else
    {
        PersonelBook *i = head;
        while (i != 0)
        {
            PersonelBook *j = i->getNext();
            while (j != 0)
            {
                if (i->getYear() > j->getYear())
                {
                    swapBookData(i, j);
                }
                j = j->getNext();
            }
            i = i->getNext();
        }
    }
    int sayac = 0;
    PersonelBook *temp = head;
    while (temp != nullptr && sayac < 5)
    {
        cout << "ID: " << temp->getId() << endl;
        cout << "Baslik: " << temp->getTitle() << endl;
        cout << "Yazar: " << temp->getAuthor() << endl;
        cout << "Basim Yili: " << temp->getYear() << endl;
        cout << "Sayfa Sayisi: " << temp->getPages() << endl;
        cout << "---------------------------" << endl;
        temp = temp->getNext();
        sayac++;
    }
}

PersonelBook *BookManager::getHead() const
{
    return head;
}

void BookManager::setHead(PersonelBook *h)
{
    this->head = h;
}

void BookManager::addBookByData(int id, string title, string author, int year, int pages, time_t addedTime, string publisher, string language, string category)
{
    // Aynı ID varsa eklenmesin
    if (findBookById(id) != nullptr)
    {
        cout << "Bu ID'ye sahip bir kitap zaten mevcut. Eklenemedi!" << endl;
        return;
    }

    if (publisher == "Yerlı")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Yerli' atandi.\n";
        publisher = "Yerli";
    }
    else if (publisher == "Yabancı")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Yabanci' atandi.\n";
        publisher = "Yabanci";
    }

    // // Dil kontrolü
    if (language == "Türkçe")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Turkce' atandi.\n";
        language = "Turkce";
    }
    else if (language == "İngilizce")
    {
        cout << "Gecersiz dil bilgisi. Varsayilan olarak 'Ingilizce' atandi.\n";
        language = "Ingilizce";
    }

    PersonelBook *newBook = new PersonelBook(id, title, author, year, pages, addedTime, publisher, language, category);

    if (head == nullptr)
    {
        head = newBook;
    }
    else
    {
        PersonelBook *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newBook);
    }

    cout << "Kitap talep uzerine kutuphaneye eklendi!" << endl;
}
// ben handlerequestta direkt olarak new PersonelBook ile nesne olusturup bagli lsiteye kendim bagliyorum.
// bu fonksiyon ile daha temiz kullanim olur aslinda ama bence digeri daha anlasilir,orad gorunsun.
