#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    std::cout << *(ptr + 2) << " " << *(arr + 2) << " " << arr[2] << " " << ptr[2];
    return 0;
}
