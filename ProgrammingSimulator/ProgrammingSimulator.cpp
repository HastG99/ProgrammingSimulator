#include <iostream>
#include <cstring>

#ifdef _WIN32 
	#include <conio.h>
#else 
	#include <unistd.h>
	#include <termios.h>
#endif

using namespace std;

char getChar();

int main()
{

	// An array of characters for character-by-character output to the console.
	const char* code = "#include <iostream>\n#include <cstring>\n\n#ifdef _WIN32\n\t#include <conio.h>\n#else\n\t#include <unistd.h>\n\t#include <termios.h>\n#endif\n\nusing namespace std;\n\nchar getChar();\n\nint main()\n{\n\n\t// An array of characters for character-by-character output to the console.\n\tconst char* code = \"StackOverFlowException\";\n\n\t// Loop counter.\n\tint pointer = 0;\n\n\t// The length of the string.\n\tconst int length = strlen(code);\n\n\t// A loop that is executed if the loop counter is less than the length of the string.\n\twhile (pointer < length)\n\t{\n\t\t/*\n\t\t\tWaiting for a key to be pressed on the keyboard and receiving its number.\n\t\t\tIf the number is 3, which is equivalent to CTRL + C, the loop ends.\n*/\n\t\tif (getChar() == 3) break;\n\n\t\t// Prints 1 character from a string with an index equal to the loop counter and adds 1 to it.\n\t\tcout << code[pointer++];\n\t}\n\n\t// Prints next line.\n\tcout << endl;\n\n\t#ifdef _WIN32\n\t\tsystem(\"pause\");\n\t#endif\n\n\treturn 0;\n}\n\nchar getChar() {\n\t#ifdef _WIN32\n\t\treturn _getch();\n\t#elif defined linux\n\t\tchar buf = 0;\n\t\tstruct termios old = { 0 };\n\t\tfflush(stdout);\n\t\tif (tcgetattr(0, &old) < 0)\n\t\t\tperror(\"tcsetattr()\");\n\t\told.c_lflag &= ~ICANON;\n\t\told.c_lflag &= ~ECHO;\n\t\told.c_cc[VMIN] = 1;\n\t\told.c_cc[VTIME] = 0;\n\t\tif (tcsetattr(0, TCSANOW, &old) < 0)\n\t\t\tperror(\"tcsetattr ICANON\");\n\t\tif (read(0, &buf, 1) < 0)\n\t\t\tperror(\"read()\");\n\t\told.c_lflag |= ICANON;\n\t\told.c_lflag |= ECHO;\n\t\tif (tcsetattr(0, TCSADRAIN, &old) < 0)\n\t\t\tperror(\"tcsetattr ~ICANON\");\n\t\treturn buf;\n\t#else\n\t\tthrow new exception(\"System not supported.\");\n\t\treturn -1;\n\t#endif\n}";

	// Loop counter.
	int pointer = 0;

	// The length of the string.
	const int length = strlen(code);

	// A loop that is executed if the loop counter is less than the length of the string.
	while (pointer < length) 
	{
		/*
			Waiting for a key to be pressed on the keyboard and receiving its number.
			If the number is 3, which is equivalent to CTRL + C, the loop ends.
		*/
		if (getChar() == 3) break;

		// Prints 1 character from a string with an index equal to the loop counter and adds 1 to it.
		cout << code[pointer++];
	}

	// Prints next line.
	cout << endl;

	#ifdef _WIN32 
		      ("pause");
	#endif

	return 0;
}

char getChar() {
	#ifdef _WIN32 
		return _getch();
	#elif defined linux

		char buf = 0;
		struct termios old = { 0 };
		fflush(stdout);
		if (tcgetattr(0, &old) < 0)
			perror("tcsetattr()");
		old.c_lflag &= ~ICANON;
		old.c_lflag &= ~ECHO;
		old.c_cc[VMIN] = 1;
		old.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSANOW, &old) < 0)
			perror("tcsetattr ICANON");
		if (read(0, &buf, 1) < 0)
			perror("read()");
		old.c_lflag |= ICANON;
		old.c_lflag |= ECHO;
		if (tcsetattr(0, TCSADRAIN, &old) < 0)
			perror("tcsetattr ~ICANON");
		return buf;
	#else
		throw new exception("System not supported.");
		return -1;
	#endif
}