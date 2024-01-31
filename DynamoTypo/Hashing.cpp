#include "Hashing.h"
//class User;
template class HashTable<int/*User*/>;
template<typename T>
HashTable<T>:: HashTable() : size(0) {
     hash_table.resize(table_size);
 }

template<typename T>
 int HashTable<T>::hash(int id) {
     return static_cast<int>((z * id) >> (w - d));
 }

 template<typename T>
 bool HashTable<T>::insert(int id,T key) {
     int index = hash(id) % (table_size);
     if (index >= table_size || index < 0) {
         cout << "index out of range " << std::endl;
         return false;
     }
     hash_table[index].push_back(key);
     size++;
     return true;
 }

 template<typename T>
 T HashTable<T>::remove(int id) {
     int index = hash(id) % table_size;
    size_t size_row = hash_table[index].size();
     for (size_t i = 0; i < size_row; i++) {
         if (hash_table[index][i] == id) {
             T removedUser = hash_table[index][i];
             hash_table[index].erase(hash_table[index].begin() + i);
             size--;
             return removedUser;
         }
     }
     return T{};
 }

 template<typename T>
 T HashTable<T>::find(int id) {
     int index = hash(id) % table_size;
     size_t size_row = hash_table[index].size();
     for (size_t i = 0; i < size_row; i++) {
         if (hash_table[index][i] == id) {
             return hash_table[index][i];
         }
     }
     return T{};
 }

 template<typename T>
 size_t HashTable<T>::getSize() const {
     return size;
 }

 template<typename T>
 void HashTable<T>::printTable() {
     for (int i = 0; i < table_size; i++) {
         cout << "*~~~~~~~~~~~~~~~~~~~~~~~~Level " << i + 1 << std::endl;
         printItemsInIndex(i);
     }
 }

 template<typename T>
 void HashTable<T>::printItemsInIndex(int index) {
     for (const auto& user : hash_table[index]) {
         cout << user << std::endl;
     }
 }

 template<typename T>
 bool HashTable<T>::contains(int id) {
     return find(id) != T{};
 }

 template<typename T>
 bool HashTable<T>::operator==(const HashTable<T>& other) const {
     if (size != other.size)  return false;
     for (int i = 0; i < table_size; i++)
         if (hash_table[i] != other.hash_table[i]) return false;
     return true;
 }

 template<typename T>
 bool HashTable<T>::operator!=(const HashTable<T>& other) const {
     return !(*this == other);
 }
