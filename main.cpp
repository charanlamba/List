#include "List.h"

using namespace std;

int main()
{
    List<int> arr, list;
    arr.add(1);
    arr.add(2);
    list = arr;
    list[0] = 2;
    list.display();
    return 0;
}