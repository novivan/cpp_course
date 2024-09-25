//
//  main.cpp
//  lang_cpp
//
//  Created by Ivan Novikov on 14.09.2024.
//

#include <iostream>

/*
 КЛЮЧИ ТОЧНО МОЖНО СРАВНИВАТЬ
 НЕ ДОЛЖНО БЫТЬ УТЕЧЕК ПАМЯТИ
 */
 
/*
 Помимо этого требуется, чтобы следующие конструкции компилировались и корректно работали (корректность подразумевает в том числе отсутствие лишних копирований элементов):

 for (const auto &[k, v] : tree) {}
 for (const auto &[k, v] : tree.range(a, b)) {}
 
 Первая должна перебирать все элементы дерева в порядке возрастания ключа, вторая – только элементы из полуинтервала [a, b), тоже в порядке возрастания.
 */

/*
 methods:
 
//DONE
        добавлениe элементов по ключу
    не должен изменять дерево, если элемент с таким ключем уже существует
 
//UNDONE
        поиск элементов по ключу
    должен возвращать либо валидный итератор на соответствующий элемент, либо итератор равный end(), если такого элемента нет в контейнере
 
//UNDONE
        удалениe элементов по ключу
    если ключа нет в дереве, не меняет его
 
 //UNDONE
        нахождение минимального ключа
 
 //UNDONE
        нахождение максимального ключа
 
 //UNDONE
        перечисления элементов контейнера, значения
    ключей которых лежат в заданном полуинтервале [a, b)
*/

/**
    Итератор может быть реализован в виде внешнего класса.
 Итераторы должны оставаться валидными
 **/


template<class K, class V>
class SearchingTree {
    
typedef  SearchingTree* ptrST;
typedef std::pair<ptrST, ptrST> ptrST_2;
    
private:
    K k;
    V val;
    ptrST left, right;
    
public:
    //FUNCTIONS FROM TASK:
        //DONE:
    SearchingTree(const K &key, const V &value);
    void insert(const K &key, const V &value); //...
        //UNDONE:
    void erase(const K &key); //...
    V find(const K &key); //...
    K min_key();
    K max_key();
    void print_elems(K a, K b);
    
    //ACCOMPANING FUNCTIONS ()
    ptrST_2 split(const K &key);
    ptrST merge(ptrST left, ptrST right);
};

template <class K, class V>
SearchingTree<K, V>::SearchingTree(const K &key, const V &value){
    this->val = value;
    this->k = key;
    this->left = nullptr;
    this->right = nullptr;
    return this;
}


//TODO: обработать создание первой ноды(при вызове insert от nullptr ничего не произойдет)
template <class K, class V>
void SearchingTree<K, V>::insert(const K &key, const V &value) {
    if (this == nullptr) return;
    if (this->k == key) return;
    if (key < this->key) {
        if (this->left) {
            this->left->insert(key, value);
            return;
        }
        this->left = new SearchingTree(key, value);
        return;
    }
    //key > this->key :
    if (this->right) {
        this->right->insert(key, val);
        return;
    }
    this->right = new SearchingTree(key, value);
    return;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
