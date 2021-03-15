#include <iostream>
#include<math.h>
#include<string.h>
#include<string>

using namespace std;

class stackEmpty
{
public:
    stackEmpty()
    {
    }
};

class Stack
{
public:
    Stack();
    void push_back(char sumbol);
    void push_back(double number);
    void pop();
    void print();
    int processStr(char* str);
    void calculateObrat(int index);
private:



    class Node
    {
    public:
        char sumbol;
        double number;
        Node* pNext;
        Node(char sumbol, Node* pNext)
        {
            this->sumbol = sumbol;
            this->pNext = pNext;
        }

        Node(double number, Node* pNext)
        {
            this->number = number;
            this->pNext = pNext;
        }


    };
    Node* top;
    int capacity;
    //char obratPolsk[100];
    string obratPolsk[100];
};

int Stack::processStr(char* str)
{
    int size = strlen(str);
    str[size] = '+';
    size++;
    int begin = 0;
    int index = 1;
    string substring="";
    int k = 0;
    int capacityIntoBracets = 0;
    int activaton = 0;
    for(int i=0;i<size;i++)
    {

        
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'|| str[i] == '('|| str[i] == ')')
        {
            if(str[i]=='(' || str[i] == ')')
            {
                this->push_back(str[i]);
                capacityIntoBracets++;
                activaton = 1;
                capacity--;
            }
            else
            {
                obratPolsk[index] = substring;
                index++;
                substring = "";
                if (k != 0)
                {
                    //print();
                    if ((str[i] == '+' || str[i] == '-')&top->sumbol!='(' & top->sumbol != ')')
                    {
                        if (activaton == 1)
                        {
                            for (int j = 0; j < (capacityIntoBracets-1); j++)
                            {
                                obratPolsk[index] = top->sumbol;
                                index++;
                                top = top->pNext;
                            }
                            this->push_back(str[i]);
                            capacity--;
                        }
                        else 
                        {
                            for (int j = 0; j < capacity; j++)
                            {
                                obratPolsk[index] = top->sumbol;
                                index++;
                                top = top->pNext;
                            }
                            this->push_back(str[i]);
                        }
                        
                    }
                    else if ((str[i] == '+' || str[i] == '-') & top->sumbol == '(') 
                    {
                        this->push_back(str[i]);
                        capacity--;
                        capacityIntoBracets++;
                    }

                    else if ((str[i] == '*' || str[i] == '/') & top->sumbol != ')')
                    {
                        if (activaton == 1) 
                        {
                            this->push_back(str[i]);
                            capacity--;
                            capacityIntoBracets++;
                        }
                        else 
                        {
                            this->push_back(str[i]);
                        }
                        
                    }
                    else if (top->sumbol == ')')
                    {

                        for (int j = 0; j < capacityIntoBracets; j++)
                        {
                            if (top->sumbol != '(' & top->sumbol != ')') 
                            {
                                obratPolsk[index] = top->sumbol;
                                index++;
                                top = top->pNext;
                            }
                            else 
                            {
                                top = top->pNext;
                            }
                        }

                        for (int j = 0; j < capacity; j++)
                        {
                            obratPolsk[index] = top->sumbol;
                            index++;
                            top = top->pNext;
                        }

                        activaton = 0;
                        k = 0;
                        capacityIntoBracets = 0;

                        if ((str[i] == '*' || str[i] == '/'||str[i] == '+' || str[i] == '-')&i!=(size-1))
                        {
                            this->push_back(str[i]);
                            k = 1;
                        }
                    }
                }
                else
                {
                    if (activaton == 1) 
                    {
                        capacityIntoBracets++;
                        capacity--;
                    }
                    this->push_back(str[i]);
                    if (i == (size - 1)) 
                    {
                    
                        obratPolsk[index] = top->sumbol;
                        index++;
                    }
                    k++;
                }
            }
        }
        else
        {
            substring = substring + str[i];
        }

    }

    for(int i=1;i<index;i++)
    {
        cout << obratPolsk[i] << " ";
    }
    return index;
}

void Stack::push_back(char sumbol)
{
    if (top == nullptr)
    {
        Node* currant = new Node(sumbol,nullptr);
        top = currant;

        capacity=1;
    }
    else
    {
        Node* currant = new Node(sumbol, top);
        top = currant;
        capacity++;
    }
}

void Stack::push_back(double number)
{
    if (top == nullptr)
    {
        Node* currant = new Node(number, nullptr);
        top = currant;

        capacity = 1;
    }
    else
    {
        Node* currant = new Node(number, top);
        top = currant;
        capacity++;
    }
}

Stack::Stack()
{
    top = nullptr;
    capacity = 0;
}

void Stack::pop()
{
    top = top->pNext;
}

void Stack::print()
{
    cout << top->sumbol << endl;
}

void Stack::calculateObrat(int index)
{
    if(top!=nullptr)
    {
        top = top->pNext;
    }

    double num;
    double a, b;
    double resultOfExample = 0;
    string buf;
    char unit;
    for(int i=1;i<index;i++)
    {
    if(obratPolsk[i]!="+"& obratPolsk[i] != "-"& obratPolsk[i] != "*"&obratPolsk[i] != "/")
    {
        num = stof(obratPolsk[i]);
        this->push_back(num);
    }
    else 
    {
        buf = obratPolsk[i];
        unit = buf[0];
        b = top->number;
        top = top->pNext;
        a = top->number;
        top = top->pNext;
        switch (unit)
        {
        case '+':
            resultOfExample = a + b;
            break;
        case '-':
            resultOfExample =a - b;
            break;
        case '*':
            resultOfExample =a * b;
            break;
        case '/':
            resultOfExample =a / b;
            break;
        }
        this->push_back(resultOfExample);
    }

    }
    cout << "\nResult = " << resultOfExample << endl;
}

int main()
{
    Stack stack;
    char primer[100];
    cin.get(primer, 100);
    int n=stack.processStr(primer);

    stack.calculateObrat(n);

}
