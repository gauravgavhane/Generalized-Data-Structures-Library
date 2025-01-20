/////////////////////////////////////////////////////////////////////////////////
//
//  Generalized Data Structures Library
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// Singly Linear Linked List
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;                     // Data of generic type T
    struct nodeSL *next;        // Pointer to the next node
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   SinglyLL
//  Description     :   Implements a singly linear linked list
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> *First;    // Pointer to the first node in the list
        int iCount;                 // Count of nodes in the list

    public:
        SinglyLL();                 // Constructor

        void Display();             // Function to display all elements
        int Count();                // Function to count the number of nodes

        void InsertFirst(T No);     // Function to insert at the beginning
        void InsertLast(T No);      // Function to insert at the end
        void InsertAtPos(T No, int iPos);  // Function to insert at a specific position

        void DeleteFirst();         // Function to delete the first node
        void DeleteLast();          // Function to delete the last node
        void DeleteAtPos(int iPos); // Function to delete a node at a specific position

        // Aggregate Functions
        T Addition();               // Function to calculate sum of all elements
        int EvenCount();            // Function to count even elements
        int OddCount();             // Function to count odd elements
        int Frequency(T No);        // Function to count frequency of an element
        bool Search(T No);          // Function to search for an element
        int SearchFirstOccurrence(T No); // Function to find first occurrence of an element
        int SearchLastOccurrence(T No);  // Function to find last occurrence of an element
        void SumDigits();           // Function to display sum of digits of each element
        T FactorsAddition(T iNo);   // Function to calculate sum of factors of a number
        bool CheckPerfect(T iNo);   // Function to check if a number is perfect
        void DisplayPerfect();      // Function to display perfect numbers from the list
        void SumFactors();          // Function to display sum of factors for each element
        T MiddleElement();          // Function to find middle element (method 1)
        T MiddleElementX();         // Function to find middle element (method 2)        
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  SinglyLL
//  Description:       Initializes an empty singly linear linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;               // Initialize First pointer to NULL
    iCount = 0;                 // Initialize node count to 0
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> *temp = First;  // Temporary pointer for traversal

    while (temp != NULL)             // Traverse until the end of the list
    {
        cout << "| " << temp->data << "|-> ";  // Print current node's data
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl;          // End of list
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Count
//  Description:      Counts the number of nodes in the linked list
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;                   // Return the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertFirst
//  Description:      Inserts an element at the beginning of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> *newn = NULL;   // Pointer to new node

    newn = new nodeSL<T>;            // Allocate memory for new node
    newn->data = No;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                // Set new node as first node
    }
    else
    {
        newn->next = First;          // Link new node to first node
        First = newn;                // Update First to new node
    }
    iCount++;                        // Increment node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertLast
//  Description:      Inserts an element at the end of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> *newn = NULL;   // Pointer to new node
    struct nodeSL<T> *temp = First;  // Temporary pointer for traversal

    newn = new nodeSL<T>;            // Allocate memory for new node
    newn->data = No;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                // Set new node as first node
    }
    else
    {
        while (temp->next != NULL)   // Traverse to the last node
        {
            temp = temp->next;
        }
        temp->next = newn;           // Link last node to new node
    }
    iCount++;                        // Increment node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertAtPos
//  Description:      Inserts an element at a specific position in the linked list
//  Input:            T (generic data type)
//                    Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> *newn = NULL;   // Pointer to new node
    int i = 0;
    struct nodeSL<T> *temp;          // Temporary pointer for traversal

    if ((iPos < 1) || (iPos > iCount + 1))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)                   // Insert at first position
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)     // Insert at last position
    {
        InsertLast(No);
    }
    else
    {
        temp = First;                // Initialize temp pointer

        newn = new nodeSL<T>;        // Allocate memory for new node
        newn->data = No;             // Initialize data
        newn->next = NULL;           // Initialize next pointer to NULL

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;     // Link new node to next node
        temp->next = newn;           // Link (iPos-1)th node to new node
        iCount++;                    // Increment node count
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteFirst
//  Description:      Deletes the first element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = First;  // Temporary pointer to first node

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                // Deallocate memory of first node
        First = NULL;                // Set First to NULL
    }
    else
    {
        First = First->next;         // Move First to next node
        delete temp;                 // Deallocate memory of old first node
    }
    iCount--;                        // Decrement node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteLast
//  Description:      Deletes the last element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = First;  // Temporary pointer for traversal

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                // Deallocate memory of first node
        First = NULL;                // Set First to NULL
    }
    else
    {
        while (temp->next->next != NULL)  // Traverse to second last node
        {
            temp = temp->next;
        }
        delete temp->next;           // Deallocate memory of last node
        temp->next = NULL;           // Set next of second last node to NULL
    }
    iCount--;                        // Decrement node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteAtPos
//  Description:      Deletes an element from a specific position in the linked list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1;         // Temporary pointer for traversal
    struct nodeSL<T> *temp2;         // Pointer to node to be deleted

    if ((iPos < 1) || (iPos > iCount))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)                   // Delete first node
    {
        DeleteFirst();
    }
    else if (iPos == iCount)         // Delete last node
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;               // Initialize temp1 pointer

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;         // Node to be deleted

        temp1->next = temp2->next;   // Link (iPos-1)th node to (iPos+1)th node
        delete temp2;                // Deallocate memory of node to be deleted

        iCount--;                    // Decrement node count
    }
}


