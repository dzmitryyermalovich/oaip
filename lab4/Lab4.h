//---------------------------------------------------------------------------

#ifndef Lab4H
#define Lab4H
//---------------------------------------------------------------------------
#endif
#include<String.h>
#include<String>
class Stack
{
public:
		  Stack()
		  {
		   top = nullptr;
		   capacity = 0;
		  }

		  void push_back(char sumbol)
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

		  void push_back(double number)
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

		  int processStr(char* str,TMemo *Memo1)
		  {
				int size = strlen(str);
				str[size] = '+';
				size++;
				int begin = 0;
				int index = 1;
				String substring="";
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

			String NewStr="";

			for(int i=1;i<index;i++)
			{
				NewStr=NewStr+obratPolsk[i];
			}

				Memo1->Lines->Add(NewStr);

			//Memo1->Lines->Add(obratPolsk[1]+" "+obratPolsk[2]+" "+obratPolsk[3]+" "+obratPolsk[4]+" "+obratPolsk[5]+" "+obratPolsk[6]);
			//for(int i=1;i<=index;i++)
			//{
			 //Memo1->Lines->Add(NewStr);
			//}


			return index;
		  }

		 void calculateObrat(int index,TMemo *Memo1)
		 {
					if(top!=nullptr)
					{
						top = top->pNext;
					}

					float num;
					float a, b;
					float resultOfExample = 0;
					String buf;
					char unit;

					for(int i=1;i<index;i++)
					{
					if(obratPolsk[i]!="+"& obratPolsk[i] != "-"& obratPolsk[i] != "*"&obratPolsk[i] != "/")
					{
						num = StrToFloat(obratPolsk[i]);
						this->push_back(num);
					}
					else
					{
						buf = obratPolsk[i];
						unit = buf[1];
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

					Memo1->Lines->Add(resultOfExample);
					//cout << "\nResult = " << resultOfExample << endl;
		 }
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
	String obratPolsk[100];

};
