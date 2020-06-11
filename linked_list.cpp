#include <iostream>

using namespace std;


template<typename Key, typename Info>
 struct Element{
    Key k;
    Info i;
    Element<Key,Info> *next;
    };

template<typename Key, typename Info>
class Sequence
{


    Element<Key,Info>* head=NULL;
    size_t lenght;

public:
    Sequence();
    ~Sequence();
    //bool insertAfter(const Key&k,k new, const Info,i new, const Key&kwhere);
    bool remove_elem(const Key&kold);
    //bool findel(const Key)

};

template <typename Key, typename Info>
int split(const Sequence<Key,Info>&source, int start, Sequence<Key,Info>&result1,int step1, Sequence<Key,Info>&result2, int step2)
{

if(head= NULL) return false;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
