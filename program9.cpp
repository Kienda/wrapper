/*
Abdoulaye Diallo
Program9
*/

#include <iostream>

using namespace std;

const long DEFAULT_SIZE = 100;

class Array
{

private:
    int *array = nullptr;
    int size = 0;

    void create_array()
    {

        if ((get_size() > 0) && (get_array() == nullptr))
        {
            array = new int[get_size()];

            for (int i = 0; i < get_size(); i++)
            {
                array[i] = i;
            }
        }
    }

public:
    Array()
    {

        set_size(DEFAULT_SIZE);
        create_array();

        return;
    }

    Array(int size)
    {

        set_size(size);
        create_array();

        return;
    }

    ~Array()
    {

        delete (get_array());

        return;
    }

    int *get_array()
    {

        return array;
    }

    int get_size()
    {

        return size;
    }

    int return_element(int element_number)
    {
        int element = 0;

        element = get_array()[element_number];

        return element;
    }

    void set_array(int *in_array)
    {

        array = in_array;

        return;
    }

    void set_size(int in_size)
    {

        size = in_size;

        return;
    }

    void resize(int n)
    {
        int new_array[n] = {};

        if (get_size() > n)
        {
            for (int i = 0; i < n; i++)
            {
                new_array[i] = return_element(i);
                cout << "The new array [" << i << "]: " << new_array[i] << endl;
            }
        }
        delete (get_array());
    }
};

int main()
{
    Array *test = nullptr;
    Array *test2 = nullptr;
    Array *new_array = nullptr;

    new_array = new Array();

    new_array->resize(10);

    if (test == nullptr)
    {
        test = new Array();
        for (int i = 0; i < test->get_size(); i++)
            cout << "test[" << i << "] = " << test->return_element(i) << endl;
    }

    if (test2 == nullptr)
    {
        test2 = new Array(101);
        for (int i = 0; i < test2->get_size(); i++)
            cout << "test2[" << i << "] = " << test2->get_array()[i] << endl;
        cout << "test2[100] is " << test2->return_element(100) << endl;
    }

    delete (new_array);
    delete (test);
    delete (test2);

    return 0;
}
