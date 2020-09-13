//BLG252E-Object Oriented Programming
//Homework-3
//Mehmet Gencay Ertürk - 150130118
#include <bits/stdc++.h>
#define e 2.71828
using namespace std;
class Neuron{ //Abstract neuron base class 
	double z,a;
	public: //Virtual activate function,getter/setters for z,a.
		virtual void activate()=0;
		void set_z(double x){z=x;}
		void set_a(double y){a=y;}
		double get_z(){return z;}
		double get_a(){return a;} //Activate functions in derived classes used this
};
class SigmoidNeuron:public Neuron //Derived neuron classes and activate functions
{
	public:
		void activate(){set_a(1/(1+pow(e,-1*get_z())));} 
		SigmoidNeuron(){}; //Empty constructors are for convenience
};
class ReluNeuron:public Neuron
{
	public:
		void activate(){set_a(max(0.0,get_z()));}
		ReluNeuron(){};
};
class LReluNeuron:public Neuron
{
	public:
		void activate()
		{
			double x=get_z();
			set_a(max(0.1*x,x));
		}
		LReluNeuron(){};
};
class Layer{
	int size;
	Neuron* neurons; //Layer is array of neurons
	public:
		Layer(){}
		Layer(int x,int y,double* z,bool firstlayer) //Create a layer
		{
			size=x; //Number of neurons in layer
			if(y==0){neurons=new SigmoidNeuron[size];} //Determine neuron type
			else if(y==1){neurons=new LReluNeuron[size];}
			else{neurons=new ReluNeuron[size];}
			for(int i=0;i<size;i++)
			{
				neurons[i].set_z(z[i]); //Set z values of layer neurons
				if(firstlayer){cout<<neurons[i].get_z()<<endl;} //Print z value and do not calculate a value for first layer
				else //Calculate and print a value for other neurons.
				{
					neurons[i].activate();
					cout<<neurons[i].get_a()<<endl;
				}
			}
		}
		Neuron& getneuron(int i){return neurons[i];} //Neuron getter of Layer class
		~Layer(){delete[] neurons;}
};
class Network{ 
	int size;
	Layer* layers;
	public:
		Network(int x,int* y,int* z,double* a) //Create a network of layers
		{
			size=x;
			layers=new Layer[size];
			bool firstlayer=true;
			for(int i=0;i<size;i++)
			{
				cout<<"Layer "<<i<<endl; //Print layer number
				if(i>0)
				{
					double** W=new double*[y[i]]; //Creste W and B matrices
					double* b=new double[y[i]];
					a=new double[y[i]];
					for(int j=0;j<y[i];j++)
					{
						W[j]=new double[y[i-1]];
						b[j]=0.1;
						a[j]=b[j];
						for(int k=0;k<y[i-1];k++)
						{
							W[j][k]=0.1;
							if(i==1) //Calculate z values of neurons in next layer. In second layer,use z values previous layer.Otherwise,use a values. 
							{
								firstlayer=false;
								a[j]+=W[j][k]*layers[i-1].getneuron(k).get_z();
							}
							else{a[j]+=W[j][k]*layers[i-1].getneuron(k).get_a();}
						}
					}
					delete[] W;
					delete[] b;
				}
				layers[i]=Layer(y[i],z[i],a,firstlayer);
			}
		}
		~Network(){delete[] layers;}
};
int main(int argc,char** argv)
{
	ifstream file(argv[1]);
	int number_of_layers=file.get()-'0';
	int* number_of_neurons=new int[number_of_layers],*neuron_types=new int[number_of_layers];
	double* first_layer_neuron_values=new double[number_of_neurons[0]];
	for(int i=0;i<number_of_layers;i++)
	{
		file.get(); //Get newline or space character
		number_of_neurons[i]=file.get()-'0';		
	}
	for(int i=0;i<number_of_layers;i++) 
	{
		file.get(); //Get newline or space character
		try
		{
			neuron_types[i]=file.get()-'0'; //Get neuron type value and throw exception for invalid value.
			if(neuron_types[i]<0 || neuron_types[i]>2){throw "Unidentified activation function!";}
		}
		catch(const char* msg)
		{
			cerr<<msg;	
			file.close();
			delete[] number_of_neurons,neuron_types,first_layer_neuron_values;
			exit(1);
		}
	}
	file.get(); //Get newline
	for(int i=0;i<number_of_neurons[0];i++) //Take z values as much as number of neurons 
	{
		try
		{
			if(file.eof()){throw "Input shape does not match!";} //The file is invalid if file ends before loop
		}
		catch(const char* msg)
		{
			cerr<<msg;
			file.close();
			delete[] number_of_neurons,neuron_types,first_layer_neuron_values;
			exit(1);
		}
		char x=file.get(); //Get a first layer neuron value
		if(x=='-'){first_layer_neuron_values[i]='0'-file.get();} //If it gets '-' character,then the value is minus of next character.
		else{first_layer_neuron_values[i]=x-'0';}
		file.get();	//Get space character	
	}
	try
	{
		if(!file.eof()){throw "Input shape does not match!";} //Input is invalid if file does not end.
	}
	catch(const char* msg)
	{
		cerr<<msg;
		file.close();
		delete[] number_of_neurons,neuron_types,first_layer_neuron_values;
		exit(1);
	}
	Network n(number_of_layers,number_of_neurons,neuron_types,first_layer_neuron_values);
	file.close();
	delete[] number_of_neurons,neuron_types,first_layer_neuron_values;
	getchar();
	return 0;
}
