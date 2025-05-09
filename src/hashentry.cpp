#include "HashEntry.hpp"

HashEntry::HashEntry(int id, string t, string c, int r) {
    bookId = id;
    title = t;
    category = c;
    rating = r;
    next = nullptr;
}

int HashEntry::getId() {
    return bookId;
}

string HashEntry::getTitle() {
    return title;
}

string HashEntry::getCategory() {
    return category;
}

int HashEntry::getRating() {
    return rating;
}

void HashEntry::setRating(int r) {
    rating = r;
}

HashEntry* HashEntry::getNext() {
    return next;
}

void HashEntry::setNext(HashEntry* n) {
    next = n;
}
