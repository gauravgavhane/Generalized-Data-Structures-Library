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
    T data;                     
    struct nodeSL *next;        
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
        struct nodeSL<T> *First;    
        int iCount;                 

    public:
        SinglyLL();                 

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
    First = NULL;               
    iCount = 0;                 
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
    struct nodeSL<T> *temp = First;  

    while (temp != NULL)             // Traverse until the end of the list
    {
        cout << "| " << temp->data << "|-> ";  
        temp = temp->next;           
    }
    cout << "NULL" << endl;          
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
    return iCount;                   
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
    struct nodeSL<T> *newn = NULL;   

    newn = new nodeSL<T>;            
    newn->data = No;                 
    newn->next = NULL;               

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                
    }
    else
    {
        newn->next = First;          
        First = newn;                
    }
    iCount++;                        
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
    struct nodeSL<T> *newn = NULL;   
    struct nodeSL<T> *temp = First;  

    newn = new nodeSL<T>;            
    newn->data = No;                 
    newn->next = NULL;               

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                
    }
    else
    {
        while (temp->next != NULL)   // Traverse to the last node
        {
            temp = temp->next;
        }
        temp->next = newn;           
    }
    iCount++;                        
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
    struct nodeSL<T> *newn = NULL;   
    int i = 0;
    struct nodeSL<T> *temp;          

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
        temp = First;                

        newn = new nodeSL<T>;        
        newn->data = No;             
        newn->next = NULL;           

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;     
        temp->next = newn;           
        iCount++;                    
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
    struct nodeSL<T> *temp = First;  // 

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                
        First = NULL;                
    }
    else
    {
        First = First->next;         
        delete temp;                 
    }
    iCount--;                        
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
    struct nodeSL<T> *temp = First;  

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                
        First = NULL;                
    }
    else
    {
        while (temp->next->next != NULL)  // Traverse to second last node
        {
            temp = temp->next;
        }
        delete temp->next;           
        temp->next = NULL;           
    }
    iCount--;                        
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
    struct nodeSL<T> *temp1;         
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
        temp1 = First;               

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;         // Node to be deleted

        temp1->next = temp2->next;   
        delete temp2;                

        iCount--;                    
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
    struct nodeSL<T> *fastPtr = First;  
    struct nodeSL<T> *slowPtr = First;  

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
    T data;                     
    struct nodeDL *next;        
    struct nodeDL *prev;        
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
        struct nodeDL<T> *First;    
        int iCount;                 

    public:
        DoublyLL();                 

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
    First = NULL;               
    iCount = 0;                 
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
    struct nodeDL<T> *temp = First;  

    while (temp != NULL)             // Traverse until the end of the list
    {
        cout << "| " << temp->data << " |<=> ";  
        temp = temp->next;           
    }
    cout << "NULL" << endl;          
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
    return iCount;                   
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
    struct nodeDL<T> *newn = NULL;   

    newn = new nodeDL<T>;            
    newn->data = No;                 
    newn->next = NULL;               
    newn->prev = NULL;               

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                
    }
    else
    {
        newn->next = First;          
        First->prev = newn;          
        First = newn;                
    }
    iCount++;                        
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
    struct nodeDL<T> *newn = NULL;   
    struct nodeDL<T> *temp = First;  

    newn = new nodeDL<T>;            
    newn->data = No;                 
    newn->next = NULL;               
    newn->prev = NULL;               

    if (First == NULL)               // Check if list is empty
    {
        First = newn;                
    }
    else
    {
        while (temp->next != NULL)   // Traverse to the last node
        {
            temp = temp->next;
        }
        temp->next = newn;           
        newn->prev = temp;           
    }
    iCount++;                        
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
    struct nodeDL<T> *newn = NULL;   
    int i = 0;
    struct nodeDL<T> *temp;          

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
        temp = First;                

        newn = new nodeDL<T>;        
        newn->data = No;             
        newn->next = NULL;           
        newn->prev = NULL;           

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;     
        newn->prev = temp;           
        temp->next->prev = newn;     
        temp->next = newn;           

        iCount++;                    
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
        delete First;                
        First = NULL;                
    }
    else
    {
        First = First->next;         
        delete First->prev;          
        First->prev = NULL;          
    }
    iCount--;                        
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
    struct nodeDL<T> *temp = First;  

    if (First == NULL)               // Check if list is empty
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)    // Check if only one node
    {
        delete First;                
        First = NULL;                
    }
    else
    {
        while (temp->next->next != NULL)  // Traverse to second last node
        {
            temp = temp->next;
        }
        delete temp->next;           
        temp->next = NULL;           
    }
    iCount--;                        
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
    struct nodeDL<T> *temp1;         
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
        temp1 = First;               

        for (i = 1; i < iPos - 1; i++)  // Traverse to (iPos-1)th node
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;         // Node to be deleted
        temp1->next = temp2->next;   

        if (temp2->next != NULL)     // Check if temp2 is not the last node
        {
            temp2->next->prev = temp1; 
        }

        delete temp2;                

        iCount--;                    
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
    struct nodeDL<T> *fastPtr = First;  
    struct nodeDL<T> *slowPtr = First;  

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
    T data;                     
    struct nodeSC *next;        
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
        struct nodeSC<T> *First;    
        struct nodeSC<T> *Last;     

    public:
        SinglyCL();                 

        void Display();             // Function to display all elements
        int Count();                // Function to count the number of nodes

        void InsertFirst(T no);     // Function to insert at the beginning
        void InsertLast(T no);      // Function to insert at the end
        void InsertAtPos(T no, int ipos);  // Function to insert at a specific position

        void DeleteFirst();         // Function to delete the first node
        void DeleteLast();          // Function to delete the last node
        void DeleteAtPos(int ipos); // Function to delete a node at a specific position

        // Aggregate functions
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
//  Constructor Name:  SinglyCL
//  Description:       Initializes an empty singly circular linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;               
    Last = NULL;                
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
    struct nodeSC<T> *temp = First;  

    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return;
    }

    do
    {
        cout << "|" << temp->data << "|-> ";  
        temp = temp->next;                   
    } while (temp != First);                 // Continue until loop back to First

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
int SinglyCL<T>::Count()
{
    int iCnt = 0;
    struct nodeSC<T> *temp = First;  

    if (First == NULL && Last == NULL)  // Check if list is empty
    {
        return 0;
    }

    do
    {
        iCnt++;                         
        temp = temp->next;              
    } while (temp != First);            // Continue until loop back to First

    return iCnt;                        
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
    struct nodeSC<T> *newn = NULL;   

    newn = new struct nodeSC<T>;     
    newn->data = no;                 
    newn->next = NULL;               

    if ((First == NULL) && (Last == NULL))  // Check if list is empty
    {
        First = newn;                
        Last = newn;                 
    }
    else
    {
        newn->next = First;          
        First = newn;                
    }
    Last->next = First;              
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
    struct nodeSC<T> *newn = NULL;   

    newn = new struct nodeSC<T>;     
    newn->data = no;                 
    newn->next = NULL;               

    if ((First == NULL) && (Last == NULL))  // Check if list is empty
    {
        First = newn;                
        Last = newn;                 
    }
    else
    {
        Last->next = newn;           
        Last = newn;                 
    }
    Last->next = First;              
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
        struct nodeSC<T> *newn = NULL;   

        newn = new struct nodeSC<T>;     
        newn->data = no;                 
        newn->next = NULL;               

        struct nodeSC<T> *temp = First;  
        int iCnt = 0;                    

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)  // Traverse to (ipos-1)th node
        {
            temp = temp->next;
        }

        newn->next = temp->next;         
        temp->next = newn;               
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
        delete First;                   
        First = NULL;                   
        Last = NULL;                    // Set Last to NULL
    }
    else
    {
        First = First->next;            
        delete Last->next;              

        Last->next = First;             
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
        delete Last;                    
        First = NULL;                   
        Last = NULL;                    // Set Last to NULL
    }
    else
    {
        struct nodeSC<T> *temp = First;  

        while (temp->next != Last)       // Traverse to second last node
        {
            temp = temp->next;
        }

        delete Last;                    
        Last = temp;                    

        Last->next = First;             
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
        struct nodeSC<T> *temp1 = First;  
        int iCnt = 0;                    

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)  // Traverse to (ipos-1)th node
        {
            temp1 = temp1->next;
        }

        struct nodeSC<T> *temp2 = temp1->next;  // Pointer to node to be deleted

        temp1->next = temp2->next;              
        delete temp2;                           
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Addition
//  Description:      Calculates the sum of all elements in the singly circular linked list
//  Input:            None
//  Output:           T (sum of elements)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::Addition()
{
    T iSum = 0;

    if (First == NULL)  // Check if list is empty
    {
        return iSum;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    } while (temp != First);

    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    EvenCount
//  Description:      Counts the even numbers in the singly circular linked list
//  Input:            None
//  Output:           Integer (count of even numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::EvenCount()
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    OddCount
//  Description:      Counts the odd numbers in the singly circular linked list
//  Input:            None
//  Output:           Integer (count of odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::OddCount()
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Frequency
//  Description:      Counts the frequency of a specific element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (frequency of element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Frequency(T No)
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Search
//  Description:      Searches for an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Boolean (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool SinglyCL<T>::Search(T No)
{
    bool bFlag = false;

    if (First == NULL)
    {
        return bFlag;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    } while (temp != First);

    return bFlag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchFirstOccurrence
//  Description:      Finds the first occurrence of an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (position of first occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;

    if (First == NULL)
    {
        return iPos;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    } while (temp != First);

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchLastOccurrence
//  Description:      Finds the last occurrence of an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (position of last occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;

    if (First == NULL)
    {
        return iPos;  
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCount;
        }
        iCount++;
        temp = temp->next;
    } while (temp != First);

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumDigits
//  Description:      Displays the sum of digits for each element in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;

    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeSC<T> *temp = First;

    do
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
    } while (temp != First);
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
T SinglyCL<T>::FactorsAddition(T iNo)
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
bool SinglyCL<T>::CheckPerfect(T iNo)
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
//  Description:      Displays all perfect numbers in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DisplayPerfect()
{
    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeSC<T> *temp = First;

    do
    {
        if (CheckPerfect(temp->data) == true)
        {
            cout << temp->data << " is a perfect number" << endl;
        }
        temp = temp->next;
    } while (temp != First);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumFactors
//  Description:      Displays the sum of factors for each element in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::SumFactors()
{
    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeSC<T> *temp = First;

    do
    {
        cout << "Sum of factors of " << temp->data << " is: " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    } while (temp != First);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElement
//  Description:      Finds the middle element using the length of the singly circular linked list
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::MiddleElement()
{
    int iMid = Count() / 2;
    int i = 0;

    if (First == NULL)
    {
        cout << "Linked list is empty " << endl;
        return;
    }

    struct nodeSC<T> *temp = First;

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
T SinglyCL<T>::MiddleElementX()
{
    struct nodeSC<T> *fastPtr = First;  
    struct nodeSC<T> *slowPtr = First;  

    if (First == NULL)
    {
        cout << "Linked list is empty " << endl;
        return;
    }

    do
    {
        if (fastPtr->next != First && fastPtr->next->next != First)
        {
            fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
            slowPtr = slowPtr->next;        // Move slow pointer by one step
        }
        else
        {
            break;  // Break when fastPtr reaches or is about to reach the end
        }
    } while (fastPtr != First && fastPtr->next != First);

    return slowPtr->data;  // Slow pointer will be at the middle
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
    struct nodeDC *next;                
    struct nodeDC *prev;                
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
    DoublyCL();                         

    void Display();                     // Function to display all elements in the list
    int Count();                        // Function to count the total number of nodes

    void InsertFirst(T No);             // Function to insert an element at the beginning
    void InsertLast(T No);              // Function to insert an element at the end
    void InsertAtPos(T No, int iPos);   // Function to insert an element at a specific position

    void DeleteFirst();                 // Function to delete the first element
    void DeleteLast();                  // Function to delete the last element
    void DeleteAtPos(int iPos);         // Function to delete an element at a specific position

    // Aggregate functions
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
//  Constructor Name:  DoublyCL
//  Description:       Initializes an empty doubly circular linked list
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;                        
    Last = NULL;                         
    iCount = 0;                          
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
        First = First->next;            
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
    return iCount;                       
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

    newn = new nodeDC<T>;                

    newn->data = No;                     
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
    Last->next = First;                  
    First->prev = Last;

    iCount++;                            
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

    newn = new nodeDC<T>;                

    newn->data = No;                     
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
    Last->next = First;                  
    First->prev = Last;

    iCount++;                            
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
        newn = new nodeDC<T>;            

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

        iCount++;                        
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
    iCount--;                            
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
    iCount--;                            
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

        iCount--;                        
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Addition
//  Description:      Calculates the sum of all elements in the singly circular linked list
//  Input:            None
//  Output:           T (sum of elements)
//
/////////////////////////////////////////////////////////////////////////////////


template <class T>
T DoublyCL<T>::Addition()
{
    T iSum = 0;

    if (First == NULL)  // Check if list is empty
    {
        return iSum;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        iSum = iSum + temp->data;
        temp = temp->next;
    } while (temp != First);

    return iSum;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    EvenCount
//  Description:      Counts the even numbers in the singly circular linked list
//  Input:            None
//  Output:           Integer (count of even numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::EvenCount()
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data % 2 == 0)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    OddCount
//  Description:      Counts the odd numbers in the singly circular linked list
//  Input:            None
//  Output:           Integer (count of odd numbers)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::OddCount()
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data % 2 != 0)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Frequency
//  Description:      Counts the frequency of a specific element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (frequency of element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Frequency(T No)
{
    int iCnt = 0;

    if (First == NULL)
    {
        return iCnt;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iCnt++;
        }
        temp = temp->next;
    } while (temp != First);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Search
//  Description:      Searches for an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Boolean (true if found, false otherwise)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
bool DoublyCL<T>::Search(T No)
{
    bool bFlag = false;

    if (First == NULL)
    {
        return bFlag;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            bFlag = true;
            break;
        }
        temp = temp->next;
    } while (temp != First);

    return bFlag;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchFirstOccurrence
//  Description:      Finds the first occurrence of an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (position of first occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;

    if (First == NULL)
    {
        return iPos;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCount;
            break;
        }
        iCount++;
        temp = temp->next;
    } while (temp != First);

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SearchLastOccurrence
//  Description:      Finds the last occurrence of an element in the singly circular linked list
//  Input:            T (element to search)
//  Output:           Integer (position of last occurrence)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;

    if (First == NULL)
    {
        return iPos;  
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (temp->data == No)
        {
            iPos = iCount;
        }
        iCount++;
        temp = temp->next;
    } while (temp != First);

    return iPos;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumDigits
//  Description:      Displays the sum of digits for each element in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;

    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeDC<T> *temp = First;

    do
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
    } while (temp != First);
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
T DoublyCL<T>::FactorsAddition(T iNo)
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
bool DoublyCL<T>::CheckPerfect(T iNo)
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
//  Description:      Displays all perfect numbers in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DisplayPerfect()
{
    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeDC<T> *temp = First;

    do
    {
        if (CheckPerfect(temp->data) == true)
        {
            cout << temp->data << " is a perfect number" << endl;
        }
        temp = temp->next;
    } while (temp != First);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    SumFactors
//  Description:      Displays the sum of factors for each element in the singly circular linked list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::SumFactors()
{
    if (First == NULL)
    {
        return;  // Return if the list is empty
    }

    struct nodeDC<T> *temp = First;

    do
    {
        cout << "Sum of factors of " << temp->data << " is: " << FactorsAddition(temp->data) << endl;
        temp = temp->next;
    } while (temp != First);
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    MiddleElement
//  Description:      Finds the middle element using the length of the singly circular linked list
//  Input:            None
//  Output:           T (middle element)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
T DoublyCL<T>::MiddleElement()
{
    int iMid = Count() / 2;
    int i = 0;

    if (First == NULL)
    {
        cout << "Linked list is empty " << endl;
        return;
    }

    struct nodeDC<T> *temp = First;

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
T DoublyCL<T>::MiddleElementX()
{
    struct nodeDC<T> *fastPtr = First;  
    struct nodeDC<T> *slowPtr = First;  

    if (First == NULL)
    {
        cout << "Linked list is empty " << endl;
        return;
    }

    do
    {
        if (fastPtr->next != First && fastPtr->next->next != First)
        {
            fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
            slowPtr = slowPtr->next;        // Move slow pointer by one step
        }
        else
        {
            break;  // Break when fastPtr reaches or is about to reach the end
        }
    } while (fastPtr != First && fastPtr->next != First);

    return slowPtr->data;  // Slow pointer will be at the middle
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
    struct NodeS *next;    in the stack
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
        Stack();               
        void Push(T);          // Function to insert an element into the stack
        void Pop();            // Function to remove an element from the stack
        void Display();        // Function to display all elements in the stack
        int CountNode();       // Function to count the number of nodes in the stack

        // Aggregate functions
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
//  Constructor Name:  Stack
//  Description:       Initializes an empty stack
//  Input:             None
//  Output:            None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T>::Stack()
{
    First = NULL;         
    iCount = 0;            
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
    struct NodeS<T> *newn = NULL;   
    newn = new NodeS<T>;           

    newn->data = no;               
    newn->next = NULL;             

    newn->next = First;            
    First = newn;                  
    iCount++;                      
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
    T no;                         

    if (First == NULL)            // Check if the stack is empty
    {
        cout << "Unable to pop the element as stack is empty" << endl;
        return;
    }

    struct NodeS<T> *temp = First;  
    no = First->data;              
    First = First->next;           
    delete temp;                   

    iCount--;                      
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
    struct NodeS<T> *temp = First;  

    while (temp != NULL)            // Traverse until the end of the stack
    {
        cout << temp->data << " ";  
        temp = temp->next;          
    }
    cout << endl;                   
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
    return iCount;                  in the stack
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
T Stack<T>::Addition()
{
    T iSum = 0;
    struct NodeS<T> *temp = First;

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
int Stack<T>::EvenCount()
{
    int iCnt = 0;
    struct NodeS<T> *temp = First;

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
int Stack<T>::OddCount()
{
    int iCnt = 0;
    struct NodeS<T> *temp = First;

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
int Stack<T>::Frequency(T No)
{
    int iCnt = 0;
    struct NodeS<T> *temp = First;

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
bool Stack<T>::Search(T No)
{
    bool bFlag = false;
    struct NodeS<T> *temp = First;

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
int Stack<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct NodeS<T> *temp = First;

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
int Stack<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct NodeS<T> *temp = First;

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
void Stack<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;
    struct NodeS<T> *temp = First;

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
T Stack<T>::FactorsAddition(T iNo)
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
bool Stack<T>::CheckPerfect(T iNo)
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
void Stack<T>::DisplayPerfect()
{
    struct NodeS<T> *temp = First;

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
void Stack<T>::SumFactors()
{
    struct NodeS<T> *temp = First;

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
T Stack<T>::MiddleElement()
{
    int iMid = 0, i = 0;
    iMid = iCount / 2;
    struct NodeS<T> *temp = First;

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
T Stack<T>::MiddleElementX()
{
    struct NodeS<T> *fastPtr = First;  
    struct NodeS<T> *slowPtr = First;  

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
        slowPtr = slowPtr->next;        // Move slow pointer by one step
    }

    return slowPtr->data;  // Slow pointer will be at the middle
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
    struct nodeQ *next;    in the queue
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
        Queue();                  
        void Enqueue(T);         // Function to insert an element into the queue
        void Dequeue();          // Function to remove an element from the queue
        void Display();          // Function to display all elements in the queue
        int CountNode();         // Function to count the number of nodes in the queue

        // Aggregate functions
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
    iCount = 0;              
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
    struct nodeQ<T> *newn = NULL;   
    newn = new nodeQ<T>;           

    newn->data = no;               
    newn->next = NULL;             

    if (First == NULL)             // If the queue is empty
    {
        First = newn;              
    }
    else                           // If the queue is not empty
    {
        struct nodeQ<T> *temp = First; 
        while (temp->next != NULL)     // Traverse to the last node
        {
            temp = temp->next;
        }

        temp->next = newn;             
    }
    iCount++;                          
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
    T no;                           

    if (First == NULL)              // Check if the queue is empty
    {
        cout << "Unable to remove the element as queue is empty" << endl;
        return;
    }

    struct nodeQ<T> *temp = First;  
    no = First->data;               
    First = First->next;            
    delete temp;                    

    iCount--;                       
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
    struct nodeQ<T> *temp = First;  

    while (temp != NULL)            // Traverse until the end of the queue
    {
        cout << temp->data << " ";  
        temp = temp->next;          
    }
    cout << endl;                   
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
    return iCount;                   in the queue
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
T Queue<T>::Addition()
{
    T iSum = 0;
    struct nodeQ<T> *temp = First;

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
int Queue<T>::EvenCount()
{
    int iCnt = 0;
    struct nodeQ<T> *temp = First;

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
int Queue<T>::OddCount()
{
    int iCnt = 0;
    struct nodeQ<T> *temp = First;

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
int Queue<T>::Frequency(T No)
{
    int iCnt = 0;
    struct nodeQ<T> *temp = First;

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
bool Queue<T>::Search(T No)
{
    bool bFlag = false;
    struct nodeQ<T> *temp = First;

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
int Queue<T>::SearchFirstOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeQ<T> *temp = First;

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
int Queue<T>::SearchLastOccurrence(T No)
{
    int iCount = 1;
    int iPos = -1;
    struct nodeQ<T> *temp = First;

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
void Queue<T>::SumDigits()
{
    T iSum = 0;
    T iNo = 0;
    int iDigit = 0;
    struct nodeQ<T> *temp = First;

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
T Queue<T>::FactorsAddition(T iNo)
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
bool Queue<T>::CheckPerfect(T iNo)
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
void Queue<T>::DisplayPerfect()
{
    struct nodeQ<T> *temp = First;

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
void Queue<T>::SumFactors()
{
    struct nodeQ<T> *temp = First;

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
T Queue<T>::MiddleElement()
{
    int iMid = 0, i = 0;
    iMid = iCount / 2;
    struct nodeQ<T> *temp = First;

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
T Queue<T>::MiddleElementX()
{
    struct nodeQ<T> *fastPtr = First;  
    struct nodeQ<T> *slowPtr = First;  

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;  // Move fast pointer by two steps
        slowPtr = slowPtr->next;        // Move slow pointer by one step
    }

    return slowPtr->data;  // Slow pointer will be at the middle
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
    SearchAlgorithms(int size);   
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
    SortAlgorithms(int size);  
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
    T data;                    
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
    BinarySearchTree();     
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
    struct nodeBST<T> *newn = new nodeBST<T>; 

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
