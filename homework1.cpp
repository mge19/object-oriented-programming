//BLG252E-Object Oriented Programming
//Homework-1
//Mehmet Gencay Ertürk - 150130118
#include <bits/stdc++.h>
using namespace std;
class Pizza{ //Pizza attributes and methods
	private:
		string name,size,crust_type,*ingredients;
	public:
		Pizza();
		Pizza(string size,string crust_type,int pizza_type);
		string getsize(),getcrust(),getname(),*getingredients();
		Pizza(const Pizza& p);
		~Pizza();
};
Pizza::Pizza() //Pizza empty constructor creates medium size,normal crust pizza with mozarella ingredient.
{
	size="medium";
	crust_type="normal";
	ingredients=new string;
	ingredients[0]="mozarella";
}
Pizza::Pizza(string size,string crust,int pizza_type) //Create a pizza with given size,crust,type. Ingredients depend on type.
{
	this->size=size;
	this->crust_type=crust;
	ingredients=new string[6];
	ingredients[0]="mozarella";
	ingredients[1]="corn";
	if(pizza_type==1 || pizza_type==3)
	{
		ingredients[2]="mushroom";
		ingredients[3]="tomato";
	}
	if(pizza_type==1)
	{
		name="Chicken";
		ingredients[4]="chicken";
	}
	if(pizza_type==2)
	{
		name="Broccoli";
		ingredients[2]="broccoli";
		ingredients[3]="pepperoni";
	}
	if(pizza_type==2 || pizza_type==3){ingredients[4]="olive";}
	if(pizza_type==3)
	{
		name="Sausage";
		ingredients[5]="sausage";
	}
	if(pizza_type==1 || pizza_type==2){ingredients[5]="onion";}
}
Pizza::Pizza(const Pizza& p) //Copy constructor
{
	name=p.name;
	size=p.size;
	crust_type=p.crust_type;
	ingredients=new string[6];
	copy(p.ingredients,p.ingredients+6,ingredients);
	string choices;
	cout<<"Please enter the number of the ingredient you want to remove from your pizza(s):"<<endl; //When the pizza is copied, remove any ingredients.
	for(int i=0;i<6;i++){cout<<i+1<<"."<<ingredients[i]<<endl;}
	cout<<"Press 0 to save:"<<endl;
	while(true) //Take customer inputs.
	{
		char choice;
		cin>>choice;
		if(choice=='0'){break;}
		else if(choice>'6' || choice<'0'){cout<<"Invalid choice.Please try again."<<endl;}
		else //Pizza should contain at least one ingredient.
		{
			int empty=0;
			for(int i=0;i<6;i++)
			{
				if(ingredients[i]==""){empty++;}
			}
			if(empty<5){ingredients[choice-'0'-1]="";}
			else
			{
				cout<<"At least one ingredient should be present."<<endl;
				break;
			}
		}
	}
} //Getter attributes
string Pizza::getsize(){return size;}
string Pizza::getcrust(){return crust_type;}
string Pizza::getname(){return name;}
string* Pizza::getingredients(){return ingredients;}
Pizza::~Pizza(){} //Mandatory destructor
class Order{ //Order class and attributes.
	private:
		string customer; //Customer name
		int *drink; //List of drinks.1=Cola,2=soda,3=ice tea,4=fruit juice
		int amount,size; //Amount=number of pizzas,size=number of drinks
		Pizza* pizza; //List of pizzas
	public:
		Order* next; //Pointer to next order object in linked list.
		Order(string name,Pizza* p,int* drinks,int length,int length2);
		Order(string name,Pizza* p,int length);
		double getPrice();
		string getcustomer();
		void printOrder();
		~Order();
};
Order::Order(string name,Pizza* p,int* drinks,int length,int length2) //Constructor with drinks
{
	customer=name;
	amount=length;
	pizza=new Pizza[amount];
	copy(p,p+amount,pizza);
	size=length2;
	drink=new int[size];
	copy(drinks,drinks+size,drink);
	next=0;
}
Order::Order(string name,Pizza* p,int length) //Constructor with no drinks
{
	customer=name;
	amount=length;
	pizza=new Pizza[amount];
	copy(p,p+amount,pizza);
	next=0;	
	size=0;
}
double Order::getPrice() //Calculate price
{
	double price=amount;
	if(pizza[0].getsize()=="small"){price*=15;}
	else if(pizza[0].getsize()=="normal"){price*=20;}
	else{price*=25;}
	for(int i=0;i<size;i++)
	{
		if(drink[i]==1){price+=4;}
		else if(drink[i]==2){price+=2;}
		else if(drink[i]==3){price+=3;}
		else{price+=3.5;}
	}	
	return price;	
}
void Order::printOrder() //Print 1.customer name,2.Pizza details and 3.drinks and their counts if available.
{
	int n1=0,n2=0,n3=0,n4=0;
	cout<<"---------------"<<endl;
	cout<<"Name:"<<customer<<endl;
	for(int i=0;i<amount;i++)
	{
		cout<<pizza[i].getname()<<" Pizza(";
		string* x=pizza[i].getingredients();
		int endindex;
		for(int j=0;j<6;j++)
		{
			if(x[j]!=""){endindex=j;}
		}
		for(int j=0;j<6;j++)
		{
			if(x[j]!="")
			{
				cout<<x[j];
				if(j!=endindex){cout<<",";}
			}
		}
		cout<<")"<<endl;
		cout<<"Size:"<<pizza[i].getsize()<<",crust:"<<pizza[i].getcrust()<<endl;
	}
	if(size!=0)
	{
		for(int i=0;i<size;i++)
		{
			if(drink[i]==1){n1++;}
			else if(drink[i]==2){n2++;}
			else if(drink[i]==3){n3++;}
			else{n4++;}
		}
		if(n1>0){cout<<n1<<" cola";}
		if(n1>1){cout<<"s";}
		if(n1>0 && n2+n3+n4>0){cout<<",";}
		if(n2>0){cout<<n2<<" soda";}
		if(n2>1){cout<<"s";}
		if(n2>0 && n3+n4>0){cout<<",";}
		if(n3>0){cout<<n3<<" ice tea";}
		if(n3>1){cout<<"s";}
		if(n3>0 && n4>0){cout<<",";}
		if(n4>0){cout<<n4<<" fruit juice";}
		if(n4>1){cout<<n4<<"s";}
		cout<<endl;
	}
	else{cout<<"No drinks."<<endl;}
	cout<<"---------------"<<endl; 
} //Getter for customer name
string Order::getcustomer(){return customer;}
Order::~Order(){delete[] pizza,drink;} //Destructor
class OrderList{
	private:
		int n;
		Order* head; //First element of orders linked list
	public:
		OrderList();
		~OrderList();
		bool takeOrder();
		void listOrders(),deliverOrders();
};
OrderList::OrderList() //Consructor
{
	n=0;
	head=NULL;
}
bool OrderList::takeOrder()
{
	Order* prev,*current,*new_order;
	int select,amount,select_drink,*drinks;
	string size,crust,name,drinklist;
	cout<<"Pizza Menu"<<endl; //Select Pizza type
	cout<<"1.Chicken Pizza(mozarella,chicken,mushroom,corn,onion,tomato)"<<endl;
	cout<<"2.Broccoli Pizza(mozarella,broccoli,pepperoni,olive,corn,onion)"<<endl;
	cout<<"3.Sausage Pizza(mozarella,sausage,tomato,olive,mushroom,corn)"<<endl;
	cout<<"0.Back to main menu"<<endl;
	cin>>select;
	while(select<0 || select>3)
	{
		cout<<"Invalid selection.Please try again."<<endl;
		cin>>select;
	}
	if(select==0){return false;}
	cout<<"Select size:small(15 TL),medium(20 TL),big(25 TL):"; //Select size and crust
	cin>>size;
	while(size!="small" && size!="medium" && size!="big")
	{
		cout<<"Invalid selection.Please try again."<<endl;
		cin>>size;
	}
	cout<<"Select crust type(thin,normal,thick):";
	cin>>crust;
	while(crust!="thick" && crust!="normal" && crust!="thin")
	{
		cout<<"Invalid selection.Please try again."<<endl;
		cin>>crust;
	}	
	cout<<"Enter the amount:"; //Select number of pizzas
	cin>>amount;
	while(amount<1)
	{
		cout<<"Invalid selection.Please try again."<<endl;
		cin>>amount;
	}
	Pizza* pizza=new Pizza[amount]{{size,crust,select}}; //Create new pizza objects as the amount and define the first pizza
	for(int i=1;i<amount;i++){pizza[i]=Pizza(pizza[0]);} //Copy other pizzas from first pizza
	cout<<"Please choose a drink:"<<endl;
	cout<<"0.No drink"<<endl;
	cout<<"1.Cola(4 TL)"<<endl;
	cout<<"2.Soda(3 TL)"<<endl;
	cout<<"3.Ice tea(2 TL)"<<endl;
	cout<<"4.Fruit juice(3.5 TL)"<<endl;
	cout<<"Press -1 to save order"<<endl;
	cin>>select_drink;
	while(select_drink<-1 || select_drink>4)
	{
		cout<<"Invalid selection.Please try again."<<endl;
		cin>>select_drink;
	}	
	if(select_drink==0 || select_drink==-1) //Create an order object with no drinks.
	{
		cout<<"Please enter your name:";
		cin>>name;
		new_order=new Order(name,pizza,amount);
		if(!new_order)
		{
			cout<<"New order cannot be created."<<endl;
			return false;
		}
	}
	else //Take drink choices
	{
		while(true)
		{
			if(select_drink==-1){break;}
			else if(select_drink<1 || select_drink>4)
			{
				cout<<"Invalid selection.Please try again."<<endl;
				cin>>select_drink;
			}
			else
			{
				drinklist+=(select_drink+'0');
				cin>>select_drink;	
			}
		}
	}
	if(!drinklist.empty()) //Create an order objects with drinks.
	{
		int size=drinklist.size();
		drinks=new int[size];
		for(int i=0;i<size;i++){drinks[i]=drinklist[i]-'0';}
		cout<<"Please enter your name:";
		cin>>name;	
		new_order=new Order(name,pizza,drinks,amount,size);
		if(!new_order)
		{
			cout<<"New order cannot be created."<<endl;
			return false;
		}	
		delete[] drinks; //Delete temporary drink object;
	}
	delete[] pizza; //Delete temporary pizza object.
	cout<<"Your order is saved, it will be delivered when it is ready..."<<endl;
	new_order->printOrder(); //Print the new order and add it to the end of the list.
	if(!head){head=new_order;} //If there are no orders in the list.
	else
	{
		prev=head;
		current=head->next;
		while(current)
		{
			prev=current;
			current=current->next;
		}
		prev->next=new_order;
	}
	n++;
	return true;
}
void OrderList::listOrders() //Print every order with order number.
{
	if(!head) //If no orders
	{
		cout<<"No orders found."<<endl;
		return;
	}
	Order* temp=head;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<endl;
		temp->printOrder();
		temp=temp->next;
	}
}
void OrderList::deliverOrders() //Deliver order and remove it from the list. List orders before delivering.
{
	if(!head) //If no orders.
	{
		cout<<"No orders found."<<endl;
		return;
	}	
	listOrders();
	string name;
	cout<<"Please write the customer name in order to deliver his/her order(s):";
	cin>>name;
	bool found=false;
	Order* temp=head;
	int i=1;
	while(temp)
	{
		if(temp->getcustomer()==name)
		{
			found=true;
			cout<<"Following order is delivering..."<<endl;
			char yesorno;
			cout<<i<<endl;
			temp->printOrder();
			cout<<"Total price:"<<temp->getPrice()<<" TL"<<endl;
			cout<<"Do you have a promotion code?(y/n):";
			cin>>yesorno;
			while(yesorno!='y' && yesorno!='n')
			{
				cout<<"Invalid selection.Please try again."<<endl;
				cin>>yesorno;
			}
			if(yesorno=='y') //10% discount with "I am a student" promotion code.
			{
				string promotion_code;
				cout<<"Please enter your code:";
				getline(cin,promotion_code);
				getline(cin,promotion_code);
				if(promotion_code=="I am a student"){cout<<"Discounted price:"<<9*temp->getPrice()/10<<" TL"<<endl;}
				else{cout<<"Promotion code is not accepted."<<endl;}
			}
			Order* current;
			n--;
			if(temp==head){head=head->next;}
			else
			{
				Order* prev=head;
				while(prev->next!=temp){prev=prev->next;}
				current=prev->next;
				prev->next=prev->next->next;
			}
			delete current;
			cout<<"The order is delivered successfullly."<<endl;
		}
		temp=temp->next;
		i++;
	}
	if(!found){cout<<"No orders found with this name."<<endl;}
}
OrderList::~OrderList() //Destructor. Delete every nodes.
{
	while(head)
	{
		Order* current=head;
		head=head->next;
		delete current;
	}
}
int main()
{
	bool exit=false;
	OrderList orl;
	while(!exit) //Print menu and call chosen function untit user exits.
	{
		char select;
		cout<<"Welcome to Unicorn Pizza!"<<endl;
		cout<<"1.Add an order"<<endl;
		cout<<"2.List orders"<<endl;
		cout<<"3.Deliver order"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Choose what to do:";
		cin>>select;
		switch(select)
		{
			case '1':
				if(orl.takeOrder()){}
				break;
			case '2':
				orl.listOrders();
				break;
			case '3':
				orl.deliverOrders();
				break;
			case '4':
				cout<<"Goodbye...";
				exit=true;
				break;
			default:
				cout<<"Invalid choice."<<endl;
				break;
		}
	}
	getchar();
	return 0;
}
