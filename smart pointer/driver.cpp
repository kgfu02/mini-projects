#include <iostream>
#include <memory>
#include "my_shared_pointer.h"
#include <string>

using namespace std;

int main() {
    int* a = new int(1);
    int b = 1;
    string s = "jello";
    string t = "hello";

    shared_ptr<int> aPtr = make_shared<int>(*a);
    my_shared_pointer<string> my_aPtr = my_shared_pointer<string>(s);
    {
        my_shared_pointer<string> my_aPtr2 = my_shared_pointer<string>(t);
        my_aPtr = my_aPtr2;
        cout << *my_aPtr.get() << endl;
        cout << my_aPtr.use_count() << endl;
    }
    cout << *my_aPtr.get() << endl;
    cout << my_aPtr.use_count() << endl;
}