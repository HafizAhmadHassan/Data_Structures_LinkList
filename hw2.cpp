#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

template <typename T>

class list
{
private:
	struct node
	{
		T data;
		node * next;
	};

	node * head;
	node * tail;
	int size;

public:

	node * create_node(T &x)
	{
		mode * temp = new node;
		temp->data = x;
		temp->next = NULL;
		return temp;
	}
	list()
	{
		head=tail=NULL;
		size=0;
	}
	list(const T arr[])
	{
		size=0;
		node * temp = new node;
		temp->data=arr[0];
		temp->next= new node;
		head=temp;
		size++;
		for(int i=1; arr[i]!='\0'; i++)
		{
			temp=temp->next;
			temp->data=arr[i];
			temp->next = new node;
			size++;
		}

		tail=temp;
		temp->next=NULL;
		
	}
	/*list (list &obj)
	{
		node * temp1 = new node;
		temp1 = obj.head;
		size=obj.size;

		node * temp2 = new node;
		head = temp2;

		for(int i=0; i<obj.size; i++)
		{
			temp2->data = temp1->data;
			
			if(temp1->next!=NULL){temp1=temp1->next;}
			temp2->next = new node;
			temp2=temp2->next;
			
		}
		tail=temp2;
		temp2->next=NULL;
	}*/
	list copy_from_arr(T arr[])
	{
		size=0;
		node * temp = new node;
		temp->data=arr[0];
		temp->next= new node;
		head=temp;
		size++;
		for(int i=1; arr[i]!='\0'; i++)
		{
			temp=temp->next;
			temp->data=arr[i];
			temp->next = new node;
			size++;
		}

		tail=temp;
		temp->next=NULL;

		return *this;
	}
	list operator = (list obj)
	{
		node * temp1 = new node;
		temp1 = obj.head;

		node * temp2 = new node;
		head = temp2;

		for(int i=0; i<obj.size; i++)
		{
			temp2->data = temp1->data;	
			if(temp1->next!=NULL && temp2->next!=NULL)
			{
				temp2->next = new node;
				temp2=temp2->next;
				temp1=temp1->next;
			}
		}

		size=obj.size;
		tail=temp2;
		temp2->next=NULL;
		

		return *this;
	}
	list operator + (list obj)
	{
		node * temp = new node;
		temp = head;

		node * temp2 = new node;
		temp2 = obj.head;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}

		while(temp2!=NULL)
		{
			temp->next = new node;
			temp=temp->next;
			temp->data = temp2->data;
			temp2=temp2->next;
			
		}

		tail=temp;
		temp->next=NULL;

		size = size + obj.size; 

