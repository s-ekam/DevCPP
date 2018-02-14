#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std ;

vector<string> datatypes;
vector<string> functions;
vector<string> keywords;
stack<string> parenthesis;
vector<string> variables;

bool isdatatype(string);
void abort(string s )
{
	cout<<s;
}
void write(string s )
{
	cout<<s;
}

//void log(string data){
//	ofstream outfile;
//  	outfile.open("log.txt", ios_base::app);
//  	outfile <<data<<endl; 
//	outfile.close();
//}



//
//void balanced(string s)
//{
//	if(parenthesis.empty())
//	{
//		abort("No Opening Bracket found, but closing bracket encounter");
//	}
//	char x=s[0];
//	string par;
//	switch(x)
//	{
//		case '}':
//			par=parenthesis.top();
//			if(par[0] != '{')
//			{
//				abort("Unbalanced Bracket,  '}' encountered");
//			}
//			parenthesis.pop();
//			break;
//		case ')':
//			par=parenthesis.top();
//			if(par[0] != '(')
//			{
//				abort("Unbalanced Bracket,  ')' encountered");
//			}
//			parenthesis.pop();
//			break;
//		case ']':
//			par=parenthesis.top();
//			if(par[0] != '[')
//			{
//				abort("Unbalanced Bracket,  ']' encountered");
//			}
//			parenthesis.pop();
//			break;
//		default :
//			if(parenthesis.empty())
//			{
//				abort("No Opening Bracket found, but closing bracket encounter");
//			}
//			break;
//	}
//}
//
//void push(string s)
//{
//	parenthesis.push(s);
//}
//
//
//void check_paren(vector<string> vec)
//{
//	for(int i=0;i<vec.size();i++)
//	{
//		if(vec[i].compare("{")==0 || vec[i].compare("(")==0 || vec[i].compare("[")==0)
//		{
//			push(vec[i]);
//		}
//		if(vec[i].compare("}")==0 || vec[i].compare(")")==0 || vec[i].compare("]")==0)
//		{
//			balanced(vec[i]);
//		}
//	}
//	if(!parenthesis.empty())
//	{
//		abort("Parenthesis not balanced");
//	}
//}
void clrscreen(vector<string>);
int main()
{
	
	cout<<"Hello World\n";
	cout<<"Hello World2\n";
	system("CLS");
	cout<<"Hello World3\n";
	string s = "clear";
	vector<string> vec;
	vec.push_back(s);
	
	vec.push_back(" 5 ");
	clrscreen(vec);
	return 0;

}



//
//vector<string> datatypes;
//vector<string> functions;
//vector<string> keywords;

void isvalid_func(vector<string> vec)
{
	if(vec[0]!="def")
	{
		return;
	}
	if(!isdatatype(vec[1]))
	{
		abort("Invalid Return Type");
	}
	
	string name = vec[2];
	int size = name.size()-name.find_first_of("(");
	name =name.substr(0,size);
	
	for(int i=0;i<keywords.size();i++)
	{
		if(keywords[i].compare(name)==0)
		{
			abort("Function name cannot be a Keyword");
		}
	}
	
	for(int i=0;i<functions.size();i++)
	{
		if(functions[i]==vec[2])
		{
			abort("Function Name Repeated");
		}
	}
	
	functions.push_back(vec[2]);
	if(vec[3]!="{")
	{
		abort("{ expected ");
	}
	string str = vec[1]+" "+vec[2]+" "+vec[3] + " ;";
	write(str);
	
}

bool isvariable(string str)
{
	for(int i=0;i<variables.size();i++)
	{
		if(str.compare(variables[i])==0)
		{
			return true;
		}
	}
	return false;
}

bool isdatatype(string str)
{
	for(int i=0;i<datatypes.size();i++)
	{
		if(str.compare(datatypes[i])==0)
		{
			return true;
		}
	}
	return false;
}


void clrscreen(vector<string> vec)
{
	if(vec[0].compare("clear")==0 && vec.size()==1)
	{
		string clr = "system(\"CLS\");";
		write(clr);
	}
	else
	{
		abort("Invalid Clear Command");
	}
	
}


void isvalid_return(vector<string> vec)
{
	if(isvalid_number(vec[1]))
	{
		string str = vec[0] + " " + vec[1] + " ;";
		write(str);
	}
	else
	{
		abort("Invalid return");
	}
}

bool isvalid_function(vector<string> vec)
{
	for(int index=0;index<vec.size());index++)
	{
		for(int i=0;i<functions.size());i++)
		{
			if(functions[i].compare(vec[index]))
			{
				func_call(vec,index);
				return true;
			}
		}
	}
	return false;
}

void func_call(vector<string> vec,int index)
{
	if(index==0)
	{
		string str = vec[0] + " ;";
		write(str);
	}
	if(index == 2)
	{
		string str = vec[0] + " " + vec[1] + " " + vec[2] + " ;";
		write(str); 
	}
	else
	{
		abort("Invalid Function Call");
	}
}




void isvalid_expression(vector<string> tokens)
{
    int flag, i = 0, index = 0;
    string str;
    if(!isvalid_function(tokens))
    {
		while (index < tokens.size())
	    {
	        flag = 0;
	        if (i % 2 == 0)
	        {
	            if (isvalid_variable(tokens[index]) || isvalid_number(tokens[index] ))
	                flag = 1;
	        }
	        else
	        {
	            if (isvalid_operator(tokens[index]))
	                flag = 2;
	        }
	        if (flag == 0)
	            abort("error in expression");
	        str = str + " " + tokens[index];
	        i++;
	        index++;
	    }
	    str = str + ";";
	    write(str);
	}
}










