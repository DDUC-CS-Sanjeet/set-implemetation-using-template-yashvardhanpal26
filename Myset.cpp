#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

template <typename T>
class MySet
{
    private:
        T *arr;
        int card;
    public:
        // Constructor to initialise the instance variables
        MySet(int size = 0)
        {
            card = size;
            arr = new T[size];
        }
        // Function to take input of arr and removing duplicates in the set
        void takearr()
        {
            for(int i = 0; i < card; ++i)
                cin >> arr[i];
            removeDuplicates();
        }
        // Function to display the set in the readable format
        void display()
        {
            cout << "{ ";
            for(int i = 0; i < card; ++i)
            {
                cout << arr[i];
                if(i != card - 1)
                    cout << ", ";
                else
                    cout << " ";
            } 
            cout << "}" << endl;
        }
        // Function to remove duplicates in the set
        void removeDuplicates()
        {
            for(int i = 0; i < card; ++i)
                for(int check = i + 1; check < card; ++check)
                    if(arr[i] == arr[check])
                    {
                        for(int del = check; del < card; ++del)
                            arr[del] = arr[del+1];
                        card--;
                        check--;
                    }
        }
        // Overloading + operator to find the union of two sets
        MySet operator+ (const MySet obj)
        {
            MySet temp(card + obj.card);
            int i = 0;
            for(int copy = 0; copy < card; ++copy)
                temp.arr[i++] = arr[copy];
            for(int copy = 0; copy < obj.card; ++copy)
                temp.arr[i++] = obj.arr[copy];
            temp.removeDuplicates();
            return temp;
        }
        // Overloading * operator to find the intersection of two sets
        MySet operator* (const MySet obj)
        {
            int count = 0;
            for(int i = 0; i < card; ++i)
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                        count++;
            MySet temp(count);
            count = 0;
            for(int i = 0; i < card; ++i)
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                        temp.arr[count++] = arr[i];
            return temp;
        }
        // Overloading - operator to find the difference between two sets
        MySet operator- (const MySet obj)
        {
            int count = 0;
            for(int i = 0; i < card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet temp(count);
            int temp_i = 0;
            for(int i = 0; i < card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.arr[temp_i++] = arr[i];
            }
            return temp;
        }
        // Overloading ^ operator to find the symmetric difference between two sets
        MySet operator^ (const MySet obj)
        {
            int count = 0;
            for(int i = 0; i < card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            for(int i = 0; i < obj.card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < card; ++check)
                    if(obj.arr[i] == arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    count++;
            }
            MySet temp(count);
            count = 0;
            for(int i = 0; i < card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < obj.card; ++check)
                    if(arr[i] == obj.arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.arr[count++] = arr[i];
            }
            for(int i = 0; i < obj.card; ++i)
            {
                int flag = 0;
                for(int check = 0; check < card; ++check)
                    if(obj.arr[i] == arr[check])
                    {
                        flag++;
                        break;
                    }
                if(flag == 0)
                    temp.arr[count++] = obj.arr[i];
            }
            return temp;
        }
        // Overloading = operator to assign the values of one set into another
        MySet operator= (const MySet obj)
        {
            MySet temp(obj.card);
            for(int i = 0; i < card; ++i)
                temp.arr[i] = obj.arr[i];
            return temp;
        }
        // Overloading == operator to check if two sets are equal or not
        bool operator== (const MySet obj)
        {
            if(card != obj.card)
                return false;
            else
            {
                int flag = 0;
                for(int i = 0; i < card; ++i)
                    for(int check = 0; check < obj.card; ++check)
                        if(arr[i] == obj.arr[check])
                            flag++;
                if(flag == card)
                    return true;
                else
                    return false;
            }
        }
        // Function to print the card of a set
        void printcard()
        {
            cout << card;
        }
        // Function to print the power set of a given set
        void powerSet()
        {
            int powerset_size = pow(2, card);
            for(int counter = 0; counter < powerset_size; ++counter)
            {
                int count_arr = 0;
                cout << "{ ";
                for(int set = 0; set < card; ++set)
                    if(counter & (1 << set))
                    {
                        if(count_arr != 0)
                            cout << ", ";
                        cout << arr[set];
                        count_arr++;
                    }
                cout << " }";
                if(counter != powerset_size - 1)
                    cout << ", ";
            }
        }
};

//Function to print all the sets
template <typename T>
void printSets(MySet <T> firstSet, MySet <T> secondSet, MySet <T> thirdSet, MySet <T> fourthSet, MySet <T> fifthSet, MySet <T> sixthSet, bool answer)
{
    system("cls");
    cout << "Set A: ";
    firstSet.display();
    cout << "\nSet B: ";
    secondSet.display();
    cout << "\nUnion: ";
    thirdSet.display();
    cout << "\nIntersection: ";
    fourthSet.display();
    cout << "\nDifference: ";
    fifthSet.display();
    cout << "\nSymmetric Difference: ";
    sixthSet.display();
    cout << "\nPower Set of A... \n{ ";
    firstSet.powerSet();
    cout << " }\n";
    cout << "\nPower Set of B... \n{ ";
    secondSet.powerSet();
    cout << " }\n";
    if(answer == true)
        cout << "\nEquality: The Sets A and B are equal\n\n";
    else
        cout << "\nEquality: The Sets A and B are not equal\n\n";
}

int main()
{
    int choice_type = 0;
    char choice_iterate = 'N';
    do
    {
        system("cls");
        cout << "*****Menu*****\n";
        cout << "Choose the type of data in the set...\n";
        cout << "1. Integer\n";
        cout << "2. String\n";
        cout << "3. Floating-points\n";
        cout << "Enter your choice: ";
        cin >> choice_type;
        system("cls");
        switch(choice_type)
        {
            case 1: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of arr in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of arr in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <int> firstSet(size_of_1Set);
                        cout << "Enter the arr of 1st Set...\n";
                        firstSet.takearr();
                        MySet <int> secondSet(size_of_2Set);
                        cout << "Enter the arr of 2nd Set...\n";
                        secondSet.takearr();
                        MySet <int> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <int> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <int> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <int> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 2: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of arr in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of arr in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <char> firstSet(size_of_1Set);
                        cout << "Enter the arr of 1st Set...\n";
                        firstSet.takearr();
                        MySet <char> secondSet(size_of_2Set);
                        cout << "Enter the arr of 2nd Set...\n";
                        secondSet.takearr();
                        MySet <char> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <char> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <char> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <char> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            case 3: {
                        int size_of_1Set = 0, size_of_2Set = 0;
                        cout << "Enter the number of arr in the 1st Set: ";
                        cin >> size_of_1Set;
                        cout << "Enter the number of arr in the 2nd Set: ";
                        cin >> size_of_2Set;
                        MySet <float> firstSet(size_of_1Set);
                        cout << "Enter the arr of 1st Set...\n";
                        firstSet.takearr();
                        MySet <float> secondSet(size_of_2Set);
                        cout << "Enter the arr of 2nd Set...\n";
                        secondSet.takearr();
                        MySet <float> thirdSet = firstSet + secondSet;        //To store the union of the two sets
                        MySet <float> fourthSet = firstSet * secondSet;       //To store the intersection of the two sets
                        MySet <float> fifthSet = firstSet - secondSet;        //To store the difference of the two sets
                        MySet <float> sixthSet = firstSet ^ secondSet;        //To store the symmetric difference of two sets
                        bool answer = firstSet == secondSet;
                        printSets(firstSet, secondSet, thirdSet, fourthSet, fifthSet, sixthSet, answer);
                        break;
                    }
            default: cout << "Wrong choice of Options!!!";
        }
        cout << "Do you want to operate more (Y/N): ";
        cin >> choice_iterate;
        system("cls");
    } while (choice_iterate == 'Y' || choice_iterate == 'y');
    return 0;
}