		return *this;
	}
	friend istream& operator >>(istream &in, list &l)
	{
		T arr[1000];
		cout<<endl<<" Enter the list: ";
		in.getline(arr,1000);
		l.copy_from_arr(arr);

		return in;

	} 
	friend ostream& operator <<(ostream &out, list l)
	{
		out<<endl;
		int i=0;
		node * temp=new node;
		temp=l.head;

		cout<<" ";
		while(i<l.size)
		{
			out<<temp->data;
			temp=temp->next;
			i++;
		}

		out<<" ; Size:"<<l.size<<endl<<endl;

		return out;
	}
	int getSize()
	{
		return size;
	}
	bool find(T arr[])
	{
		node * temp = new node;
		temp=head;
		int i=0,len=0;
		bool check=false;

		for(int x=0; arr[x]!='\0'; x++)
		{
			len++;
		}
		if(len>size)
		{
			return false;
		}

		int k=0;

		while(k<size)
		{
			
			if(temp->data == arr[i])
			{
				temp = temp->next;
				check=true;
				for(int j=i+1; j<i+len; j++)
				{
					if(arr[j]!=temp->data)
					{
						check=false;
						break;
					}
					if(temp->next!=NULL)
					{
						temp=temp->next;
					}
				}

				if(check==true)
				{
					return true;
				}
			}
			if(temp->next!=NULL)
			{
				i=0;
				temp=temp->next;
			}

			k++;
		}

		return check;
	}
	bool find_list(list &obj)
	{
		node * temp1 = new node;
		temp1=head;

		node * temp2 = new node;
		temp2=obj.head;

		bool check=false;

		while(temp1->next!=NULL)
		{
			
			if(temp1->data == temp2->data)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
				check=true;

				while(temp2!=NULL)
				{
					if(temp1->data!=temp2->data)
					{
						check=false;
						break;
					}
					else
					{
						temp1=temp1->next;
						temp2=temp2->next;
					}
				}

				if(check==true)
				{
					return true;
				}
			}
				temp2=obj.head;
				temp1 = temp1->next;
		}

		return check;
	}
	list& findANDcopy(T arr[])
	{
		list l;
		node * copy = new node;
		l.head = copy;

		node * temp = new node;
		temp = head;

		int i=0,len=0;
		int j=i+1;

		bool check = find(arr);

		if(check==false)
		{
			cout<<" Not Found";
			copy=NULL;
			return l;
		}
		else
		{
			cout<<" Found";
			for(int a=0; arr[a]!='\0'; a++)
			{
				len++;
			}
			l.size = len;

			while(temp->next!=NULL)
			{
				if(temp->data==arr[i])
				{
					copy->data = arr[i];
					copy->next = new node;
					copy = copy->next;
					temp = temp->next;

					for(j=i+1; j<i+len; j++)
					{
						if(temp->data!=arr[j])
						{
							check = false;
							break;
						}

						copy->data = arr[j];
						copy->next=NULL;
						if(temp->next!=NULL && j!=i+len-1)
						{
							copy->next = new node;
							copy = copy->next;
							temp = temp->next;
						}
					}

					if(check==true)
					{
						return l;
					}
				}

				i=0;
				temp=temp->next;
				copy=l.head;
			}
		}
		

		return l;

	}
	list& findANDcut(T arr[])
	{
		list l;
		node * first = new node;
		node * cut = new node;
		l.head = cut;

		node * temp = new node;
		temp = head;

		int len=0;
		for(int i=0 ; arr[i]!='\0'; i++)
		{
			len++;
		}

		bool check=find(arr);
		if(check==false || len>size)
		{
			return l;
		}
		else
		{
			int i=0;
			int index=0;
			first=temp;
			while(i<size)
			{
				if(temp->data==arr[index])
				{
					check=true;
					cut->data=arr[index];
					cut->next = new node;
					cut = cut->next;
					temp = temp->next;
					index++;
					for(int j=index; j<index+len-1; j++)
					{
						if(temp->data!=arr[j])
						{
							check=false;
							break;
						}
						else
						{
							cut->data=arr[index];
							cut->next = new node;
							cut = cut->next;
							temp = temp->next;
						}
					}
					if(check==true)
					{
						if(first==head && i==0)
						{
							first->next = temp;
							head = head->next;
							size=size-len;
							return l;
						}
						else
						{
							first->next = temp;
							size=size-len;
							return l;
						}
					}
				}





				i++;
				first = temp;
				index=0;
				if(temp->next!=NULL)
				{
					temp = temp->next;
				}
				cut = l.head;
			}

		}



	}
	list& findANDreplace(T arr[], T arr2[])
	{
		list l;
		node * first = new node;
		node * cut = new node;
		l.head = cut;

		node * temp = new node;
		temp = head;

		int len=0;
		for(int i=0 ; arr[i]!='\0'; i++)
		{
			len++;
		}
		int len2=0;
		for(int i=0 ; arr2[i]!='\0'; i++)
		{
			len2++;
		}

		bool check=find(arr);
		if(check==false || len>size)
		{
			return l;
		}
		else
		{
			int i=0;
			int index=0;
			first=temp;
			while(i<size)
			{
				if(temp->data==arr[index])
				{
					
					check=true;
					cut->data=arr[index];
					cut->next = new node;
					cut = cut->next;
					temp = temp->next;
					index++;
					for(int j=index; j<index+len-1; j++)
					{
						if(temp->data!=arr[j])
						{
							check=false;
							break;
						}
						else
						{
							cut->data=arr[j];
							cut->next = new node;
							cut = cut->next;
							temp = temp->next;
						}
					}
					if(check==true)
					{
						if(first==head && i==0)
						{
							for(int i=0; i<len2; i++)
							{
								first->data = arr2[i];
								if(i<len2-1)
								{
									first->next = new node;
									first = first->next;
								}
							}
							first->next = temp;
							size=size-len+len2;
							return l;
						}
						else
						{
							first = first->next;
							for(int i=0; i<len2; i++)
							{
								first->data = arr2[i];
								if(i<len2-1)
								{
									first->next = new node;
									first = first->next;
								}
							}
							first->next = temp;
							size=size-len+len2;
							return l;
						}
					}
				}





				i++;
				first = temp;
				index=0;
				if(temp->next!=NULL)
				{
					temp = temp->next;
					cut = l.head;
				}
			}

		}

	}
	list& findANDinsert(T arr[], T arr2[])
	{
		list l;
		node * first = new node;
		node * cut = new node;
		l.head = cut;

		node * temp = new node;
		temp = head;

		int len=0;
		for(int i=0 ; arr[i]!='\0'; i++)
		{
			len++;
		}		
		int len2=0;
		for(int i=0 ; arr2[i]!='\0'; i++)
		{
			len2++;
		}

		bool check=find(arr);
		if(check==false || len>size)
		{
			return l;
		}
		else
		{
			int i=0;
			int index=0;
			while(i<size)
			{
				if(temp->data==arr[index])
				{
					check=true;
					cut->data=arr[index];
					cut->next = new node;
					cut = cut->next;
					first=temp;
					temp = temp->next;
					index++;
					for(int j=index; j<index+len-1; j++)
					{
						if(temp->data!=arr[j])
						{
							check=false;
							break;
						}
						else
						{
							cut->data=arr[index];
							cut->next = new node;
							cut = cut->next;
							first=temp;
							temp = temp->next;

						}
					}
					if(check==true)
					{
						node * last = temp;
						first->next=new node;
						first=first->next;
						for(int i=0; i<len2; i++)
						{
							first->data=arr2[i];
							if(i<len2-1)
							{
								first->next=new node;
								first = first->next;
							}
						}

						first->next=temp;
						size=size+len2;
						return l;

					}
				}

				i++;
				index=0;
				if(temp->next!=NULL)
				{
					temp = temp->next;
				}
				cut = l.head;
			}

		}

	}
	list& findANDinvert(T arr[])
	{
		list l;
		node * first = new node;
		node * cut = new node;
		l.head = cut;
		T arr2[1000];
		node * temp = new node;
		temp = head;

		int len=0;
		for(int i=0 ; arr[i]!='\0'; i++)
		{
			len++;
		}
		for(int a=0; arr[a]!='\0'; a++)
		{
			arr2[a]=arr[len-1-a];	
			arr2[a+1]='\0';
		}
		int len2=len;

		bool check=find(arr);
		if(check==false || len>size)
		{
			return l;
		}
		else
		{
			int i=0;
			int index=0;
			first=temp;
			while(i<size)
			{
				if(temp->data==arr[index])
				{
					
					check=true;
					cut->data=arr[index];
					cut->next = new node;
					cut = cut->next;
					temp = temp->next;
					index++;
					for(int j=index; j<index+len-1; j++)
					{
						if(temp->data!=arr[j])
						{
							check=false;
							break;
						}
						else
						{
							cut->data=arr[index];
							cut->next = new node;
							cut = cut->next;
							temp = temp->next;
						}
					}
					if(check==true)
					{
						if(first==head && i==0)
						{
							for(int i=0; i<len2; i++)
							{
								first->data = arr2[i];
								if(i<len2-1)
								{
									first->next = new node;
									first = first->next;
								}
							}
							first->next = temp;
							size=size-len+len2;
							return l;
						}
						else
						{
							first = first->next;
							for(int i=0; i<len2; i++)
							{
								first->data = arr2[i];
								if(i<len2-1)
								{
									first->next = new node;
									first = first->next;
								}
							}
							first->next = temp;
							size=size-len+len2;
							return l;
						}
					}
				}





				i++;
				index=0;
				first = temp;
				if(temp->next!=NULL)
				{
					temp = temp->next;
				}
				cut = l.head;
			}

		}

	}
	void reverse()
	{
		node * temp = new node;
		temp = head;
		T arr[1000];
		int i=0;

		for(i=0; i<size; i++)
		{
			arr[i]=temp->data;
			temp=temp->next;
		}

		arr[i]='\0';

		temp = head;

		for(i=size-1; i>=0; i--)
		{
			temp->data=arr[i];
			if(i>0)
			{
				temp->next = new node;
				temp=temp->next;
				temp->next=NULL;
			}
		}

	}

};

