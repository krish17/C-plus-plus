#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("my.html");

	outfile << "<!DOCTYPE html>"<<endl;
	outfile << "<html>" << endl;
	outfile << "<head>" << endl;
	outfile << "<title>Page Title</title>" << endl;
	outfile << "</head>" << endl;
	outfile << "<body>" << endl;
	outfile << "<h1>This is a Heading</h1>" << endl;
	outfile << "<p>This is a paragraph.</p>" << endl;
	outfile << "</body>" << endl;
	outfile << "</html>" << endl;

	outfile.close();
	system("pause");
	return 0;
}
