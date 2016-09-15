// Eugene Han

#include<iostream>
#include<fstream>
using namespace std;



class Convert_Input
{
private: int hour;
private: int minute;
private: string pmORam;

	public: Convert_Input()
	{
		hour = 0;
		minute = 0;
		pmORam = "NA";
	}
	public: ~Convert_Input(){}

	public:

	void readFileInput()
	{
		ifstream InputStream;
		InputStream.open("inputhour.txt");
		if(InputStream.is_open())
		{
			InputStream >> hour;
		}
		else
			cout << "failed to open file";
		InputStream.close();

		InputStream.open("inputminute.txt");
		if(InputStream.is_open())
		{
			InputStream >> minute;
		}
		else
			cout << "failed to open file";
		InputStream.close();
	}

	void convertHour()
	{
		if(hour == NULL)
			cout << "no input read yet!";
		else
		{
			if(hour > 12)
			{
				hour = hour - 12;
				pmORam = "pm";
			}
			else if(hour == 12)
				pmORam = "pm";
			else
				pmORam = "am";
		}
	}

	void writeFileOutput()
	{
		ofstream outputStream;
		outputStream.open("output.txt");
		if(!outputStream.is_open())
		{
			cout << "error opening output.txt";
		}

		outputStream << hour << ":" << minute << pmORam;
		cout << "the time is: " << hour << ":" << minute << pmORam;
		cout << "\n\n\ncheck the file output.txt to check if I did this right.";

		outputStream.close();
	}

	void convertInputAPI()
	{
			readFileInput();

			convertHour();
			writeFileOutput();
	}



};

int main() {

	Convert_Input convertInputObject;

	convertInputObject.convertInputAPI();

}