int main(void)
{
	char arr[25];
	char arr2[25];
	list<char> l;
	list<char> m;
	cin>>l;
	char key;
	system("cls");
	

	while(true)
	{
		cout<<" ------------------------------------------------------------------------------"<<endl;
		cout<<l;
		cout<<" ------------------------------------------------------------------------------"<<endl<<endl;
		cout<<" Press key:"<<endl<<endl;
		cout<<" a=Concatenate; b=Find; c=Find&Copy; d=Find&Cut"<<endl<<endl;
		cout<<" e=Find&Replace; f=Find&Insert; g=Find&Invert"<<endl<<endl;
		cout<<" h=Reversve; q=Quit"<<endl;
		cout<<" ";
		up:key = getch();

		if(key=='a')
		{
			list<char> m;
			cout<<"";
			cin>>m;
			l=l+m;
		}
		else if(key=='b')
		{
			bool check=false;
			cout<<endl<<" Find: ";
			cin.getline(arr,25);
			check=l.find(arr);
			if(check==true)
			{
				cout<<endl<<endl<<" Found";
			}
			else if(check==false)
			{
				cout<<endl<<endl<<" Not Found";
			}
		}
		else if(key=='c')
		{
			list<char> m;
			cout<<endl<<" Copy: ";
			cin.getline(arr,25);
			cout<<endl;
			m=l.findANDcopy(arr);
			if(m.getSize()!=0)
			{
				cout<<endl<<m;
			}
		}
		else if(key=='d')
		{
			list<char> m;
			cout<<endl<<" Cut: ";
			cin.getline(arr,25);
			cout<<endl;
			m=l.findANDcut(arr);
			if(m.getSize()!=0)
			{
				cout<<endl<<m;
				cout<<l;
			}
		}
		else if(key=='e')
		{
			list<char> m;
			cout<<endl<<" Cut: ";
			cin.getline(arr,25);
			cout<<endl<<" Paste: ";
			cin.getline(arr2,25);
			cout<<endl;

			m=l.findANDreplace(arr,arr2);
			if(m.getSize()!=0)
			{
				cout<<endl<<m;
				cout<<l;
			}
		}
		else if(key=='f')
		{
			list<char> m;
			cout<<endl<<" Enter: ";
			cin.getline(arr2,25);
			cout<<endl<<" After: ";
			cin.getline(arr,25);
			cout<<endl;

			m=l.findANDinsert(arr,arr2);
			if(m.getSize()!=0)
			{
				cout<<endl<<m;
				cout<<l;
			}
		}
		else if(key=='g')
		{
			list<char> m;
			cout<<endl<<" Invert: ";
			cin.getline(arr2,25);

			m=l.findANDinvert(arr2);
			if(m.getSize()!=0)
			{
				cout<<endl<<m;
				cout<<l;
			}
		}
		else if(key=='h')
		{
			list<char> m;
			l.reverse();		
		}
		else if(key=='q')
	    {break;}
		else
		{
			goto up;
		}
		getch();
		system("cls");
	}

}
