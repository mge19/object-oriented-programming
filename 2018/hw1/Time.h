/************************************
*BLG252E-Object Oriented Programming*
*Homework-1                         *
*Mehmet Gencay Ertürk - 150130118   *
************************************/    
class Time {
   private:
    	int day,month,year,hour,minute;
   public:		
  	  	Time(int a[5]);
  	  	void getTime();
   	  	bool operator==(const Time& t);
   	  	bool operator<(const Time& t);
   	  	bool operator>(const Time& t);
		long int getDate();
};
