#include <iostream>
#include <tr1/unordered_map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;


//used to determine type of function to perform
string substring(string input, int start, int end){
	string returnString = "";
	if(input.length() < (unsigned int)end-start+1){
		return input;
	}
	for(int i = 0;i<(end-start+1);i++){
		returnString.append(" ");
	}
	for(int i = start;i<=end;i++){
		returnString.at(i-start)=input.at(i);
	}
	return returnString;
}
//removes spaces
string noSpaces(string input){
	string returnString;
	for(unsigned int i = 0,k = 0; i<input.length() ;i++){
		if(input.at(i)!=' '){
			returnString.append(" ");
			returnString.at(k)=input.at(i);
			k++;
		}
	}
	return returnString;
}

//converts string to double
double stoi(string input){
	double returnValue;
	
	for(unsigned int i = 0, j=0; i<input.length();i++){
		if(input.at(i)=='1'){
			returnValue += 1*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='2'){
			returnValue += 2*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='3'){
			returnValue += 3*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='4'){
			returnValue += 4*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='5'){
			returnValue += 5*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='6'){
			returnValue += 6*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='7'){
			returnValue += 7*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='8'){
			returnValue += 8*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='9'){
			returnValue += 9*pow(10,input.length()-1-i+j);
		}else if(input.at(i)=='.'){
			j=1;
		}
	}
	return returnValue;
}

//determines if input string is a number
bool isNum(string input){
	bool returnValue = true;
	
	for(unsigned int i = 0; i<input.length();i++){
		if(input.at(i)=='1'){
		}else if(input.at(i)=='2'){
		}else if(input.at(i)=='3'){
		}else if(input.at(i)=='4'){
		}else if(input.at(i)=='5'){
		}else if(input.at(i)=='6'){
		}else if(input.at(i)=='7'){
		}else if(input.at(i)=='8'){
		}else if(input.at(i)=='9'){
		}else if(input.at(i)=='.'){
		}else if(input.at(i)=='0'){	
		}else{
			return false;
		}
	}
	return returnValue;
}

//determines if input is an operator
bool isOperator(string input){
	if(input == "^"){
		return true;
	}else if(input == "*"){
		return true;
	}else if(input == "/"){
		return true;
	}else if(input == "+"){
		return true;
	}else if(input == "-"){
		return true;
	}else if(input == "("){
		return true;
	}else if(input == ")"){
		return true;
	}else{
		return false;
	}
	
}

//determines if input is a string(var name)
bool isString(string input){
	for(unsigned int i = 0; i<input.length();i++){
		if(((input.at(i) >=65 && input.at(i) <=90) || (input.at(i) >=97 && input.at(i) <=122))){
		}else{
			return false;
		}
	}return true;
}

//determines if input is a string(function)
bool isFunction(string input){
	if(input == "sin("){
		return true;
	}else if(input == "cos("){
		return true;
	}else if(input == "log("){
		return true;
	}else if(input == "sin"){
		return true;
	}else if(input == "cos"){
		return true;
	}else if(input == "log"){
		return true;
	}else{
		return false;
	}
}

