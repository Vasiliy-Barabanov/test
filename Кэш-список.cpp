#include <iostream>
#include<string>

using namespace std;

template <typename T>
class Container
{
private:
    struct s {
        T val;
        int k;
        s* next;
        s* priv;
    };
    s* head;
public:
    Container(T value) {
        head = new s;
        head->val = value;
        head->k = 0;
        head->next = nullptr;
        head->priv = nullptr;
    }

    Container(const Container& other) { //конструктор копирования
        s* n = other.head;
        while (n->next != nullptr) {
            this->head->add(n->val);
                n = n->next;
        }
        this->head->add(n->val);
    }

   void add(T value) {
        s* n = head;
        s* a = new s;
        a->val = value;
        a->k = 0;
        a->next = nullptr;
        while (n->next != nullptr)
            n = n->next;
        n->next = a;
        a->priv = n;
    }
   int search(T znach) {
        s *st = head;
        s* a = new s;
        while (st->val != znach && st->next != nullptr) {
            st = st->next;
        }
        a = st;
        if ((st->next == nullptr) && (st->val != znach))
            return -1;
        else {
            if ((st->priv != nullptr)) {
                a->k++;              
                st->priv->next = st->next;
                s* ks = head;
                while (a->k < ks->k) {
                    ks = ks->next;
                }
                a->priv = ks->priv;
                if (ks->priv != nullptr)
                    ks->priv->next = a;
                ks->priv = a;
                a->next = ks;
                if (a->priv == nullptr)
                    head = a;
            }
            else a->k++;
        }
            
    }
   void see() {
       s* n = head;
       while (n->next != nullptr) {
           cout << n->val << ' ' << n->k << endl;
           n = n->next;
       }
       cout << n->val << ' ' << n->k << endl;
   }
    ~Container() {
        s* n;
        while (head->next != nullptr) {
            n = head->next;
            delete head;
            head = n;
        }
        delete head;
    }
};


int main()
{
   Container < string > mycont("gg");
   mycont.add("fdfd");
   mycont.add("tttt");
   mycont.add("uuu");
   mycont.search("fdfd");
   mycont.search("fdfd");
   mycont.search("uuu");
   mycont.search("fdfd");
   mycont.search("gg");
   mycont.see();
}