/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Addition
//  Description:      Calculates the sum of all elements in the list
//  Input:            None
//  Output:           T (sum of elements)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::Addition()
{
    T iSum = 0;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }

    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    EvenCount
//  Description:      Counts the even numbers in the list
//  Input:            None
//  Output:           Integer (count of even numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::EvenCount()
{
    int iCnt = 0;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    OddCount
//  Description:      Counts the odd numbers in the list
//  Input:            None
//  Output:           Integer (count of odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::OddCount()
{
    int iCnt = 0;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Frequency
//  Description:      Counts the frequency of a specific element in the list
//  Input:            T (element to search)
//  Output:           Integer (frequency of element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Frequency(T No)
{
    int iCnt = 0;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Search
//  Description:      Searches for an element in the list
//  Input:            T (element to search)
//  Output:           Boolean (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL<T>::Search(T No)
{
    bool bFlag = false;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }

    return bFlag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchFirstOccurrence
//  Description:      Finds the first occurrence of an element in the list
//  Input:            T (element to search)
//  Output:           Integer (position of first occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    }

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchLastOccurrence
//  Description:      Finds the last occurrence of an element in the list
//  Input:            T (element to search)
//  Output:           Integer (position of last occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iPos = iCount;
        }
        iCount++;
        temp = temp->next;
    }

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumDigits
//  Description:      Displays the sum of digits for each element in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        iNo = temp->data;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout << "Sum of digits of " << temp->data << " is: " << iSum << endl;
        iSum = 0;

        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    FactorsAddition
//  Description:      Calculates the sum of factors of a number
//  Input:            T (number to calculate factors)
//  Output:           T (sum of factors)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::FactorsAddition(T iNo)
{
    T iSum = 0;
    T i = 0;

    for (i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CheckPerfect
//  Description:      Checks if a number is a perfect number
//  Input:            T (number to check)
//  Output:           Boolean (true if perfect, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyLL<T>::CheckPerfect(T iNo)
{
    T iSum = 0;
    T i = 0;

    for(i = 1; i <= iNo/2; i++)
    {
        if(iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else 
    {
        return false;
    }    
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DisplayPerfect
//  Description:      Displays all perfect numbers in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DisplayPerfect()
{
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        if (CheckPerfect(temp->data) == true)
        {
            cout << temp->data << " is a perfect number" << endl;
        }
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumFactors
//  Description:      Displays the sum of factors for each element in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::SumFactors()
{
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "Sum of factors of " << temp->data << " is: " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElement
//  Description:      Finds the middle element using the length of the list
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::MiddleElement()
{
    int iMid = 0, i = 0;
    iMid = iCount / 2;
    struct nodeSL<T> *temp = First;

    for (i = 1; i <= iMid; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElementX
//  Description:      Finds the middle element using the two-pointer approach
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::MiddleElementX()
{
    struct nodeSL<T> *fastPtr = First;  // Fast pointer moves two steps at a time
    struct nodeSL<T> *slowPtr = First;  // Slow pointer moves one step at a time

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
        slowPtr = slowPtr->next;        // Move slow pointer by one step
    }

    return slowPtr->data;  // Slow pointer will be at the middle
}

/////////////////////////////////////////////////////////////////////////////////
//
// Doubly Linear Linked List
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;                     // Data of generic type T
    struct nodeDL *next;        // Pointer to the next node
    struct nodeDL *prev;        // Pointer to the previous node
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   DoublyLL
//  Description     :   Implements a doubly linear linked list
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> *First;    // Pointer to the first node in the list
        int iCount;                 // Count of nodes in the list

    public:
        DoublyLL();                 // Constructor

        void Display();             // Function to display all elements
        int Count();                // Function to count the number of nodes

        void InsertFirst(T No);     // Function to insert at the beginning
        void InsertLast(T No);      // Function to insert at the end
        void InsertAtPos(T No, int iPos);  // Function to insert at a specific position

        void DeleteFirst();         // Function to delete the first node
        void DeleteLast();          // Function to delete the last node
        void DeleteAtPos(int iPos); // Function to delete a node at a specific position

        // Aggregate Function
        T Addition();               // Function to calculate sum of all elements
        int EvenCount();            // Function to count even elements
        int OddCount();             // Function to count odd elements
        int Frequency(T No);        // Function to count frequency of an element
        bool Search(T No);          // Function to search for an element
        int SearchFirstOccurrence(T No); // Function to find first occurrence of an element
        int SearchLastOccurrence(T No);  // Function to find last occurrence of an element
        void SumDigits();           // Function to display sum of digits of each element
        T FactorsAddition(T iNo);   // Function to calculate sum of factors of a number
        bool CheckPerfect(T iNo);   // Function to check if a number is perfect
        void DisplayPerfect();      // Function to display perfect numbers from the list
        void SumFactors();          // Function to display sum of factors for each element
        T MiddleElement();          // Function to find middle element (method 1)
        T MiddleElementX();         // Function to find middle element (method 2)
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  DoublyLL
//  Description:       Initializes an empty doubly linear linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;               // Initialize First pointer to NULL
    iCount = 0;                 // Initialize node count to 0
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> *temp = First;  // Temporary pointer for traversal

    while (temp != NULL)             // Traverse until the end of the list
    {
        cout << "| " << temp->data << " |<=> ";  // Print current node's data
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl;          // End of list
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Count
//  Description:      Counts the number of nodes in the linked list
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;                   // Return the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertFirst
//  Description:      Inserts an element at the beginning of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = NULL;   // Pointer to new node

    newn = new nodeDL<T>;            // Allocate memory for new node
    newn->data = No;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL
    newn->prev = NULL;               // Initialize prev pointer to NULL

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                // Set new node as first node
    }
    else
    {
        newn->next = First;          // Link new node to first node
        First->prev = newn;          // Link first node's prev to new node
        First = newn;                // Update First to new node
    }
    iCount++;                        // Increment node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertLast
//  Description:      Inserts an element at the end of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> *newn = NULL;   // Pointer to new node
    struct nodeDL<T> *temp = First;  // Temporary pointer for traversal

    newn = new nodeDL<T>;            // Allocate memory for new node
    newn->data = No;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL
    newn->prev = NULL;               // Initialize prev pointer to NULL

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                // Set new node as first node
    }
    else
    {
        while (temp->next != NULL)   // Traverse to the last node
        {
            temp = temp->next;
        }
        temp->next = newn;           // Link last node to new node
        newn->prev = temp;           // Link new node's prev to last node
    }
    iCount++;                        // Increment node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertAtPos
//  Description:      Inserts an element at a specific position in the linked list
//  Input:            T (generic data type)
//                    Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> *newn = NULL;   // Pointer to new node
    int i = 0;
    struct nodeDL<T> *temp;          // Temporary pointer for traversal

    if ((iPos < 1) || (iPos > iCount + 1))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)                   // Insert at first position
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)     // Insert at last position
    {
        InsertLast(No);
    }
    else
    {
        temp = First;                // Initialize temp pointer

        newn = new nodeDL<T>;        // Allocate memory for new node
        newn->data = No;             // Initialize data
        newn->next = NULL;           // Initialize next pointer to NULL
        newn->prev = NULL;           // Initialize prev pointer to NULL

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;     // Link new node to next node
        newn->prev = temp;           // Link new node to current node
        temp->next->prev = newn;     // Link next node's prev to new node
        temp->next = newn;           // Link current node to new node

        iCount++;                    // Increment node count
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteFirst
//  Description:      Deletes the first element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                // Deallocate memory of first node
        First = NULL;                // Set First to NULL
    }
    else
    {
        First = First->next;         // Move First to next node
        delete First->prev;          // Deallocate memory of old first node
        First->prev = NULL;          // Set prev of new first node to NULL
    }
    iCount--;                        // Decrement node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteLast
//  Description:      Deletes the last element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> *temp = First;  // Temporary pointer for traversal

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                // Deallocate memory of first node
        First = NULL;                // Set First to NULL
    }
    else
    {
        while (temp->next->next != NULL)  // Traverse to second last node
        {
            temp = temp->next;
        }
        delete temp->next;           // Deallocate memory of last node
        temp->next = NULL;           // Set next of second last node to NULL
    }
    iCount--;                        // Decrement node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteAtPos
//  Description:      Deletes an element from a specific position in the linked list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL<T> *temp1;         // Temporary pointer for traversal
    struct nodeDL<T> *temp2;         // Pointer to node to be deleted

    if ((iPos < 1) || (iPos > iCount))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)                   // Delete first node
    {
        DeleteFirst();
    }
    else if (iPos == iCount)         // Delete last node
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;               // Initialize temp1 pointer

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;         // Node to be deleted
        temp1->next = temp2->next;   // Link (iPos-1)th node to (iPos+1)th node

        if (temp2->next != NULL)     // Check if temp2 is not the last node
        {
            temp2->next->prev = temp1; // Link (iPos+1)th node's prev to (iPos-1)th node
        }

        delete temp2;                // Deallocate memory of node to be deleted

        iCount--;                    // Decrement node count
    }
}


/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Addition
//  Description:      Calculates the sum of all elements in the list
//  Input:            None
//  Output:           T (sum of elements)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::Addition()
{
    T iSum = 0;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        iSum = iSum + (temp->data);
        temp = temp->next;
    }

    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    EvenCount
//  Description:      Counts the even numbers in the list
//  Input:            None
//  Output:           Integer (count of even numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::EvenCount()
{
    int iCnt = 0;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    OddCount
//  Description:      Counts the odd numbers in the list
//  Input:            None
//  Output:           Integer (count of odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::OddCount()
{
    int iCnt = 0;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if ((temp->data) % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Frequency
//  Description:      Counts the frequency of a specific element in the list
//  Input:            T (element to search)
//  Output:           Integer (frequency of element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Frequency(T No)
{
    int iCnt = 0;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    }

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Search
//  Description:      Searches for an element in the list
//  Input:            T (element to search)
//  Output:           Boolean (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyLL<T>::Search(T No)
{
    bool bFlag = false;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    }

    return bFlag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchFirstOccurrence
//  Description:      Finds the first occurrence of an element in the list
//  Input:            T (element to search)
//  Output:           Integer (position of first occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    }

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchLastOccurrence
//  Description:      Finds the last occurrence of an element in the list
//  Input:            T (element to search)
//  Output:           Integer (position of last occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            iPos = iCount;
        }
        iCount++;
        temp = temp->next;
    }

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumDigits
//  Description:      Displays the sum of digits for each element in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        iNo = temp->data;

        while (iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        cout << "Sum of digits of " << temp->data << " is: " << iSum << endl;
        iSum = 0;

        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    FactorsAddition
//  Description:      Calculates the sum of factors of a number
//  Input:            T (number to calculate factors)
//  Output:           T (sum of factors)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::FactorsAddition(T iNo)
{
    T iSum = 0;
    T i = 0;

    for (i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CheckPerfect
//  Description:      Checks if a number is a perfect number
//  Input:            T (number to check)
//  Output:           Boolean (true if perfect, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////


template <class T>
bool DoublyLL<T>::CheckPerfect(T iNo)
{
    T iSum = 0;
    T i = 0;

    for (i = 1; i <= iNo / 2; i++)
    {
        if (iNo % i == 0)
        {
            iSum = iSum + i;
        }
    }

    if(iSum == iNo)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DisplayPerfect
//  Description:      Displays all perfect numbers in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DisplayPerfect()
{
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        if (CheckPerfect(temp->data) == true)
        {
            cout << temp->data << " is a perfect number" << endl;
        }
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumFactors
//  Description:      Displays the sum of factors for each element in the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::SumFactors()
{
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "Sum of factors of " << temp->data << " is: " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElement
//  Description:      Finds the middle element using the length of the list
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::MiddleElement()
{
    int iMid = 0, i = 0;
    iMid = iCount / 2;
    struct nodeDL<T> *temp = First;

    for (i = 1; i <= iMid; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElementX
//  Description:      Finds the middle element using the two-pointer approach
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::MiddleElementX()
{
    struct nodeDL<T> *fastPtr = First;  // Fast pointer moves two steps at a time
    struct nodeDL<T> *slowPtr = First;  // Slow pointer moves one step at a time

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
        slowPtr = slowPtr->next;        // Move slow pointer by one step
    }

    return slowPtr->data;  // Slow pointer will be at the middle
}

/////////////////////////////////////////////////////////////////////////////////
//
// Singly Circular Linked List
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;                     // Data of generic type T
    struct nodeSC *next;        // Pointer to the next node
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   SinglyCL
//  Description     :   Implements a singly circular linked list
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    private:
        struct nodeSC<T> *First;    // Pointer to the first node in the list
        struct nodeSC<T> *Last;     // Pointer to the last node in the list

    public:
        SinglyCL();                 // Constructor

        void InsertFirst(T no);     // Function to insert at the beginning
        void InsertLast(T no);      // Function to insert at the end
        void InsertAtPos(T no, int ipos);  // Function to insert at a specific position
        void DeleteFirst();         // Function to delete the first node
        void DeleteLast();          // Function to delete the last node
        void DeleteAtPos(int ipos); // Function to delete a node at a specific position
        void Display();             // Function to display all elements
        int Count();                // Function to count the number of nodes
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  SinglyCL
//  Description:       Initializes an empty singly circular linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;               // Initialize First pointer to NULL
    Last = NULL;                // Initialize Last pointer to NULL
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeSC<T> *temp = First;  // Temporary pointer for traversal

    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return;
    }

    do
    {
        cout << "|" << temp->data << "|-> ";  // Print current node's data
        temp = temp->next;                   // Move to the next node
    } while (temp != First);                 // Continue until loop back to First

    cout << endl;                            // End of list
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Count
//  Description:      Counts the number of nodes in the linked list
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count()
{
    int iCnt = 0;
    struct nodeSC<T> *temp = First;  // Temporary pointer for traversal

    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return 0;
    }

    do
    {
        iCnt++;                         // Increment node count
        temp = temp->next;              // Move to the next node
    } while (temp != First);            // Continue until loop back to First

    return iCnt;                        // Return the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertFirst
//  Description:      Inserts an element at the beginning of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct nodeSC<T> *newn = NULL;   // Pointer to new node

    newn = new struct nodeSC<T>;     // Allocate memory for new node
    newn->data = no;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL

    if ((First == NULL) && (Last == NULL))  // Check if list is empty
    {
        First = newn;                // Set new node as first node
        Last = newn;                 // Set new node as last node
    }
    else
    {
        newn->next = First;          // Link new node to first node
        First = newn;                // Update First to new node
    }
    Last->next = First;              // Make list circular by linking Last to First
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertLast
//  Description:      Inserts an element at the end of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct nodeSC<T> *newn = NULL;   // Pointer to new node

    newn = new struct nodeSC<T>;     // Allocate memory for new node
    newn->data = no;                 // Initialize data
    newn->next = NULL;               // Initialize next pointer to NULL

    if ((First == NULL) && (Last == NULL))  // Check if list is empty
    {
        First = newn;                // Set new node as first node
        Last = newn;                 // Set new node as last node
    }
    else
    {
        Last->next = newn;           // Link last node to new node
        Last = newn;                 // Update Last to new node
    }
    Last->next = First;              // Make list circular by linking Last to First
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertAtPos
//  Description:      Inserts an element at a specific position in the linked list
//  Input:            T (generic data type)
//                    Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int iSize = Count();             // Get current size of list

    if ((ipos < 1) || (ipos > iSize + 1))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)                   // Insert at first position
    {
        InsertFirst(no);
    }
    else if (ipos == iSize + 1)      // Insert at last position
    {
        InsertLast(no);
    }
    else
    {
        struct nodeSC<T> *newn = NULL;   // Pointer to new node

        newn = new struct nodeSC<T>;     // Allocate memory for new node
        newn->data = no;                 // Initialize data
        newn->next = NULL;               // Initialize next pointer to NULL

        struct nodeSC<T> *temp = First;  // Temporary pointer for traversal
        int iCnt = 0;                    // Separate declaration of iCnt

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)  // Traverse to (ipos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;         // Link new node to next node
        temp->next = newn;               // Link (ipos-1)th node to new node
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteFirst
//  Description:      Deletes the first element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return;
    }
    else if (First == Last)             // Check if only one node
    {
        delete First;                   // Deallocate memory of first node
        First = NULL;                   // Set First to NULL
        Last = NULL;                    // Set Last to NULL
    }
    else
    {
        First = First->next;            // Move First to next node
        delete Last->next;              // Deallocate memory of old first node

        Last->next = First;             // Link Last to new First
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteLast
//  Description:      Deletes the last element of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return;
    }
    else if (First == Last)             // Check if only one node
    {
        delete Last;                    // Deallocate memory of last node
        First = NULL;                   // Set First to NULL
        Last = NULL;                    // Set Last to NULL
    }
    else
    {
        struct nodeSC<T> *temp = First;  // Temporary pointer for traversal

        while (temp->next != Last)       // Traverse to second last node
        {
            temp = temp->next;
        }

        delete Last;                    // Deallocate memory of last node
        Last = temp;                    // Update Last to second last node

        Last->next = First;             // Link Last to First
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteAtPos
//  Description:      Deletes an element from a specific position in the linked list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int iSize = Count();             // Get current size of list

    if ((ipos < 1) || (ipos > iSize))  // Validate position
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)                   // Delete first node
    {
        DeleteFirst();
    }
    else if (ipos == iSize)          // Delete last node
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC<T> *temp1 = First;  // Temporary pointer for traversal
        int iCnt = 0;                    // Separate declaration of iCnt

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)  // Traverse to (ipos-1)th node
        {
            temp1 = temp1->next;
        }

        struct nodeSC<T> *temp2 = temp1->next;  // Pointer to node to be deleted

        temp1->next = temp2->next;              // Link (ipos-1)th node to (ipos+1)th node
        delete temp2;                           // Deallocate memory of node to be deleted
    }
}


/////////////////////////////////////////////////////////////////////////////////
//
//  Doubly Circular Linked List
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;                              // Generic data of the node
    struct nodeDC *next;                // Pointer to the next node
    struct nodeDC *prev;                // Pointer to the previous node
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   DoublyCL
//  Description     :   Implements a doubly circular linked list
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
private:
    struct nodeDC<T> *First;            // Pointer to the first node
    struct nodeDC<T> *Last;             // Pointer to the last node
    int iCount;                         // Counter to keep track of the number of nodes

public:
    DoublyCL();                         // Constructor

    void Display();                     // Function to display all elements in the list
    int Count();                        // Function to count the total number of nodes

    void InsertFirst(T No);             // Function to insert an element at the beginning
    void InsertLast(T No);              // Function to insert an element at the end
    void InsertAtPos(T No, int iPos);   // Function to insert an element at a specific position

    void DeleteFirst();                 // Function to delete the first element
    void DeleteLast();                  // Function to delete the last element
    void DeleteAtPos(int iPos);         // Function to delete an element at a specific position
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  DoublyCL
//  Description:       Initializes an empty doubly circular linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;                        // Initialize the First pointer to NULL
    Last = NULL;                         // Initialize the Last pointer to NULL
    iCount = 0;                          // Initialize the node counter to 0
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display()
{
    if (First == NULL && Last == NULL)   // Check if the list is empty
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << First->data << "| <=> ";
        First = First->next;            // Traverse to the next node
    } while (Last->next != First);      // Stop when we loop back to the first node

    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Count
//  Description:      Counts the number of nodes in the linked list
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;                       // Return the current node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertFirst
//  Description:      Inserts an element at the beginning of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;                // Allocate memory for the new node

    newn->data = No;                     // Set the data of the new node
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) // If the list is empty
    {
        First = newn;
        Last = newn;
    }
    else                                  // If the list is not empty
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;                  // Update the circular connection
    First->prev = Last;

    iCount++;                            // Increment the node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertLast
//  Description:      Inserts an element at the end of the linked list
//  Input:            T (generic data type)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;                // Allocate memory for the new node

    newn->data = No;                     // Set the data of the new node
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL)) // If the list is empty
    {
        First = newn;
        Last = newn;
    }
    else                                  // If the list is not empty
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;                  // Update the circular connection
    First->prev = Last;

    iCount++;                            // Increment the node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertAtPos
//  Description:      Inserts an element at specific position of the list
//  Input:            T (generic data type)
//                    Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> *temp = NULL;
    struct nodeDC<T> *newn = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount + 1)   // Validate the position
    {
        cout << "Invalid postion" << endl;
        return;
    }

    if (iPos == 1)                       // Insert at the first position
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)         // Insert at the last position
    {
        InsertLast(No);
    }
    else                                 // Insert at a specific position
    {
        newn = new nodeDC<T>;            // Allocate memory for the new node

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)   // Traverse to the desired position
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;                        // Increment the node count
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteFirst
//  Description:      Deletes the first element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)   // Check if the list is empty
    {
        return;
    }
    else if (First == Last)              // If there is only one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                                 // If there are multiple nodes
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;                            // Decrement the node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteLast
//  Description:      Deletes the last element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)   // Check if the list is empty
    {
        return;
    }
    else if (First == Last)              // If there is only one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                                 // If there are multiple nodes
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;                            // Decrement the node count
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    DeleteAtPos
//  Description:      Deletes an element from specific position of the list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> *temp = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount)       // Validate the position
    {
        cout << "Invalid postion" << endl;
        return;
    }

    if (iPos == 1)                       // Delete the first node
    {
        DeleteFirst();
    }
    else if (iPos == iCount)             // Delete the last node
    {
        DeleteLast();
    }
    else                                 // Delete a specific node
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)   // Traverse to the desired position
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;                        // Decrement the node count
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  STACK
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;               // Stores the data of generic type T
    struct NodeS *next;   // Pointer to the next node in the stack
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   Stack
//  Description     :   Implements a stack
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
private:
    struct NodeS<T> *First;  // Pointer to the first/top node of the stack
    int iCount;              // Counter for the number of elements in the stack