double evaluate(tr1::unordered_map <string,double> map, tr1::unordered_map <string,bool> mappedValues,queue<string> input){
	double returnValue = 0;
	queue<string> output;
	stack<string> operators;
	stack<double> evaluateStack;
	bool doPop = true;
	
	//shunting-yard to postfix
	while(!input.empty()){
		doPop = true;
		if(isNum(input.front())){
			output.push(input.front());
		}
		if(isString(input.front())){
			output.push(input.front());
		}
		if(isOperator(input.front()) && input.front() != " "){
			if(input.front()=="^"){
					operators.push(input.front());
			}
			if(input.front()=="/" || input.front()=="*"){
				if(operators.size()!=0){
					if(operators.top()=="/" || operators.top()=="*" || operators.top()== "^"){
						output.push(operators.top());
						operators.pop();
						doPop = false;
					}else{
						operators.push(input.front());
					}
				}else{
					operators.push(input.front());
				}
			}
			if(input.front()=="-" || input.front()=="+"){
				if(operators.size()!=0){
					if(operators.top()=="-" || operators.top()=="+" || operators.top()=="/" || operators.top()=="*" || operators.top()== "^"){
						output.push(operators.top());
						operators.pop();	
						doPop = false;
					}else{
						operators.push(input.front());
					}
				}else{
					operators.push(input.front());
				}
			}
			if(input.front()=="("){
				operators.push(input.front());
			}
			if(input.front()==")"){
				while(true){
					if(operators.top() == "("){
						break;
					}
					output.push(operators.top());
					operators.pop();
				}
				operators.pop();
			}
		}
		if(isFunction(input.front())){
			if(input.front() == "sin("){
				operators.push("sin");
				operators.push("(");
			}
			if(input.front() == "cos("){
				operators.push("cos");
				operators.push("(");
			}
			if(input.front() == "log("){
				operators.push("log");
				operators.push("(");
			}
		}
		if(doPop){
			input.pop();
		}
		
	}
	
	//empty operator stack to output queue
	while(!operators.empty()){
		if(operators.top() != "(" && operators.top() != ")"){
			output.push(operators.top());
		}
		
		operators.pop();
	}
	
	/*queue<string> temp = output;
	while(!temp.empty()){
		cout << temp.front();
		temp.pop();
	}
	cout << endl;*/
	
	//evaluate postfix
	while(!output.empty()){
		if(isNum(output.front())){
			evaluateStack.push(stoi(output.front()));
		}else if(isString(output.front()) && !isFunction(output.front())){
			if(mappedValues[output.front()]==false){
				throw 2;
			}else{
				evaluateStack.push(map[output.front()]);
			}
		}else if(isOperator(output.front()) && !isFunction(output.front())){
			double x = evaluateStack.top();
			evaluateStack.pop();
			double y = evaluateStack.top();
			evaluateStack.pop();
			
			if(output.front() == "+"){
				evaluateStack.push(y + x);
			}
			if(output.front() == "-"){
				evaluateStack.push(y - x);
			}
			if(output.front() == "/"){
				if(x == 0){
					throw 1;
					return 0;
				}else{
					evaluateStack.push(y/x);
				}
			}
			if(output.front() == "*"){
				evaluateStack.push(y * x);
			}
			if(output.front() == "^"){
				evaluateStack.push(pow(y,x));
			}
		}else if(isFunction(output.front())){
			double x = evaluateStack.top();
			evaluateStack.pop();
			if(output.front() == "sin"){
				evaluateStack.push(sin(x));
			}
			if(output.front() == "cos"){
				evaluateStack.push(cos(x));
			}
			if(output.front() == "log"){
				evaluateStack.push(log(x));
			}
		}
		output.pop();
	}
	//return final value
	returnValue = evaluateStack.top();
	return returnValue; 
}


int main(){
	string inputString;
	string typeOfFunction;
	string tempString;
	string name;
	string data;
	string quit;
	double value = 1;
	bool operatedOn = true;
	tr1::unordered_map <string, double> map;
	tr1::unordered_map <string, bool> mappedVars;
	
	queue<string> input;
	map["Pi"]=3.14169;
	map["e"]=2.718;
	mappedVars["Pi"]=true;
	mappedVars["e"]=true;
	
	while(quit != "quit"){
		//take in input
		getline(cin,inputString);
		inputString.append(" ");
	
		
		for(unsigned int startIndex=0;startIndex<inputString.length();startIndex++){
			if(inputString.at(startIndex) != ' '){
				for(unsigned int endIndex=startIndex;endIndex<inputString.length();endIndex++){
					if(inputString.at(endIndex) == ' ' && noSpaces(substring(inputString,startIndex,endIndex-1)) != ""){
						input.push(noSpaces(substring(inputString,startIndex,endIndex-1)));
						startIndex = endIndex;
					}else if(endIndex == inputString.length()-1){
						input.push(noSpaces(substring(inputString,startIndex,endIndex-1)));
					}	
				}
			}	
		}
		
		if(input.front() == "quit"){
			break;
		}
		//evaluating expression	
		if(input.front() != "let" && input.size()!=1){
			try{
				cout << evaluate(map, mappedVars,input) << endl;
			}catch(int e){
				if(e == 1){
					cout << "ERROR: Division by zero" << endl;
				}else if (e == 2){
					cout << "ERROR: Undeclared Variable" << endl;
				}
			}
			operatedOn = false;
		}
		
		//setting var
		if(input.front()=="let"){
			input.pop();
			name = noSpaces(input.front());
			input.pop();
			try{
				value = evaluate(map, mappedVars, input);
			}catch(int e){
				if(e == 1){
					cout << "ERROR: Division by zero" << endl;
				}else if (e == 2){
					cout << "ERROR: Undeclared Variable" << endl;
				}
			}
			
			map[name]= value;
			mappedVars[name]= true;
			operatedOn=false;
		}
		
		//print var
		if(mappedVars[input.front()] && operatedOn){
			cout << map[input.front()] << endl;
		}else if(mappedVars[input.front()]==false && operatedOn){
			cout << "Error: Undeclared Variable" << endl;
		}
		operatedOn=true;
		while(!input.empty()){
			input.pop();
		}
	}
	return 0;
}
