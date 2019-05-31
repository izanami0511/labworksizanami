#include <iostream>

#include "merge_sort.h"
#include "cq.hpp"
#include <ctime>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    int *test_int_pointer = nullptr;
    char *test_char_pointer = nullptr;
    double *test_double_pointer = nullptr;
    float *test_float_pointer = nullptr;
    cq<int> *int_q = nullptr;
    cq<char> *ch_q = nullptr;
    cq<float> *float_q = nullptr;
    cq<double> *double_q = nullptr;
    bool exit = true;
    char c = 0;
    
    do {
        cout << "1 - сортировка слиянием данных с типом int" << endl << "2 - сортировка слиянием данных с типом char" << endl << "3 - сортировка слиянием данных с типом float" << endl << "4 - сортировка слиянием данных с типом double" << endl << "Прекратить работу с функцией сортировки - любая клавиша" << endl;
        c = getchar();
        switch (c)
        {
            case '1':
            {
                int num;
                cout << "Введите размерность массива" << endl;
                cin >> num;
                test_int_pointer = new int[num];
                cout << "Введите данные" << endl;
                for (int i =0;i<num;++i)
                {
                    cout << "int[" << i << "]:" << endl;
                    cin >> test_int_pointer[i];
                }
                try
                {
                    merge_sort(test_int_pointer, 0, num - 1,num);
                }
                catch (int myException)
                {
                    cout << "Массив состоит из одного элемента" << endl;
                    delete[] test_int_pointer;
                    break;
                }
                cout << "Результат сортировки" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "int[" << i << "]:" ;
                    cout << test_int_pointer[i];
                    cout << endl;
                }
                delete[] test_int_pointer;
                break;
            }
            case '2':
            {
                int num;
                cout << "Введите размерность массива" << endl;
                cin >> num;
                test_char_pointer = new char[num];
                cout << "Введите данные" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "char[" << i << "]:" << endl;
                    cin >> test_char_pointer[i];
                }
                try {
                    merge_sort(test_char_pointer, 0, num - 1,num);
                }
                catch (int myException)
                {
                    cout << "Массив состоит из одного элемента" << endl;
                    delete[] test_char_pointer;
                    break;
                }
                cout << "Результат сортировки" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "char[" << i << "]:";
                    cout << test_char_pointer[i];
                    cout << endl;
                }
                delete[] test_char_pointer;
                break;
            }
            case '3':
            {
                int num;
                cout << "Введите размерность массива" << endl;
                cin >> num;
                test_float_pointer = new float[num];
                cout << "Введите данные" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "float[" << i << "]:" << endl;
                    cin >> test_float_pointer[i];
                }
                try
                {
                    merge_sort(test_float_pointer, 0, num - 1,num);
                }
                catch (int myException)
                {
                    cout << "Массив состоит из одного элемента" << endl;
                    delete[] test_float_pointer;
                    break;
                }
                cout << "Результат сортировки" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "float[" << i << "]:";
                    cout << test_float_pointer[i];
                    cout << endl;
                }
                delete[] test_float_pointer;
                break;
            }
            case '4':
            {
                int num;
                cout << "Введите размерность массива" << endl;
                cin >> num;
                test_double_pointer = new double[num];
                cout << "Введите данные" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "double[" << i << "]:" << endl;
                    cin >> test_double_pointer[i];
                }
                try {
                    merge_sort(test_double_pointer, 0, num - 1,num);
                }
                catch (int myException)
                {
                    cout << "Массив состоит из одного элемента" << endl;
                    delete[] test_double_pointer;
                    break;
                }
                cout << "Результат сортировки" << endl;
                for (int i = 0; i < num; ++i)
                {
                    cout << "double[" << i << "]:";
                    cout << test_double_pointer[i];
                    cout << endl;
                }
                delete[] test_double_pointer;
                break;
            }
            default:
            {
                exit = false;
                break;
            }
        }
        
    } while (exit);
    exit = true;
    do {
        cout << "1 - Создать очередь int" << endl << "2 - Создать очередь char" << endl << "3 - Создать очередь float" << endl << "4 - Создать очередь double" << endl;
        c = getchar();
        switch (c)
        {
            case '1':
            {
                int num;
                cout << "Введите размерность" << endl;
                cin >> num;
                int_q = new cq<int>(num);
                char a = 0;
                do {
                    cout << "1 - добавить элемент в очередь" << endl << "2 - удалить элемент из очереди" << endl << "3 - проверить на пустоту" << endl << "Выйти - любая клавиша" << endl;
                    cin >> a;
                    switch (a)
                    {
                        case '1':
                        {
                            int_q->print();
                            +*int_q;
                            int_q->print();
                            break;
                        }
                        case '2':
                        {
                            int_q->print();
                            try
                            {
                                -*int_q;
                            }
                            catch (int myException)
                            {
                                cout << "Нехорошо удалять элементы из пустой очереди!" << endl;
                            }
                            int_q->print();
                            break;
                        }
                        case '3':
                        {
                            if (!*int_q)
                            {
                                cout << "Очередь пуста" << endl;
                            }
                            else
                            {
                                cout << "Очередь не пуста, в ней " << int_q->getnum() << "элементов" << endl;
                            }
                            break;
                        }
                        default:
                        {
                            exit = false;
                            break;
                        }
                    }
                } while (exit);
                break;
            }
            case '2':
            {
                int num;
                cout << "Введите размерность" << endl;
                cin >> num;
                ch_q = new cq<char>(num);
                char a = 0;
                cout << "1 - добавить элемент в очередь" << endl << "2 - удалить элемент из очереди" << endl << "3 - проверить на пустоту" << "Выйти - любая клавиша" << endl;
                cin >> a;
                switch (a)
                {
                    case '1':
                    {
                        ch_q->print();
                        +*ch_q;
                        ch_q->print();
                        break;
                    }
                    case '2':
                    {
                        ch_q->print();
                        try
                        {
                            -*ch_q;
                        }
                        catch (int myException)
                        {
                            cout << "Нехорошо удалять элементы из пустой очереди!" << endl;
                        }
                        ch_q->print();
                        break;
                    }
                    case '3':
                    {
                        if (!*ch_q)
                        {
                            cout << "Очередь пуста" << endl;
                        }
                        else
                        {
                            cout << "Очередь не пуста, в ней " << ch_q->getnum() << "элементов" << endl;
                        }
                        break;
                    }
                    default:
                    {
                        exit = false;
                        break;
                    }
                }
                break;
                
            }
            case '3':
            {
                int num;
                cout << "Введите размерность" << endl;
                cin >> num;
                float_q = new cq<float>(num);
                char a = 0;
                cout << "1 - добавить элемент в очередь" << endl << "2 - удалить элемент из очереди" << endl << "3 - проверить на пустоту" << "Выйти - любая клавиша" << endl;
                cin >> a;
                switch (a)
                {
                    case '1':
                    {
                        float_q->print();
                        +*float_q;
                        float_q->print();
                        break;
                    }
                    case '2':
                    {
                        float_q->print();
                        try
                        {
                            -*float_q;
                        }
                        catch (int myException)
                        {
                            cout << "Нехорошо удалять элементы из пустой очереди!" << endl;
                        }
                        float_q->print();
                        break;
                    }
                    case '3':
                    {
                        if (!*float_q)
                        {
                            cout << "Очередь пуста" << endl;
                        }
                        else
                        {
                            cout << "Очередь не пуста, в ней " << int_q->getnum() << "элементов" << endl;
                        }
                        break;
                    }
                    default:
                    {
                        exit = false;
                        break;
                    }
                }
                break;
            }
            case '4':
            {
                int num;
                cout << "Введите размерность" << endl;
                cin >> num;
                double_q = new cq<double>(num);
                char a = 0;
                cout << "1 - добавить элемент в очередь" << endl << "2 - удалить элемент из очереди" << endl << "3 - проверить на пустоту" << "Выйти - любая клавиша" << endl;
                cin >> a;
                switch (a)
                {
                    case '1':
                    {
                        double_q->print();
                        +*double_q;
                        double_q->print();
                        break;
                    }
                    case '2':
                    {
                        double_q->print();
                        try
                        {
                            -*double_q;
                        }
                        catch (int myException)
                        {
                            cout << "Нехорошо удалять элементы из пустой очереди!" << endl;
                        }
                        double_q->print();
                        break;
                    }
                    case '3':
                    {
                        if (!*double_q)
                        {
                            cout << "Очередь пуста" << endl;
                        }
                        else
                        {
                            cout << "Очередь не пуста, в ней " << double_q->getnum() << "элементов" << endl;
                        }
                        break;
                    }
                    default:
                    {
                        exit = false;
                        break;
                    }
                }
                break;
            }
        }
        
    } while (exit);
    delete int_q;
    delete ch_q;
    delete float_q;
    delete double_q;
    return 0;
}
