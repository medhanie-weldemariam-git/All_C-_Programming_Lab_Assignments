#include"sorted_list.h"

using namespace std;
int main()
{


Sorted_List a;
//a.remove(33);
a.print(cout);
a.insert(44,23342);
a.remove(44);
a.insert(44,43434);
a.insert(45,23342);
a.insert(22,23342);
a.insert(60,23342);
a.insert(74,23342);
a.insert(72,23342);
a.insert(72,23342);
a.insert(73,23342);
a.print(cout);
a.insert(66,23342);
a.print(cout);
a.insert(11,23342);
a.insert(50,2334444);
a.insert(50,2884444);
a.insert(50,23544);
a.insert(50,233434);
a.insert(11,233434);
a.print(cout);
a.remove(11);
a.print(cout);
a.insert(11,2434343);
a.print(cout);
a.remove(7777);
a.remove(7777);
a.remove(7777);
a.remove(7777);
a.print(cout);

a.remove(60);
a.print(cout);

cout << a.size() << endl;

if (a.find(66)){
	cout << "found" << endl;
}

a.remove(66);
a.print(cout);

a.insert(70,23342);
a.insert(80,23342);
a.print(cout);

a.remove(74);
a.print(cout);
a.remove(80);
a.print(cout);


Sorted_List b;

if (a.contains(b)){
	cout << "a contains b" << endl;
}
else
	cout << "Not contained" << endl;

b.insert(44,23742);
b.insert(70,2742);
b.insert(45,23742);
b.insert(72,2742);
b.print(cout);
if (a.contains(b)){
	cout << "a contains b" << endl;
}
else
	cout << "Not contained" << endl;

b.remove(44);
b.remove(44);
b.print(cout);
b.remove(70);
b.print(cout);
b.print(cout);
b.print(cout);

if (a.contains(b)){
	cout << "a contains b" << endl;
}
else
	cout << "Not contained" << endl;

b.insert(10,10);
if (a.contains(b)){
	cout << "a contains b" << endl;
}
else
	cout << "Not contained" << endl;
b.remove(10);
b.insert(9999,434);
if (a.contains(b)){
	cout << "a contains b" << endl;
}
else
	cout << "Not contained" << endl;
b.remove(9999);



Sorted_List c;
if (b.contains(c)){
	cout << "b contains c" << endl;
}
else
	cout << "Not contained" << endl;
c.insert(55,444);
c.insert(1,4444);
c.print(cout);
if (b.contains(c)){
	cout << "b contains c" << endl;
}
else
	cout << "Not contained" << endl;


// Copy Constructor
Sorted_List d(c);
c.print(cout);
d.print(cout);

c.remove(55);
c.print(cout);
d.print(cout);
d.insert(577,444);
c.insert(1,4444);
c.print(cout);
d.print(cout);
d.remove(1);
c.insert(2,4444);
c.print(cout);
d.print(cout);

Sorted_List e(d);
Sorted_List f(e);
c.print(cout);
d.print(cout);
e.print(cout);

e.insert(55,6666);
e.print(cout);
e.insert(57,6666);
e.print(cout);
e.remove(57);
e.print(cout);
cout << "legendary" << endl;
e.insert(55,6666);	
e.remove(55);
e.insert(56,6666);
f.insert(9999,6666);
cout << "list d" << endl; d.print(cout);
cout << "list c"<< endl; c.print(cout);
cout << "list e" << endl;e.print(cout);
cout << "list f" << endl;f.print(cout);


//f.modifies(f);
cout << "list f" << endl;f.print(cout);

// Assignament operator
Sorted_List assignament_operator = e;
assignament_operator.insert(2121212,212121);
cout << "list e" << endl;e.print(cout);
cout << "list assignament_operator" << endl;assignament_operator.print(cout);

//+Operator
Sorted_List plus_operator = f + c;

plus_operator.print(cout);

//[] Operator
cout << "insert(577,444); "<<plus_operator[577] << endl;
if (plus_operator.contains_key_value(577,plus_operator[577])){
	cout << "577 and " << plus_operator[577] << " are in the list" << endl;
}
cout << plus_operator[578] << endl;
if (!plus_operator.contains_key_value(578,plus_operator[578])){
	cout << "578 and " << plus_operator[578] << " are not in the list" << endl;
}
cout <<  "insert(55,6666); "<< plus_operator[9999] << endl;
cout << plus_operator[0] << endl;
cout << "insert(1,4444); "<<plus_operator[1] << endl;
if (plus_operator.contains_key_value(1,plus_operator[1])){
	cout << "1 and " << plus_operator[1] << " are in the list" << endl;
}

//<< Operator
ostream& temporary = operator<<(cout, plus_operator);
temporary.operator<<(endl);

ostream& temporary2 = operator<<(cout, c);
temporary2.operator<<(endl);

//Iterator

for (Sorted_List::Iterator i = plus_operator.begin(); i != plus_operator.end(); ++i)
{
cout << *i << endl; // retrieve and print each data item
}
return 0;
}