public:
    Stack();               // Constructor
    void Push(T);          // Function to insert an element into the stack
    void Pop();            // Function to remove an element from the stack
    void Display();        // Function to display all elements in the stack
    int CountNode();       // Function to count the number of nodes in the stack
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  Stack
//  Description:       Initializes an empty stack
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    First = NULL;          // Initialize the stack to be empty
    iCount = 0;            // Set the count of nodes to 0
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Push
//  Description:      Inserts the new element in the stack
//  Input:            T (generic data type) - Element to be pushed into the stack
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T no)
{
    struct NodeS<T> *newn = NULL;   // Pointer to create a new node
    newn = new NodeS<T>;           // Allocate memory for the new node

    newn->data = no;               // Set the data of the new node
    newn->next = NULL;             // Initialize the next pointer of the new node to NULL

    newn->next = First;            // Link the new node to the top of the stack
    First = newn;                  // Update the top of the stack to the new node
    iCount++;                      // Increment the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Pop
//  Description:      Deletes the element from the stack
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Pop()
{
    T no;                         // Variable to store the data of the node being removed

    if (First == NULL)            // Check if the stack is empty
    {
        cout << "Unable to pop the element as stack is empty" << endl;
        return;
    }

    struct NodeS<T> *temp = First;  // Temporary pointer to hold the top node
    no = First->data;              // Retrieve the data from the top node
    First = First->next;           // Update the top pointer to the next node
    delete temp;                   // Delete the old top node

    iCount--;                      // Decrement the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the stack
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Display()
{
    cout << "Elements from Stack are : " << endl;
    struct NodeS<T> *temp = First;  // Temporary pointer to traverse the stack

    while (temp != NULL)            // Traverse until the end of the stack
    {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    cout << endl;                   // Print a newline at the end
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountNode
//  Description:      Counts the number of nodes in the stack
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::CountNode()
{
    return iCount;                 // Return the count of nodes in the stack
}

/////////////////////////////////////////////////////////////////////////////////
//
//  QUEUE
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;               // Stores the data of generic type T
    struct nodeQ *next;   // Pointer to the next node in the queue
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   Queue
//  Description     :   Implements a queue
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
private:
    struct nodeQ<T> *First;  // Pointer to the first/front node of the queue
    int iCount;              // Counter for the number of elements in the queue

public:
    Queue();                 // Constructor to initialize an empty queue
    void Enqueue(T);         // Function to insert an element into the queue
    void Dequeue();          // Function to remove an element from the queue
    void Display();          // Function to display all elements in the queue
    int CountNode();         // Function to count the number of nodes in the queue
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  Queue
//  Description:       Initializes an empty queue
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T>::Queue()
{
    First = NULL;            // Initialize the queue to be empty
    iCount = 0;              // Set the count of nodes to 0
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Enqueue
//  Description:      Inserts a new element into the queue
//  Input:            T (generic data type) - Element to be added to the queue
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T no)
{
    struct nodeQ<T> *newn = NULL;   // Pointer to create a new node
    newn = new nodeQ<T>;           // Allocate memory for the new node

    newn->data = no;               // Set the data of the new node
    newn->next = NULL;             // Initialize the next pointer of the new node to NULL

    if (First == NULL)             // If the queue is empty
    {
        First = newn;              // Set the new node as the first node
    }
    else                           // If the queue is not empty
    {
        struct nodeQ<T> *temp = First; // Temporary pointer to traverse the queue
        while (temp->next != NULL)     // Traverse to the last node
        {
            temp = temp->next;
        }

        temp->next = newn;             // Link the new node to the last node
    }
    iCount++;                          // Increment the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Dequeue
//  Description:      Deletes an element from the front of the queue
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Dequeue()
{
    T no;                           // Variable to store the data of the node being removed

    if (First == NULL)              // Check if the queue is empty
    {
        cout << "Unable to remove the element as queue is empty" << endl;
        return;
    }

    struct nodeQ<T> *temp = First;  // Temporary pointer to hold the front node
    no = First->data;               // Retrieve the data from the front node
    First = First->next;            // Update the front pointer to the next node
    delete temp;                    // Delete the old front node

    iCount--;                       // Decrement the count of nodes
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays all elements of the queue
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    cout << "Elements from Queue are : " << endl;
    struct nodeQ<T> *temp = First;  // Temporary pointer to traverse the queue

    while (temp != NULL)            // Traverse until the end of the queue
    {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    cout << endl;                   // Print a newline at the end
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountNode
//  Description:      Counts the number of nodes in the queue
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::CountNode()
{
    return iCount;                  // Return the count of nodes in the queue
}


/////////////////////////////////////////////////////////////////////////////////
//
//  Searching Algorithms
//
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   SearchAlgorithms
//  Description     :   Implements search algorithms: Linear, Bi-Directional, and Binary Search
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class SearchAlgorithms
{
private:
    T *Arr;
    int iSize;

public:
    SearchAlgorithms(int size);  // Constructor to initialize array size
    ~SearchAlgorithms();         // Destructor to release array memory
    void Accept();               // Accept array elements
    void Display();              // Display array elements
    bool LinearSearch(T);        // Performs Linear Search
    bool BiDirectionalSearch(T); // Performs Bi-Directional Search
    bool BinarySearch(T);        // Performs Binary Search
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:    SearchAlgorithms
//  Description:         Initializes array and its size
//  Input:               int (Size of array)
//  Output:              None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SearchAlgorithms<T>::SearchAlgorithms(int size)
{
    this->iSize = size;
    this->Arr = new T[size];
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Destructor Name:     ~SearchAlgorithms
//  Description:         Releases allocated memory for the array
//  Input:               None
//  Output:              None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SearchAlgorithms<T>::~SearchAlgorithms()
{
    delete[] Arr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Accept
//  Description:      Accepts the elements for the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SearchAlgorithms<T>::Accept()
{
    int i = 0;

    cout << "Enter the elements: \n";
    for (i = 0; i < iSize; i++)
    {
        cin >> Arr[i];
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays the elements of the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SearchAlgorithms<T>::Display()
{
    int i = 0;

    cout << "Array elements are: \n";
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    LinearSearch
//  Description:      Performs a linear search to find the element
//  Input:            T (Element to search)
//  Output:           bool (True if element found, otherwise false)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgorithms<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for (i = 0; i < iSize; i++)
    {
        if (Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    BiDirectionalSearch
//  Description:      Performs a bidirectional search to find the element
//  Input:            T (Element to search)
//  Output:           bool (True if element found, otherwise false)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgorithms<T>::BiDirectionalSearch(T Value)
{
    int iStart = 0, iEnd = 0;
    bool flag = false;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    BinarySearch
//  Description:      Performs binary search to find the element
//  Input:            T (Element to search)
//  Output:           bool (True if element found, otherwise false)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SearchAlgorithms<T>::BinarySearch(T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iEnd = iSize - 1;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if ((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if (Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
        else if (Value > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
    }

    return flag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  SortAlgorithms
//
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   SortAlgorithms
//  Description     :   Implements sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class SortAlgorithms
{
private:
    T *Arr;
    int iSize;

public:
    SortAlgorithms(int size); // Constructor to initialize array size
    ~SortAlgorithms();        // Destructor to release array memory
    void Accept();            // Accept array elements
    void Display();           // Display array elements
    void BubbleSort();        // Performs Bubble Sort
    void SelectionSort();     // Performs Selection Sort
    void InsertionSort();     // Performs Insertion Sort
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:    SortAlgorithms
//  Description:         Initializes array and its size
//  Input:               int (Size of array)
//  Output:              None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SortAlgorithms<T>::SortAlgorithms(int size)
{
    this->iSize = size;
    this->Arr = new T[size];
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Destructor Name:     ~SortAlgorithms
//  Description:         Releases allocated memory for the array
//  Input:               None
//  Output:              None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SortAlgorithms<T>::~SortAlgorithms()
{
    delete[] Arr;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Accept
//  Description:      Accepts the elements for the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SortAlgorithms<T>::Accept()
{
    int i = 0;

    cout << "Enter the elements: \n";
    for (i = 0; i < iSize; i++)
    {
        cin >> Arr[i];
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Display
//  Description:      Displays the elements of the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SortAlgorithms<T>::Display()
{
    int i = 0;

    cout << "Array elements are: \n";
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    BubbleSort
//  Description:      Performs Bubble Sort on the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SortAlgorithms<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    for (i = 0; (i < iSize - 1) && (flag == true); i++)
    {
        flag = false;
        for (j = 0; j < iSize - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
        }

        cout << "\nArray after pass : " << i + 1 << "\n";
        Display();
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SelectionSort
//  Description:      Performs Selection Sort on the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SortAlgorithms<T>::SelectionSort()
{
    int i = 0, j = 0, minIndex = 0;
    T temp;

    for (i = 0; i < iSize - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = Arr[i];
        Arr[i] = Arr[minIndex];
        Arr[minIndex] = temp;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    InsertionSort
//  Description:      Performs Insertion Sort on the array
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SortAlgorithms<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for (i = 1; i < iSize; i++)
    {
        for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
// Binary Search Tree
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeBST
{
    T data;                    // Data of generic type T
    struct nodeBST<T> *lchild; // Pointer to left child
    struct nodeBST<T> *rchild; // Pointer to right child
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name      :   BinarySearchTree
//  Description     :   Implements a binary search tree with generic data type
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
class BinarySearchTree
{
private:
    struct nodeBST<T> *Root; // Pointer to the root node

public:
    BinarySearchTree();     // Constructor
    void Insert(T No);      // Function to insert an element
    void Inorder();         // Function for inorder traversal
    void Preorder();        // Function for preorder traversal
    void Postorder();       // Function for postorder traversal
    bool Search(T No);      // Function to search for an element
    int CountLeafNodes();   // Function to count leaf nodes
    int CountParentNodes(); // Function to count parent nodes
    int CountAllNodes();    // Function to count all nodes

private:
    void Inorder(struct nodeBST<T> *Root);         // Helper for inorder traversal
    void Preorder(struct nodeBST<T> *Root);        // Helper for preorder traversal
    void Postorder(struct nodeBST<T> *Root);       // Helper for postorder traversal
    bool Search(struct nodeBST<T> *Root, T No);    // Helper for searching
    int CountLeafNodes(struct nodeBST<T> *Root);   // Helper for counting leaf nodes
    int CountParentNodes(struct nodeBST<T> *Root); // Helper for counting parent nodes
    int CountAllNodes(struct nodeBST<T> *Root);    // Helper for counting all nodes
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name:  BinarySearchTree
//  Description:       Initializes an empty binary search tree
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    Root = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Insert
//  Description:      Inserts an element into the binary search tree
//  Input:            Element to insert (generic type T)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinarySearchTree<T>::Insert(T No)
{
    struct nodeBST<T> *newn = new nodeBST<T>; // Allocate memory for new node

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (Root == NULL) // If tree is empty
    {
        Root = newn;
    }
    else // Traverse the tree to find the correct position
    {
        struct nodeBST<T> *temp = Root;

        while (true)
        {
            if (temp->data == No)
            {
                cout << "Unable to insert node as element is already present\n";
                delete newn;
                break;
            }
            else if (No > temp->data) // Navigate to the right subtree
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else // Navigate to the left subtree
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Inorder
//  Description:      Performs inorder traversal of the binary search tree
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinarySearchTree<T>::Inorder()
{
    Inorder(Root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::Inorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        Inorder(Root->lchild);
        cout << Root->data << " ";
        Inorder(Root->rchild);
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Preorder
//  Description:      Performs preorder traversal of the binary search tree
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinarySearchTree<T>::Preorder()
{
    Preorder(Root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::Preorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        cout << Root->data << " ";
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Postorder
//  Description:      Performs postorder traversal of the binary search tree
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void BinarySearchTree<T>::Postorder()
{
    Postorder(Root);
    cout << endl;
}

template <class T>
void BinarySearchTree<T>::Postorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        cout << Root->data << " ";
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Search
//  Description:      Searches for a value in the binary search tree
//  Input:            Element to search (generic type T)
//  Output:           Boolean (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BinarySearchTree<T>::Search(T No)
{
    return Search(Root, No);
}

template <class T>
bool BinarySearchTree<T>::Search(struct nodeBST<T> *Root, T No)
{
    while (Root != NULL)
    {
        if (Root->data == No)
        {
            return true;
        }
        else if (No > Root->data)
        {
            Root = Root->rchild;
        }
        else
        {
            Root = Root->lchild;
        }
    }
    return false;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountLeafNodes
//  Description:      Counts the leaf nodes in the binary search tree
//  Input:            None
//  Output:           Integer (count of leaf nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int BinarySearchTree<T>::CountLeafNodes()
{
    return CountLeafNodes(Root);
}

template <class T>
int BinarySearchTree<T>::CountLeafNodes(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;
    if (Root->lchild == NULL && Root->rchild == NULL)
        return 1;
    return CountLeafNodes(Root->lchild) + CountLeafNodes(Root->rchild);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountParentNodes
//  Description:      Counts the parent nodes in the binary search tree
//  Input:            None
//  Output:           Integer (count of parent nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int BinarySearchTree<T>::CountParentNodes()
{
    return CountParentNodes(Root);
}

template <class T>
int BinarySearchTree<T>::CountParentNodes(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;
    int count = (Root->lchild != NULL || Root->rchild != NULL) ? 1 : 0;
    return count + CountParentNodes(Root->lchild) + CountParentNodes(Root->rchild);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountAllNodes
//  Description:      Counts all nodes in the binary search tree
//  Input:            None
//  Output:           Integer (total count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int BinarySearchTree<T>::CountAllNodes()
{
    return CountAllNodes(Root);
}

template <class T>
int BinarySearchTree<T>::CountAllNodes(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;
    return 1 + CountAllNodes(Root->lchild) + CountAllNodes(Root->rchild);
}

/////////////////////////////////////////////////////////////////////////////////
//  Entry point function
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    return 0;
}
