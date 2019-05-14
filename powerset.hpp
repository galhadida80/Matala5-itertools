#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
#include <bitset>
#include <math.h>
using namespace std;
namespace itertools{
template <class Z>
class powerset
{
    Z a;
public:   
   
        class iterator{

        public:

        decltype(a.begin()) itS;
        decltype(a.begin()) itE;
        int n=0;
        int subsetIndex=0;
        int length=0;
        
            iterator(Z theBaseRange): itS(theBaseRange.begin()), itE(theBaseRange.end())
            {
              auto start=itS;
                while(start!=itE)
                {
                   start++;
                    n++;
                    length++;
                }
                n=pow(2,n);
            }
        iterator& operator++() { 
         subsetIndex++;
         return *this;
        }
        iterator operator++(int) { 
          iterator tmp(*this); 
          operator++(); 
          return tmp;
          }
        bool operator!=( iterator  &rhs) {
         return !(subsetIndex==rhs.n);
        }
     string operator*() 
     {
    auto itPowerS =itS; 
    constexpr int lenght2 = 3;
    string binary = bitset<lenght2>(subsetIndex).to_string(); //to binary
    auto bin=binary.begin();
       string s= "{";
       while (itPowerS!=itE)
       {
            if (*bin=='1')
                {
                        s=s+" "+to_string(*itPowerS);
                }
              itPowerS++; 
              bin++; 
       }
        s=s+'}';
        return s;
        } 
    };
    powerset (Z a): a(a){
    }
    auto begin() 
        { 
            return iterator(a); 
        }  
    auto end()  
        { 
             return iterator(a); 
        }   
};
}