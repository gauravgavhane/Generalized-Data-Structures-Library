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

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
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

    while (temp != NULL)
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

    if (First == NULL)
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

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
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
//  Description:      Inserts an element at specific position of the list
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

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
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
//  Description:      Deletes the first element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)
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
//  Description:      Deletes the last element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
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
//  Description:      Deletes an element from specific position of the list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1;
    struct nodeSL<T> *temp2;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
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

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
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

    while (temp != NULL)
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

    if (First == NULL)
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

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
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
//  Description:      Inserts an element at specific position of the list
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

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
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

        for (i = 1; i < iPos - 1; i++)
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
//  Description:      Deletes the first element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)
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
//  Description:      Deletes the last element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
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
//  Description:      Deletes an element from specific position of the list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL<T> *temp1;
    struct nodeDL<T> *temp2;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;

        if (temp2->next != NULL)
        {
            temp2->next->prev = temp1;
        }

        delete temp2;

        iCount--;
    }
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
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
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

    if (First == NULL && Last == NULL)
    {
        return;
    }

    do
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    } while (temp != First);

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

    if (First == NULL && Last == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != First);

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

    if ((First == NULL) && (Last == NULL))
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

    if ((First == NULL) && (Last == NULL))
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
//  Description:      Inserts an element at specific position of the list
//  Input:            T (generic data type)
//                    Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize + 1))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iSize + 1)
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

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
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
//  Description:      Deletes the first element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
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
//  Description:      Deletes the last element of the list
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete Last;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T> *temp = First;

        while (temp->next != Last)
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
//  Description:      Deletes an element from specific position of the list
//  Input:            Integer (Position of element)
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int iSize = Count();

    if ((ipos < 1) || (ipos > iSize))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC<T> *temp1 = First;
        int iCnt = 0;

        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeSC<T> *temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
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
    T data;
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
    struct nodeDC<T> *First;
    struct nodeDC<T> *Last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
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
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << First->data << "| <=> ";
        First = First->next;
    } while (Last->next != First);

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

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
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

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
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

    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid postion" << endl;
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)
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
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
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
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
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

    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid postion" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
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
//  STACK
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
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
    struct NodeS<T> *First;
    int iCount;

public:
    Stack();
    void Push(T);
    void Pop();
    void Display();
    int CountNode();
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
//  Input:            T (generic data type)
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
//  Description:      Deletes the element from stack
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Pop()
{
    T no;

    if (First == NULL)
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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountNode
//  Description:      Counts the number of nodes of the stack
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T>::CountNode()
{
    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  QUEUE
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
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
    struct nodeQ<T> *First;
    int iCount;

public:
    Queue();
    void Enqueue(T);
    void Dequeue();
    void Display();
    int CountNode();
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
    First = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    Enque
//  Description:      Inserts the new element in the queue
//  Input:            T (generic data type)
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

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeQ<T> *temp = First;
        while (temp->next != NULL)
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
//  Description:      Deletes the element from queue
//  Input:            None
//  Output:           None
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Dequeue()
{
    T no;

    if (First == NULL)
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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name:    CountNode
//  Description:      Counts the number of nodes of the queue
//  Input:            None
//  Output:           Integer (count of nodes)
//
/////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::CountNode()
{
    return iCount;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  SearchAlgorithms
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
//  Entry point function
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    return 0;
}