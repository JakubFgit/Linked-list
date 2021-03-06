#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename Key, typename Info>
class Sequence
{
    struct Element {
        Key k;
        Info i;
        Element* next;
    };
    Element* head;
    int count1;

public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence<Key, Info>& otherList);
    void clear_list();
    void print();
    void Copy_List(const Sequence<Key, Info>& otherList);
    int length()const;
    Key Position_key(int position)const;
    Info Position_info(int position)const;
    bool remove_elem(const Key& kold);
    bool search_for_element(const Key& k, const Info& i);
    //bool search_for_key(const Key& k);
    //bool search_for_data(const Info& i);
    //insertion methods
    bool addFirst(const Key& k, const Info& i);
    bool addLast(const Key& k, const Info& i);
    bool insert_at(const Key& k, const Info& i, int position);
    //Operators
    friend ostream& operator<<(ostream& o, const Sequence<Key, Info>& s) { print(); return 0; };
    Sequence<Key, Info> operator+(const Sequence<Key, Info>& other)const;
    Sequence<Key, Info> operator-(const Sequence<Key, Info>& s) const;
    const Sequence<Key, Info>& operator=(const Sequence<Key, Info>& otherList);
};
template <typename Key, typename Info>
Sequence<Key, Info> ::Sequence(const Sequence<Key, Info>& otherList)
{
    head = NULL;
    Copy_List(otherList);
}
template <typename Key, typename Info>
Sequence<Key, Info> ::Sequence()
{
    head = NULL;
    count1 = 0;
}
template <typename Key, typename Info>
Sequence<Key, Info> ::	~Sequence()
{
    clear_list();
}
template <typename Key, typename Info>
int Sequence<Key, Info>::length() const
{
    return count1;
}
template <typename Key, typename Info>
void  Sequence<Key, Info> ::clear_list()
{
    if (head == NULL)
        return;

    Element* ptr;
    do {
        ptr = head;//set ptr to current node
        head = ptr->next;//first to the next element
        delete ptr;//deallocate memory
    } while (head != NULL);
    count1 = 0;
}
template <typename Key, typename Info>
bool Sequence<Key, Info> ::addFirst(const Key& k, const Info& i)
{
    Element* curr = new Element;

    if (curr == NULL)
    {
        return false;
    }
    curr->i = i;
    curr->k = k;
    curr->next = head;
    head = curr;
    count1++;

    return true;
}
template <typename Key, typename Info>
bool Sequence<Key, Info> ::addLast(const Key& k, const Info& i)
{
    Element* curr = new Element;
    Element* ptr = head;


    if (curr == NULL)
    {
        return false;
    }
    curr->i = i;
    curr->k = k;
    curr->next = NULL;
    if (head == NULL)//adding as head
    {
        head = curr;

        count1++;
        return true;
    }
    else {

        while (ptr->next)//traversing the list and adding at the end
        {
            ptr = ptr->next;
        }
        ptr->next = curr;
        count1++;
        return true;
    }
    return false;

}
template<typename Key, typename Info>
bool Sequence<Key, Info>::insert_at(const Key& k, const Info& i, int position)
{
    if (position > length() + 1 || position < 0)
    {
        cout << " Position does not exist" << endl;
        return false;
    }
    if (position == 0)
    {
        addFirst(k, i);
        return true;
    }
    else if (position == length())
    {
        addLast(k, i);
        return true;
    }
    else
    {
        Element* el = new Element;
        Element* current;
        if (el == NULL)
        {
            cerr << "Allocation memory failure" << endl;
            return false;
        }
        el->k = k;
        el->i = i;
        current = head;
        int n = position;
        for (int d = 0; d < n - 1; d++)
        {
            current = current->next;
        }
        el->next = current->next;
        current->next = el;
        count1++;
        return true;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::remove_elem(const Key& kold)
{
    Element* ptr = head;
    Element* prev_ptr = head;

    if (ptr->k == kold) //if element is head, than delete head and makes next element be header one.
    {
        head = ptr->next;
        delete ptr;
        count1--;

        return true;
    }
    while (ptr->next)
    {
        if (ptr->k == kold) {
            prev_ptr->next = ptr->next;
            delete ptr;
            count1--;
            return true;
        }
        prev_ptr = ptr;
        ptr = ptr->next;
    }  // traversing if element not found

    return false;
}
template <typename Key, typename Info>
Key Sequence<Key, Info>::Position_key(int position)const
{
    Element* curr = head;
    if (head != NULL)
    {
        int n = 0;
        do
        {
            if (n == position)
                return curr->k;
            n++;
            curr = curr->next;
        } while (curr != NULL);
    }

    else cout << "List is empty" << endl;
    return 0;

}
template <typename Key, typename Info>
Info Sequence<Key, Info>::Position_info(int position)const
{
    Element* curr = head;
    if (head != NULL)
    {
        int n = 0;
        do
        {
            if (n == position)
                return curr->i;
            n++;
            curr = curr->next;
        } while (curr != NULL);
    }

    else cout << "List is empty" << endl;
    return 0;

}
/*template <typename Key, typename Info>
Key Sequence<Key, Info>::search_for_key(const Key& k)
    {
        Element*current;
        current = head;

        while (current != NULL)
        {
            if (current->k == k)
                return current->k;
            current = current->next;

        }
        return 0;
    }
template <typename Key, typename Info>
bool Sequence<Key, Info>::search_for_data(const Info& i)
    {
        Element* current;
        current = head;

        while (current != NULL)
        {
            if (current->i == i)
                return true;
            current = current->next;

        }
        return false;
    }*/
template <typename Key, typename Info>
bool Sequence<Key, Info>::search_for_element(const Key& k, const Info& i)
{
    Element* current;
    current = head;
    if (head == NULL)
    {
        return false;
    }
    while (current != NULL)
    {
        if (current->i == i && current->k == k)
        {
            return true;
        }
        else
            current = current->next;
    }
    return false;
}
template <typename Key, typename Info>
const Sequence<Key, Info>& Sequence<Key, Info>::operator=(const Sequence<Key, Info>& otherList)
{
    if (this != &otherList)//do not self copy
    {
        Copy_List(otherList);
    }
    return *this;
}
template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>:: operator+(const Sequence<Key, Info>& other)const
{
    Sequence<Key, Info> another; // create empty list
    Element* temp = head;
    while (temp) { // copy all content from another list into other list
        another.addFirst(temp->k, temp->i);
        temp = temp->next;
    }
    temp = other.head;
    while (temp) { // copy all content from second list into other list
        another.addFirst(temp->k, temp->i);
        temp = temp->next;
    }
    return another;
}

template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>:: operator-(const Sequence<Key, Info>& s) const
{
    Sequence<Key, Info> other; // create empty list
    Element* temp = head;
    if (temp == NULL) { // substracted list is empty
        return other;
    }
    temp = head;
    while (temp) { // copy all content from first list into result list
        other.addLast(temp->k, temp->i);
        temp = temp->next;
    }

    temp = s.head;
    while (temp) { // remove elements from second list on the result list
        other.remove_elem(temp->k);
        temp = temp->next;
    }
    return other;
}
template <typename Key, typename Info>
void Sequence<Key, Info>::Copy_List(const Sequence<Key, Info>& otherList)
{

    Element* NewElement;//pointer to create a node
    Element* current;//pointer to traverse the list

    if (head != NULL) //if the list is nonempty, make it empty
        clear_list();
    if (otherList.head == NULL) //otherList is empty
    {
        head = NULL;
    }
    else
    {
        head = new Element;
        head->k = otherList.head->k;//copy key
        head->i = otherList.head->i;//copy info
        head->next = NULL;//set the next of the element to NULL
        NewElement = head;//sets new element as head
        current = otherList.head->next;//current pointer to the next element

        while (current)//copy the remaining list
        {
            NewElement->next = new Element;  //create element
            NewElement = NewElement->next;
            NewElement->k = current->k;//copy key
            NewElement->i = current->i;//copy info
            NewElement->next = NULL;//set the next of the new element to NULL
            current = current->next;// make current point to next element
        }
        count1 = otherList.count1;
    }
}
template <typename Key, typename Info>
void  Sequence<Key, Info> ::print()
{
    Element* ptr = head;
    if (head == NULL)
    {
        return;
    }
    while (ptr != NULL)
    {
        cout << ptr->k << "--> " << ptr->i << endl;
        ptr = ptr->next;
    }
}

template <typename Key, typename Info>
int split(const Sequence<Key, Info>& source, int start, Sequence<Key, Info>& result1, int step1, Sequence<Key, Info>& result2, int step2)
{
    int position = start;
    int count = 1;

    if (position < 0 || position >= source.length() + 1)
    {
        cout << "Start cannot be determined" << endl;
        return 0;
    }
    cout << "The length of the source is:" << source.length() << endl;
    cout << "The starting position is:" << position << endl;
    while (position < source.length())
    { //cout<<position<<endl;
        for (int i = 0; i < step1; i++)
        {
            if (position >= source.length()) return count;//checking of not the end of the sequence
            result1.addLast(source.Position_key(position), source.Position_info(position));
            position++;

        }
        for (int i = 0; i < step2; i++)
        {
            if (position >= source.length()) return count;
            result2.addLast(source.Position_key(position), source.Position_info(position));//adding to result list using position_key and position_info
            position++;
        }
        count += 1;
    }
    return count;
}

int main()
{
    Sequence<int, int> s1, s2, s3, s22, s21;
    Sequence<int, int> res1;
    Sequence<int, int> res2;
    s1.addFirst(1, 1);
    s1.addFirst(2, 2);
    s1.addFirst(3, 3);
    //s1.insertAtPosition(0,0,1);
    s1.addFirst(4, 4);
    s1.addLast(5, 5);
    s1.addLast(6, 6);
    s1.remove_elem(5);
    s1.insert_at(20, 20, 3);
    s1.insert_at(11, 11, 99);
    s1.insert_at(12, 12, -3);
    s1.insert_at(13, 13, 0);
    s1.insert_at(18, 18, 7);
    //s1.insertAfter(8, 2, 8,2,3,2);
    cout << "S1:" << endl;
    s1.print();
    cout << "is there element 1?" << endl;
    cout << s1.search_for_element(1, 1) << endl << endl;
    cout << "The length of sequence is:" << s1.length() << endl;
    //cout<<s1.search_for_key(6)<<endl<<endl;
    //cout<<s1.search_for_data(6)<<endl<<endl;
    //s1.remove_elem(1,1);
    //s1.remove_elem(4,4);
    //cout << "S1 after removing:"<<endl;
    //s1.print();

    s2.addLast(3, 3);
    s2.addLast(5, 5);
    s2.addLast(16, 16);

    s22 = s1 - s2;
    cout << "S22;" << endl;
    s22.print();
    cout << s22.length() << endl;
    cout << "adding last as head, S2:" << endl;
    s2.print();
    cout << endl;

    s3 = s1;  //usage of operator=
    cout << "S3 = S1(operator=):" << endl;
    s3.print();
    cout << "S3 length:" << s3.length() << endl;
    s3 + s2 = s21;
    cout << "S21(using operator+):" << endl;
    s21.print();
    cout << s21.length() << endl;

    Sequence<int, int> s9(s3);  //usage of Copyconstructor
    cout << "S9 length:" << s9.length() << endl;
    cout << "S9 is copied from using copy constructor:" << endl;
    s9.print();


    cout << "split S9:" << endl;
    int s;
    s = split<int, int>(s9, 3, res1, 2, res2, 1);
    //int u= split<int, float>(s4,10,res1 ,2,res2, 1);
    cout << "int s: " << s << endl;
    //cout<<"int: "<<u<<endl;
    cout << "result1: ";
    res1.print();
    cout << endl;
    cout << "result2: ";
    res2.print();
    cout << endl;

    Sequence<int, string>s6;
    Sequence<int, string>re1, re2;

    s6.addLast(1, "one");
    s6.addFirst(2, "two");
    s6.addFirst(3, "three");
    s6.addLast(4, "four");

    s6.addFirst(5, "five");
    s6.addLast(6, "six");
    s6.addLast(7, "seven");
    s6.addFirst(8, "eight");
    cout << endl;
    cout << "S6:" << endl;
    s6.print();
    cout << endl;
    cout << "split: " << endl;
    int p = split<int, string>(s6, 3, re1, 3, re2, 1);
    int z = split<int, string>(s6, 99, re1, 3, re2, 1);
    int u = split<int, string>(s6, -3, re1, 3, re2, 1);
    cout << " after splitting:" << endl;
    cout << "int: " << p << endl;
    cout << "res1: ";
    re1.print();
    cout << endl;
    cout << "res2: ";
    re2.print();
    cout << "int: " << z << endl;
    cout << "int: " << u << endl;

    cout << endl;

    return 0;
}
