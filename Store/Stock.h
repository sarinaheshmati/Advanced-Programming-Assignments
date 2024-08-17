#ifndef Stock_h
#define Stock_h
#include <map>
using namespace std;
class Stock
{
public:
    int get_count(int);
    void change_count_by(int, int);
    map<int, int>& get_items(){ return items;  };
private:
    map<int, int> items;
};

#endif /* Stock_h */
