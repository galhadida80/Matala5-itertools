#include <iostream> 
#include <bitset>
#include <math.h>
#include <string>
#include <set>


using namespace std;
namespace itertools{
template <class Z>
class powerset
{
Z a;
public:   
typedef
typename remove_const<
typename remove_reference<
decltype(*a.begin())>::type>::type Element;

class iterator{
private:
decltype(a.begin()) iterStart;
decltype(a.begin()) iterEnd;

void reverseStr(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
}
    

public:
   
    int n=0;
    int ind=0;
    int length=0; 
    iterator(Z theBaseRange): iterStart(theBaseRange.begin()), iterEnd(theBaseRange.end())
    {
        auto start=iterStart;
        while(start!=iterEnd)
        {
            start++;
            n++;
            length++;
        }
        n=pow(2,n);
    }
    iterator& operator++()
    { 
        ind++;
        return *this;
    }
    iterator operator++(int) 
    { 
        iterator tmp(*this); 
        operator++(); 
        return tmp;
    }
    
    bool operator!=( iterator  &rhs) {return !(ind==rhs.n);}
    set<Element> operator*() 
    {
        auto point = iterStart; 
        // int lenght2 = length;
        string binary = bitset<100>(ind).to_string(); //to binary
        reverseStr(binary);
        auto bin = binary.begin();
        auto binend = binary.end();
        string b = "";
        string s = "{";
        string h = "";
        set<Element> g;
        while (point!=iterEnd)
        {

            if((h[0] > 96 && h[0] < 123) || (h[0] > 64 && h[0] < 91))
            {
                if (*bin=='1' && *bin!=*binend)
                { 
                    g.insert(*point); 
                } 
            }
            else
            {  
                if (*bin=='1' && *bin!=*binend)
                { 
                    g.insert(*point);
                }
            }
            point++; 
            bin++;
        }
        return g;
        } 
    };
    powerset (Z a): a(a){}
    auto begin() const {return iterator(a); }  
    auto end() const{return iterator(a);}   
};
}
template <typename Y>
ostream &operator<<(ostream &os, const set<Y> &Set)
{
    os << "{";

    auto iter = Set.begin();
    if(iter != Set.end())
    {//first time without ','
        os << *iter; 
        ++iter;
    }

    while (iter != Set.end())
    {
        os << ',' << *iter;
        ++iter;
    }
    os << "}";
    return os;
}