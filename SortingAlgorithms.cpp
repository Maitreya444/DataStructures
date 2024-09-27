#include<iostream>
using namespace std;

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();
        void BubbleSort();
        void BubbleSortEfficient();
        void SelectionSort();
        void InsertionSort();
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

template <class T>
void ArrayX<T> :: BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
        //cout<<"Data after pass : "<<i+1<<"\n";
        //Display();
    }
}

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX <T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX <T>::InsertionSort()
{
    int i =0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

int main()
{
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the size of array : \n";
    cin>>iValue;

    ArrayX <int>*obj = new ArrayX<int>(iValue);

    obj->Accept();
    obj->Display();

    obj->SelectionSort();

    cout<<"Data after sorting is : \n";
    obj->Display();

    delete obj;

    delete obj;
    
    return 0;
}