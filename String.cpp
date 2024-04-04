#include "String.hpp"
#include <iostream>

//CONSTRUCTORS

//Default Constructor
String::String()
{
    str = nullptr;
    length = 0;
    capacity = 0;
}

//Constructor with string parameter
String::String(const char* str)
{
    length = strlen(str);
    capacity = length + 1;
    this->str = new char[capacity];
    strcpy(this->str, str);
}

//Copy Constructor
String::String(const String& other)
{
    length = other.length;
    capacity = other.capacity;
    str = new char[capacity];
    strcpy(str, other.str);
}

//Destructor
String::~String()
{
    delete[] str;
}

//FUNCTIONS

//Returns the length of the string
size_t String::Length() const
{
    return length;
}

//Returns the character at the given index
char& String::CharacterAt(size_t index)
{
    return str[index];
}

//Returns the character at the given index
const char& String::CharacterAt(size_t index) const
{
    return str[index];
}

//Returns true if the string is equal to the other string
bool String::EqualTo(const String& other) const
{
    if (strcmp(str, other.str) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Appends the given string to the end of this string
String& String::Append(const String& other)
{
    size_t newlength = length + other.length; //Calculate the new length
	capacity = newlength + 1;
	char* temp = new char[capacity];
	strcpy(temp, str);
	delete[] str;
	str = temp; //Set THIS->STR to the TEMP string
	strcat(str, other.str); //Append the string
	length = newlength; //Update the length
	return *this;

}

//Prepends the given string to the beginning of this string
String& String::Prepend(const String& other)
{
	size_t newlength = length + other.length; //Calculate the new length
	capacity = newlength + 1;
	char* temp = new char[capacity];
	strcpy(temp, other.str); //Copy the OTHER string to the TEMP string
	strcat(temp, str); //Append THIS->STR to the TEMP string
	delete[] str;
	str = temp; //Set THIS->STR to the TEMP string
	length = newlength; //Update the length
	return *this;
}

//Returns the string
const char* String::CStr() const
{
	return str;
}

//Converts the string to lowercase
String& String::ToLower()
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
	return *this;
}

//Converts the string to uppercase
String& String::ToUpper()
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = toupper(str[i]);
	}
	return *this;
}

//Finds the first occurrence of the given string in this string
size_t String::Find(const String& other)
{
	size_t i = 0;
	size_t j = 0;

	while (str[i] != '\0')
	{
		j = 0;
		while(other.str[j] == str[i + j]) //While the characters match, keep going
		{
			if (other.str[j + 1] == '\0') //if the other string is complete
			{
				return i; //return the index
			}
			j++;
		}
		i++;
	}
	return -1;
}

//Finds the first occurrence of the given string in this string, starting from the given index
size_t String::Find(size_t startIndex, const String& other)
{
	size_t i = startIndex;
	size_t j = 0;

	while (str[i] != '\0')
	{
		j = 0;
		while(other.str[j] == str[i + j]) //While the characters match, keep going
		{
			if (other.str[j + 1] == '\0') //if the other string is complete
			{
				return i; //return the index
			}
			j++;
		}
		i++;
	}
	return -1;
}

//Replaces all occurrences of the given string with the replacement string
String& String::Replace(const String& find, const String& replace)
{
	String ogstr(str); //Copy of the original string. We use this later
	int findcount = 0; //Count of how many times the find string appears
	int index = Find(find); //Index of occurrence of the find string
	while(Find(index, find) != -1) //While there are still occurrences of the find string
	{
		index = Find(index, find.str) + 1; //Find the next occurrence
		findcount++; //Increment the count
	}
	int strdiff = (strlen(replace.str) - strlen(find.str)); //Difference in length between the find and replace strings
	length = length + (strdiff * findcount); //Update the length
	capacity = length + 1; //Update the capacity
	char* temp = new char[capacity]; //Create a new string with the updated capacity
	delete[] str; 
	str = temp; //Set THIS->STR to the TEMP string

	index = ogstr.Find(find); //Find the first occurrence of the find string

	int i = 0; //i is where we're up to in the new string
	int j = 0; //j is where we're up to in the replace string
	int k = 0; //k is where we're up to in the original string
	while (i < length) //While we're not at the end of the new string
	{
		if (k == index) //If we're at the index of the find string
		{
			j = 0; //Reset j
			while(replace.str[j] != '\0')
			{
				str[i] = replace.str[j];
				i++;
				j++;
			}
			index++;
			index = ogstr.Find(index, find); //Find the next occurrence of the find string
			k = k + strlen(find.str); //Skip the find string (we don't want to add it to the new string)
		}
		else
		{
			str[i] = ogstr.str[k]; //Copy the character from the original string
			i++;
			k++;
		}
	}

	str[i] = '\0';
	
	return *this;
}

//Reads a string from the console
String& String::ReadFromConsole()
{
	char temp[100];
	std::cin.getline(temp, 100);
	length = strlen(temp);
	capacity = length + 1;
	str = new char[capacity];
	strcpy(str, temp);
	return *this;
}

//Writes the string to the console
String& String::WriteToConsole()
{
	std::cout << str << std::endl;
	return *this;
}

//OPERATORS

//Returns true if the strings are equal
bool String::operator==(const String& _other) const
{
	if (strcmp(str, _other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Returns true if the strings are not equal
bool String::operator!=(const String& _other)
{
	if (strcmp(str, _other.str) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Assigns the values of the other string to this string
String& String::operator=(const String& other)
{
	length = other.length;
	capacity = other.capacity;
	delete[] str;
	str = new char[capacity];
	strcpy(str, other.str);
	return *this;
}

//Returns the character at the given index
char& String::operator[](size_t index)
{
	return str[index];
}

//Returns the character at the given index
const char& String::operator[](size_t index) const
{
	return str[index];
}

//Returns true if first (non-matching) is 
bool String::operator<(const String& other) const
{
	if (strcmp(str, other.str) < 0) //strcmp returns a negative number if the first string is less than the second
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Returns a new string that combines this string and the other string
String String::operator+(const String& other) const
{
	char* newdata = new char[strlen(str) + strlen(other.str) + 1];
	strcpy(newdata, str);
	strcat(newdata, other.str);

	String result(newdata);

	delete[] newdata;

	return result;
}

//Appends the other string to this string
String& String::operator+=(const String& other)
{
	Append(other);
	return *this;
}

